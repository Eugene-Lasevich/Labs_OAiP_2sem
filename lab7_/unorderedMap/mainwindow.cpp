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
    ui->tableWidget->setColumnCount(2);
    ui->addKey->setPlaceholderText("key:");
    ui->addValue->setPlaceholderText("value:");
    ui->searchKey->setPlaceholderText("key:");
    ui->removeKey->setPlaceholderText("key:");

    ui->add->setDisabled(1);
    ui->search->setDisabled(1);
}


bool MainWindow::correct_input_key(QString str)
{
    if(str.size()>3) return false;

    for(int i = 0; i<str.size(); i++)
        if(str[i]<'0' ||  str[i] > '9')
            return false;

    return true;
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

    map.insert(std::make_pair(ui->addKey->text().toInt(), ui->addValue->text().toInt()));
    ui->tableWidget->setRowCount(map.size());
    this->view();
}


void MainWindow::on_search_clicked()
{
    unordered_map<int, int>::iterator it = map.find(ui->searchKey->text().toInt());
    map[ui->searchKey->text().toInt()];
    ui->tableWidget->setRowCount(map.size());
    this->view();

    if(it == map.end())
    {
        QMessageBox::information(this,"","Key with given key not found");
        return;
    }

    QMessageBox::information(this,"",QString::number(it->second));

}


void MainWindow::on_remove_clicked()
{
    map.erase(ui->removeKey->text().toInt());

    this->view();
}

void MainWindow::view()
{
    unordered_map<int, int>::iterator it = map.begin();

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
    ui->tableWidget->setRowCount(map.size());

    for(int i = 0; it != map.end(); ++it, i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(it->first)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(it->second)));
    }
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

