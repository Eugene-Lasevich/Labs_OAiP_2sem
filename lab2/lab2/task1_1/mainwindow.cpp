#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->display->hide();
    ui->name->setInputMask("Aaaaaaa");
    ui->surname->setInputMask("Aaaaaaaa");
    ui->patronymic->setInputMask("Aaaaaaaaaaa");
    ui->Physics->setInputMask("00");
    ui->math->setInputMask("00");
    ui->russian->setInputMask("00");
    ui->display->hide();
    ui->change_in_list->hide();
    ui->groupBox->hide();
    ui->read->setDisabled(1);
    ui->resave->setDisabled(1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::convert_enrolle_to_string(Enrollee enrollee)
{
    QString tmp;
    tmp = enrollee.getName()+'\t'+enrollee.getSurname() +'\t' + enrollee.getPatronymic() +'\t' + enrollee.getPhysics() +'\t' + enrollee.getMath() + '\t' + enrollee.getRussian() + '\n' ;
    return tmp;


}

bool MainWindow::empty_fields()
{
    if(ui->name->text()=="" && ui->surname->text() == "" && ui->patronymic->text()=="" && ui->Physics->text()=="" && ui->math->text()=="" && ui->russian->text()=="") return true;
    return false;
}


void MainWindow::on_add_in_list_pressed()
{
    //number_of_studetns_clicked++;
    enrollee.setName(ui->name->text());
    enrollee.setSurname(ui->surname->text());
    enrollee.setPatronymic(ui->patronymic->text());
    enrollee.setMath(ui->math->text());
    enrollee.setPhysics(ui->Physics->text());
    enrollee.setRussian(ui->russian->text());
    if(!enrollee.isEmpty())list.push_back(enrollee);
    ui->display->clear();


}


void MainWindow::on_add_in_list_released()
{
    if(enrollee.isEmpty())
    {

        QMessageBox::information(this,"Incorect data", enrollee.empty_fields());
        return;
    }

    int number = 1;
    QString str_;
    str_.setNum(number);

    ui->name->clear();
    ui->surname->clear();
    ui->patronymic->clear();
    ui->Physics->clear();
    ui->math->clear();
    ui->russian->clear();
    ui->combo_change->clear();
    ui->combo_delete->clear();
    for(int i = 0; i<list.getSize(); i++)
    {
        ui->combo_change->addItem(str_.setNum(number));
        ui->combo_delete->addItem(str_.setNum(number));
        number++;
    }


    QString str;
    ui->display->show();
    ui->groupBox->show();

    for(int i = 0; i<list.getSize(); i++) str+=convert_enrolle_to_string(list[i]);
    ui->display->setText(str);


}



void MainWindow::on_change_clicked()
{
    ui->add_in_list->hide();
    ui->change_in_list->show();
    //ui->display->clear();

}


void MainWindow::on_search_clicked()
{
    ui->change_in_list->hide();


    if(ui->combo_search->currentText() == "Name")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
        ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getName()) returnStr+=convert_enrolle_to_string(list[i]);

        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No name found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Surname")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getSurname()) returnStr+=convert_enrolle_to_string(list[i]);
        }


        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No surname found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Patronymic")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getPatronymic()) returnStr+=convert_enrolle_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No patronymic found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Physics")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getPhysics()) returnStr+=convert_enrolle_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No physics found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }


    else if(ui->combo_search->currentText() == "Math")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getMath()) returnStr+=convert_enrolle_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No math found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Russian")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getRussian()) returnStr+=convert_enrolle_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No russian found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Go Back")
    {

         ui->search_->clear();
        QString returnStr;
        for(int i = 0; i<list.getSize(); i++) returnStr+=convert_enrolle_to_string(list[i]);
        ui->display->clear();
        ui->display->setText(returnStr);
        ui->add_in_list->show();
    }


}





void MainWindow::on_change_in_list_clicked()
{
   ui->add_in_list->show();
   ui->change_in_list->hide();



   if(this->empty_fields())
   {
       QMessageBox::information(this,"","You didn't change anything");
       return;
   }

   ui->display->clear();

   int index = ui->combo_change->currentText().toInt();



   if(!(ui->name->text() == "")) list[index-1].setName(ui->name->text());
   if(!(ui->surname->text() == "")) list[index-1].setSurname(ui->surname->text());
   if(!(ui->patronymic->text() == "")) list[index-1].setPatronymic(ui->patronymic->text());
   if(!(ui->Physics->text() == "")) list[index-1].setPhysics(ui->Physics->text());
   if(!(ui->math->text() == "")) list[index-1].setMath(ui->math->text());
   if(!(ui->russian->text() == "")) list[index-1].setRussian(ui->russian->text());


   ui->name->clear();
   ui->surname->clear();
   ui->patronymic->clear();
   ui->Physics->clear();
   ui->math->clear();
   ui->russian->clear();
   ui->display->clear();

   QString str;
   for(int i = 0; i<list.getSize(); i++) str+=convert_enrolle_to_string(list[i]);
   ui->display->setText(str);


}


void MainWindow::on_combo_search_currentTextChanged(const QString &arg1)
{


    if(ui->combo_search->currentText() == "Go Back")
    {
        ui->search_->setDisabled(1);
        ui->search->setText("Go Back");
        ui->search_->update();
    }

    else
    {
        ui->search_->setDisabled(0);
        ui->search->setText("Search");
        ui->search_->update();
    }
}


void MainWindow::on_delete_2_clicked()
{
    QString str;
    QString returnStr;
    str = ui->combo_delete->currentText();
    qDebug()<<list.getSize();
    if(list.getSize() == 1)
    {
        QMessageBox::information(this, "", "Can no longer be deleted");
        return;
    }
    int index = str.toInt();
    list.removeAt(index-1);

    ui->combo_delete->clear();
    ui->combo_change->clear();

    for(int i = 0; i<list.getSize();i++)
    {
        QString str;
        str.setNum(i+1);
        returnStr+=convert_enrolle_to_string(list[i]);
        ui->combo_delete->addItem(str);
        ui->combo_change->addItem(str);
    }
    ui->display->setText(returnStr);
}


void MainWindow::on_sort_clicked()
{
    sort(ui->combo_sort->currentText());

    QString str;
    for(int i = 0; i<list.getSize(); i++)
    {
        str+=convert_enrolle_to_string(list[i]);
    }
    ui->display->clear();
    ui->display->setText(str);
}

void MainWindow::sort(QString field)
{
    if(field == "Name")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            QString tmp_str = list[i].getName();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getName() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }
    }

    else if(field == "Surname")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            QString tmp_str = list[i].getSurname();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getSurname() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Patronymic")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            QString tmp_str = list[i].getPatronymic();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getPatronymic() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }
    }

    else if(field == "Physics")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            int tmp_str = list[i].getPhysics().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getPhysics().toInt() >= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }


    else if(field == "Math")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            int tmp_str = list[i].getMath().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getMath().toInt() >= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Russian Language")
    {

        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Enrollee tmp = list[i];
            int tmp_str = list[i].getRussian().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getRussian().toInt() >= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }
    }
}




void MainWindow::on_resave_clicked()
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }
    QString str;
    for(int i= 0; i<list.getSize();i++) str+=convert_enrollee_for_file(list[i]);
    QTextStream out(&file);
    ui->view_file->setText(str);
    out << str;
    file.flush();
    file.close();
}



void MainWindow::on_read_clicked()
{

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }

    QTextStream in(&file);
    QString input;
    input = in.readAll();

    if(input.isEmpty())
    {
        QMessageBox::information(this,"Empty","File is empty");
        return;
    }
     ui->view_file->setText(input);

    int line_number =1;
    in.seek(0);


   ui->groupBox->show();


   do
   {
    QString str;
    str = in.readLine();

    if(line_number % 7 == 1 && str.size()<=15)tmp.setName(str);
    else if(line_number % 7 == 2 && str.size()<=15)tmp.setSurname(str);
    else if(line_number % 7 == 3 && str.size() <=15)tmp.setPatronymic(str);
    else if(line_number % 7 == 4 && str.toInt()<=100 && str.size()<=3)tmp.setPhysics(str);
    else if(line_number % 7 == 5 && str.toInt()<=100 && str.size()<=3)tmp.setMath(str);
    else if(line_number % 7 == 6 && str.toInt()<=100 && str.size()<=3)
    {
        tmp.setRussian(str);
        list.push_back(tmp);
    }

    line_number++;

   }
   while(!in.atEnd());

    qDebug()<<"size = "<<list.getSize();

    file.close();
    QString tmp;
    QString tmp_;
    int number = 1;

    for(int i = 0; i<list.getSize();i++)
    {
        tmp+=convert_enrolle_to_string(list[i]);
    }

    ui->combo_change->clear();
    ui->combo_delete->clear();

    for(int i = 0; i<list.getSize(); i++)
    {
        ui->combo_change->addItem(tmp_.setNum(number));
        ui->combo_delete->addItem(tmp_.setNum(number));
        number++;
    }

    ui->display->clear();
    ui->display->show();
    ui->display->setText(tmp);
    update();
    ui->read->setDisabled(1);
}

bool MainWindow::check_corect_file(int row, QString str)
{
    if(row % 7 == 1 && str.size()<=15) return true;
    else if(row % 7 == 2 && str.size()<=15) return true;
    else if(row % 7 == 3 && str.size() <=15) return true;
    else if(row % 7 == 4 && str.toInt()<=100 && str.size()<=3) return true;
    else if(row % 7 == 5 && str.toInt()<=100 && str.size()<=3) return true;
    else if(row % 7 == 6 && str.toInt()<=100 && str.size()<=3) return true;
    else if(row % 7 == 0 && str == "") return true;
    return false;
}

QString MainWindow::convert_enrollee_for_file(Enrollee enrollee)
{
    QString str;
    str+=enrollee.getName()+'\n';
    str+=enrollee.getSurname() +'\n';
    str+=enrollee.getPatronymic()+'\n';
    str+= enrollee.getPhysics()+'\n';
    str+= enrollee.getMath()+'\n';
    str+= enrollee.getRussian()+"\n\n";


    return str;
}


void MainWindow::on_open_file_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
       tr("Open txt"), "//", tr("txt files (*.txt)"));
    ui->read->setDisabled(1);
    ui->label->setText(fileName);

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
        return;
    }

    QTextStream in(&file);
    QString input;
    input = in.readAll();

    ui->view_file->setText(input);

    int line_number =1;
    bool correctFile = true;
    in.seek(0);

   do
   {
        QString tmp;
        tmp = in.readLine();
        qDebug()<<tmp;
        correctFile*=check_corect_file(line_number, tmp);
        line_number++;

   }
   while (!in.atEnd());


   if(correctFile && !input.isEmpty())
   {
       ui->read->setDisabled(0);
       ui->resave->setDisabled(0);
   }

   else
   {
       if(input.isEmpty())
       {
           QMessageBox::information(this,"Empty","File is empty");
           ui->resave->setDisabled(0);
           return;
       }

       QMessageBox::warning(this,"","File contains invalid data");
        file.close();
        return;
   }
}


void MainWindow::on_clear_clicked()
{
    ui->display->clear();
}

