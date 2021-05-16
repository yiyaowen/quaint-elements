/*
 * "Q    t"
 * <Quaint Elements>
 *
 * Start using fantastic UI elements in your project with one header file.
 *
 * yiyaowen (c) 2021 All rights reserved
 * Supports @ https://github.com/yiyaowen/QuaintElements
 */
#include <QApplication>

#include "QuaintWindow.h"

QuaintWindow::QuaintWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 600);
    centerHolder = std::make_unique<QWidget>();
    this->setCentralWidget(centerHolder.get());
    mainLayout = std::make_unique<QGridLayout>();
    centerHolder->setLayout(mainLayout.get());

    switcher = std::make_unique<Switch>();
    mainLayout->addWidget(switcher.get());
    switcher->show();

    connect(switcher.get(), SIGNAL(onStateChange(int)), this, SLOT(changeWindowTitle(int)));
}

void QuaintWindow::changeWindowTitle(int state) {
    // When busy with trigger events, we should lock the switch
    switcher->setLocked(true);
    if (state == Switch::On) {
        this->setWindowTitle("Switch is on");
    }
    else if (state == Switch::Off) {
        this->setWindowTitle("Switch is off");
    }
    // When done with events, the switch should be unlocked
    switcher->setLocked(false);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QuaintWindow quaintWnd;
    quaintWnd.show();
    return app.exec();
}
