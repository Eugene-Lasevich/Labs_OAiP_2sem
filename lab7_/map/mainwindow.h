#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"map.h"
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


    //void print(RBTNode<int, QString>* node, int tabs, QString& str);

    void on_insert_textChanged(const QString &arg1);

    bool correct_value(QString str);

    bool corrct_Value(QString str);

    void on_button_insert_clicked();


    void on_find_clicked();

    void on_erase_clicked();

    //void inOrder(RBTNode* node, QString& str1 );


    void on_insertValue_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    map<int, int> map_ =  map<int, int>();
    int countNodes = 0;

public:
     //void inOrder(map<int,int>::RBTree<int,int>::RBTNode* node, QString& str1 );
};

#endif // MAINWINDOW_H
