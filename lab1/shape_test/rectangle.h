#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
   double length;
   double width;
   int angle = 90;

public:
    Rectangle();
    double area(double length, double width, double angle);
    double area();
    double perimetr();
    double getLength() const;
    void setLength(double newLength);
    double getWidth() const;
    void setWidth(double newWidth);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // RECTANGLE_H
