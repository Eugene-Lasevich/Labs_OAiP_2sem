#include "line.h"

Line::Line()
{

}
QRectF Line::boundingRect() const
{
    return QRect(0,0,500,200);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
   Q_UNUSED(option);
   Q_UNUSED(widget);
   painter->drawLine(50,100,50,200);
}

void Line:: move()
{
    static double velocity = 0,coordinate = 0; //acceleration =1;

    coordinate--;
    this->setPos(250, (coordinate*velocity));


    velocity+=0.002;

    if(coordinate<=-900 || coordinate*velocity<-900)
    {
        coordinate = 0;
        this->setPos(250,550);


    }
}
