#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"rectangle.h"
#include"triangle.h"
#include"circle.h"
#include"rhombus.h"
#include"star_5.h"
#include"star_6.h"
#include"star_8.h"
#include"hexagon.h"
#include"special.h"
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QTimer *timer_size;
    QTimer *timer_rotation;
    QTimer *timer_up_down;
    QTimer *timer_right_left;
    QTimer * timer;
    QGraphicsScene *scene;
    Rectangle *rectangle;
    Triangle *triangle;
    Circle *circle;
    Rhombus *rhombus;
    Star_5 *star_5;
    Star_6 *star_6;
    Star_8 *star_8;
    Hexagon *hexagon;
    Special *special;


    bool rect = false;
    bool triangl = false;
    bool circl = false;
    bool rhomb = false;
    bool s5 = false;
    bool s6 = false;
    bool s8 = false;
    bool hex = false;
    bool spec = false;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //void create_rhombus();

    void display_x_pos();
    void display_y_pos();
    void display_angle();
    void display_size();

    void display_area();
    void display_perimetr();

    void move_up();
    void move_down();
    void move_left();
    void move_right();

    void rotate_left();
    void rotate_right();

    void size_plus();
    void size_minus();

    void on_move_up_pressed();

    void on_move_up_released();

    void on_move_down_pressed();

    void on_move_down_released();



    void on_move_left_pressed();

    void on_move_left_released();

    void on_move_right_pressed();

    void on_move_right_released();


    void on_rotate_left_pressed();

    void on_rotate_left_released();

    void on_rotate_right_released();

    void on_rotate_right_pressed();

    void on_size_plus_pressed();

    void on_size_plus_released();

    void on_size_minus_pressed();

    void on_size_minus_released();





    void on_Rectangle_toggled(bool checked);

    void on_Triangle_toggled(bool checked);

    void on_Circle_toggled(bool checked);

    void on_Rhombus_toggled(bool checked);

    void on_Star_8_toggled(bool checked);

    void on_Star_6_toggled(bool checked);

    void on_Star_5_toggled(bool checked);

    void on_Hexagon_toggled(bool checked);

    void on_Special_toggled(bool checked);


    void on_Enter_x_pos_editingFinished();

    void on_Enter_y_pos_editingFinished();

    void on_Enter_angle_editingFinished();

    void on_Enter_size_editingFinished();

    void on_create_rhombus_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
