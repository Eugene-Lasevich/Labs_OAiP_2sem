#include "goods.h"

Goods::Goods()
{

}
Goods::Goods(QString product_code,QString quantity_of_goods,QString price_of_the_one_product,QString product_name)
{
    this->product_code= product_code;
    this->quantity_of_goods = quantity_of_goods;
    this->price_of_the_one_product = price_of_the_one_product;
    this->product_name = product_name;
}

const QString &Goods::getProduct_code() const
{
    return product_code;
}

void Goods::setProduct_code(const QString &newProduct_code)
{
    product_code = newProduct_code;
}

const QString &Goods::getQuantity_of_goods() const
{
    return quantity_of_goods;
}

void Goods::setQuantity_of_goods(const QString &newQuantity_of_goods)
{
    quantity_of_goods = newQuantity_of_goods;
}

const QString &Goods::getPrice_of_the_one_product() const
{
    return price_of_the_one_product;
}

void Goods::setPrice_of_the_one_product(const QString &newPrice_of_the_one_product)
{
    price_of_the_one_product = newPrice_of_the_one_product;
}

const QString &Goods::getProduct_name() const
{
    return product_name;
}

void Goods::setProduct_name(const QString &newProduct_name)
{
    product_name = newProduct_name;
}
