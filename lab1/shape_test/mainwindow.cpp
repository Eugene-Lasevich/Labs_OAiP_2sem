#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
//------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(-300,-300,500,600);

    rectangle = new Rectangle ();
    triangle = new Triangle();
    circle = new Circle();
    //rhombus = new Rhombus();
    star_5 = new Star_5();
    star_6 = new Star_6();
    star_8 = new Star_8();
    hexagon = new Hexagon();
    special = new Special();
    //scene->addItem(special)
   // scene->addLine(scene->width()/2,0,scene->width()/2,scene->height());


    triangle->setTransformOriginPoint(50,25);
    //rhombus->setTransformOriginPoint(0,70);
    star_5->setTransformOriginPoint(0,40);
    star_6->setTransformOriginPoint(0,50);
    star_8->setTransformOriginPoint(0,50);
    hexagon->setTransformOriginPoint(0,50);
    special->setTransformOriginPoint(0,550);


    timer_up_down = new QTimer(this);
    timer_right_left = new QTimer(this);
    timer_rotation = new QTimer(this);
    timer_size = new QTimer(this);
    //timer = new QTimer(this);

     ui->Enter_x_pos->setInputMask("#00");
     ui->Enter_y_pos->setInputMask("#00");
     ui->Enter_angle->setInputMask("#00");
     ui->Enter_size->setInputMask("#0.00");

    ui->groupBox_2->hide();
}

void MainWindow::display_x_pos()
{

   if(rect) ui->X_pos->setNum(rectangle->x());
   if(triangl) ui->X_pos->setNum(triangle->x());
   if(circl) ui->X_pos->setNum(circle->x());
   if(rhomb) ui->X_pos->setNum(rhombus->x());
   if(s5) ui->X_pos->setNum(star_5->x());
   if(s6) ui->X_pos->setNum(star_6->x());
   if(s8) ui->X_pos->setNum(star_8->x());
   if(hex) ui->X_pos->setNum(hexagon->x());
   if(spec) ui->X_pos->setNum(special->x());

}

void MainWindow::display_y_pos()
{
    if(rect) ui->Y_pos->setNum(rectangle->y());
    if(triangl) ui->Y_pos->setNum(triangle->y());
    if(circl) ui->Y_pos->setNum(circle->y());
    if(rhomb) ui->Y_pos->setNum(rhombus->y());
    if(s5) ui->Y_pos->setNum(star_5->y());
    if(s6) ui->Y_pos->setNum(star_6->y());
    if(s8) ui->Y_pos->setNum(star_8->y());
    if(hex) ui->Y_pos->setNum(hexagon->y());
    if(spec) ui->Y_pos->setNum(special->y());
}

void MainWindow::display_angle()
{
    if(rect) ui->angle->setNum(rectangle->rotation());
    if(triangl) ui->angle->setNum(triangle->rotation());
    if(circl) ui->angle->setNum(circle->rotation());
    if(rhomb) ui->angle->setNum(rhombus->rotation());
    if(s5) ui->angle->setNum(star_5->rotation());
    if(s6) ui->angle->setNum(star_6->rotation());
    if(s8) ui->angle->setNum(star_8->rotation());
    if(hex) ui->angle->setNum(hexagon->rotation());
    if(spec) ui->angle->setNum(special->rotation());
}

void MainWindow::display_size()
{
    if(rect) ui->size->setNum(rectangle->scale());
    if(triangl) ui->size->setNum(triangle->scale());
    if(circl) ui->size->setNum(circle->scale());
    if(rhomb) ui->size->setNum(rhombus->scale());
    if(s5) ui->size->setNum(star_5->scale());
    if(s6) ui->size->setNum(star_6->scale());
    if(s8) ui->size->setNum(star_8->scale());
    if(hex) ui->size->setNum(hexagon->scale());
    if(spec) ui->size->setNum(special->scale());
}

void MainWindow::display_area()
{

    if(rect) ui->Area->setNum((rectangle->area()*pow(rectangle->scale(),2)));
    if(triangl) ui->Area->setNum((triangle->area()*pow(triangle->scale(),2)));
    if(circl) ui->Area->setNum((circle->area()*pow(circle->scale(),2)));
    if(rhomb) ui->Area->setNum((rhombus->area()*pow(rhombus->scale(),2)));
    if(s5) ui->Area->setText("Лень");
    if(s6) ui->Area->setText("Лень");
    if(s8) ui->Area->setText("Лень");
    if(hex) ui->Area->setText("Лень");
    if(spec) ui->Area->setText("Лень");

}

void MainWindow::display_perimetr()
{
    if(rect) ui->Perimetr->setNum((rectangle->perimetr()*(rectangle->scale())));
    if(triangl) ui->Perimetr->setNum((triangle->perimetr()*(triangle->scale())));
    if(circl) ui->Perimetr->setNum((circle->perimetr()*(circle->scale())));
    if(rhomb) ui->Perimetr->setNum((rhombus->perimetr()*(rhombus->scale())));
    if(s5) ui->Perimetr->setText("считать");
    if(s6) ui->Perimetr->setText("считать");
    if(s8) ui->Perimetr->setText("считать");
    if(hex) ui->Perimetr->setText("счиатать");
    if(spec) ui->Perimetr->setText("считать");
}

void MainWindow::on_Enter_x_pos_editingFinished()
{
    int x;
    x = ui->Enter_x_pos->text().toInt();


    if(rect) rectangle->setPos(x,rectangle->y());
    if(triangl) triangle->setPos(x,triangle->y());
    if(circl) circle->setPos(x,circle->y());
    if(rhomb) rhombus->setPos(x,rhombus->y());
    if(s5) star_5->setPos(x,star_5->y());
    if(s6) star_6->setPos(x,star_6->y());
    if(s8) star_8->setPos(x,star_8->y());
    if(hex) hexagon->setPos(x,hexagon->y());
    if(spec) special->setPos(x,special->y());
}


void MainWindow::on_Enter_y_pos_editingFinished()
{
    int y;
    y = ui->Enter_y_pos->text().toInt();


    qDebug()<<"y = "<<y;
    if(rect) rectangle->setPos(rectangle->x(),y);
    if(triangl) triangle->setPos(triangle->x(),y);
    if(circl) circle->setPos(circle->x(),y);
    if(rhomb) rhombus->setPos(rhombus->x(),y);
    if(s5) star_5->setPos(star_5->x(),y);
    if(s6) star_6->setPos(star_6->x(),y);
    if(s8) star_8->setPos(star_8->x(),y);
    if(hex) hexagon->setPos(hexagon->x(),y);
    if(spec) special->setPos(special->x(),y);
}



void MainWindow::on_Enter_angle_editingFinished()
{
    int angl;
    ui->angle->setText(ui->Enter_angle->text());
    angl = ui->Enter_angle->text().toInt();

    if(rect) rectangle->setRotation(angl);
    if(triangl) triangle->setRotation(angl);
    if(circl) circle->setRotation(angl);
    if(rhomb) rhombus->setRotation(angl);
    if(s5) star_5->setRotation(angl);
    if(s6) star_6->setRotation(angl);
    if(s8) star_8->setRotation(angl);
    if(hex) hexagon->setRotation(angl);
    if(spec) special->setRotation(angl);

}

void MainWindow::on_Enter_size_editingFinished()
{
    double size;
    ui->size->setText(ui->Enter_size->text());
    size = ui->Enter_size->text().toDouble();
    if(size>4) size = 4;
    if(size<-4) size = -4;
    if(rect) rectangle->setScale(size);
    if(triangl) triangle->setScale(size);
    if(circl) circle->setScale(size);
    if(rhomb) rhombus->setScale(size);
    if(s5) star_5->setScale(size);
    if(s6) star_6->setScale(size);
    if(s8) star_8->setScale(size);
    if(hex) hexagon->setScale(size);
    if(spec) special->setScale(size);
}

//------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}


//------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
void MainWindow::move_up()
{
    if(rect) rectangle->move_up_();
    if(triangl) triangle->move_up_();
    if(circl) circle->move_up_();
    if(rhomb) rhombus->move_up_();
    if(s5) star_5->move_up_();
    if(s6) star_6->move_up_();
    if(s8) star_8->move_up_();
    if(hex) hexagon->move_up_();
    if(spec) special->move_up_();
    if(s8) star_8->rotate_left_();
    if(rect) rectangle->rotate_left_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::move_down()
{
    if(rect) rectangle->move_down_();
    if(triangl) triangle->move_down_();
    if(circl) circle->move_down_();
    if(rhomb) rhombus->move_down_();
    if(s5) star_5->move_down_();
    if(s6) star_6->move_down_();
    if(s8) star_8->move_down_();
    if(hex) hexagon->move_down_();
    if(spec) special->move_down_();
    if(s8) star_8->rotate_right_();
    if(rect) rectangle->rotate_right_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::move_left()
{
    if(rect) rectangle->move_left_();
    if(triangl) triangle->move_left_();
    if(circl) circle->move_left_();
    if(rhomb) rhombus->move_left_();
    if(s5) star_5->move_left_();
    if(s6) star_6->move_left_();
    if(s8) star_8->move_left_();
    if(hex) hexagon->move_left_();
    if(spec) special->move_left_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::move_right()
{
    if(rect) rectangle->move_right_();
    if(triangl) triangle->move_right_();
    if(circl) circle->move_right_();
    if(rhomb) rhombus->move_right_();
    if(s5) star_5->move_right_();
    if(s6) star_6->move_right_();
    if(s8) star_8->move_right_();
    if(hex) hexagon->move_right_();
    if(spec) special->move_right_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::rotate_left()
{

    if(rect) rectangle->rotate_left_();
    if(triangl) triangle->rotate_left_();
    if(circl) circle->rotate_left_();
    if(rhomb) rhombus->rotate_left_();
    if(s5) star_5->rotate_left_();
    if(s6) star_6->rotate_left_();
    if(s8) star_8->rotate_left_();
    if(hex) hexagon->rotate_left_();
    if(spec) special->rotate_left_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::rotate_right()
{

    if(rect) rectangle->rotate_right_();
    if(triangl) triangle->rotate_right_();
    if(circl) circle->rotate_right_();
    if(rhomb) rhombus->rotate_right_();
    if(s5) star_5->rotate_right_();
    if(s6) star_6->rotate_right_();
    if(s8) star_8->rotate_right_();
    if(hex) hexagon->rotate_right_();
    if(spec) special->rotate_right_();
}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::size_plus()
{
    if(rect) rectangle->size_plus_();
    if(triangle) triangle->size_plus_();
    if(circl) circle->size_plus_();
    if(rhomb) rhombus->size_plus_();
    if(s5) star_5->size_plus_();
    if(s6) star_6->size_plus_();
    if(s8) star_8->size_plus_();
    if(hex) hexagon->size_plus_();
    if(spec) special->size_plus_();

}
//-----------------------------------------------------------------------------------------------------------------------------------
void MainWindow::size_minus()
{

    if(rect) rectangle->size_minus_();
    if(triangle) triangle->size_minus_();
    if(circl) circle->size_minus_();
    if(rhomb) rhombus->size_minus_();
    if(s5) star_5->size_minus_();
    if(s6) star_6->size_minus_();
    if(s8) star_8->size_minus_();
    if(hex) hexagon->size_minus_();
    if(spec) special->size_minus_();

}

//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_move_up_pressed()
{
    connect(timer_up_down, SIGNAL(timeout()), this, SLOT(move_up()));
    connect(timer_up_down,SIGNAL(timeout()),this, SLOT(display_y_pos()));

    timer_up_down->start(10);
}

void MainWindow::on_move_up_released()
{
    timer_up_down->stop();
    disconnect(timer_up_down, SIGNAL(timeout()), this, SLOT(move_up()));
    disconnect(timer_up_down,SIGNAL(timeout()),this, SLOT(display_y_pos()));

}

//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_move_down_pressed()
{
    connect(timer_up_down, SIGNAL(timeout()), this, SLOT(move_down()));
    connect(timer_up_down, SIGNAL(timeout()), this, SLOT(display_y_pos()));

    timer_up_down->start(10);
}


void MainWindow::on_move_down_released()
{
    timer_up_down->stop();
    disconnect(timer_up_down, SIGNAL(timeout()), this, SLOT(move_down()));
    disconnect(timer_up_down,SIGNAL(timeout()),this, SLOT(display_y_pos()));

}

//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_move_left_pressed()
{
    connect(timer_right_left, SIGNAL(timeout()), this, SLOT(move_left()));
    connect(timer_right_left,SIGNAL(timeout()),this, SLOT(display_x_pos()));

    timer_right_left->start(10);
}


void MainWindow::on_move_left_released()
{
    timer_right_left->stop();
    disconnect(timer_right_left, SIGNAL(timeout()), this, SLOT(move_left()));
    disconnect(timer_right_left,SIGNAL(timeout()),this, SLOT(display_x_pos()));

}

//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_move_right_pressed()
{
    connect(timer_right_left, SIGNAL(timeout()), this, SLOT(move_right()));
    connect(timer_right_left,SIGNAL(timeout()),this, SLOT(display_x_pos()));

    timer_right_left->start(10);
}


void MainWindow::on_move_right_released()
{
    timer_right_left->stop();
    disconnect(timer_right_left, SIGNAL(timeout()), this, SLOT(move_right()));
    disconnect(timer_right_left,SIGNAL(timeout()),this, SLOT(display_x_pos()));

}

//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_rotate_left_pressed()
{
    connect(timer_rotation, SIGNAL(timeout()), this, SLOT(rotate_left()));
    connect(timer_rotation,SIGNAL(timeout()),this, SLOT(display_angle()));
    timer_rotation->start(10);
}


void MainWindow::on_rotate_left_released()
{
    timer_rotation->stop();
    disconnect(timer_rotation, SIGNAL(timeout()), this, SLOT(rotate_left()));
    disconnect(timer_rotation,SIGNAL(timeout()),this, SLOT(display_angle()));

}
//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_rotate_right_pressed()
{
    connect(timer_rotation, SIGNAL(timeout()), this, SLOT(rotate_right()));
    connect(timer_rotation,SIGNAL(timeout()),this, SLOT(display_angle()));

    timer_rotation->start(10);
}

void MainWindow::on_rotate_right_released()
{
    timer_rotation->stop();
    disconnect(timer_rotation, SIGNAL(timeout()), this, SLOT(rotate_right()));
    disconnect(timer_rotation,SIGNAL(timeout()),this, SLOT(display_angle()));

}

//------------------------------------------------------------------------------------------------------------------



void MainWindow::on_size_plus_pressed()
{
    connect(timer_size, SIGNAL(timeout()), this, SLOT(size_plus()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_size()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_area()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_perimetr()));
    timer_size->start(10);
}


void MainWindow::on_size_plus_released()
{
    timer_size->stop();
    disconnect(timer_size, SIGNAL(timeout()), this, SLOT(size_plus()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_size()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_area()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_perimetr()));



}
//------------------------------------------------------------------------------------------------------------------

void MainWindow::on_size_minus_pressed()
{
    connect(timer_size, SIGNAL(timeout()), this, SLOT(size_minus()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_size()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_area()));
    connect(timer_size, SIGNAL(timeout()),this, SLOT(display_perimetr()));

    timer_size->start(10);
}


void MainWindow::on_size_minus_released()
{
    timer_size->stop();
    disconnect(timer_size, SIGNAL(timeout()), this, SLOT(size_minus()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_size()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_area()));
    disconnect(timer_size, SIGNAL(timeout()),this, SLOT(display_perimetr()));


}



void MainWindow::on_Rectangle_toggled(bool checked)
{
    if(checked)
    {
       rect = true;
       scene->addItem(rectangle);
       qDebug()<<"NIGGERS";
    }

    else
    {
        rect = false;
        scene->removeItem(rectangle);
        qDebug()<<"NIGGER";
    }
}


void MainWindow::on_Triangle_toggled(bool checked)
{
        if(checked)
        {
           triangl = true;
           scene->addItem(triangle);

        }

        else
        {
            triangl = false;
            scene->removeItem(triangle);
        }
}


void MainWindow::on_Circle_toggled(bool checked)
{
        if(checked)
        {
           circl = true;
           scene->addItem(circle);

        }

        else
        {
            circl = false;
            scene->removeItem(circle);
        }
}


void MainWindow::on_Rhombus_toggled(bool checked)
{
    if(checked)
    {
       rhomb = true;
       ui->groupBox_2->show();
       ui->side->setInputMask("000");
       ui->angle_2->setInputMask("00");
//       rhombus = new Rhombus(100,90);
//       scene->addItem(rhombus);

    }

    else
    {
        rhomb = false;
        scene->removeItem(rhombus);
    }
}


void MainWindow::on_Star_8_toggled(bool checked)
{
        if(checked)
        {
           s8 = true;
           scene->addItem(star_8);

        }

        else
        {
            s8 = false;
            scene->removeItem(star_8);
        }
}


void MainWindow::on_Star_6_toggled(bool checked)
{
        if(checked)
        {
           s6 = true;
           scene->addItem(star_6);

        }

        else
        {
            s6 = false;
            scene->removeItem(star_6);
        }
}


void MainWindow::on_Star_5_toggled(bool checked)
{
        if(checked)
        {
           s5 = true;
           //scene->clear();
           scene->addItem(star_5);

        }

        else
        {
            s5 = false;
            scene->removeItem(star_5);
        }
}


void MainWindow::on_Hexagon_toggled(bool checked)
{
        if(checked)
        {
           hex = true;
           //scene->clear();
           scene->addItem(hexagon);

        }

        else
        {
            hex = false;
            scene->removeItem(hexagon);
        }
}


void MainWindow::on_Special_toggled(bool checked)
{
        if(checked)
        {
           spec = true;
           scene->addItem(special);
           special->setScale(0.5);
           special->setPos(0,-400);
        }

        else
        {
            spec = false;
            scene->removeItem(special);
             qDebug()<<"NIGGER";
        }
}




void MainWindow::on_create_rhombus_clicked()
{
    static int i = 0;
    if(i>=1)
    {
        scene->removeItem(rhombus);
        i = 0;
    }
    double side = ui->side->text().toDouble();
    double angle = ui->angle_2->text().toDouble();
    ui->groupBox_2->show();
    rhombus = new Rhombus(side,angle);
    rhombus->setTransformOriginPoint(0,side*cos(angle/57.28/2));
    scene->addItem(rhombus);
    i++;
}

