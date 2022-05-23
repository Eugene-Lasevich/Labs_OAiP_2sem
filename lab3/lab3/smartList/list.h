#ifndef LIST_H
#define LIST_H
#include"smart_pointers.h"
#include<QDebug>


class list
{
private:
    struct Num
    {
        int number;
        shared_ptr<Num> next;
        weak_ptr<Num> prev;
        Num(int number) : number (number){}
        Num(){}
    };
    Num *element;
    int size = 0;

public:
    list();
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    void insert(int pos, int val);
    void erase(int pos);
    int getSize();
    int getData(int pos);
    bool isEmpy();


};

#endif // LIST_H
