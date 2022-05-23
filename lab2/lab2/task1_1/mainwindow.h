#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include"enrollee.h"
#include"mylist.h"
#include<QFile>
#include<QFileDialog>
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getSize_of_list() const;


private slots:
    QString convert_enrolle_to_string(Enrollee enrollee);

    bool empty_fields();

    void on_add_in_list_pressed();

    void on_add_in_list_released();


    void on_change_clicked();

    void on_search_clicked();


    void on_change_in_list_clicked();

    void on_combo_search_currentTextChanged(const QString &arg1);

    void on_delete_2_clicked();

    void on_sort_clicked();
    void sort(QString field);


    void on_resave_clicked();


    void on_read_clicked();

    bool check_corect_file(int row, QString str);
    QString convert_enrollee_for_file(Enrollee  enrollee);

    void on_open_file_clicked();

    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    QString fileName;
    int number_of_studetns_clicked = 0;
    Enrollee enrollee;
    Enrollee tmp;
    MyList list;
    int size_of_list = 0;
    //int number =1;

};
#endif // MAINWINDOW_H
