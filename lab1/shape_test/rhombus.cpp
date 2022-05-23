#include "rhombus.h"
#include<cmath>
#include<QDebug>

Rhombus::Rhombus()
{

}
Rhombus::Rhombus(double side, double angle)
{
    sideR = side;
    smal_angle = angle;

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(sideR==0 && smal_angle == 0)
    {
        QPolygon polygon;
        polygon << QPoint(0,0)<<QPoint(-50,70)<<QPoint(0,140)<<QPoint(50,70);
        painter->drawPolygon(polygon);
    }
    else
    {
        double x1,x2,x3,x4,y1,y2,y3,y4;
        x1= -sideR*sin(smal_angle/2*0.0175);
        x2  = 0;
        x3  = sideR*sin(smal_angle/2*0.0175);
        x4  = 0;
        y1 =  sideR * cos(smal_angle/2*0.0175);
        y2 = 0;
        y3 =  sideR * cos(smal_angle/2*0.0175);
        y4 = 2 * sideR * cos(smal_angle/2*0.0175);

        QPolygonF polygon;
        polygon<<QPointF(x1,y1)<<QPointF(x2,y2)<<QPointF(x3,y3)<<QPointF(x4,y4);
        painter->drawPolygon(polygon);
        qDebug()<<"side = "<<sideR;
        qDebug()<<"angle = "<<smal_angle;
        qDebug()<<"Rhombus has createted";
    }
}

QRectF Rhombus::boundingRect() const
{
     return QRectF(-300,-300,2000,2000);
}

double Rhombus::area()
{
    return Rectangle::area(sideR, sideR, smal_angle);
}

double Rhombus::perimetr()
{
    return 4*sideR;
}


