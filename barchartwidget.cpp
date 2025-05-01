#include "barchartwidget.h"
#include <QPainter>
#include <QFontMetrics>
#include <QDebug>

BarChartWidget::BarChartWidget(QWidget *parent) : QWidget(parent)
{
    m_animation = new QPropertyAnimation(this, "animationProgress");
    m_animation->setDuration(m_animationDuration);
    m_animation->setStartValue(0.0);
    m_animation->setEndValue(1.0);
    m_animation->setEasingCurve(QEasingCurve::OutBack);
}

void BarChartWidget::setData(const QMap<QString, double>& data)
{
    m_data = data;
    m_maxValue = 0;

    for (const double value : m_data) {
        if (value > m_maxValue) {
            m_maxValue = value;
        }
    }

    calculateChartDimensions();
    m_animation->start();
    update();
}

void BarChartWidget::addDataItem(const QString& label, double value)
{
    m_data.insert(label, value);
    if (value > m_maxValue) {
        m_maxValue = value;
    }
    calculateChartDimensions();
    update();
}

void BarChartWidget::clearData()
{
    m_data.clear();
    m_barColors.clear();
    m_maxValue = 0;
    update();
}

void BarChartWidget::setBarColor(const QColor& color)
{
    m_defaultBarColor = color;
    update();
}

void BarChartWidget::setBarColor(const QString& label, const QColor& color)
{
    m_barColors.insert(label, color);
    update();
}

void BarChartWidget::setBackgroundColor(const QColor& color)
{
    m_backgroundColor = color;
    update();
}

void BarChartWidget::setTextColor(const QColor& color)
{
    m_textColor = color;
    update();
}

void BarChartWidget::setAnimationDuration(int milliseconds)
{
    m_animationDuration = milliseconds;
    m_animation->setDuration(milliseconds);
}

double BarChartWidget::animationProgress() const
{
    return m_animationProgress;
}

void BarChartWidget::setAnimationProgress(double progress)
{
    m_animationProgress = progress;
    update();
}

void BarChartWidget::calculateChartDimensions()
{
    if (m_data.isEmpty()) return;

    int availableWidth = width() - 2 * m_margin;
    int availableHeight = height() - 2 * m_margin;

    int totalBarSpace = availableWidth - (m_data.size() - 1) * m_barSpacing;
    int barWidth = qMin(m_maxBarWidth, totalBarSpace / m_data.size());

    m_scaleFactor = (availableHeight - 30) / m_maxValue; // Leave space for labels
}

void BarChartWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw background
    painter.fillRect(rect(), m_backgroundColor);

    if (m_data.isEmpty()) return;

    drawAxis(painter);
    drawBars(painter);
    drawLabels(painter);
    drawLegend(painter);
}

void BarChartWidget::drawBars(QPainter& painter)
{
    int availableWidth = width() - 2 * m_margin;
    int availableHeight = height() - 2 * m_margin;

    int totalBarSpace = availableWidth - (m_data.size() - 1) * m_barSpacing;
    int barWidth = qMin(m_maxBarWidth, totalBarSpace / m_data.size());

    int x = m_margin;
    int yBase = height() - m_margin;

    int i = 0;
    for (auto it = m_data.constBegin(); it != m_data.constEnd(); ++it) {
        double value = it.value();
        const QString& label = it.key();

        // Get color for this bar
        QColor color = m_barColors.contains(label) ? m_barColors[label] : m_defaultBarColor;

        // Calculate animated height
        double animatedValue = value * m_animationProgress;
        int barHeight = animatedValue * m_scaleFactor;

        // Draw bar
        painter.setPen(Qt::NoPen);
        painter.setBrush(color);
        painter.drawRect(x, yBase - barHeight, barWidth, barHeight);

        // Draw highlight
        QColor highlight = color.lighter(120);
        painter.setBrush(highlight);
        painter.drawRect(x, yBase - barHeight, barWidth, 5);

        x += barWidth + m_barSpacing;
        i++;
    }
}

void BarChartWidget::drawAxis(QPainter& painter)
{
    painter.setPen(QPen(m_axisColor, 2));

    // X axis
    painter.drawLine(m_margin, height() - m_margin,
                     width() - m_margin, height() - m_margin);

    // Y axis
    painter.drawLine(m_margin, height() - m_margin,
                     m_margin, m_margin);
}

void BarChartWidget::drawLabels(QPainter& painter)
{
    painter.setPen(m_textColor);
    QFont font = painter.font();
    font.setPointSize(9);
    painter.setFont(font);

    int availableWidth = width() - 2 * m_margin;
    int totalBarSpace = availableWidth - (m_data.size() - 1) * m_barSpacing;
    int barWidth = qMin(m_maxBarWidth, totalBarSpace / m_data.size());

    int x = m_margin;
    int yBase = height() - m_margin;

    // Draw value labels
    for (auto it = m_data.constBegin(); it != m_data.constEnd(); ++it) {
        double value = it.value();
        const QString& label = it.key();

        double animatedValue = value * m_animationProgress;
        int barHeight = animatedValue * m_scaleFactor;

        QString valueText = QString::number(value, 'f', 1);
        QRect textRect(x, yBase - barHeight - 20, barWidth, 20);
        painter.drawText(textRect, Qt::AlignCenter, valueText);

        // Draw category labels
        QRect labelRect(x, yBase + 5, barWidth, 20);
        painter.drawText(labelRect, Qt::AlignCenter, label);

        x += barWidth + m_barSpacing;
    }
}

void BarChartWidget::drawLegend(QPainter& painter)
{
    if (m_barColors.isEmpty()) return;

    painter.setPen(m_textColor);
    QFont font = painter.font();
    font.setPointSize(8);
    painter.setFont(font);

    int legendX = width() - m_margin - 100;
    int legendY = m_margin;
    int itemHeight = 15;

    painter.drawText(legendX, legendY - 10, 100, 20, Qt::AlignLeft, "Legend");

    int i = 0;
    for (auto it = m_barColors.constBegin(); it != m_barColors.constEnd(); ++it) {
        const QString& label = it.key();
        const QColor& color = it.value();

        painter.setPen(Qt::NoPen);
        painter.setBrush(color);
        painter.drawRect(legendX, legendY + i * itemHeight, 10, 10);

        painter.setPen(m_textColor);
        painter.drawText(legendX + 15, legendY + i * itemHeight + 10,
                         85, 20, Qt::AlignLeft, label);

        i++;
    }
}

QSize BarChartWidget::minimumSizeHint() const
{
    return QSize(200, 150);
}

QSize BarChartWidget::sizeHint() const
{
    return QSize(400, 300);
}

void BarChartWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    calculateChartDimensions();
}
