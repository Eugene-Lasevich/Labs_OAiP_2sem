#include "stack_double.h"

Stack_double::Stack_double()
{
    root = nullptr;
}

void Stack_double::push(const double &x)
{
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = root;
    root = newnode;
}

bool Stack_double::empty() const
{
     return root == nullptr;
}

const double &Stack_double::top() const
{
    return root->data;
}

double Stack_double::pop()
{
    Node * delnode = root;
    double x = delnode->data;
    root = delnode->next;
    delete delnode;
    return x;
}

Stack_double::~Stack_double()
{
    while (!empty())
    {
        pop(); //некоторая проблема - из-за неоптимальной реализации pop прозводится лишнее копирование
    }
}
