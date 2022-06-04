#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColor>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button_insert->setDisabled(1);
    ui->insert->setPlaceholderText("key: ");
    ui->lineErase->setPlaceholderText("key: ");
    ui->lineFind->setPlaceholderText("key: ");



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_insert_textChanged(const QString &arg1)
{
    if(correct_value(arg1)) ui->button_insert->setDisabled(0);
    else ui->button_insert->setDisabled(1);

    if(ui->insert->text().isEmpty()) ui->button_insert->setDisabled(1);
}

bool MainWindow::correct_value(QString str)
{
    if(str.size()>3) return false;
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i]<'0' ||  str[i] > '9') return false;
    }
    return true;
}

bool MainWindow::corrct_Value(QString str)
{
    if(str.size()>3) return false;
    return true;
}


void MainWindow::on_button_insert_clicked()
{

    int key;
    key = ui->insert->text().toInt();

    if(set_.insert(key))
    {

        countNodes++;
        set<int>::iterator it = set_.begin();

        QString inOr = "";

        for(;it != set_.end(); ++it)
        {

            QString tmp;
            tmp.setNum(it.node->key);
            inOr+=+'\t'+tmp+ '\n';
        }

        ui->inOrder->setText(inOr);
    }

    else QMessageBox::information(this, "", "Failed to insert value by key");


}



void MainWindow::on_find_clicked()
{
    bool findValue = set_.search(ui->lineFind->text().toInt()).second;
    if(findValue)
    {
        QString tmp;
        tmp.setNum(set_.search(ui->lineFind->text().toInt()).first.node->key);
        QMessageBox::information(this,"", tmp);
    }
    else QMessageBox::information(this, " ", "No value found with the given key");

}


void MainWindow::on_erase_clicked()
{

    if(countNodes> 0)
    {
        ui->button_insert->setDisabled(0);
        if(set_.erase(ui->lineErase->text().toInt()))
        {

            set<int>::iterator it = set_.begin();

            QString inOr = "";

            for(;it != set_.end(); ++it)
            {
                QString tmp;
                tmp.setNum(it.node->key);
                inOr+=+'\t'+tmp+ '\n';
            }

            ui->inOrder->setText(inOr);


            countNodes--;
        }
        else QMessageBox::information(this,"","Failed to delete value by given key");
    }


}





