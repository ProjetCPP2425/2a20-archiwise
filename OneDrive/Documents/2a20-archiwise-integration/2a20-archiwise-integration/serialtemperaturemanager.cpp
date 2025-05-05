#include "SerialTemperatureManager.h"
#include <QSqlError>


SerialTemperatureManager::SerialTemperatureManager(QObject *parent)
    : QObject(parent), serial(new QSerialPort(this)), chantierIdToUpdate(-1)
{
    // Set default serial parameters
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    connect(serial, &QSerialPort::readyRead, this, &SerialTemperatureManager::readSerialData);
    connect(serial, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError error) {
        if (error != QSerialPort::NoError) {
            emit errorOccurred("Serial port error: " + serial->errorString());
        }
    });
}

SerialTemperatureManager::~SerialTemperatureManager()
{
    stopListening();
    delete serial;
}

void SerialTemperatureManager::setSerialParameters(qint32 baudRate, QSerialPort::DataBits dataBits,
                                                   QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    if (serial->isOpen()) {
        serial->close();
    }

    serial->setBaudRate(baudRate);
    serial->setDataBits(dataBits);
    serial->setParity(parity);
    serial->setStopBits(stopBits);
}

void SerialTemperatureManager::startListening(const QString &portName, int chantierId)
{
    if (serial->isOpen()) {
        serial->close();
    }

    chantierIdToUpdate = chantierId;
    serial->setPortName(portName);

    if (!serial->open(QIODevice::ReadWrite)) {
        emit errorOccurred("Failed to open serial port: " + serial->errorString());
        return;
    }

    qDebug() << "✅ Serial port opened successfully on" << portName;
}

void SerialTemperatureManager::stopListening()
{
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Serial port closed";
    }
}

void SerialTemperatureManager::readSerialData()
{
    while (serial->canReadLine()) {
        QByteArray data = serial->readLine();
        QString dataString = QString::fromUtf8(data).trimmed();
        qDebug() << "🌡️ Raw data received:" << dataString;

        // Use a regex to extract the temperature value
        QRegularExpression re("Temperature.*?(-?\\d+\\.?\\d*)"); // Matches numbers like 24, -3.5, 100.75
        QRegularExpressionMatch match = re.match(dataString);

        bool ok = false;
        float temperature = 0.0f;

        if (match.hasMatch()) {
            QString tempStr = match.captured(1); // Get the captured number
            temperature = tempStr.toFloat(&ok); // Attempt conversion
        }

        if (ok && validateTemperature(temperature)) {
            qDebug() << "🌡️ Parsed temperature:" << temperature;
            updateTemperatureInDatabase(temperature);
        } else {
            QString errorMsg = QString("Invalid temperature data: %1").arg(dataString);
            qDebug() << "⚠️" << errorMsg;
            emit errorOccurred(errorMsg);
        }
    }
}
bool SerialTemperatureManager::validateTemperature(float temperature)
{
    // Adjust these values based on your expected temperature range
    const float MIN_TEMP = -50.0f;
    const float MAX_TEMP = 150.0f;

    if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
        qDebug() << "Temperature out of range:" << temperature;
        return false;
    }
    return true;
}

void SerialTemperatureManager::updateTemperatureInDatabase(float temperature)
{
    if (chantierIdToUpdate == -1) {
        QString errorMsg = "No chantier selected for update.";
        qDebug() << "⚠️" << errorMsg;
        emit errorOccurred(errorMsg);
        return;
    }

    // Ensure database is valid and open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        QString errorMsg = "Database connection is invalid.";
        qDebug() << "❌" << errorMsg;
        emit errorOccurred(errorMsg);
        return;
    }

    if (!db.isOpen() && !db.open()) {
        QString errorMsg = "Failed to open the database: " + db.lastError().text();
        qDebug() << "❌" << errorMsg;
        emit errorOccurred(errorMsg);
        return;
    }

    // Update temperature in database
    QSqlQuery query(db);
    query.prepare("UPDATE chantiers SET temperature = :temperature WHERE id = :id");
    query.bindValue(":temperature", temperature);
    query.bindValue(":id", chantierIdToUpdate);

    if (!query.exec()) {
        QString errorMsg = "SQL update error: " + query.lastError().text();
        qDebug() << "❌" << errorMsg;
        emit errorOccurred(errorMsg);
        return;
    }

    if (query.numRowsAffected() == 0) {
        QString warningMsg = QString("⚠️ UPDATE executed but no rows affected (maybe wrong ID: %1)").arg(chantierIdToUpdate);
        qDebug() << warningMsg;
        emit errorOccurred(warningMsg);
        return;
    }

    qDebug() << "✅ Temperature updated successfully for chantier ID:" << chantierIdToUpdate << ", new temperature:" << temperature;
    emit temperatureUpdated(chantierIdToUpdate, temperature);

    // Control buzzer and fan based on temperature threshold (22°C)
    const float ACTIVATION_THRESHOLD = 22.0f;
    if (temperature > ACTIVATION_THRESHOLD) {
        emit activateBuzzerAndFan();
    } else {
        emit deactivateBuzzerAndFan();
    }
}


void SerialTemperatureManager::activateBuzzerAndFan()
{
    if (!serial->isOpen()) {
        qDebug() << "⚠️ Serial port not open, cannot activate buzzer and fan";
        return;
    }

    // Send activation command (adjust based on your hardware protocol)
    QByteArray command = "ACTIVATE_BUZZER_FAN\n";
    qint64 bytesWritten = serial->write(command);

    if (bytesWritten == -1) {
        qDebug() << "❌ Failed to write activation command:" << serial->errorString();
        emit errorOccurred("Failed to activate buzzer and fan: " + serial->errorString());
    } else {
        qDebug() << "🔔🔄 Buzzer and Fan ACTIVATED (Temperature > 22°C)";
    }
}

void SerialTemperatureManager::deactivateBuzzerAndFan()
{
    if (!serial->isOpen()) {
        qDebug() << "⚠️ Serial port not open, cannot deactivate buzzer and fan";
        return;
    }

    // Send deactivation command (adjust based on your hardware protocol)
    QByteArray command = "DEACTIVATE_BUZZER_FAN\n";
    qint64 bytesWritten = serial->write(command);

    if (bytesWritten == -1) {
        qDebug() << "❌ Failed to write deactivation command:" << serial->errorString();
        emit errorOccurred("Failed to deactivate buzzer and fan: " + serial->errorString());
    } else {
        qDebug() << "🔕⏹️ Buzzer and Fan DEACTIVATED (Temperature ≤ 22°C)";
    }
}
