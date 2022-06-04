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
    ui->insertValue->setPlaceholderText("value: ");
    ui->lineErase->setPlaceholderText("key: ");
    ui->lineFind->setPlaceholderText("key: ");



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_insert_textChanged(const QString &arg1)
{
    if(correct_value(arg1) && !ui->insertValue->text().isEmpty()) ui->button_insert->setDisabled(0);
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
    int str;
    str = ui->insertValue->text().toInt();
    key = ui->insert->text().toInt();

    std::pair<int, int> pr;
    pr.first= key;
    pr.second = str;
    if(map_.insert(pr))
    {

        countNodes++;
        map<int, int>::iterator it = map_.begin();

        QString inOr = "";

        for(;it != map_.end(); ++it)
        {

            QString tmp;
            QString tmp1;
            tmp.setNum(it.node->key);
            tmp1.setNum(it.node->value);
            inOr+=+'\t'+tmp+'-'+tmp1+ '\n';
        }
        static int i = 1;
        qDebug()<<i;
        i++;
        ui->inOrder->setText(inOr);
    }

    else QMessageBox::information(this, "", "Failed to insert value by key");


}



void MainWindow::on_find_clicked()
{
    bool findValue = map_.search(ui->lineFind->text().toInt()).second;
    if(findValue)
    {
        QString tmp;
        tmp.setNum(map_.search(ui->lineFind->text().toInt()).first.node->value);
        QMessageBox::information(this,"", tmp);
    }
    else QMessageBox::information(this, " ", "No value found with the given key");

}


void MainWindow::on_erase_clicked()
{

    if(countNodes> 0)
    {
        ui->button_insert->setDisabled(0);
        if(map_.erase(ui->lineErase->text().toInt()))
        {

            map<int, int>::iterator it = map_.begin();

            QString inOr = "";

            for(;it != map_.end(); ++it)
            {
                QString tmp;
                QString tmp1;
                tmp.setNum(it.node->key);
                tmp1.setNum(it.node->value);
                inOr+=+'\t'+tmp+'-'+tmp1+ '\n';
            }

            ui->inOrder->setText(inOr);


            countNodes--;
        }
        else QMessageBox::information(this,"","Failed to delete value by given key");
    }


}




void MainWindow::on_insertValue_textChanged(const QString &arg1)
{
    if(correct_value(arg1) && !ui->insert->text().isEmpty()) ui->button_insert->setDisabled(0);
    else ui->button_insert->setDisabled(1);

    if(ui->insertValue->text().isEmpty()) ui->button_insert->setDisabled(1);
}


