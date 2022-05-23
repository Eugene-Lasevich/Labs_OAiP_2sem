#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"figure.h"

class Triangle : public Figure
{
public:
    Triangle();
    double area();
    double perimetr();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //override;
    QRectF boundingRect() const;//override;
};

#endif // TRIANGLE_H
