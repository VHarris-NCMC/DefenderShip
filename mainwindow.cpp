#include "mainwindow.h"
#include <windowmanager.h>
#include <QCoreApplication>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this,SLOT(checkSize()));
    timer->start(CONFIG::GameSpeed()/300);
}

MainWindow::~MainWindow()
{

}
void MainWindow::checkSize()
{
       showMaximized();
}

