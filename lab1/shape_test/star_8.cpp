#include "star_8.h"

Star_8::Star_8()
{

}
void Star_8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon polygon;
    polygon<<QPoint(0,0)<<QPoint(50,50)<<QPoint(0,100)<<QPoint(-50,50);
    painter->drawPolygon(polygon);

    painter->drawRect(-35,15,71,71);
}

QRectF Star_8::boundingRect() const
{
     return QRectF(-50,0,800,900);
}
