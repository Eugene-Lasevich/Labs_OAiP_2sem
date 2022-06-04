#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"bitset.h"

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

    void on_flipButton_clicked();

    void on_setButton_clicked();

    void on_resetButton_clicked();

    void on_setNumberButton_clicked();

private:
    Ui::MainWindow *ui;

    bitset<128>* bitsus;
};

#endif // MAINWINDOW_H
