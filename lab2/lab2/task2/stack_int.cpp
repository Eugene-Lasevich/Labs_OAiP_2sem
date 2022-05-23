#include "stack_int.h"

Stack_int::Stack_int()
{
    root = nullptr;
}

void Stack_int::push(const int &x)
{
    size++;
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = root;
    root = newnode;
}

bool Stack_int::empty() const
{
     return root == nullptr;
}

const int &Stack_int::top() const
{
    if (empty())
    {

    }
    return root->data;
}

int Stack_int::pop()
{
    if (empty())
    {

    }
    size--;
    Node * delnode = root;
    int x = delnode->data;
    root = delnode->next;
    delete delnode;
    return x;
}

Stack_int::~Stack_int()
{
    while (!empty())
    {
        pop(); //некоторая проблема - из-за неоптимальной реализации pop прозводится лишнее копирование
    }
}

