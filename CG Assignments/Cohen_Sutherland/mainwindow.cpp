#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPainter>
#include<QTextEdit>
#include<QImage>
#include<QLine>
#include<QLabel>

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

QImage image(500,500,QImage::Format_RGBA8888);

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter qp(this);
    myfunction(&qp);
}


void MainWindow::myfunction(QPainter *qp)
{
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(200,200,400,200);
    qp->drawLine(200,400,400,400);
    qp->drawLine(200,200,200,400);
    qp->drawLine(400,200,400,400);

    qp->drawLine(600,200,800,200);
    qp->drawLine(600,400,800,400);
    qp->drawLine(600,200,600,400);
    qp->drawLine(800,200,800,400);

    float x1,y1,x2,y2,x3,y3,x4,y4;
    char c[4],d[4];
    x1=250;
    y1=300;
    x2=450;
    y2=450;

    x3=650;
    y3=300;
    x4=850;
    y4=450;

    float m= float((y4-y3)/(x4-x3));
    Code(c,x3,y3);
    Code(d,x4,y4);
    Clipping(c,d,x3,y3,m);
    Clipping(d,c,x4,y4,m);


    qp->setPen(QPen(Qt::blue,Qt::SolidLine));
    qp->drawLine(x1,y1,x2,y2);
    qp->drawLine(x3,y3,x4,y4);
}


void MainWindow::Code(char c[4],float x,float y)
{
    c[0]=(y<200)?'1':'0';   //top
    c[1]=(y>400)?'1':'0';   //bottom
    c[2]=(x>800)?'1':'0';   //right
    c[3]=(x<600)?'1':'0';   //left
}


void MainWindow::Clipping(char c[],char d[],float&x,float &y,float m)
{
    int flag=0;
    int i;
    for (i=0;i<4;i++)
    {
        if(c[i]!='0' && d[i]!='0') //completely inside
        {
            flag=1;               // to be displayed
            break;
        }


        if(flag==0)              //partial
        {
            if(c[0]!='0')        //top
            {
                x=((200-y)/m)+x;
                y=200;
            }
            else if(c[1]!='0')   //bottom
            {
                x=((400-y)/m)+x;
                y=400;
            }
            else if(c[2]!='0')   //right
            {
                y=m*(800-x)+y;
                x=800;
            }
            else if(c[3]!='0')   //left
            {
                y=m*(600-x)+y;
                x=600;
            }
        }
    }
}
