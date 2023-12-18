#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage image(500,500,QImage::Format_RGB888);
QImage image1(500,500,QImage::Format_RGB888);

void MainWindow::DDA(int x1,int y1,int x2,int y2, int c1,int c2,int c3)
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
    };
    //ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::Draw_Polygon()
{
    DDA(200,200,400,200,255,255,0);
    DDA(200,400,400,400,255,255,0);
    DDA(200,200,200,400,255,255,0);
    DDA(400,200,400,400,255,255,0);

    DDA(250,300,450,450,255,0,0);
}

void MainWindow::on_pushButton_clicked()
{
    Draw_Polygon();
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::Code(int c[],float x,float y)
{
    if(x<200)
    {
        c[0]=1;
    }
    else
    {
        c[0]=0;
    }
    if(x>400)
    {
        c[1]=1;
    }
    else
    {
        c[1]=0;
    }
    if(y<200)
    {
        c[2]=1;
    }
    else
    {
        c[2]=0;
    }
    if(y>400)
    {
        c[3]=1;
    }
    else
    {
        c[3]=0;
    }
}

void MainWindow::line_test(int c[], int d[])
{
    int i=0;
    for (i=0;i<4;i++)
    {
        if(c[i]!=0 && d[i]!=0)
        {
            flag=false;
        }
    }
}

void MainWindow::Window_Clip(int c[],int d[],float &x,float &y,float m)
{
    int i=0;
    for (i=0;i<4;i++)
    {
        if(c[i]!=0 && d[i]!=0)
        {
            flag=false;
            break;
        }
        if(flag)
        {
        if(c[0]!=0)
        {
            y=m*(200-x)+y;
            x=200;
        }
        else if(c[1]!=0)
        {
            y=m*(400-x)+y;
            x=400;
        }
        else if(c[2]!=0)
        {
            x=((200-y)/m)+x;
            y=200;
        }
        else if(c[3]!=0)
        {
            x=((400-y)/m)+x;
            y=400;
        }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    DDA(200,200,400,200,255,255,0);
    DDA(200,400,400,400,255,255,0);
    DDA(200,200,200,400,255,255,0);
    DDA(400,200,400,400,255,255,0);

    float x1=250;
    float y1=300;
    float x2=450;
    float y2=450;

    for(int i=0;i<x2;i=i+1)
    {
        flag = true;
        int t[4],u[4];
        Code(t,x1,y1);
        Code(u,x2,y2);
        line_test(t,u);
        if(flag==false)
        {
            continue;
        }
        float m =float((y2-y1)/(x2-x1));
        Window_Clip(t,u,x2,y1,m);
        Window_Clip(u,t,x2,y2,m);
        DDA(x1,y1,x2,y2,0,255,0);
    }
    ui->label_2->setPixmap(QPixmap::fromImage(image));
}
