    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QStringData>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->order_date->setInputMask("00.00.0000");
    ui->order_number->setInputMask("0000");
    ui->requisites->setInputMask("000000");
    ui->product_code->setInputMask("000");
    ui->quantity_of_goods->setInputMask("00");
    ui->price_of_one->setInputMask("000");
    ui->product_name->setInputMask("AAAAAAAAAAAA");
    ui->label_4->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_6->hide();
    ui->price_of_one->hide();
    ui->quantity_of_goods->hide();
    ui->product_name->hide();
    ui->product_code->hide();
    ui->add_product->hide();
    ui->finish_additing->hide();
    ui->tableWidget->hide();
    ui->tableWidget->setEditTriggers(0);
    ui->show_result->setDisabled(1);
    ui->save_file->setDisabled(1);
    ui->read_items->setDisabled(1);



}

MainWindow::~MainWindow()
{
    delete ui;
}



QString MainWindow::convert_row_to_string(int row)
{
    QString tmp;
     qDebug()<<"row"<<row;
    for(int i = 0; i<7; i++)
    {
        qDebug()<<"i = "<<i;
        if(ui->tableWidget->item(row,i))
        {
            qDebug()<<"value = "<<ui->tableWidget->item(row,i)->text().isEmpty();
            tmp += ui->tableWidget->item(row,i)->text()+'\t';
        }
        else
        {
        tmp+='\t';
        }

    }
    tmp+='\n';
    return tmp;

}


void MainWindow::on_Create_pressed()
{


   number_of_oders++;
   tmpOrder.setOrder_number(ui->order_number->text());
   tmpOrder.setOrder_date(ui->order_date->text());
   tmpOrder.setRequisites(ui->requisites->text());
   orders.push_back(tmpOrder);


}

void MainWindow::on_Create_released()
{


    ui->Create->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->order_date->hide();
    ui->order_number->hide();
    ui->requisites->hide();
    ui->label_4->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_6->show();
    ui->price_of_one->show();
    ui->quantity_of_goods->show();
    ui->product_name->show();
    ui->product_code->show();
    ui->add_product->show();
    ui->finish_additing->show();
    ui->tableWidget->clear();
    ui->tableWidget->hide();
    ui->finish_additing->setDisabled(1);

}

int MainWindow::sum_vector(QVector<int> num)
{
    int sum =0 ;
    for(int i=0; i<num.size(); i++)
    {
        sum+=num[i];
    }
    return sum;
}


void MainWindow::on_add_product_pressed()
{

    number_of_clicks_++;
    Goods tmp(ui->product_code->text(),ui->quantity_of_goods->text(),ui->price_of_one->text(),ui->product_name->text());
    goods.push_back(tmp);
    ui->finish_additing->setDisabled(0);


}



void MainWindow::on_finish_additing_pressed()
{

    ui->Create->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->order_date->show();
    ui->order_number->show();
    ui->requisites->show();
    ui->label_4->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_6->hide();
    ui->price_of_one->hide();
    ui->quantity_of_goods->hide();
    ui->product_name->hide();
    ui->product_code->hide();
    ui->add_product->hide();
    ui->finish_additing->hide();
    ui->show_result->setDisabled(0);
    number.push_back(number_of_clicks_);
    number_of_clicks_ = 0;


}



void MainWindow::on_show_result_released()
{


    qDebug()<<goods.isEmpty();

    if(goods.isEmpty())
    {
        QMessageBox::information(this, "Mistake","NO DATA");
        return;
    }

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(sum_vector(number));
        ui->tableWidget->setColumnCount(7);
        ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("order number"));
        ui->tableWidget->setHorizontalHeaderItem(1 ,new QTableWidgetItem("requsits"));
        ui->tableWidget->setHorizontalHeaderItem(2 ,new QTableWidgetItem("date"));
        ui->tableWidget->setHorizontalHeaderItem(3 ,new QTableWidgetItem("product name"));
        ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("amount"));
        ui->tableWidget->setHorizontalHeaderItem(5 ,new QTableWidgetItem("unit price"));
        ui->tableWidget->setHorizontalHeaderItem(6,new QTableWidgetItem("Product code"));

        int j_tmp = 0;


//        static int number_tmp = 0;
//        static int number_tmp_ = 0;


        for(int j = 0; j<number.size();j++)
        {
           // int sum_tmp = 0;
            qDebug()<<number.size();
            if(j>=1)  j_tmp+=number[j-1];
            qDebug()<<"j_tmp"<<j_tmp;

            ui->tableWidget->setItem(j_tmp,0,new QTableWidgetItem(orders[j].getOrder_number()));
            ui->tableWidget->setItem(j_tmp,1,new QTableWidgetItem(orders[j].getRequisites()));
            ui->tableWidget->setItem(j_tmp,2,new QTableWidgetItem(orders[j].getOrder_date()));
            QString tmp = ui->tableWidget->item(j_tmp,2)->text();
            if(!check_correct_sting(tmp)) ui->tableWidget->setItem(j_tmp,2, new QTableWidgetItem("Incorect date")) ;


            }



        for(int k = 0; k<sum_vector(number); k++)
        {
            //qDebug()<<"GOODS";
            qDebug()<<goods[k].getProduct_name();
            ui->tableWidget->setItem(k,3,new QTableWidgetItem(goods[k].getProduct_name()));
            ui->tableWidget->setItem(k,4,new QTableWidgetItem(goods[k].getQuantity_of_goods()));
            ui->tableWidget->setItem(k,5,new QTableWidgetItem(goods[k].getPrice_of_the_one_product()));
            ui->tableWidget->setItem(k,6, new QTableWidgetItem(goods[k].getProduct_code()));

        }


     ui->tableWidget->show();
     ui->show_result->setDisabled(1);

}
int MainWindow::maxValue(QVector<int> number)
{
    int tmp = 0;
    for(int i = 0; i<number.size(); i++)
    {
        if(number[i]>tmp) tmp = number[i];
    }
    return tmp;
}


void MainWindow::on_open_file_clicked()
{
    qDebug()<<"NIGGERS";
     fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));
    qDebug()<<fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }

    QTextStream in(&file);
    QString input;
    input = in.readAll();
    qDebug()<<input;
    if(input.isEmpty()) QMessageBox::information(this,"Empty","File is empty");
    file.close();
    ui->display->setText(input);
    update();
   // qDebug()<<ui->display->toPlainText();
    ui->save_file->setDisabled(0);
}


void MainWindow::on_save_file_clicked()
{/*
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open txt"), "//", tr("txt files (*.txt)"));*/
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }
    QTextStream out(&file);
    out << ui->display->toPlainText();
    file.flush();
    file.close();
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

bool MainWindow::check_correct_order(int i, QString str)
{
    if(i % 4 == 1 && ((str.size()<5 && str.toInt()) || str == "")) return true;
    else if(i % 4 == 2 && ((str.size()<11 && check_correct_sting(str)) || str == "")) return true;
    else if(i % 4 == 3 && ((str.size()<7 && str.toInt()) || str == "")) return true;
    else if(i% 4 ==0 && str =="----") return true;
    return false;
}

bool MainWindow::check_correct_goods(int i, QString str)
{
    if(i % 5 == 1 && ((str.size()<4 && str.toInt()) || str == "")) return true;
    else if(i % 5 == 2 && ((str.size()<3 && str.toInt() || str == ""))) return true;
    else if(i % 5 == 3 && ((str.size()<4 && str.toInt()) || str == "")) return true;
   else if(i % 5 == 4 && (str.size()<13 || str == "")) return true;
    else if(i % 5 == 0 && (str == "----" || str == "")) return true;
    return false;
}





void MainWindow::on_show_in_file_clicked()
{

    QString tmp;

    for(int j = 0; j<sum_vector(number);j++)
    {
        qDebug()<<"sum = "<<sum_vector(number);
        tmp += convert_row_to_string(j);
        qDebug()<<"Работает"<<j;
        ui->display->setPlainText(tmp);

    }

}







void MainWindow::on_read_orders_clicked()
{

    qDebug()<<"NIGGERS";

   QFile file(file_orders);
   qDebug()<<file_orders;
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
           QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
           return;
   }


   QTextStream in_(&file);
   QString input_;
   input_ = in_.readAll();
   if(input_.isEmpty())
   {
       QMessageBox::information(this,"Empty","Failed to read data from file becaude it is empty");
       file.close();
       return;
   }
   in_.seek(0);


    int line_number =1;
    bool correctOrder = true;

   do
   {
        QString tmp;
        tmp = in_.readLine();
       if(tmp == "----") number_dividing_lines_orders++;

       correctOrder*=check_correct_order(line_number,tmp);
       line_number++;


   }
   while (!in_.atEnd());

   if(!correctOrder)
   {
    QMessageBox::warning(this,"Incorect file","FILE CONTAINS INVALID DATA");
    file.close();
    return;
   }


   in_.seek(0);
   int line_number_ = 1;

    do
   {
       QString tmp;
       tmp = in_.readLine();
       qDebug()<<tmp;
       if(line_number_ % 4 == 1) tmpOrder.setOrder_number(tmp);
       if(line_number_ % 4 == 2) tmpOrder.setOrder_date(tmp);
       if(line_number_ % 4 == 3) tmpOrder.setRequisites(tmp);
       if(line_number_ % 4 == 0)
       {
       number_of_oders++;
       orders.push_back(tmpOrder);
       }
       line_number_++;

//       qDebug()<<"date = "<<tmpOrder.getOrder_date();
//       qDebug()<<"number = "<<tmpOrder.getOrder_number();
//       qDebug()<<"requsits = "<<tmpOrder.getRequisites();
   }
   while(!in_.atEnd());
   qDebug()<<number_of_oders;
   qDebug()<<orders.size();
   ui->read_items->setDisabled(0);
   ui->read_orders->setDisabled(1);
   ui->display->setText(input_);
   ui->show_result->setDisabled(1);
}


void MainWindow::on_read_items_clicked()
{


    QFile file(file_goods);
    qDebug()<<file_goods;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }


    QTextStream in_(&file);
    QString input_;
    input_ = in_.readAll();
    if(input_.isEmpty())
    {
        QMessageBox::information(this,"Empty","Failed to read data from file becaude it is empty");
        file.close();
        return;
    }
    in_.seek(0);


     int line_number =1;
     bool correctGoods = true;

     do
     {
          QString tmp;
          tmp = in_.readLine();
          if(tmp == "----") number_dividing_lines_goods++;
          qDebug()<<tmp<<" "<< check_correct_goods(line_number,tmp);

         correctGoods*=check_correct_goods(line_number,tmp);
         line_number++;


     }
     while (!in_.atEnd());

     if(number_dividing_lines_goods!=number_dividing_lines_orders)
     {
         QMessageBox::warning(this, "WARNING","The number of dividing lines does not match");
         ui->read_items->setDisabled(1);
         orders.clear();
         goods.clear();
         return;
     }

     if(!correctGoods)
     {
      QMessageBox::warning(this,"Incorect file","FILE CONTAINS INVALID DATA");
      file.close();
      return;
     }


     in_.seek(0);
     int line_number_ = 1;

     Goods tmp_;

     do
    {
        QString str;
        //Goods tmp_;
        str = in_.readLine();
        //qDebug()<<"NIGGGGGGGGGGGGGGERS "<<str;
        if(line_number_ % 5 == 1)
        {
            tmp_.setProduct_code(str);
            qDebug()<<"CODE "<<tmp_.getProduct_code();
        }
        if(line_number_ % 5 == 2) tmp_.setQuantity_of_goods(str);
        if(line_number_ % 5 == 3) tmp_.setPrice_of_the_one_product(str);
        if(line_number_ % 5 == 4) tmp_.setProduct_name(str);
        if(line_number_ % 5 == 0 && str == "")
        {
            qDebug()<<"Code"<<tmp_.getProduct_code();
            qDebug()<<"Quantity"<<tmp_.getQuantity_of_goods();
            qDebug()<<"Price"<<tmp_.getPrice_of_the_one_product();
            qDebug()<<"Name"<<tmp_.getProduct_name();
            number_of_clicks_++;
            goods.push_back(tmp_);

        }

        if(line_number_ % 5 == 0 && str == "----")
        {
            goods.push_back(tmp_);
            number_of_clicks_++;
            qDebug()<<"num "<<number_of_clicks_;
            number.push_back(number_of_clicks_);
            number_of_clicks_ = 0;
        }
        line_number_++;

//        qDebug()<<"Product = "<<tmp_.getProduct_code();
//        qDebug()<<"Quantity = "<<tmp_.getQuantity_of_goods();
//        qDebug()<<"Price = "<<tmp_.getPrice_of_the_one_product();
//        qDebug()<<"Name = "<<tmp_.getProduct_name();
    }
    while(!in_.atEnd());

    qDebug()<<"size "<<goods.size();
    qDebug()<<sum_vector(number);
    ui->display->setText(input_);
    ui->read_items->setDisabled(1);
    ui->show_result->setDisabled(0);
}






















