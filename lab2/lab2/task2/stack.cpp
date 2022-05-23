#include "stack.h"



//template<typename T>
//Stack<T>::Stack()
//{
// root = nullptr;
//}

//template<typename T>
//void Stack<T>::push(const T &x)
//{
//    Node* newnode = new Node;
//    newnode->data = x;
//    newnode->next = root;
//    root = newnode;
//}

//template<typename T>
//bool Stack<T>::empty() const
//{
//    return root == nullptr;
//}

//template<typename T>
//const T &Stack<T>::top() const
//{
//    if (empty())
//    {
//       qDebug()<<"BLSBLSB";
//    }
//    return root->data;
//}

//template<typename T>
//T Stack<T>::pop()
//{
//    if (empty())
//    {
//        qDebug()<<"BLABLABLa";
//    }
//    Node * delnode = root;
//    T x = delnode->data;
//    root = delnode->next;
//    delete delnode;
//    return x;
//}

//template<typename T>
//Stack<T>::~Stack()
//{
//    while (!empty())
//    {
//        pop(); //некоторая проблема - из-за неоптимальной реализации pop прозводится лишнее копирование
//    }
//}



Stack::Stack()
{
    root = nullptr;
}

void Stack::push(const QChar &x)
{
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = root;
    root = newnode;
}

bool Stack::empty() const
{
     return root == nullptr;
}

const QChar &Stack::top() const
{
    if (empty())
    {
        qDebug()<<"BLSBLSB";
    }
    return root->data;
}

QChar Stack::pop()
{
    if (empty())
    {
        qDebug()<<"BLABLABLa";
    }
    Node * delnode = root;
    QChar x = delnode->data;
    root = delnode->next;
    delete delnode;
    return x;
}

Stack::~Stack()
{
    while (!empty())
    {
        pop(); //некоторая проблема - из-за неоптимальной реализации pop прозводится лишнее копирование
    }
}
