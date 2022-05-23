#include "star_6.h"

Star_6::Star_6()
{

}

void Star_6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon polygon;
    QPolygon polygon1;


    //painter->drawLine(0,0,0,87);
    polygon << QPoint(0,0) << QPoint(-43,75)<<QPoint(43,75);

    painter->drawPolygon(polygon);

    polygon1 << QPoint(0,100) << QPoint(-43,25)<<QPoint(43,25);
    painter->drawPolygon(polygon1);

}

QRectF Star_6::boundingRect() const
{
     return QRectF(-50,0,800,900);
}
