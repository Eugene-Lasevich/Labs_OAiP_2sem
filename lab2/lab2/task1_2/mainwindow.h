#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mylist.h"
#include<QDebug>
#include<QMessageBox>
#include"participant.h"
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
    void on_add_in_list_pressed();

    void on_add_in_list_released();

    QString conver_participant_to_string(Participant pt);


    void on_sort_clicked();

    void on_change_clicked();

    void on_search_clicked();

    void on_delete_2_clicked();

    void on_change_in_list_clicked();

    bool empty_fields();

    void sort(QString field);

    void on_combo_search_currentTextChanged(const QString &arg1);

    void on_open_file_clicked();

    void on_read_clicked();

    void on_resave_clicked();
    bool check_corect_file(int row, QString str);
    QString convert_participant_for_file(Participant  pt);

private:
    Ui::MainWindow *ui;
    QString fileName;
    MyList<Participant> list;
    Participant participant;
    Participant tmp;
};
#endif // MAINWINDOW_H
