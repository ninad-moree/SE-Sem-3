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
    void goToXY(int x, int y);
    void Hilbert1(int level);
    void Hilbert2(int level);
    void Hilbert3(int level);
    void Hilbert4(int level);
    void DDA(int x1, int y1, int x2, int y2);
    void drawLine(int dx, int dy);

    private slots:
    void on_pushButton_clicked();

    private:
    Ui::MainWindow *ui;
    int x{}, y{}, dist_main{}, dist{};
};
#endif // MAINWINDOW_H
