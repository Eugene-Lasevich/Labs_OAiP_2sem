#include "star_5.h"

Star_5::Star_5()
{

}
void Star_5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon polygon;
    polygon << QPoint(0,0)<<QPoint(-30,80)<<QPoint(45,30)<<QPoint(-45,30)<<QPoint(30,80);
    painter->drawPolygon(polygon);

}

QRectF Star_5::boundingRect() const
{
     return QRectF(-45,-40,800,900);
}
