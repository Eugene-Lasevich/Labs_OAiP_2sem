#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->push->setDisabled(1);
    ui->pop->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_clicked()
{
    stack[i] = ui->lineEdit->text().toInt();
    i++;
    ui->display->clear();
    ui->display->setText(show_string());
    if(i>=1)ui->pop->setDisabled(0);
    if (i>=15)
    {
        QMessageBox::information(this,"","Top of stack reached");
        ui->push->setDisabled(1);
    }
}


void MainWindow::on_pop_clicked()
{
    i--;
    ui->push->setDisabled(0);
    ui->display->clear();
    ui->display->setText(show_string());
    if(i<1)
    {
        QMessageBox::information(this,"","Stack is empty");
        ui->pop->setDisabled(1);
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(correct_input(arg1)) ui->push->setDisabled(0);
    else ui->push->setDisabled(1);
}

bool MainWindow::correct_input(QString str)
{
    if(str.size()>7) return false;
    for(int i = 0; i< str.size(); i++)
    {
        if(str[i]<'0' || str[i]>'9') return false;
    }

    return true;
}

QString MainWindow::show_string()
{
    QString tmp, tmp1;
    for(int  j = 0; j<i; j++)
    {
        tmp1.setNum(stack[j]);
        tmp += '\t'+tmp1 + '\n';
    }
    return tmp;
}

