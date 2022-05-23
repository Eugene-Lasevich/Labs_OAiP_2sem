#include "circle.h"

Circle::Circle()
{

}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(0,0,50,50);

}

QRectF Circle::boundingRect() const
{
     return QRectF(0,0,800,900);
}

double Circle:: area()
{
    return 3.14159 * 50* 50;
}
double Circle::perimetr()
{
    return 3.14159 * 100;
}
