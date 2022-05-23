#ifndef STAR_8_H
#define STAR_8_H

#include <QGraphicsItem>
#include<QPainter>
#include"figure.h"

class Star_8 : public Figure
{
public:
    Star_8();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};

#endif // STAR_8_H
