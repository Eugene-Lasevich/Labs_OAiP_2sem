#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QGraphicsItem>
#include<QPainter>
#include"figure.h"
#include"rectangle.h"

class Rhombus : public Rectangle
{
    double sideR = 0;
    double smal_angle = 0;
public:
    Rhombus();
    Rhombus(double,double);
    double area();
    double perimetr();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // RHOMBUS_H
