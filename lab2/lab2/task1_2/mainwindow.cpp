#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Name->setInputMask("Aaaaaaaaaa");
    ui->Surname->setInputMask("Aaaaaaaaaaaa");
    ui->Patronymic->setInputMask("Aaaaaaaaaaaa");
    ui->country->setInputMask("Aaaaaaaaa");
    ui->team->setInputMask("Aaaaaaaaaaa");
    ui->gameNumber->setInputMask("00");
    ui->Age->setInputMask("00");
    ui->Growth->setInputMask("000");
    ui->Weight->setInputMask("00");
    ui->change_in_list->hide();
    //ui->groupBox->hide();
    ui->read->setDisabled(1);
    ui->resave->setDisabled(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_in_list_pressed()
{
    participant.setName(ui->Name->text());
    participant.setSurname(ui->Surname->text());
    participant.setPatronymic(ui->Patronymic->text());
    participant.setCountry(ui->country->text());
    participant.setGameNumber(ui->gameNumber->text());
    participant.setTeam(ui->team->text());
    participant.setAge(ui->Age->text());
    participant.setGrowth(ui->Growth->text());
    participant.setWeight(ui->Weight->text());

    if(!participant.isEmpty())list.add(participant);
    //ui->display->clear();
}


void MainWindow::on_add_in_list_released()
{
    if(participant.isEmpty())
    {

        QMessageBox::information(this,"Incorect data", participant.empty_fields());
        return;
    }
    ui->display->clear();

    int number = 1;
    QString str_;
    str_.setNum(number);

    ui->Name->clear();
    ui->Surname->clear();
    ui->Patronymic->clear();
    ui->country->clear();
    ui->team->clear();
    ui->gameNumber->clear();
    ui->Age->clear();
    ui->Growth->clear();
    ui->Weight->clear();

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
    //ui->groupBox->show();

    for(int i = 0; i<list.getSize(); i++) str+=conver_participant_to_string(list[i]);
        ui->display->setText(str);
}

QString MainWindow::conver_participant_to_string(Participant pt)
{
    QString str;
    str = pt.getName() + '\t' + pt.getSurname() + '\t' + pt.getPatronymic() + '\t' + pt.getCountry() +'\t' + pt.getTeam() + '\t' +\
          pt.getGameNumber() + '\t'  + pt.getAge()+ '\t' + pt.getGrowth() + '\t' + pt.getWeight() + '\n';
    return str;

}


void MainWindow::on_sort_clicked()
{
    sort(ui->combo_sort->currentText());

    QString str;
    for(int i = 0; i<list.getSize(); i++)
    {
        str+=conver_participant_to_string(list[i]);
    }
    ui->display->clear();
    ui->display->setText(str);
}


void MainWindow::on_change_clicked()
{
    ui->add_in_list->hide();
    ui->change_in_list->show();
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
            if(str == list[i].getName()) returnStr+=conver_participant_to_string(list[i]);

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
            if(str == list[i].getSurname()) returnStr+=conver_participant_to_string(list[i]);
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
            if(str == list[i].getPatronymic()) returnStr+=conver_participant_to_string(list[i]);
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

    else if(ui->combo_search->currentText() == "Country")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getCountry()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No country found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Team")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getTeam()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No team found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Game number")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getGameNumber()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No game number found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Age")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getAge()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No age found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Growth")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getGrowth()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No growth found "+ str);
            return;
        }

        ui->display->clear();
        ui->display->setText(returnStr);
        return;

    }

    else if(ui->combo_search->currentText() == "Weight")
    {
        QString str;
        QString returnStr;
        str = ui->search_->text();
         ui->search_->clear();

        for(int i = 0; i < list.getSize(); i++)
        {
            if(str == list[i].getWeight()) returnStr+=conver_participant_to_string(list[i]);
        }

        if(returnStr.isEmpty())
        {
            QMessageBox::information(this,"","No weight found "+ str);
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
        for(int i = 0; i<list.getSize(); i++) returnStr+=conver_participant_to_string(list[i]);
        ui->display->clear();
        ui->display->setText(returnStr);
        ui->add_in_list->show();
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
    list.del(index-1);

    ui->combo_delete->clear();
    ui->combo_change->clear();

    for(int i = 0; i<list.getSize();i++)
    {
        QString str;
        str.setNum(i+1);
        returnStr+=conver_participant_to_string(list[i]);
        ui->combo_delete->addItem(str);
        ui->combo_change->addItem(str);
    }
    ui->display->setText(returnStr);
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



    if(!(ui->Name->text() == "")) list[index-1].setName(ui->Name->text());
    if(!(ui->Surname->text() == "")) list[index-1].setSurname(ui->Surname->text());
    if(!(ui->Patronymic->text() == "")) list[index-1].setPatronymic(ui->Patronymic->text());
    if(!(ui->country->text() == "")) list[index-1].setCountry(ui->country->text());
    if(!(ui->gameNumber->text() == "")) list[index-1].setGameNumber(ui->gameNumber->text());
    if(!(ui->team->text() == "")) list[index-1].setTeam(ui->team->text());
    if(!(ui->Age->text() == "")) list[index-1].setAge(ui->Age->text());
    if(!(ui->Growth->text() == "")) list[index-1].setGrowth(ui->Growth->text());
    if(!(ui->Weight->text() == "")) list[index-1].setWeight(ui->Weight->text());




    ui->Name->clear();
    ui->Surname->clear();
    ui->Patronymic->clear();
    ui->country->clear();
    ui->gameNumber->clear();
    ui->team->clear();
    ui->Age->clear();
    ui->Growth->clear();
    ui->Weight->clear();

    QString str;
    for(int i = 0; i<list.getSize(); i++) str+=conver_participant_to_string(list[i]);
    ui->display->setText(str);
}

bool MainWindow::empty_fields()
{
    if(ui->Name->text()=="" && ui->Surname->text() == "" && ui->Patronymic->text()=="" \
       && ui->country->text()=="" && ui->team->text()=="" && ui->gameNumber->text()==""\
        && ui->Age->text()=="" && ui->Growth->text()=="" && ui->Weight->text()=="" ) return true;
    return false;
}

void MainWindow::sort(QString field)
{
    if(field == "Name")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
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
            Participant tmp = list[i];
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
            Participant tmp = list[i];
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

    else if(field == "Country")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            QString tmp_str = list[i].getCountry();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getCountry() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }


    else if(field == "Team")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            QString tmp_str = list[i].getTeam();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getTeam() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Game number")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            int tmp_str = list[i].getGameNumber().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getGameNumber().toInt() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Age")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            int tmp_str = list[i].getAge().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getAge().toInt() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Growth")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            int tmp_str = list[i].getGrowth().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getGrowth().toInt() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }

    else if(field == "Weight")
    {
        int j;
        for (int i = 0; i < list.getSize(); i++)
        {
            Participant tmp = list[i];
            int tmp_str = list[i].getWeight().toInt();
            for ( j = i - 1; j >= 0; j--)
            {
                if (list[j].getWeight().toInt() <= tmp_str)
                {
                    break;
                }
                list[j + 1] = list[j];
            }
            list[j + 1] = tmp;
        }

    }
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

    ui->viewFile->setText(input);

    int line_number =1;
    bool correctFile = true;
    in.seek(0);

   do
   {
        QString tmp;
        tmp = in.readLine();
       // qDebug()<<tmp;
        correctFile*=check_corect_file(line_number, tmp);
        qDebug()<<correctFile;
        line_number++;

   }
   while (!in.atEnd());
    if(line_number % 10 != 0) correctFile =false;

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
     ui->viewFile->setText(input);

    int line_number =1;
    in.seek(0);


   ui->groupBox->show();


   do
   {
    QString str;
    str = in.readLine();

    if(line_number % 10 == 1 && str.size() <= 15) tmp.setName(str);
    else if(line_number % 10 == 2 && str.size() <= 15) tmp.setSurname(str);
    else if(line_number % 10 == 3 && str.size() <=15) tmp.setPatronymic(str);
    else if(line_number % 10 == 4 && str.size() <= 15) tmp.setCountry(str);
    else if(line_number % 10 == 5 && str.size() <= 15) tmp.setTeam(str);
    else if(line_number % 10 == 6 && str.toInt() <= 99 && str.size()<=2) tmp.setGameNumber(str);
    else if(line_number % 10 == 7 && str.toInt() <= 100 && str.size()<=3) tmp.setAge(str);
    else if(line_number % 10 == 8 && str.toInt() <= 270 && str.size()<=3) tmp.setGrowth(str);
    else if(line_number % 10 == 9 && str.toInt() <= 100 && str.size()<=3)
    {
        tmp.setWeight(str);
        list.add(tmp);
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
        tmp+=conver_participant_to_string(list[i]);
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


void MainWindow::on_resave_clicked()
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            QMessageBox::warning(this,"WARNING","FILE IS NOT OPEN");
            return;
    }
    QString str;
    for(int i= 0; i<list.getSize();i++) str+=convert_participant_for_file(list[i]);
    QTextStream out(&file);
    ui->viewFile->setText(str);
    out << str;
    file.flush();
    file.close();

}

bool MainWindow::check_corect_file(int row, QString str)
{

    if(row % 10 == 1 && str.size() <= 15 && !str.isEmpty() && !str.toInt()) return true;
    else if(row % 10 == 2 && str.size() <= 15  && !str.isEmpty() && !str.toInt()) return true;
    else if(row % 10 == 3 && str.size() <=15  && !str.isEmpty() && !str.toInt()) return true;
    else if(row % 10 == 4 && str.size() <= 15  && !str.isEmpty() && !str.toInt()) return true;
    else if(row % 10 == 5 && str.size() <= 15  && !str.isEmpty() && !str.toInt()) return true;
    else if(row % 10 == 6 && str.toInt() <= 99 && str.size()<=2  && !str.isEmpty()) return true;
    else if(row % 10 == 7 && str.toInt() <= 100 && str.size()<=3  && !str.isEmpty()) return true;
    else if(row % 10 == 8 && str.toInt() <= 270 && str.size()<=3  && !str.isEmpty()) return true;
    else if(row % 10 == 9 && str.toInt() <= 100 && str.size()<=3  && !str.isEmpty()) return true;
    else if(row % 10 == 0 && str == "") return true;
    return false;
}

QString MainWindow::convert_participant_for_file(Participant pt)
{
    QString str;
    str+=pt.getName()+'\n';
    str+=pt.getSurname() +'\n';
    str+=pt.getPatronymic()+'\n';
    str+= pt.getCountry()+'\n';
    str+= pt.getTeam()+'\n';
    str+=pt.getGameNumber() +'\n';
    str+=pt.getAge() + '\n';
    str+=pt.getGrowth() +'\n';
    str+= pt.getWeight()+"\n\n";


    return str;
}

