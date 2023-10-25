#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <iostream>

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
    QString myFilename;

protected:
    void paintEvent(QPaintEvent *event);
    void myfunction(QPainter *qp);

    void Code(char c[4],float x,float y);
    void Clipping(char c[],char d[],float &x,float &y,float m);

};
#endif // MAINWINDOW_H
