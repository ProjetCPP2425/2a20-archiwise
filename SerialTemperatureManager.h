#ifndef SERIALTEMPERATUREMANAGER_H
#define SERIALTEMPERATUREMANAGER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QSqlQuery>
#include <QDebug>
#include<QtSerialPort/QSerialPortInfo>
#include<QtSerialPort>
#include<QSerialPortInfo>

class SerialTemperatureManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialTemperatureManager(QObject *parent = nullptr);
    ~SerialTemperatureManager();

    void startListening(const QString &portName, int chantierId);
    void stopListening();
    void activateBuzzerAndFan();
    void deactivateBuzzerAndFan();

    void setSerialParameters(qint32 baudRate = QSerialPort::Baud9600,
                             QSerialPort::DataBits dataBits = QSerialPort::Data8,
                             QSerialPort::Parity parity = QSerialPort::NoParity,
                             QSerialPort::StopBits stopBits = QSerialPort::OneStop);

signals:
    void temperatureUpdated(int chantierId, float temperature);
    void errorOccurred(const QString &error);

private slots:
    void readSerialData();

private:
    QSerialPort *serial;
    int chantierIdToUpdate;

    void updateTemperatureInDatabase(float temperature);
    bool validateTemperature(float temperature);
};

#endif // SERIALTEMPERATUREMANAGER_H
