#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mystring.h"
#include<StringDll/include/stringdll.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    String str;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_memcpy_clicked()
{
    char str1[] = "string memcpy";
    char str2[40];
    char str3[60];
    memcpy (str2, str1, strlen(str1)+1);
    memcpy (str3, "copy of string is successful(memcpy)",60);

    QMessageBox::information(this,"", " str 1 = \"string memcpy\" str2 empty, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);


}


void MainWindow::on_memmove_clicked()
{

    char str1[] = "string memmove";
    char str2[40] = "str";
    char str3[60];
    memmove (str2, str1, strlen(str1)+1);
    memmove (str3, "copy of string is successful(memmmove)",60);

    QMessageBox::information(this,"", " str 1 = \"string memmove\" str2 str, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);
}


void MainWindow::on_strcpy_clicked()
{
    char str1[] = "string strcpy";
    char str2[40] = "str";
    char str3[60];
    strcpy (str2, str1);
    strcpy (str3, "copy of string is successful(strcpy)");

    QMessageBox::information(this,"", " str 1 = \"string strcpy\" str2 str, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);
}


void MainWindow::on_strncpy_clicked()
{
    char str1[] = "string strncpy";
    char str2[40] = "str";
    char str3[60];
    strncpy (str2, str1, strlen(str1)+1);
    strncpy (str3, "copy of string is successful(strncpy)", 60);

    QMessageBox::information(this,"", " str 1 = \"string strcpy\" str2 str, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);
}


void MainWindow::on_strcat_clicked()
{
    char str1[] = "str1";
    char str2[40] = "str 2";
    char str3[60];
    strcat (str2, str1);
    strcat (str3, "copy of string is successful(strcat)");

    QMessageBox::information(this,"", " str 1 = \"str1\" str2 str2, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);
}


void MainWindow::on_strncat_clicked()
{
    char str1[] = "str1";
    char str2[40] = "str 2";
    char str3[60];
    strncat (str2, str1,5);
    strncat (str3, "copy of string is successful(strcat)",10);

    QMessageBox::information(this,"", " str 1 = \"str1\" str2 str2, str3 empty");
    QMessageBox::information(this, "str1", str1);
    QMessageBox::information(this,"str2", str2);
    QMessageBox::information(this, "str3", str3);
}



void MainWindow::on_memcmp_clicked()
{
    char str1[] = "ABOBA";
    char str2[40] = "str2";
    int tmp  = memcmp(str1, str2 ,3);
    QString tmp1;
    tmp1.setNum(tmp);
    QMessageBox::information(this,"str1",str1);
    QMessageBox::information(this,"str2",str2);
    QMessageBox::information(this,"str1",tmp1);


}


void MainWindow::on_strcmp_clicked()
{
    char str1[] = "A";
    char str2[40] = "a";
    int tmp  = strcmp(str1, str2);
    QString tmp1;
    tmp1.setNum(tmp);
    QMessageBox::information(this,"str1",str1);
    QMessageBox::information(this,"str2",str2);
    QMessageBox::information(this,"str1",tmp1);
}


void MainWindow::on_strcoll_clicked()
{
    char str1[] = "B";
    char str2[40] = "b";
    int tmp  = strcoll(str1, str2);
    QString tmp1;
    tmp1.setNum(tmp);
    QMessageBox::information(this,"str1",str1);
    QMessageBox::information(this,"str2",str2);
    QMessageBox::information(this,"str1",tmp1);
}


void MainWindow::on_strncmp_clicked()
{
    char str1[] = "AAA";
    char str2[40] = "bbb";
    int tmp  = strncmp(str1, str2,2);
    QString tmp1;
    tmp1.setNum(tmp);
    QMessageBox::information(this,"str1",str1);
    QMessageBox::information(this,"str2",str2);
    QMessageBox::information(this,"str1",tmp1);
}





void MainWindow::on_strtok_clicked()
{
    char str[] = "Features of national fishing - feature, comedy film.\n";
    QMessageBox ::information(this,"",str);
    char * pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        //std::cout << pch  << "\n";
        QMessageBox::information(this,"", pch);
        pch = strtok (NULL, " ,.-");
    }
}


void MainWindow::on_memset_clicked()
{

    char str5[] = "Every good programmer must know !\n";
    QMessageBox::information(this,"",str5);
    mem_set(str5,'_',12);
    QMessageBox::information(this,"",str5);

}


void MainWindow::on_strlen_clicked()
{
    char str1[] = "AAA";
    int size = strlen(str1);
    QString tmp;
    tmp.setNum(size);
    QMessageBox::information(this,"",str1);
    QMessageBox::information(this, "", tmp);
}




