#include "mystack.h"

myStack::myStack()
{
    root = nullptr;
}

void myStack::push(const QChar &x)
{
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = root;
    root = newnode;
}

bool myStack::empty() const
{
    return root == nullptr;
}

const QChar &myStack::top() const
{

    return root->data;
}

QChar myStack::pop()
{

    Node * delnode = root;
    QChar x = delnode->data;
    root = delnode->next;
    delete delnode;
    return x;
}

myStack::~myStack()
{
    while (!empty())
    {
        pop(); //некоторая проблема - из-за неоптимальной реализации pop прозводится лишнее копирование
    }
}
