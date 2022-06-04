#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plainTextEdit->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_flipButton_clicked()
{
    if(ui->flipEdit->text().isEmpty())
    {
        bitsus->flip();
    }
    else
    {
       bitsus->flip(ui->flipEdit->text().toInt());
    }


    ui->ullLabel->setText(ui->setNumberEdit->text());
    ui->ulLabel->setText(ui->setNumberEdit->text());
    ui->plainTextEdit->setPlainText((QString)bitsus->to_string().c_str());
    ui->anyLabel->setText(QString::number(bitsus->any()));
    ui->countLabel->setText(QString::number(bitsus->count()));
    ui->allLabel->setText(QString::number(bitsus->all()));
    ui->noneLabel->setText(QString::number(bitsus->none()));
    ui->sizeLabel->setText(QString::number(bitsus->getSize()));
}


void MainWindow::on_setButton_clicked()
{
    if(ui->setEdit->text().isEmpty())
    {
        bitsus->set();
    }
    else
    {
       bitsus->set(ui->setEdit->text().toInt());
    }


    ui->ullLabel->setText(ui->setNumberEdit->text());
    ui->ulLabel->setText(ui->setNumberEdit->text());
    ui->plainTextEdit->setPlainText((QString)bitsus->to_string().c_str());
    ui->anyLabel->setText(QString::number(bitsus->any()));
    ui->countLabel->setText(QString::number(bitsus->count()));
    ui->allLabel->setText(QString::number(bitsus->all()));
    ui->noneLabel->setText(QString::number(bitsus->none()));
    ui->sizeLabel->setText(QString::number(bitsus->getSize()));
}


void MainWindow::on_resetButton_clicked()
{
    if(ui->resetEdit->text().isEmpty())
    {
        bitsus->reset();
    }
    else
    {
       bitsus->reset(ui->resetEdit->text().toInt());
    }


    ui->ullLabel->setText(ui->setNumberEdit->text());
    ui->ulLabel->setText(ui->setNumberEdit->text());
    ui->plainTextEdit->setPlainText((QString)bitsus->to_string().c_str());
    ui->anyLabel->setText(QString::number(bitsus->any()));
    ui->countLabel->setText(QString::number(bitsus->count()));
    ui->allLabel->setText(QString::number(bitsus->all()));
    ui->noneLabel->setText(QString::number(bitsus->none()));
    ui->sizeLabel->setText(QString::number(bitsus->getSize()));
}




void MainWindow::on_setNumberButton_clicked()
{
    bitsus = new bitset<128>(ui->setNumberEdit->text().toULongLong());
    ui->ullLabel->setText(ui->setNumberEdit->text());
    ui->ulLabel->setText(ui->setNumberEdit->text());
    ui->plainTextEdit->setPlainText((QString)bitsus->to_string().c_str());
    ui->anyLabel->setText(QString::number(bitsus->any()));
    ui->countLabel->setText(QString::number(bitsus->count()));
    ui->allLabel->setText(QString::number(bitsus->all()));
    ui->noneLabel->setText(QString::number(bitsus->none()));
    ui->sizeLabel->setText(QString::number(bitsus->getSize()));
}

