#include "orderlist.h"

OrderList::OrderList()
{

}


QString OrderList::getOrder_number() const
{
    return order_number;
}


void OrderList::setOrder_number(QString newOrder_number)
{
    order_number = newOrder_number;
}


const QDate &OrderList::getOrder_date() const
{
    return order_date;
}


void OrderList::setOrder_date(const QDate &newOrder_date)
{
    order_date = newOrder_date;
}

const QString &OrderList::getRequisites() const
{
    return requisites;
}

void OrderList::setRequisites(const QString &newRequisites)
{
    requisites = newRequisites;
}

const QString &OrderList::getProduct_code() const
{
    return product_code;
}

void OrderList::setProduct_code(const QString &newProduct_code)
{
    product_code = newProduct_code;
}

QString  OrderList::getQuantity_of_goods() const
{
    return quantity_of_goods;
}

void OrderList::setQuantity_of_goods(QString newQuantity_of_goods)
{
    quantity_of_goods = newQuantity_of_goods;
}

QString OrderList::getPrice_of_the_one_product() const
{
    return price_of_the_one_product;
}

void OrderList::setPrice_of_the_one_product(QString newPrice_of_the_one_product)
{
    price_of_the_one_product = newPrice_of_the_one_product;
}

const QString &OrderList::getProduct_name() const
{
    return product_name;
}

void OrderList::setProduct_name(const QString &newProduct_name)
{
    product_name = newProduct_name;
}
