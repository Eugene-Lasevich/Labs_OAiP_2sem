#ifndef STACK_INT_H
#define STACK_INT_H


class Stack_int
{
public:
  Stack_int();
  void push(const int& x);
  bool empty() const;
  const int& top()const;
  int pop();
  ~Stack_int() ;
  int size = 0;

private:
  struct Node
  {
      int data;
      Node * next;
  };
  Node* root;
};

#endif // STACK_INT_H
