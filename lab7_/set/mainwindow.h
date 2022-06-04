#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"set.h"
#include<QString>



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


    //void print(RBTNode<int, QString>* node, int tabs, QString& str);

    void on_insert_textChanged(const QString &arg1);

    bool correct_value(QString str);

    bool corrct_Value(QString str);

    void on_button_insert_clicked();


    void on_find_clicked();

    void on_erase_clicked();


private:
    Ui::MainWindow *ui;
    set<int> set_ =  set<int>();
    int countNodes = 0;

public:
     //void inOrder(map<int,int>::RBTree<int,int>::RBTNode* node, QString& str1 );
};

#endif // MAINWINDOW_H
