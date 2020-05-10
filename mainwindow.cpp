#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new ODBppClient("localhost", 10000);
    QTimer::singleShot(1000, [=]{
        test();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(){
    client->sendLayer("C:\\Users\\alexe\\Desktop\\study\\7 сем\\Радар\\ODB test\\tests\\bottom\\features_bottom", 0, 255, 0);
    QThread::msleep(1000);
    client->sendLayer("C:\\Users\\alexe\\Desktop\\study\\7 сем\\Радар\\ODB test\\tests\\top\\features_top", 0, 0, 255);

    QThread::msleep(1000);
    client->sendNetlist("C:\\Users\\alexe\\Desktop\\study\\7 сем\\Радар\\ODB test\\tests\\netlist\\netlist");
    QThread::msleep(7000);
    client->illuminateNet("A3");
    QThread::msleep(1000);
    client->illuminateNet("A4");
}
