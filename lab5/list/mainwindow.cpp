#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    list.push_back(1);
    list.push_back(1);
    ui->push_back->setDisabled(0);
    ui->push_front->setDisabled(0);
    ui->pop_back->setDisabled(1);
    ui->pop_front->setDisabled(1);
    ui->insert->setDisabled(1);
    ui->erase->setDisabled(1);
//    ui->comboInsert->setDisabled(1);
//    ui->comboErase->setDisabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_back_clicked()
{

    list.push_back(random_value());
    ui->pop_back->setDisabled(0);
    ui->pop_front->setDisabled(0);
    ui->erase->setDisabled(0);
    ui->insert->setDisabled(0);
    ui->display->clear();
    ui->display->setText(show_string());
    number_of_clicks++;
    filling_combo();
    if(number_of_clicks>99)
    {
        QMessageBox::information(this,"","TO MUCH");
        return ;
    }



}


void MainWindow::on_push_front_clicked()
{
    list.push_front(random_value());
    ui->pop_back->setDisabled(0);
    ui->pop_front->setDisabled(0);
    ui->erase->setDisabled(0);
    ui->insert->setDisabled(0);
    number_of_clicks++;
    ui->display->clear();
    ui->display->setText(show_string());
    filling_combo();
    if(number_of_clicks>99)
    {
        QMessageBox::information(this,"","TO MUCH");
        return ;
    }
}


void MainWindow::on_insert_clicked()
{
    int pos = ui->comboInsert->currentText().toInt()+1;
    int val = random_value();
    list.insert(pos,val);
    ui->display->clear();
    ui->display->setText(show_string());
    number_of_clicks++;
    filling_combo();
    if(number_of_clicks>99)
    {
        QMessageBox::information(this,"","TO MUCH");
        return ;
    }
    if(list.isEmpy())
    {
        ui->pop_back->setDisabled(1);
        ui->pop_front->setDisabled(1);
        ui->erase->setDisabled(1);
        QMessageBox::information(this,"","List is empty");
        return;
    }
    else
    {
        ui->pop_back->setDisabled(0);
        ui->pop_front->setDisabled(0);
        ui->erase->setDisabled(0);
        return;
    }
}


void MainWindow::on_erase_clicked()
{
    int pos = ui->comboErase->currentText().toInt() +1;
    list.erase(pos);
    ui->display->clear();
    ui->display->setText(show_string());
    number_of_clicks--;
    filling_combo();
    if(list.isEmpy())
    {
        ui->pop_back->setDisabled(1);
        ui->pop_front->setDisabled(1);
        ui->erase->setDisabled(1);
        QMessageBox::information(this,"","List is empty");
        return;
    }
}


void MainWindow::on_pop_back_clicked()
{
    list.pop_back();
    ui->display->clear();
    ui->display->setText(show_string());
    filling_combo();
    number_of_clicks--;
    if(list.isEmpy())
    {
        ui->pop_back->setDisabled(1);
        ui->pop_front->setDisabled(1);
        ui->erase->setDisabled(1);
        QMessageBox::information(this,"","List is empty");
        return;
    }

}


void MainWindow::on_pop_front_clicked()
{
    list.pop_front();
    ui->display->clear();
    ui->display->setText(show_string());
    filling_combo();
    number_of_clicks--;
    if(list.isEmpy())
    {
        ui->pop_back->setDisabled(1);
        ui->pop_front->setDisabled(1);
        ui->erase->setDisabled(1);
        QMessageBox::information(this,"","List is empty");
        return;
    }
}

bool MainWindow::correct_input(QString str)
{
    if(str.size()>7) return false;
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i]<'0' || str[i] > '9') return false;
    }

    return true;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(correct_input(arg1))
    {
        ui->push_back->setDisabled(0);
        ui->push_front->setDisabled(0);

    }
    else
    {
        ui->push_back->setDisabled(1);
        ui->push_front->setDisabled(1);
        ui->insert->setDisabled(1);
    }
}

QString MainWindow::show_string()
{
    QString tmp,tmp1;
    for(int i = 2; i<list.getSize();i ++)
    {
        tmp1.setNum(list.getData(i));
        tmp+= '\t' + tmp1 + '\n';
    }
    return tmp;
}

void MainWindow::filling_combo()
{
    ui->comboInsert->clear();
    ui->comboErase->clear();
    for(int i = 2; i<list.getSize(); i++)
    {
        QString tmp;
        tmp.setNum(i-1);
        ui->comboInsert->addItem(tmp);
        ui->comboErase->addItem(tmp);
    }
}

int MainWindow::random_value()
{
    /* static int a  = 0;
     a++;
    // return (rand() % 10000);
     return a*/;

    return (rand() % 1000);
}


void MainWindow::on_deleteMinToMax_clicked()
{
    int minIndex = 2;
    int maxIndex = 2;
    int min=list.getData(2);
    int max = list.getData(2);

    for(int i = 2; i< list.getSize(); i++)
    {
        if(min > list.getData(i))
        {
            minIndex = i;
            min = list.getData(i);
        }

        if(max < list.getData(i))
        {
            maxIndex = i;
            max = list.getData(i);
        }

    }
    qDebug()<<min<<" "<<max;

    if(minIndex< maxIndex)
        for(int i = minIndex; i<maxIndex-1; i++)
            list.erase(minIndex+1);

    else if(maxIndex< minIndex)
        for(int i = maxIndex; i<minIndex-1; i++)
            list.erase(maxIndex+1);

    filling_combo();
    ui->display->setText(show_string());
}

