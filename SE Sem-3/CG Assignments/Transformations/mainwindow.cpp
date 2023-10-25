#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>

using namespace std ;
QImage img(1150, 700, QImage :: Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(int x1, int y1, int x2, int y2, int color1, int color2, int color3)
{
    float dx, dy, x, y, len, Xinc, Yinc;
    dx = x2 - x1 ;
    dy = y2 - y1 ;
    if (abs(dx)>=abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }
    x = x1 ;
    y = y1 ;
    int i = 0 ;
    Xinc = dx/len;
    Yinc = dy/len ;
    while (i<len)
    {
        img.setPixel(x,y, qRgb(color1, color2, color3));
        x = x + Xinc;
        y = y + Yinc ;
        i++;
    };
    ui -> label->setPixmap(QPixmap :: fromImage(img));
}

void MainWindow::translation(){
    int tx, ty;
    tx = ui->plainTextEdit->toPlainText().toInt();
    ty = ui->plainTextEdit_2->toPlainText().toInt();

    DDA(575+tx,350-ty,600+tx,310-ty,0,255,0);
    DDA(575+tx,350-ty,625+tx,350-ty,0,255,0);
    DDA(600+tx,310-ty,625+tx,350-ty,0,255,0);
}

void MainWindow::scaling(){
    int sx, sy;

    sx = ui->plainTextEdit_3->toPlainText().toFloat();
    sy = ui->plainTextEdit_4->toPlainText().toFloat();

    DDA(575,350,575+((625-575)*sx),350,0,0,255);
    DDA(575,350,575+((600-575)*sx),350-((350-310)*sy),0,0,255);
    DDA(575+((600-575)*sx),350-((350-310)*sy),575+((625-575)*sx),350,0,0,255);

    ui -> label->setPixmap(QPixmap :: fromImage(img));
}

void MainWindow::rotate(){
    float deg;
    //deg = ui->plainTextEdit_5->toPlainText().toFloat();
    deg = ui->plainTextEdit_5->toPlainText().toFloat();
    deg = deg*3.14/180.0;

    int x1 = 0;
    int x2 = (50*cos(deg));
    int x3 = (25*cos(deg))-((-40)*sin(deg));

    int y1 = 0;
    int y2 = (50*sin(deg));
    int y3 = (25*sin(deg))+((-40)*cos(deg));

    DDA(575+x1,350+y1,575+x2,350+y2,255,255,0);
    DDA(575+x2,350+y2,575+x3,350+y3,255,255,0);
    DDA(575+x1,350+y1,575+x3,350+y3,255,255,0);
}

void MainWindow::on_pushButton_clicked()
{
    translation();
}

void MainWindow::on_pushButton_2_clicked()
{
    scaling();
}

void MainWindow::on_pushButton_3_clicked()
{
    DDA(575,0,575,700,255,255,255);
    DDA(0,350,1150,350,255,255,255);

    DDA(575,350,625,350,255,0,0);
    DDA(575,350,600,310,255,0,0);
    DDA(600,310,625,350,255,0,0);
}

void MainWindow::on_pushButton_4_clicked()
{
    rotate();
}
