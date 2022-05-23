#ifndef ROCKET_H
#define ROCKET_H

#include <QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include"line.h"


class Rocket : public Line
{
public:
    Rocket();


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // ROCKET_H
