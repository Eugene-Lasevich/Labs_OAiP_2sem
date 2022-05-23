#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"rocket.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,800,900);
    scene->addLine(150,0,300,0,QPen(Qt::blue,10));
    scene->addLine(150,900,300,900,QPen(Qt::yellow,10));

    myRocketTimer = new QTimer(this);
    myRocketTimer->start(10);


    LineTimer = new QTimer(this);
    LineTimer->start(1000/100);


    rocket->setPos(250,0);
    scene->addItem(rocket);

    line->setPos(98,50);
    scene->addItem(line);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::moveLine()
{

    line->move();

}


void MainWindow::moveRocket()
{

    rocket->move();
}



void MainWindow::on_Start_line_clicked()
{
    connect(LineTimer, SIGNAL(timeout()),this,SLOT(moveLine()));
}


void MainWindow::on_Stop_line_clicked()
{
    disconnect(LineTimer, SIGNAL(timeout()),this,SLOT(moveLine()));
}


void MainWindow::on_Start_rocket_clicked()
{
    connect(myRocketTimer, SIGNAL(timeout()),this,SLOT(moveRocket()));
}


void MainWindow::on_Stop_rocket_clicked()
{
    disconnect(myRocketTimer, SIGNAL(timeout()),this,SLOT(moveRocket()));

}

