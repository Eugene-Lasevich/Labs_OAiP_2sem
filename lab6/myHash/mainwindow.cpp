#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QMessageBox>

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new HashTable();
    ui->tableWidget->setColumnCount(2);
    ui->addKey->setPlaceholderText("key:");
    ui->addValue->setPlaceholderText("value:");
    ui->searchKey->setPlaceholderText("key:");
    ui->removeKey->setPlaceholderText("key:");

    ui->add->setDisabled(1);
    ui->search->setDisabled(1);
    ui->remove->setDisabled(1);


    for(int i = 0; i< table->get_size()/2; ++i)
    {
        table->put(pow(-1,rand())*(rand()%11),QString::number(rand()%11));
    }

    ShowAll();
}

void MainWindow::ShowAll()
{
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setRowCount(table->get_size());

    for(int i = 0; i< table->get_size(); ++i)
    {
        if(table->operator[](i))
        {
            QStack<QPair<int,QString>> stack = *table->operator[](i);

            while(stack.size())
            {
                if(!ui->tableWidget->item(i,0))
                {
                    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(stack.top().first)));
                    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(stack.top().second));
                }

                else
                {
                    ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i,0)->text() + QString(" ") + QString::number(stack.top().first));
                    ui->tableWidget->item(i, 1)->setText(ui->tableWidget->item(i,1)->text() + QString(" ") + stack.top().second);

                }
                stack.pop();
            }
        }
    }
}

bool MainWindow::correct_input_key(QString str)
{
    if(str.size()>3) return false;

    if(str[0] == '-' || str[0] >='0' && str[0] <='9')
    {
        for(int i = 1; i<str.size(); i++)
            if(str[i]<'0' ||  str[i] > '9')
                return false;

        return true;
    }

    return false;
}

bool MainWindow::correct_input_value(QString str)
{
    if(str.size()>3) return false;
    return true;
}
MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_addKey_textChanged(const QString &arg1)
{

    if(correct_input_key(arg1) && !ui->addValue->text().isEmpty()) ui->add->setDisabled(0);
    else ui->add->setDisabled(1);

    if(ui->addKey->text().isEmpty()) ui->add->setDisabled(1);
}


void MainWindow::on_addValue_textChanged(const QString &arg1)
{
    if(correct_input_value(arg1) && !ui->addKey->text().isEmpty()) ui->add->setDisabled(0);
    else ui->add->setDisabled(1);

    if(ui->addValue->text().isEmpty()) ui->add->setDisabled(1);
}

void MainWindow::on_add_clicked()
{
    if(ui->addKey->text().toInt())
    {
        if(table->put(ui->addKey->text().toInt(), ui->addValue->text()))
        {
            int i = table->CalculateHash(ui->addKey->text().toInt());

            if(!ui->tableWidget->item(i,0))
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(ui->addKey->text()));
                ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ui->addValue->text()));
            }
            else
            {
                ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i,0)->text() + QString(" ") + ui->addKey->text());
                ui->tableWidget->item(i, 1)->setText(ui->tableWidget->item(i,1)->text() + QString(" ") + ui->addValue->text());
            }
        }
        else
        {
            QMessageBox::information(this,"","There is such a key");
        }
    }
}


void MainWindow::on_search_clicked()
{
    QString str;

    if(table->get(ui->searchKey->text().toInt(), str))QMessageBox::information(this,"", str);
    else QMessageBox::information(this,"","No such key found");

}


void MainWindow::on_remove_clicked()
{
    if(table->remove(ui->removeKey->text().toInt())) ShowAll();
    else QMessageBox::information(this,"","No such key found");

}


void MainWindow::on_myFunction_clicked()
{
    for(int i = -999; i<-1;i++)  table->remove(i);
     ShowAll();
}




void MainWindow::on_searchKey_textChanged(const QString &arg1)
{
    if(correct_input_key(arg1)) ui->search->setDisabled(0);
    else ui->search->setDisabled(1);

}


void MainWindow::on_removeKey_textChanged(const QString &arg1)
{
    if(correct_input_key(arg1)) ui->remove->setDisabled(0);
    else ui->remove->setDisabled(1);
}

