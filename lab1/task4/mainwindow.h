#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"orders.h"
#include"goods.h"
#include<QFile>
#include<QFileDialog>


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



    QString convert_row_to_string(int row);

    void on_Create_pressed();

    void on_add_product_pressed();

    void on_finish_additing_pressed();

    void on_Create_released();

    int sum_vector(QVector<int>);

    void on_show_result_released();

    int maxValue(QVector<int>);

    void on_open_file_clicked();

    void on_save_file_clicked();

    void on_show_in_file_clicked();

    bool check_correct_sting(QString str);
    bool check_correct_order(int i,  QString str);
    bool check_correct_goods(int i, QString str);

   // void on_pushButton_clicked();



    void on_read_orders_clicked();

    void on_read_items_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Order> orders;
    QVector<Goods> goods;
    QVector<int> number;
    int number_of_clicks_ = 0;
    int number_of_oders= 0;
    Order tmpOrder;
    Goods tmpGoods;
    int tmp_tmp = 0;
    QString fileName;
    int number_dividing_lines_orders = 0;
    int number_dividing_lines_goods = 0;
    QString file_orders = "C:/Users/ASUS/Desktop/orders.txt";
    QString file_goods = "C:/Users/ASUS/Desktop/goods.txt";


};
#endif // MAINWINDOW_H
