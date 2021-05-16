/*
 * "Q    t"
 * <Quaint Elements>
 *
 * Start using fantastic UI elements in your project with one header file.
 *
 * yiyaowen (c) 2021 All rights reserved
 * Supports @ https://github.com/yiyaowen/QuaintElements
 */
#ifndef QUAINT_ELEM_SWITCH_H
#define QUAINT_ELEM_SWITCH_H

#include <memory>
#include <QTimer>
#include <QWidget>

namespace QuaintElements {
    class Switch : public QWidget {
    Q_OBJECT
    public:
        explicit Switch(QWidget* parent = nullptr);
        Switch(int width, int height, QWidget* parent = nullptr);
        ~Switch() override = default;

    public:
        inline void setLocked(bool value) { mIsLocked = value; }
        inline bool isLocked() const { return mIsLocked; }

    public:
        constexpr static int On = 1;
        constexpr static int Off = 2;

    private:
        constexpr static int AnimatingOn = 3;
        constexpr static int AnimatingOff = 4;

    signals:
        void onStateChange(int state);

    private slots:
        void playAnimation();

    protected:
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;

    private:
        int width = 50;
        int height = 30;
        int rectWidth = 20;

        int sliderCenterPosX = 0;

        bool mIsLocked = false;
        int state = Off;
        std::unique_ptr<QTimer> timer = nullptr;

        QColor backgroundEmptyColor = QColor(181, 181, 184);
        QColor backgroundFillColor = QColor(45, 114, 246);
        QColor sliderFillColor = QColor(255, 255, 255);
    };
}

#endif // QUAINT_ELEM_SWITCH_H