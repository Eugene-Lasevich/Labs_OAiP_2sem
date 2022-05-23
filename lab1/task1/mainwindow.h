#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"rocket.h"
#include"line.h"
#include<QPushButton>
#include<QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene *scene;
    Rocket *rocket = new Rocket();
    Line *line = new Line();

    QTimer *myRocketTimer;
    QTimer *LineTimer;

    bool rocket_move =false;
    bool line_move = false;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void moveLine();

    void moveRocket();


    void on_Start_line_clicked();

    void on_Stop_line_clicked();

    void on_Start_rocket_clicked();

    void on_Stop_rocket_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
