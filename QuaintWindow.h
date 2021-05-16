/*
 * "Q    t"
 * <Quaint Elements>
 *
 * Start using fantastic UI elements in your project with one header file.
 *
 * yiyaowen (c) 2021 All rights reserved
 * Supports @ https://github.com/yiyaowen/QuaintElements
 */
#ifndef QUAINT_WINDOW_H
#define QUAINT_WINDOW_H

#include <QGridLayout>
#include <QMainWindow>

#include "Switch.h"
using namespace QuaintElements;

class QuaintWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit QuaintWindow(QWidget *parent = nullptr);
    ~QuaintWindow() override = default;

private slots:
    void changeWindowTitle(int state);

private:
    std::unique_ptr<QWidget> centerHolder = nullptr;
    std::unique_ptr<QGridLayout> mainLayout = nullptr;
    std::unique_ptr<Switch> switcher = nullptr;
};
#endif // QUAINT_WINDOW_H
