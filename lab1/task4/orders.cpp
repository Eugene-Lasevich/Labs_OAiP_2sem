#include "orders.h"
#include<QDebug>

Order::Order()
{

}

const QString &Order::getOrder_number() const
{
    return order_number;
}

void Order::setOrder_number(const QString &newOrder_number)
{
    order_number = newOrder_number;
}

const QString &Order::getOrder_date() const
{
    return order_date;
}

void Order::setOrder_date(const QString &newOrder_date)
{
    order_date = newOrder_date;
}

const QString &Order::getRequisites() const
{
    return requisites;
}

void Order::setRequisites(const QString &newRequisites)
{
    requisites = newRequisites;
}












