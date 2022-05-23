#ifndef STAR_5_H
#define STAR_5_H

#include<QPainter>
#include<QGraphicsItem>
#include"figure.h"

class Star_5 : public Figure
{
public:
    Star_5();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // STAR_5_H
