#ifndef MYLIST_H
#define MYLIST_H

template<class T>
class MyList
{
    int len = 0;
    int size =0 ;
    int next[50];
    T arr[50];
public:
    T& find(int pos)
    {
        int cur = next[0];

        for(int i = 0; i < pos; i++)
        {
            cur = next[cur];
        }

        return arr[cur - 1];
    }

    void add(T input)
    {
        next[len] = len + 1;
        arr[len] = input;
        len++;
        size++;
    }

    void del(int pos)
    {
        int current = next[0];

        for(int i = 0; i < pos; i++)
        {
            current = next[current];
        }

        next[current - 1]++;
        size--;
    }

    T& operator[](int i )
    {
        return find(i);
    }

    int getSize() const
    {
        return size;
    }

    MyList() {}
};

#endif // MYLIST_H
