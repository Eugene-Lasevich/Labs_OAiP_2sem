#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QDebug>
#include"stack.h"
#include"stack_int.h"
#include<QFileDialog>
#include<QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool check_brackets(QString expression, int& i);
    QString covert_to_convert(QString str);


private slots:
    void on_add_string_clicked();

    void on_show_result_clicked();

    void on_read_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    QString enteredString;
};
#endif // MAINWINDOW_H
