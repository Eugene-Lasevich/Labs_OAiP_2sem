#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColor>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->button_insert->setDisabled(1);
    ui->insert->setPlaceholderText("key: ");
    ui->insertValue->setPlaceholderText("value: ");
    ui->lineErase->setPlaceholderText("key: ");
    ui->lineFind->setPlaceholderText("key: ");


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::print(RBTNode<int> *node, int tabs, QString& str)
{


    str+="\n";

    if (node && node != nullptr)
    {
        tabs += 10;
        QString tmp;
        print(node->right, tabs, str);

        for (int i = 10; i < tabs; ++i) str+=  " ";

        if (node->color == Red)
        {
            tmp.setNum(node->key);
            str+=  tmp + "-R-" + node->value;
        }

        else
        {
            tmp.setNum(node->key);
            str+= tmp+"-B-" + node->value  + "\n";
        }

        print(node->left, tabs,str);
    }


}


void MainWindow::on_insert_textChanged(const QString &arg1)
{
    if(correct_value(arg1) && !ui->insertValue->text().isEmpty()) ui->button_insert->setDisabled(0);
    else ui->button_insert->setDisabled(1);

    if(ui->insert->text().isEmpty()) ui->button_insert->setDisabled(1);
}
bool MainWindow::correct_value(QString str)
{
    if(str.size()>3) return false;
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i]<'0' ||  str[i] > '9') return false;
    }
    return true;
}

bool MainWindow::corrct_Value(QString str)
{
    if(str.size()>3) return false;
    return true;
}


void MainWindow::on_button_insert_clicked()
{
    if(countNodes>9)
    {
        QMessageBox::information(this,"", "Many values, may be incorrect display");
        ui->button_insert->setDisabled(1);
        return;
    }
    int key;
    QString str;
    str = ui->insertValue->text();
    key = ui->insert->text().toInt();

    std::pair<int, QString> pr;
    pr.first= key;
    pr.second = str;
    if(tree.insert(pr))
    {
        QString tree_;

        tree_.clear();

        print(tree.root, 10, tree_);
        ui->textBrowser->setText(tree_);
        countNodes++;

        QString postOr= "";
        QString inOr = "";
        QString preOr= "";

        postOrder(tree.root,postOr);
        inOrder(tree.root,inOr);
        preOrder(tree.root, preOr);

        ui->postOrder->setText(postOr);
        ui->inOrder->setText(inOr);
        ui->preOrder->setText(preOr);
    }

    else
    {
        QMessageBox::information(this, "", "Failed to insert value by key");
    }

}



void MainWindow::on_find_clicked()
{
    bool findValue = tree.search(ui->lineFind->text().toInt()).second;
    if(findValue)  QMessageBox::information(this,"", tree.search(ui->lineFind->text().toInt()).first->value);
    else QMessageBox::information(this, " ", "No value found with the given key");

}


void MainWindow::on_erase_clicked()
{
    if(countNodes> 0)
    {
        ui->button_insert->setDisabled(0);
        if(tree.remove(ui->lineErase->text().toInt()))
        {
            QString tree_1;

            tree_1.clear();

            print(tree.root, 10, tree_1);

            QString postOr= "";
            QString inOr = "";
            QString preOr= "";

            postOrder(tree.root,postOr);
            inOrder(tree.root,inOr);
            preOrder(tree.root, preOr);

            ui->postOrder->setText(postOr);
            ui->inOrder->setText(inOr);
            ui->preOrder->setText(preOr);
            ui->textBrowser->setText(tree_1);

            countNodes--;
        }
        else QMessageBox::information(this,"","Failed to delete value by given key");
    }


}

void MainWindow::inOrder(RBTNode<int> *node, QString &str1)
{
    QString tmp;
    if (node != nullptr)
    {
        inOrder(node->left, str1);
        tmp.setNum(node->key);
        str1+=tmp + '\n';
        tmp.clear();
        inOrder(node->right,str1);
    }
    else return;
}

void MainWindow::postOrder(RBTNode<int> *node, QString &str2)
{
    if (node != nullptr)
    {
        postOrder(node->left, str2);
        postOrder(node->right, str2);
        QString tmp;
        tmp.setNum(node->key);
        str2+=tmp + '\n';

    }
}

void MainWindow::preOrder(RBTNode<int> *node, QString &str3)
{
    if (node != nullptr)
    {
        QString  tmp;
        tmp.setNum(node->key);
        str3+=tmp+ '\n';
        preOrder(node->left,str3);
        preOrder(node->right,str3);
    }
}


void MainWindow::on_insertValue_textChanged(const QString &arg1)
{
    if(corrct_Value(arg1) && !ui->insert->text().isEmpty()) ui->button_insert->setDisabled(0);
    else ui->button_insert->setDisabled(1);

    if(ui->insertValue->text().isEmpty()) ui->button_insert->setDisabled(1);
}


