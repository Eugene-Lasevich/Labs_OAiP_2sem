#ifndef GOODS_H
#define GOODS_H
#include<QString>

class Goods
{
public:
    Goods();
    Goods(QString product_code,QString quantity_of_goods,QString price_of_the_one_product,QString product_name);


    const QString &getProduct_code() const;
    void setProduct_code(const QString &newProduct_code);
    const QString &getQuantity_of_goods() const;
    void setQuantity_of_goods(const QString &newQuantity_of_goods);

    const QString &getPrice_of_the_one_product() const;
    void setPrice_of_the_one_product(const QString &newPrice_of_the_one_product);
    const QString &getProduct_name() const;
    void setProduct_name(const QString &newProduct_name);


private:
    QString product_code;
    QString quantity_of_goods;
    QString price_of_the_one_product;
    QString product_name;
};

#endif // GOODS_H
