#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->add_expression->hide();
    ui->line_expression->hide();
    ui->label->hide();
    ui->label_expresssion->setText(ui->comboBox->currentText());
    ui->enter_a->setDisabled(1);
    ui->enter_b->setDisabled(1);
    ui->enter_c->setDisabled(1);
    ui->enter_d->setDisabled(1);
    ui->enter_e->setDisabled(1);
    disabled_fields(ui->comboBox->currentText());

}

MainWindow::~MainWindow()
{
    delete ui;
}



bool MainWindow::correct_expression(QString str)
{
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_e = 0;
    if(str.isEmpty())return false;
    if(!ckeck_brackets(str)) return false;
    for(int i = 0; i< str.size(); i++)
    {
        //if(str.isEmpty())return false;
        if(i>0)
        if(str[i-1] == str[i] && str[i] !='(' && str[i] !=')') return false;

        if(str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')') continue;
        if(str[i] != 'a' && str[i] != 'b' && str[i] != 'c'&& str[i] !='d' && str[i] != 'e') return false;


        if(str[i]=='a')count_a++;
        if(str[i]=='b')count_b++;
        if(str[i]=='c')count_c++;
        if(str[i]=='d')count_d++;
        if(str[i]=='e')count_e++;


        if(count_a>1)return false;
        if(count_b>1)return false;
        if(count_c>1)return false;
        if(count_d>1)return false;
        if(count_e>1)return false;
    }

    return true;
}



void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "new expression")
    {
        ui->add_expression->show();
        ui->line_expression->show();
        ui->label->show();
        ui->groupBox->hide();
        ui->enter_a->setDisabled(1);
        ui->enter_b->setDisabled(1);
        ui->enter_c->setDisabled(1);
        ui->enter_d->setDisabled(1);
        ui->enter_e->setDisabled(1);
        //ui->label_expresssion->setText(mas[number_expression]);
    }

    else
    {
        disabled_fields(arg1);
        ui->add_expression->hide();
        ui->line_expression->hide();
        ui->label->hide();
        ui->groupBox->show();
        ui->label_expresssion->setText(ui->comboBox->currentText());
    }
}


void MainWindow::on_add_expression_clicked()
{
    QString str = ui->line_expression->text();
    if(!correct_expression(str))
    {
        QMessageBox::information(this,"","Incorect expression");
        ui->line_expression->clear();
        return;
    }


    disabled_fields(str);

    ui->label_expresssion->setText(str);
    ui->groupBox->show();
    ui->line_expression->clear();
    ui->add_expression->hide();
    ui->label->hide();
    ui->line_expression->hide();


}

bool MainWindow::check_correct_values(QString str)
{
    int count_points = 0;
    if(str.size()>10) return false;
    if(str[0] == '.') return false;
    for(int i = 0 ; i< str.size(); i++)
    {
        if(str[0]=='-') continue;
        if((str[i]<'0' || str[i]>'9') && str[i] !='.')return false;

        if(str[i]=='.') count_points++;
        if(count_points>1) return false;
    }
    return true;
}


QString MainWindow::conver_infix_to_prefix(QString str)
{
    QString returnStr;
    for(int i = 0; i< str.size(); i++)
    {
        if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            if(signs.empty())
            {
            signs.push(str[i]);
            continue;
            }

            else if(priorety(signs.top())>= priorety(str[i]))
            {
                returnStr.push_back(signs.pop());
                signs.push(str[i]);
                continue;
            }

            else
            {
                signs.push(str[i]);
                continue;

            }


        }

        if(str[i] == '(')
        {
            signs.push(str[i]);
            continue;
        }

        if(str[i]==')')
        {
            QString pop_;
            while(signs.top() != '(') returnStr.push_back(signs.pop());
            if(signs.top() == '(') pop_ = signs.pop();
            continue;
        }



        returnStr.push_back(str[i]);
    }
    while(!signs.empty()) returnStr.push_back(signs.pop());
    return returnStr;
}

int MainWindow::priorety(QChar ch)
{
    if(ch == '*' || ch =='/') return 2;
    if(ch == '-' || ch == '+') return 1;

    return -1;
}

double MainWindow::calculate_prefix(QString str, double a =0 , double b = 0, double c =0, double d= 0, double e = 0)
{
    double tmp1 = 0;
    double tmp2 = 0;
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i] == 'a') value.push(a);
        if(str[i] == 'b') value.push(b);
        if(str[i] == 'c') value.push(c);
        if(str[i] == 'd') value.push(d);
        if(str[i] == 'e') value.push(e);

        if(str[i] == '+')
        {
            tmp1 = value.pop();
            tmp2 = value.pop();
            qDebug()<<"tmp1 + tmp2"<<tmp1<<tmp2<<tmp1+tmp2;
            value.push(tmp1+tmp2);
        }

        if(str[i] == '-')
        {
            tmp2 = value.pop();
            tmp1 = value.pop();
            qDebug()<<"tmp1 - tmp2"<<tmp1<<tmp2<<tmp1-tmp2;
            value.push(tmp1-tmp2);
        }

        if(str[i] == '*')
        {
            tmp1 = value.pop();
            tmp2 = value.pop();
            qDebug()<<"tmp1 * tmp2"<<tmp1<<tmp2<<tmp1*tmp2;
            value.push(tmp1*tmp2);
        }

        if(str[i] == '/')
        {
            tmp2 = value.pop();
            tmp1 = value.pop();
            qDebug()<<"tmp1 / tmp2"<<tmp1<<tmp2<<tmp1/tmp2;
            value.push(tmp1/tmp2);
        }
    }

    if(!value.empty()) return value.pop();
    else return -123456789;
}

bool MainWindow::ckeck_brackets(QString expression)
{
    myStack brackets;



    for (int j = 0;  j<expression.size(); j++)
    {
        if(expression[j]=='\n')continue;


        if (expression[j] == '[' || expression[j] == '(' ||expression[j] == '{')
        {
            brackets.push(expression[j]);


            continue;
        }

        if (expression[j] == ']' || expression[j] == ')' || expression[j] == '}')
        {

            if (brackets.empty())
                return false;

            if (expression[j] == ']' && brackets.top() != '[')
                return false;
            if (expression[j] == ')' && brackets.top() != '(')
                return false;
            if (expression[j] == '}' && brackets.top() != '{')
                return false;
            brackets.pop();

        }

    }

    return brackets.empty();
}

void MainWindow::disabled_fields(QString str)
{
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i] == 'a') ui->enter_a->setDisabled(0);
        if(str[i] == 'b') ui->enter_b->setDisabled(0);
        if(str[i] == 'c') ui->enter_c->setDisabled(0);
        if(str[i] == 'd') ui->enter_d->setDisabled(0);
        if(str[i] == 'e') ui->enter_e->setDisabled(0);
    }
}





void MainWindow::on_calculate_clicked()
{

    QString str_a = ui->enter_a->text();
    QString str_b = ui->enter_b->text();
    QString str_c = ui->enter_c->text();
    QString str_d = ui->enter_d->text();
    QString str_e = ui->enter_e->text();

    if(!check_correct_values(str_a))QMessageBox::information(this,"","a containts invalid value");
    if(!check_correct_values(str_b))QMessageBox::information(this,"","b containts invalid value");
    if(!check_correct_values(str_c))QMessageBox::information(this,"","c containts invalid value");
    if(!check_correct_values(str_d))QMessageBox::information(this,"","d containts invalid value");
    if(!check_correct_values(str_e))QMessageBox::information(this,"","e containts invalid value");

    if(!check_correct_values(str_a)||!check_correct_values(str_b)||!check_correct_values(str_c)||!check_correct_values(str_d)||!check_correct_values(str_e)) return;

    qDebug()<<"ABOBA";

    double a = ui->enter_a->text().toDouble();
    double b = ui->enter_b->text().toDouble();
    double c = ui->enter_c->text().toDouble();
    double d = ui->enter_d->text().toDouble();
    double e = ui->enter_e->text().toDouble();

    ui->enter_a->clear();
    ui->enter_b->clear();
    ui->enter_c->clear();
    ui->enter_d->clear();
    ui->enter_e->clear();


    QString str, strPol;
    str = ui->label_expresssion->text();
    strPol = conver_infix_to_prefix(str);
    qDebug()<<strPol;


    double tmp =calculate_prefix(strPol,a,b,c,d,e);
    QString tmp_;
    tmp_.setNum(tmp);
    QString returnStr;
    returnStr = str + '\n' + strPol +'\n'+"a = " + str_a+ '\n' +"b = " + str_b + '\n' + "c = " + str_c+ '\n' + "d = " + str_d+ '\n' + "e = " + str_e + '\n' + tmp_ +'\n'+'\n';
    mas[number_expression] = returnStr;
    number_expression++;
}


void MainWindow::on_show_result_clicked()
{   QString str;
    for(int i = 0; i<number_expression;i++) str+=mas[i];
    ui->display->clear();
    ui->display->setText(str);
}

