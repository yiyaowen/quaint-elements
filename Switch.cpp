/*
 * "Q    t"
 * <Quaint Elements>
 *
 * Start using fantastic UI elements in your project with one header file.
 *
 * yiyaowen (c) 2021 All rights reserved
 * Supports @ https://github.com/yiyaowen/QuaintElements
 */
#include <QMouseEvent>
#include <QPainter>
#include <QtMath>

#include "Switch.h"
using namespace QuaintElements;

Switch::Switch(QWidget *parent)
    : QWidget(parent)
{
    timer = std::make_unique<QTimer>();
    timer->setInterval(10);
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(playAnimation()));

    this->setFixedSize(width, height);
}

Switch::Switch(int width, int height, QWidget *parent)
    : Switch(parent)
{
    if (width > height) {
        this->width = width;
        this->height = height;
        this->rectWidth = width - height;
    }
    this->setFixedSize(width, height);
}

void Switch::playAnimation() {
    if (state == AnimatingOn) {
        sliderCenterPosX = qMax(rectWidth, sliderCenterPosX + 10);
        this->update();
        if (sliderCenterPosX == rectWidth) {
            state = On;
            timer->stop();
            emit onStateChange(On);
        }
    }
    else if (state == AnimatingOff) {
        sliderCenterPosX = qMax(0, sliderCenterPosX - 10);
        this->update();
        if (sliderCenterPosX == 0) {
            state = Off;
            timer->stop();
            emit onStateChange(Off);
        }
    }
    else {
        timer->stop();
    }
}

void Switch::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);

    // Draw empty background
    painter.setPen(Qt::NoPen);
    painter.setBrush(backgroundEmptyColor);
    painter.drawRect(height / 2 + sliderCenterPosX, 0, rectWidth - sliderCenterPosX, height);
    painter.drawPie(rectWidth, 0, height, height, -16 * 90, 16 * 180);

    // Draw filled background
    painter.setBrush(backgroundFillColor);
    painter.drawRect(height / 2, 0, sliderCenterPosX, height);
    painter.drawPie(0, 0, height, height, 16 * 90, 16 * 180);

    // Draw slider
    // (Notice: slider's center position is relative to background center rect)
    painter.setBrush(sliderFillColor);
    painter.drawPie(sliderCenterPosX, 0, height, height, 0, 16 * 360);

    painter.end();
}

void Switch::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    if (event->button() == Qt::LeftButton && !mIsLocked) {
        if (state == On) state = AnimatingOff;
        else if (state == Off) state = AnimatingOn;
        timer->start();
    }
}