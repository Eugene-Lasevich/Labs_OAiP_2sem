#ifndef ORDERS_H
#define ORDERS_H
#include<QString>
#include<QDate>
#include <QVector>
//#include"goods.h"


class Order
{
public:
    Order();
    const QString &getOrder_number() const;
    void setOrder_number(const QString &newOrder_number);
    const QString &getOrder_date() const;
    void setOrder_date(const QString &newOrder_date);
    const QString &getRequisites() const;
    void setRequisites(const QString &newRequisites);


private:

    QString order_number;
    QString order_date;
    QString requisites;

    };





#endif // ORDERS_H
