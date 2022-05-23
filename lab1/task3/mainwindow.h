#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "date.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <vector>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString *path;
    bool check_correct_sting(QString str);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_getBirthday_userDateChanged(const QDate &date);

    void on_openFile_clicked();


    void on_datesd_cellClicked(int row, int column);


    void on_add_new_date_clicked();




   // void on_change_data_clicked();

    void on_change_data_pressed();

private:
    Ui::MainWindow *ui;
    QString baseStr;
};
#endif // MAINWINDOW_H
