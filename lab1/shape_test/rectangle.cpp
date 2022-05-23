#include "rectangle.h"

double Rectangle::getLength() const
{
    return length;
}

void Rectangle::setLength(double newLength)
{
    length = newLength;
}

double Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

Rectangle::Rectangle()
{

}

double Rectangle::area(double length, double width, double angle)
{
    qDebug()<<"NIGGGGGGGGGGGGGGGGGGGGERS"<<sin(angle/57.2958);

    return length * width* sin(angle/57.2958);

}
double Rectangle::area()
{
    return getLength() * getWidth();
}
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawRect(-50,-50,70,120);
    setLength(70);
    setWidth(120);

    qDebug()<<"Pos on scene = "<<this->scenePos();

}
QRectF Rectangle::boundingRect() const
{
     return QRectF(-300,-300,500,600);
}



double Rectangle::perimetr()
{
    return 190*2;
}
