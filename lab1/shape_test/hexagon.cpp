#include "hexagon.h"


Hexagon::Hexagon()
{

}
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon hexagon;
    hexagon << QPoint(0,0) << QPoint(43,25)<<QPoint(43,75)<< QPoint(0,100) << QPoint(-43,75)<<QPoint(-43,25);
    painter->drawPolygon(hexagon);


}

QRectF Hexagon::boundingRect() const
{
     return QRectF(-43,0,800,900);
}
