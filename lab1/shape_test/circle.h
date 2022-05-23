#ifndef CIRCLE_H
#define CIRCLE_H

#include<QGraphicsItem>
#include<QPainter>
#include"figure.h"

class Circle:public Figure
{
public:
    Circle();
    double area();
    double perimetr();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;

};

#endif // CIRCLE_H
