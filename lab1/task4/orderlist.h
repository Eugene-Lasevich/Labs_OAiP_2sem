#ifndef ORDERLIST_H
#define ORDERLIST_H
#include<QDate>

class OrderList
{
public:
    OrderList();

    QString getOrder_number() const;
    void setOrder_number(QString newOrder_number);
    const QDate &getOrder_date() const;
    void setOrder_date(const QDate &newOrder_date);
    const QString &getRequisites() const;
    void setRequisites(const QString &newRequisites);
    const QString &getProduct_code() const;
    void setProduct_code(const QString &newProduct_code);
    QString getQuantity_of_goods() const;
    void setQuantity_of_goods(QString newQuantity_of_goods);
    QString getPrice_of_the_one_product() const;
    void setPrice_of_the_one_product(QString newPrice_of_the_one_product);
    const QString &getProduct_name() const;
    void setProduct_name(const QString &newProduct_name);

//    class ProductList
//    {
//    public:
////        const QString &getProduct_code() const;
////        void setProduct_code(const QString &newProduct_code);
////        int getQuantity_of_goods() const;
////        void setQuantity_of_goods(int newQuantity_of_goods);

//        class PriceList
//        {
//            int price_of_the_one_product;
//            QString product_name;

//        public:
////            int getPrice_of_the_one_product() const;
////            void setPrice_of_the_one_product(int newPrice_of_the_one_product);
////            const QString &getProduct_name() const;
////            void setProduct_name(const QString &newProduct_name);
//        };

//    private:
//       QString product_code;
//       int quantity_of_goods;


//    };

private:
    QString order_number;
    QDate order_date;
    QString requisites;
    QString product_code;
    QString quantity_of_goods;
    QString price_of_the_one_product;
    QString product_name;


    };


#endif // ORDERLIST_H
