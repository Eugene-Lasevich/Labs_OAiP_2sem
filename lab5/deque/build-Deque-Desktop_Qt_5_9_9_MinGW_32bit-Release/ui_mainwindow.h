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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
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
    QTextBrowser *display;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *push_back;
    QPushButton *push_front;
    QPushButton *pop_back;
    QPushButton *pop_front;
    QPushButton *clear;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *empty;
    QLabel *label;
    QLabel *size;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QPushButton *getAcces;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(454, 608);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        display = new QTextBrowser(centralwidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(10, 10, 431, 451));
        QFont font;
        font.setPointSize(14);
        display->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 460, 430, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        push_back = new QPushButton(layoutWidget);
        push_back->setObjectName(QStringLiteral("push_back"));

        horizontalLayout->addWidget(push_back);

        push_front = new QPushButton(layoutWidget);
        push_front->setObjectName(QStringLiteral("push_front"));

        horizontalLayout->addWidget(push_front);

        pop_back = new QPushButton(layoutWidget);
        pop_back->setObjectName(QStringLiteral("pop_back"));

        horizontalLayout->addWidget(pop_back);

        pop_front = new QPushButton(layoutWidget);
        pop_front->setObjectName(QStringLiteral("pop_front"));

        horizontalLayout->addWidget(pop_front);

        clear = new QPushButton(layoutWidget);
        clear->setObjectName(QStringLiteral("clear"));

        horizontalLayout->addWidget(clear);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 500, 431, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        empty = new QLabel(layoutWidget1);
        empty->setObjectName(QStringLiteral("empty"));

        horizontalLayout_2->addWidget(empty);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        size = new QLabel(layoutWidget1);
        size->setObjectName(QStringLiteral("size"));

        horizontalLayout_2->addWidget(size);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 520, 431, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        getAcces = new QPushButton(layoutWidget2);
        getAcces->setObjectName(QStringLiteral("getAcces"));

        horizontalLayout_3->addWidget(getAcces);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 454, 25));
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
        push_back->setText(QApplication::translate("MainWindow", "push_back", Q_NULLPTR));
        push_front->setText(QApplication::translate("MainWindow", "push_front", Q_NULLPTR));
        pop_back->setText(QApplication::translate("MainWindow", "pop_back", Q_NULLPTR));
        pop_front->setText(QApplication::translate("MainWindow", "pop_front", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "empty:", Q_NULLPTR));
        empty->setText(QString());
        label->setText(QApplication::translate("MainWindow", "size:", Q_NULLPTR));
        size->setText(QString());
        getAcces->setText(QApplication::translate("MainWindow", "get acces", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
