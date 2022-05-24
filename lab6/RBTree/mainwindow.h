#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"rbtree.h"
#include<QString>
//#include"newrbtree.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void print(RBTNode<int>* node, int tabs, QString& str);

    void on_insert_textChanged(const QString &arg1);

    bool correct_value(QString str);

    bool corrct_Value(QString str);

    void on_button_insert_clicked();


    void on_find_clicked();

    void on_erase_clicked();

    void inOrder(RBTNode<int>* node, QString& str1 );

    void postOrder(RBTNode<int>* node, QString& str2);

    void preOrder(RBTNode<int>* node, QString& str3);

    void on_insertValue_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    RBTree< int > tree =  RBTree<int>();
    int countNodes = 0;
};
#endif // MAINWINDOW_H
