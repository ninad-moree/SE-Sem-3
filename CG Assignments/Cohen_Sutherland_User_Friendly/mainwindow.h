#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Draw_Polygon();
    void DDA(int x1,int y1,int x2,int y2, int c1,int c2,int c3);
    float Sign(float x);
    void Code(int c[],float x , float y);
    void line_test(int c[], int d[]);
    void Window_Clip(int c[],int d[],float &x,float &y,float m);


private:
    Ui::MainWindow *ui;
    bool flag;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
