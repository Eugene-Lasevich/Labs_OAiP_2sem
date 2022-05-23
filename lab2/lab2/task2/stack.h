#ifndef STACK_H
#define STACK_H
#include<QDebug>

//template <typename T>
class Stack
{
public:
  Stack();
  void push(const QChar& x);
  bool empty() const;
  const QChar& top()const;
  QChar pop();
  ~Stack() ;

private:
  struct Node
  {
      QChar data;
      Node * next;
  };
  Node* root;
};

#endif // STACK_H
