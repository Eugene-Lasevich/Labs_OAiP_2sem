#include "special.h"
#include<QDebug>

Special::Special()
{

}
void Special::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::black);
    painter->setBrush(QColor("#C0C0C0"));
    painter->drawRect(-20,400,30,300);
    //painter->drawRect(-20,400,30,300,QPen(Qt::black),QBrush(QColor("#C0C0C0")));


    painter->setBrush(QColor("#696969"));
    painter->drawRect(-35,575,15,125);
    painter->drawRect(10,575,15,125);

    QPolygon tip1, tip2, tip3;
    tip1<<QPoint(-35,575)<<QPoint(-20,500)<<QPoint(-20,575);
    tip2<<QPoint(25,575)<<QPoint(10,495)<<QPoint(10,575);
    tip3<<QPoint(-20,400)<<QPoint(-7,300)<<QPoint(10,400);

    painter->setPen(Qt::gray);
    painter->setBrush(Qt::white);
    painter->drawPolygon(tip1);
    painter->drawPolygon(tip2);
    painter->drawPolygon(tip3);


    QPolygon flame1, flame2, flame3;
    flame1<<QPoint(-35,700)<<QPoint(-25,750)<<QPoint(-18,700);
    flame2<<QPoint(-18,700)<<QPoint(-5,850)<<QPoint(10,700);
    flame3<<QPoint(10,700)<<QPoint(20,750)<<QPoint(25,700);

    QLinearGradient grad1(-18,700,-18,750);
    QLinearGradient grad2(-18,700,10,850);
    QLinearGradient grad3(10,700,25,750);

    grad1.setColorAt(0.001, Qt::white);
    grad1.setColorAt(0.3, Qt::yellow);
    grad1.setColorAt(0.7, Qt::red);

    grad2.setColorAt(0.001, Qt::white);
    grad2.setColorAt(0.3, Qt::yellow);
    grad2.setColorAt(0.8, Qt::red);


    grad3.setColorAt(0.1, Qt::white);
    grad3.setColorAt(0.3, Qt::yellow);
    grad3.setColorAt(0.7, Qt::red);



    painter->setPen(Qt::red);

    painter->setBrush(grad1);
    painter->drawPolygon(flame1);

    painter->setBrush(grad2);
    painter->drawPolygon(flame2);


    painter->setBrush(grad3);
    painter->drawPolygon(flame3);
    qDebug()<<"Rocket create";


}

QRectF Special::boundingRect() const
{
    return QRectF(-50,0,800,900);
}
