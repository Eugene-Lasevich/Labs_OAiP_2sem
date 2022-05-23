#include "mylist.h"
#include<QDebug>

MyList::MyList()
{
    first = nullptr;
    last = nullptr;
    size = 0;
   // qDebug()<<"Constructor has created"<<size;


}

void MyList::push_back(Enrollee enrollee)
{
    Node*  tmp = new Node(enrollee);

    if(first == nullptr && last == nullptr) first = last = tmp;
    else
    {
        tmp->prev = last;
        last->next = tmp;
        last =tmp;
    }
    size++;

}


Enrollee MyList::pop()
{

    Enrollee enrollee = last->enrollee;

    if (last->prev == nullptr)
    {
        first = nullptr;
        last = nullptr;
        delete first;
        delete last;
    }

    else
    {
        Node* tmp = last;
        last = last->prev;
        last->next = nullptr;
        tmp->prev = nullptr;
        delete tmp;
    }
    return enrollee;
}



Enrollee &MyList::operator[](const int index)
{

    if(index<=this->getSize()/2)
    {

    int counter = 0;
    //qDebug()<<"index int list = "<<index;
    Node *current = this->first;
    while(current != nullptr)
    {
        if(counter == index)
        {

            //current->enrollee.setName("ABOBUUU");
            return current->enrollee;
        }
        current = current->next;
        counter++;
    }

 }
    else
    {
        //qDebug()<<"index > size/ 2"<<index;
        int counter = this->getSize()-1;
        Node * current = this->last;
        while(current != nullptr)
        {
            if(counter == index) return current->enrollee;
            current = current->prev;
            counter--;
        }


    }


}



void MyList::removeAt(int index)
{
    if (index == 0)
        {
            pop_front();
        }
        else
        {

            if (index<=size/2)
            {
                Node *previous = this->first;
                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->next;
                }
                Node *toDelete = previous->next;
                previous->next = toDelete->next;
                delete toDelete;
            }
            else
            {
                Node *tmp = this->last;
                for (int i=size-1; i>index; i--)
                    tmp=tmp->prev;
                Node *toDelete = tmp->prev;
                tmp->prev = toDelete->prev;
                delete toDelete;
            }

            //delete toDelete;

            size--;
        }
}

void MyList::pop_front()
{
    Node *tmp = first;

    first = first->next;

    delete tmp;

    size--;
}


int MyList::getSize() const
{
    return size;
}










