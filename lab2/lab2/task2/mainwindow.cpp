#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setMaxLength(15);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_brackets(QString expression, int& i)
{
    Stack brackets;
    Stack_int stack;



    for (int j = 0;  j<expression.size(); j++)
    {
        if(expression[j]=='\n')continue;

        i++;
        if (expression[j] == '[' || expression[j] == '(' ||expression[j] == '{')
        {
            brackets.push(expression[j]);
            stack.push(i);

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
            stack.pop();
        }

    }

    if(!stack.empty())
    {
        while(stack.size != 1)
        {
            stack.pop();
            i = stack.top();
        }
        if(stack.size ==1) i = stack.top();
    }
    return brackets.empty();

}

QString MainWindow::covert_to_convert(QString str)
{
    QString returnStr;
    qDebug()<<str.size();
    for(int i = 0; i< str.size();i++)
    {
        //if(str[i] == '\n')continue;
        if(i % 16 == 0 && i>0)
        {
            returnStr.push_back('\n');
            returnStr.push_back(str[i]);
            continue;
        }

        if(str[i] == '\n')continue;
        returnStr.push_back(str[i]);
    }
    return returnStr;
}


void MainWindow::on_add_string_clicked()
{
//    if(ui->lineEdit->text().size()<15)
//    {
//        QMessageBox::information(this,"","You entered an incomplete string");
//        return;
//    }

    int  i= 0;
    QString str;
    str = covert_to_convert(ui->textEdit->toPlainText());
    qDebug()<<str;
    ui->lineEdit->clear();
    ui->brackets->setText(str);


}


void MainWindow::on_show_result_clicked()
{
   QString str, strReverse;
   str = ui->brackets->toPlainText();


   int i = 0;
   int k = 0;
  if(check_brackets(str,i)) QMessageBox::information(this,"","Succes");
  else
  {
      QString row, column;
      row.setNum(i/15+1);
      qDebug()<<"i = "<<i;
      qDebug()<<"k = "<<k;
      if(i%15 == 0) column.setNum(15), row.setNum(i/15);
      else column.setNum(i%15);

      QMessageBox::information(this,"","Incorect parenthesis in line " + row + " in column " + column);
  }
}




void MainWindow::on_read_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
       tr("Open txt"), "//", tr("txt files (*.txt)"));
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
    ui->textEdit->setText(input);

    in.seek(0);


//   do
//   {
//    QString str, line;
//    line.setNum(line_number);
//    str = in.readLine();

//    if(str.size()<15)
//    {
//        QMessageBox::information(this,"","Failed to count because line "+line+" is less than 15" +'\n' + str);
//        return;
//    }

//    if(str.size()>15)
//    {
//        QMessageBox::information(this,"","Failed to count so line"+line+" is greater than 15"+'\n' + str);
//        return;
//    }

//    line_number++;

//   }
//   while(!in.atEnd());

   in.seek(0);
   input = in.readAll();
   ui->brackets->setText(covert_to_convert(input));
}


void MainWindow::on_clear_clicked()
{
    enteredString.clear();
    ui->brackets->clear();
}

