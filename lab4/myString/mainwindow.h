#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>
#include<iostream>
//#include"mystring.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_memcpy_clicked();

    void on_memmove_clicked();

    void on_strcpy_clicked();

    void on_strncpy_clicked();

    void on_strcat_clicked();

    void on_strncat_clicked();

    void on_memcmp_clicked();

    void on_strcmp_clicked();

    void on_strcoll_clicked();

    void on_strncmp_clicked();

    void on_strtok_clicked();

    void on_memset_clicked();

    void on_strlen_clicked();

private:
    Ui::MainWindow *ui;
    QString str;
};
#endif // MAINWINDOW_H
