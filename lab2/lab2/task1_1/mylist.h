#ifndef MYLIST_H
#define MYLIST_H
#include"enrollee.h"


class MyList
{
public:
    MyList();

    void push_back(Enrollee enrollee);
    Enrollee pop();
    Enrollee &operator[](const int index);

    void removeAt(int index);
    void pop_front();
    Enrollee change(int index);
    int getSize() const;

private:
    struct Node
    {
        Enrollee enrollee;
        Node* next;
        Node* prev;
        Node(Enrollee enrollee) : enrollee(enrollee), next(nullptr), prev(nullptr){}
        Node(){}
    };
    Node* first;
    Node* last;
    int size =0 ;
};


#endif // MYLIST_H
