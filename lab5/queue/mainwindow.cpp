#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->push->setDisabled(0);
    ui->front->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_clicked()
{
   // queue[i] = ui->lineEdit->text().toInt();
    queue[i] = rand() % 500;
    i++;
    ui->display->clear();
    ui->display->setText(show_string());
    if(i>=1)ui->front->setDisabled(0);
    if (i>=1000)
    {
        QMessageBox::information(this,"","Top of queue reached");
        ui->push->setDisabled(1);
    }
}


void MainWindow::on_front_clicked()
{
    k++;

    qDebug()<<"k = "<<k<< " i = "<<i;

    ui->push->setDisabled(0);
    ui->display->clear();
    ui->display->setText(show_string());
    if(k>=1000 || k == i)
    {
        k = 0;
        i = 0;
        QMessageBox::information(this,"","Queue is empty");
        ui->front->setDisabled(1);
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
    for(int  j = k; j<i; j++)
    {
        tmp1.setNum(queue[j]);
        tmp += '\t'+tmp1 + '\n';
    }
    return tmp;
}

