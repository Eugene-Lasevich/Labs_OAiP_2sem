#ifndef HEXAGON_H
#define HEXAGON_H

#include <QGraphicsItem>
#include<QPainter>
#include"figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // HEXAGON_H
