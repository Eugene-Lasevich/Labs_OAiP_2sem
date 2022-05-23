#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H



class Stack_double
{
public:
    Stack_double();
    void push(const double& x);
    bool empty() const;
    const double& top()const;
    double pop();
    ~Stack_double();
private:
    struct Node
    {
        double data;
        Node * next;
    };
    Node* root;
};

#endif // STACK_DOUBLE_H
