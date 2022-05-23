#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include<QPainter>

class Line : public QGraphicsItem
{
public:
    Line();
    void move();

protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
    //void move();

};

#endif // LINE_H
