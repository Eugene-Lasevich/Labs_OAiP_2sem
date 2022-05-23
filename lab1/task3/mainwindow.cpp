 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fstream>
#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMask("00.00.0000");
    ui->add_new_date->setDisabled(1);
    ui->change_data->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_getBirthday_userDateChanged(const QDate &date)
{
    Date birthday = Date(date.year(), date.month(), date.day());
    QDate today = today.currentDate();

    Date td = Date(today.year(), today.month(), today.day());
    ui->number->display(td.DaysTillYourBithday(birthday));
}

bool MainWindow::check_correct_sting(QString str)
{
    if(str.length()>12) return false;
    if(str[0].isDigit() && str[1].isDigit()&& str[2].isPunct() && str[3].isDigit() && str[4].isDigit()&& str[5].isPunct() \
        && str[6].isDigit() && str[7].isDigit() && str[8].isDigit() && str[9].isDigit())
    {
        if(str[0] =='0' && str[1] =='0' &&str[3]=='0' &&str[4]=='0' && str[6] =='0' &&str[7]=='0' &&str[8]=='0' && str[9] == '0') return false;
        if(str[2]=='.'&& str[5]=='.')
        {

        if(str[3]=='1' && str[4]<='2')

            {
            if(str[0]<'3'&& str[1] <='9') return true;
            if(str[0]=='3'&& str[1] <='1') return true;

            }
        //else return false;

        if(str[3]=='0' && str[4]<='9')

            {
            if(str[0]=='2' && str[1] =='8' && str[4] =='2') return true;
            if(str[0]<'3'&& str[1] <='9') return true;
            if(str[0]=='3'&& str[1] <='1') return true;

            }
        else return false;

        }
        else return false;
    }
    else return false;
}



void MainWindow::on_openFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"), "//", tr("txt files (*.txt)"));
    path = new QString(fileName);
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(this,"File is not open","File is not open");
            return;
    }
    if(file.readAll().isEmpty())
    {
        QMessageBox::information(this,"Empty","File is empty");
        //file.seek(0);
    }
    file.seek(0);

    QTextStream in(&file);
    std::vector<Date> dates;

    do
    {

        QString line = in.readLine();


        if(check_correct_sting(line) || line=="")
        {
            if(line == "") continue;
        QDate date = date.fromString(line, "dd.MM.yyyy");
        dates.push_back(Date(date.year(), date.month(), date.day()));
        }

        else
        {
            QMessageBox::warning(this,"incorect","This file contains invalid data: " + line);
            file.close();
            return;
        }
    }
    while (!in.atEnd());


    ui->add_new_date->setDisabled(0);
    ui->change_data->setDisabled(0);
    qDebug()<<"path = "<<*path;

    file.close();
    ui->datesd->setRowCount(dates.size());

    QDate today = today.currentDate();
    Date* x = new Date(today.year(), today.month(), today.day());

    for (int i = 0; i < dates.size(); i++)
    {
        ui->datesd->setItem(i, 0, new QTableWidgetItem(dates[i].ToString()));
        ui->datesd->setItem(i, 1, new QTableWidgetItem(dates[i].NextDay().ToString()));
        ui->datesd->setItem(i, 2, new QTableWidgetItem(dates[i].PreviousDay().ToString()));
        ui->datesd->setItem(i, 3, new QTableWidgetItem((dates[i].IsLeap() ? QString("Yes") : QString("No"))));
        ui->datesd->setItem(i, 4, new QTableWidgetItem(QString().setNum(dates[i].WeekNumber())));
        ui->datesd->setItem(i, 5, new QTableWidgetItem(QString().setNum(dates[i].Duration(*x))));
    }

}



void MainWindow::on_datesd_cellClicked(int row, int column)
{
    if(column>0)   QMessageBox::information(this,"qw","Are you ABOBA? ");


  if(column == 0)
  {

    QFile file(*path);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;

    QTextStream in(&file);
    QString baseline = ui->datesd->currentItem()->text();

    do
    {

     QString line = in.readLine();
     qDebug()<<line.length();



     if(baseline == line && check_correct_sting(baseStr))

      {
           qDebug()<<"Шанс на измение";
           int j = in.pos();
           qDebug()<<"j = "<<j;
           if(j==12) j-=12;
           if(j>12) j-=10;
           file.seek(j);
           file.write(baseStr.toLatin1());

      }

    }
    while (!in.atEnd());

  }
}



void MainWindow::on_add_new_date_clicked()
{
    QString str;
    str=  ui->lineEdit->text();
    if(!check_correct_sting(str))
    {
        QMessageBox::information(this,"Mistake","An invalid date has been entered");
        return;
    }

    QFile file(*path);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(this,"Mistake","File is not open");
        return;
    }
    QTextStream writeStream(&file);
    writeStream<<'\n'<<str;
    ui->lineEdit->clear();

}





void MainWindow::on_change_data_pressed()
{
    QString str;
    str=  ui->lineEdit->text();
    qDebug()<<str;
    if(!check_correct_sting(str))
    {
        QMessageBox::information(this,"Mistake","An invalid date has been entered");
        return;
    }
    else
    {
        baseStr = str;
        qDebug()<<"BASEstr "<<baseStr;
    }
}

