#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QTimer>
#include<QMessageBox>
#include"mystack.h"
#include"stack_double.h"

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

    bool correct_expression(QString str);


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_add_expression_clicked();
    bool check_correct_values(QString str);
    QString conver_infix_to_prefix(QString str);
    int priorety(QChar ch);
    double calculate_prefix(QString str,double a, double b, double c, double d, double e);
    bool ckeck_brackets(QString expression);
    void disabled_fields(QString str);


    void on_calculate_clicked();

    void on_show_result_clicked();

private:
    Ui::MainWindow *ui;
    int number_expression= 0;
    QString mas[255];
    double values[5];
    myStack signs;
    myStack brackets;
    Stack_double value;
};
#endif // MAINWINDOW_H
