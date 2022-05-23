#include "list.h"

list::list()
{
     element = new Num();
}

void list::push_back(int val)
{
   insert(size,val);

}

void list::push_front(int val)
{
    insert(2, val);
}

void list::pop_back()
{
    erase(size);
}

void list::pop_front()
{
    qDebug()<<"element = "<<getData(1);
    erase(2);

}

void list::insert(int pos, int val)
{
    shared_ptr<Num> tmp = make_shared<Num>();
    tmp->number = val;

    if (size == 0)
    {
        element->next = tmp;
        tmp->prev = tmp;
        tmp->next = tmp;
        size++;
        return;
    }
    else
    {
        shared_ptr<Num> current = element->next;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }

        tmp->next = current;
        tmp->prev = current->prev;
        (current->prev.lock())->next = tmp;
        current->prev = tmp;
        size++;
        return;

    }
}

void list::erase(int pos)
{
    if (size == 0)
    {
        return;
    }
    else
    {
        if (size == 1)
        {
            //element->next = nullptr;
            return;
        }
        else
        {
            shared_ptr<Num> deleteelem = element->next;
            for (int i = 0; i < pos; i++)
            {
                deleteelem = deleteelem->next;
            }
            (deleteelem->prev.lock())->next = deleteelem->next;
            deleteelem->next->prev = deleteelem->prev;
            size--;

        }
    }
}

int list::getSize()
{
 return size;
}

int list::getData(int pos)
{
    shared_ptr<Num> current = element->next;
    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }

    return current->number;
}

bool list::isEmpy()
{
if(getSize() == 2) return true;
else return false;
}


