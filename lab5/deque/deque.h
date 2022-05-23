#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#define BUFFER_SIZE 10
using namespace std;

template<class T>
class Deque
{
    size_t get_buf()
    { return BUFFER_SIZE; }

    size_t size = 0;
    size_t cap = 0;

    T** cont = nullptr;
    T* begin = nullptr;
    T* end = nullptr;

public:

    class Iterator
    {
    public:

        Iterator() { }

        Iterator(Deque<T>* deque, T* elem, size_t cur, int ind_of_map):
            deque(deque), elem(elem), cur(cur), ind_of_map(ind_of_map) { }

        T& operator* ()
        { return *elem; }

        Iterator operator+(int n) const
        {
          Iterator tmp = *this;
          return tmp += n;
        }

        Iterator operator-(int n) const
        {
          Iterator tmp = *this;
          return tmp -= n;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++*this;
            return temp;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --*this;
            return temp;
        }

        void operator++ ()
        {
            bool el = false;
            for (int i = 0; i < deque->size; i++)
            {
                if (&(*deque)[i] == elem)
                {
                    el = true;
                    break;
                }
            }
            if (!el)
            {
                elem = deque->begin;
                cur = 0;
                ind_of_map = 0;
                return;
            }
            if (elem == &(*deque)[deque->size - 1])
            {
                elem = deque->begin;
                cur = 0;
                ind_of_map = 0;
                return;
            }
            if (elem == &(deque->cont[ind_of_map][deque->get_buf()-1]))
            {
                ind_of_map++;
                cur++;
                elem = &(deque->cont[ind_of_map][0]);
            }
            else
            {
                cur++;
                elem++;
            }
        }

        void operator-- ()
        {
            bool el = false;
            for (int i = 0; i < deque->size; i++)
            {
                if (&(*deque)[i] == elem)
                {
                    el = true;
                    break;
                }
            }
            if (!el)
            {
                elem = deque->begin;
                cur = 0;
                ind_of_map = 0;
                return;
            }
            if (elem == deque->begin)
            {
                ind_of_map = deque->cap / 10 - 1;
                elem = &((*deque)[deque->size - 1]);
                cur = deque->size - 1;
                return;
            }
            if (elem == &(deque->cont[ind_of_map][0]))
            {
                ind_of_map--;
                cur--;
                elem = &(deque->cont[ind_of_map][9]);
            }
            else
            {
                cur--;
                elem--;
            }
        }

        Deque<T>* deque = nullptr;
        T* elem = nullptr;
        size_t cur;
        size_t ind_of_map;
    };

    Deque()
    {
        cont = new T* [1];
        cont[0] = new T[get_buf()];
        begin = &cont[0][1];
        end = &cont[0][2];
        cap = get_buf();
    }

    ~Deque()
    {
        for (size_t i = 0; i < size; i++)
        {
            this->pop_back();
        }
    }

    void push_front(const T& input)
    {
        if (begin == &cont[0][0])
        {
            cap += get_buf();
            T** newcont = new T* [cap / get_buf()];
            for (size_t i = 1; i < cap / get_buf(); i++)
            {
                newcont[i] = std::move(cont[i - 1]);
            }
            newcont[0] = new T[get_buf()];
            newcont[0][get_buf()-1] = input;
            begin = &newcont[0][get_buf()-1];
            size++;
            cont = newcont;
        }
        else
        {
            begin--;
            *begin = input;
            size++;
        }
    }

    void push_back(const T& input)
    {
        if (end == &cont[cap / get_buf() - 1][get_buf()-1])
        {
            cap += get_buf();
            T** newcont = new T* [cap / get_buf()];
            for (size_t i  = 0; i < cap / get_buf() - 1; i++)
            {
                newcont[i] = std::move(cont[i]);
            }
            newcont[cap / get_buf() - 1] = new T[get_buf()];
            newcont[cap / get_buf() - 2][get_buf()-2] = input;
            end = &newcont[cap / get_buf() - 1][0];
            size++;
            cont = newcont;
        }
        else if (end == &cont[cap / get_buf() - 1][0])
        {
            cont[cap / get_buf() - 2][get_buf()-1] = input;
            end++;
            size++;
        }
        else
        {
            *(end - 1) = input;
            end++;
            size++;
        }
    }

    void pop_front()
    {
        if (begin == &cont[0][get_buf()-1])
        {
            begin->~T();
            begin = &cont[1][0];
            cap -= get_buf();
            T** newcont = new T* [cap / get_buf()];
            for (size_t i = 0; i < cap / get_buf(); i++)
            {
                newcont[i] = std::move(cont[i + 1]);
            }
            delete[] cont[0];
            cont = newcont;
            size--;
        }
        else
        {
            begin->~T();
            begin++;
            size--;
        }
    }

    Iterator begin_()
    {
        return Iterator(this, begin, 0, 0);
    }

    void pop_back()
    {
        if (end == &cont[cap / get_buf() - 1][0])
        {
            cap -= get_buf();
            T** newcont = new T* [cap / get_buf()];
            for (size_t i = 0; i < cap / get_buf(); i++)
            {
                newcont[i] = std::move(cont[i]);
            }
            end = &cont[cap / get_buf() - 1][get_buf() - 1];
            end->~T();
            delete[] cont[cap / get_buf() ];
            cont = newcont;
            size--;
        }
        else
        {
            end--;
            end->~T();
            size--;
        }
    }

    T& front()
    {
        return this->operator[](0);
    }

    T& back()
    {
        return this->operator[](size-1);
    }

    T& operator[] (size_t ind)
    {
        T* temp;
        if(ind < size / 2)
        {
            temp = begin;
            for (size_t i = 0, j = 0; i < ind; i++)
            {
                if (temp == &cont[j][get_buf()-1])
                {
                    j++;
                    temp = &cont[j][get_buf()-1];
                }
                else
                {
                    temp++;
                }
            }
        }
        else
        {
            temp = end;
            for (size_t i = 0, j = cap / get_buf() - 1; i < size - ind + 1; i++)
            {
                if (temp == &cont[j][0])
                {
                    j--;
                    temp = &cont[j][get_buf()-1];
                }
                else
                {
                    temp--;
                }
            }
        }
        return *temp;
    }

    void clear()
    {
        this->~Deque();
        *this = Deque();
    }

    int size_()
    {
        return size;
    }

    bool empty()
    {
        return !size;
    }
};

#endif // DEQUE_H
