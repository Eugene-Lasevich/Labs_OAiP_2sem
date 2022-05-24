#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"hashtable.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ShowAll();
    bool correct_input_key(QString str);
    bool correct_input_value(QString str);

private slots:

    void on_addKey_textChanged(const QString &arg1);

    void on_add_clicked();

    void on_search_clicked();

    void on_remove_clicked();

    void on_myFunction_clicked();

    void on_addValue_textChanged(const QString &arg1);

    void on_searchKey_textChanged(const QString &arg1);

    void on_removeKey_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    HashTable* table;
};
#endif // MAINWINDOW_H
