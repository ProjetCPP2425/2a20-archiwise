#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QColor>
#include <QPropertyAnimation>

class BarChartWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double animationProgress READ animationProgress WRITE setAnimationProgress)

public:
    explicit BarChartWidget(QWidget *parent = nullptr);

    // Data management
    void setData(const QMap<QString, double>& data);
    void addDataItem(const QString& label, double value);
    void clearData();

    // Customization
    void setBarColor(const QColor& color);
    void setBarColor(const QString& label, const QColor& color);
    void setBackgroundColor(const QColor& color);
    void setTextColor(const QColor& color);
    void setAnimationDuration(int milliseconds);

    // Utility
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    double animationProgress() const;
    void setAnimationProgress(double progress);
    void calculateChartDimensions();
    void drawBars(QPainter& painter);
    void drawAxis(QPainter& painter);
    void drawLabels(QPainter& painter);
    void drawLegend(QPainter& painter);

    QMap<QString, double> m_data;
    QMap<QString, QColor> m_barColors;
    QColor m_defaultBarColor = QColor(65, 105, 225);  // Royal Blue
    QColor m_backgroundColor = Qt::white;
    QColor m_textColor = Qt::black;
    QColor m_axisColor = Qt::black;

    // Animation
    QPropertyAnimation* m_animation;
    double m_animationProgress = 0.0;
    int m_animationDuration = 1000;

    // Layout
    int m_margin = 20;
    int m_barSpacing = 10;
    int m_legendSpacing = 15;
    int m_maxBarWidth = 50;
    double m_maxValue = 0;
    double m_scaleFactor = 1.0;
};

#endif // BARCHARTWIDGET_H
