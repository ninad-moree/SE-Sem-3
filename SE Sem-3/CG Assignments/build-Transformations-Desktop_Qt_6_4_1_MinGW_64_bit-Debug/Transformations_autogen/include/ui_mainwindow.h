/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPlainTextEdit *plainTextEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-90, 0, 951, 641));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 10, 80, 18));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(40, 30, 104, 21));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(40, 50, 104, 21));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(40, 100, 104, 21));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(40, 120, 104, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 80, 80, 18));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 210, 80, 18));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 150, 80, 18));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(40, 180, 104, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 30, 21, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 50, 21, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 100, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 120, 37, 12));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 180, 21, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Translation", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "tx", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ty", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "sx", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "sy", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "rad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
