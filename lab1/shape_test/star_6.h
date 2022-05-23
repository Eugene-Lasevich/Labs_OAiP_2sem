#ifndef STAR_6_H
#define STAR_6_H

#include <QGraphicsItem>
#include<QPainter>
#include"figure.h"

class Star_6 : public Figure
{
public:
    Star_6();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // STAR_6_H
