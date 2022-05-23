#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"smart_pointers.h"
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
    void on_push_clicked();

    void on_front_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    bool correct_input(QString str);

    QString show_string();



private:
    Ui::MainWindow *ui;
    unique_ptr <int[]> queue = make_unique<int[]>(1000);
    int i = 0;
    int k =0;
};
#endif // MAINWINDOW_H
