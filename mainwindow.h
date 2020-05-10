#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <odbppclient.h>
#include <QTcpSocket>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //ODBppClient *client();
    ODBppClient *client/* = ODBppClient("localhost", 10000)*/;
private:
    void test();

};
#endif // MAINWINDOW_H
