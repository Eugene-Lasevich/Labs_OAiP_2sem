/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 380, 83, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 360, 83, 29));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 410, 83, 29));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(330, 430, 83, 29));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 130, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 130, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 180, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(550, 160, 63, 20));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(60, 50, 331, 291));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
