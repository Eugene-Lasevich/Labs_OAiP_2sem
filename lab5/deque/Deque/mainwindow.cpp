#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->getAcces->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_back_clicked()
{
    deque.push_back(random_number());
    show_string();
    ui->getAcces->setDisabled(0);
}


void MainWindow::on_push_front_clicked()
{
    deque.push_front(random_number());
    show_string();
    ui->getAcces->setDisabled(0);
}


void MainWindow::on_pop_back_clicked()
{
    deque.pop_back();
    show_string();
    if(deque.size()==0)ui->getAcces->setDisabled(1);
}


void MainWindow::on_pop_front_clicked()
{
    deque.pop_front();
    show_string();
    if(deque.size()==0)ui->getAcces->setDisabled(1);

}


void MainWindow::on_clear_clicked()
{
    deque.clear();
    show_string();
    ui->getAcces->setDisabled(1);
}

int MainWindow::random_number()
{
    return rand()%500;
}

void MainWindow::show_string()
{
    auto iter = deque.begin();
    int intIter = 1;
    QString returnStr;

    while (iter != deque.end())
    {
        QString tmp;
        tmp.setNum(*iter);
        if(intIter % 8) returnStr += tmp + " ";
        else returnStr +=tmp + '\n';
       ++intIter;
       ++iter;
    }

    QString size;
    QString empty = "false";
    size.setNum(intIter-1);

    if(deque.empty()) empty = "true";
    ui->size->setText(size);
    ui->empty->setText(empty);
    ui->display->setText(returnStr);


    ui->comboBox->clear();
    for(int i = 0; i < intIter-1; i++)
    {
        QString str;
        str.setNum(i+1);
        ui->comboBox->addItem(str);
    }
}




void MainWindow::on_getAcces_clicked()
{
    QString tmp;
    tmp.setNum(deque[ui->comboBox->currentText().toInt()-1]);
    QMessageBox::information(this,"",tmp);
}

