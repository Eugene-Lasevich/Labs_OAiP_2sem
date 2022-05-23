#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include <QDebug>
#include<QMessageBox>


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
    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_insert_clicked();

    void on_erase_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    bool correct_input(QString str);

    void on_lineEdit_textChanged(const QString &arg1);

    QString show_string();
    void filling_combo();

    int random_value();

    void on_deleteMinToMax_clicked();

private:
    Ui::MainWindow *ui;
    list list;
    int number_of_clicks = 0;
};
#endif // MAINWINDOW_H
