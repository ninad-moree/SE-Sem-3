#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<bits/stdc++.h>

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
using namespace std;
QImage image(800,800,QImage::Format_RGB888);

void MainWindow::DDA(int x1,int y1,int x2,int y2,int c1,int c2,int c3)
{
    float dx,dy,x,y,len,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
            len=abs(dx);
    else
            len=abs(dy);
    x=x1;
    y=y1;
    xinc=dx/len;
    yinc=dy/len;
    int i=0;
    while(i<len)
    {
        image.setPixel(x,y,qRgb(c1,c2,c3));
        x=x+xinc;
        y=y+yinc;
        i=i+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::Circle(int x,int y,int r,int c1,int c2,int c3)
{
    int x0=0;
    int y0=r;
    int p=3-2*r;

    while(x0<=y0)
    {
        image.setPixel(x+x0,y+y0,qRgb(c1,c2,c3));
        image.setPixel(x+x0,y-y0,qRgb(c1,c2,c3));
        image.setPixel(x-x0,y+y0,qRgb(c1,c2,c3));
        image.setPixel(x-x0,y-y0,qRgb(c1,c2,c3));
        image.setPixel(x+y0,y+x0,qRgb(c1,c2,c3));
        image.setPixel(x+y0,y-x0,qRgb(c1,c2,c3));
        image.setPixel(x-y0,y+x0,qRgb(c1,c2,c3));
        image.setPixel(x-y0,y-x0,qRgb(c1,c2,c3));

        if(p<0)
        {
            p=p+4*x0+6;
            x0=x0+1;
        }
        else
        {
            p=p+4*(x0-y0)+10;
            x0=x0+1;
            y0=y0-1;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    DDA(400,100,600,446, 255,255,0);
    DDA(200,446,600,446, 255,255,0);
    DDA(400,100,200,446, 255,255,0);
}

void MainWindow::on_pushButton_2_clicked()
{
    Circle(400,331,231, 255,0,0);
}

void MainWindow::on_pushButton_3_clicked()
{
    Circle(400,331,115, 0,255,0);
}
