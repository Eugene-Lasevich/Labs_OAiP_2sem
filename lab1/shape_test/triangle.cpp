#include "triangle.h"

Triangle::Triangle()
{

}
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon triangle;
    triangle << QPoint(0,0) << QPoint(50,50)<<QPoint(150,100);
    painter->drawPolygon(triangle);

}

QRectF Triangle::boundingRect() const
{
     return QRectF(0,0,800,900);
}
 double Triangle::area()
 {
     return 1250;
 }
 double Triangle::perimetr()
 {
    return 70.7+180.3+111.8;
 }
