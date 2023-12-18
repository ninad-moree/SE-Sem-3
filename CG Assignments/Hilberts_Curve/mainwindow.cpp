#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(512,512,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dist_main = 512;
    x = 0;
    y = 0;
    dist = dist_main;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, xinc, yinc, step;
    dx = x2 - x1;
    dy = y2 - y1;
    if(std::abs(dx) > std::abs(dy))
    {
        step = std::abs(dx);
    }
    else
    {
        step = std::abs(dy);
    }
    xinc = dx/step;
    yinc = dy/step;
    x = x1;
    y = y1;
    for (int i = 1; i <= step ; i++)
    {
        img.setPixel(x, y, qRgb(0, 255, 0));
        x = x + xinc;
        y = y + yinc;
    }
}

void MainWindow::drawLine(int dx, int dy)
{
    DDA(x, y, x + dx, y + dy);
    x = x + dx;
    y = y + dy;
}
void MainWindow::goToXY(int x, int y)
{
    this->x = x;
    this->y = y;
}
void MainWindow::Hilbert1(int level)
{
    if (level > 0)
    {
        Hilbert2(level -1);
        drawLine(0, dist);
        Hilbert1(level - 1);
        drawLine(dist, 0);
        Hilbert1(level - 1);
        drawLine(0, -dist);
        Hilbert3(level - 1);
    }
}
void MainWindow::Hilbert2(int level)
{
    if (level > 0)
    {
        Hilbert1(level - 1);
        drawLine(dist, 0);
        Hilbert2(level - 1);
        drawLine(0, dist);
        Hilbert2(level - 1);
        drawLine(-dist, 0);
        Hilbert4(level - 1);
    }
}
void MainWindow::Hilbert3(int level)
{
    if(level > 0)
    {
        Hilbert4(level - 1);
        drawLine(-dist, 0);
        Hilbert3(level - 1);
        drawLine(0, -dist);
        Hilbert3(level - 1);
        drawLine(dist, 0);
        Hilbert1(level - 1);
    }
}
void MainWindow::Hilbert4(int level)
{
    if(level > 0)
    {
        Hilbert3(level - 1);
        drawLine(0, -dist);
        Hilbert4(level -1);
        drawLine(-dist, 0);
        Hilbert4(level - 1);
        drawLine(0, dist);
        Hilbert2(level -1);
    }
}
void MainWindow::on_pushButton_clicked()
{
    int level;
    level = ui->textEdit->toPlainText().toInt();
    dist = 512;
    for(int i=0;i<512;i++)
    {
        for(int j=0;j<512;j++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    for (int i{level} ; i > 0 ; i--)
    {
        dist = dist / 2;
    }
    goToXY(dist/2, dist/2);
    Hilbert1(level);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
