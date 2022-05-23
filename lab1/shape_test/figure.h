#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include<QPainter>
#include<QDebug>

class Figure : public QGraphicsItem
{
public:

    Figure();
    void move_up_();
    void move_down_();
    void move_right_();
    void move_left_();
    void rotate_left_();
    void rotate_right_();
    void size_plus_();
    void size_minus_();
//   virtual double area() = 0;
//   virtual double perimert()= 0;




protected:
    virtual void  paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget) =0;
    virtual QRectF  boundingRect() const = 0;
};
#endif // FIGURE_H
