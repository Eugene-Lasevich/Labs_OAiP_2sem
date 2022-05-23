#ifndef MYSTACK_H
#define MYSTACK_H
#include<QChar>

class myStack
{
public:
    myStack();
    void push(const QChar& x);
    bool empty() const;
    const QChar& top()const;
    QChar pop();
    ~myStack();
private:
    struct Node
    {
        QChar data;
        Node * next;
    };
    Node* root;

};

#endif // MYSTACK_H
