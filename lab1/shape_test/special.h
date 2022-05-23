#ifndef SPECIAL_H
#define SPECIAL_H

#include <QGraphicsItem>
#include<QPainter>
#include<QTimer>
#include"figure.h"


class Special : public Figure
{
public:
    Special();


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
};
#endif // SPECIAL_H
