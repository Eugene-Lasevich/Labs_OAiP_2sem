#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QPair>
#include <QStack>
#include<QDebug>

class HashTable
{
public:

    HashTable()
    {

        table = new QStack<QPair<int, QString>>*[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    virtual ~HashTable()
    {
        for (int i = 0; i < size; ++i)
        {
            if(table[i])
                delete table[i];
        }
        delete[] table;
    }

    bool get(const int& key, QString& value)
    {
        int hash = CalculateHash(key);

        QStack<QPair<int, QString>> temp;
        if(table[hash])
            temp = *table[hash];
        else
            return false;

        while (temp.size())
        {
            if (temp.top().first == key)
            {
                value = temp.top().second;
                return true;
            }
            temp.pop();
        }
        return false;
    }

    bool put(const int& key, const QString& value)
    {
        int hash = CalculateHash(key);

        if(!table[hash])
        {
            table[hash] = new QStack<QPair<int, QString>>;
        }
        else
        {
            QStack<QPair<int,QString>> stack = *table[hash];

            while(stack.size())
            {
                if(stack.top().first==key)
                {
                    return false;
                }
                stack.pop();
            }
        }

        table[hash]->push(QPair<int, QString>(key, value));

        return true;
    }

    bool remove(const int& key)
    {
        bool a = false;

        int hash = CalculateHash(key);

        QStack<QPair<int, QString>> temp;
        if(table[hash])
            temp = *table[hash];
        else
            return a;

        while (temp.size())
        {
            if (temp.top().first == key)
            {
                a = true;
            }
            temp.pop();
        }

        temp = *table[hash];
        if(a)
        {
            delete table[hash];
            table[hash] = new QStack<QPair<int, QString>>;
            while (temp.size())
            {
                if (temp.top().first != key)
                {
                    table[hash]->push(temp.top());
                }
                temp.pop();
            }
        }
        return a;
    }

    QStack<QPair<int, QString>>* operator[] (const int& index)
    {
        return table[index];
    }

    int get_size()
    {
        return size;
    }

    int CalculateHash(int key)
    {
        if(key < 0)
            key = -key;
        double temp = key * v;
        temp = temp - int(temp);
        return (int(this->size * temp) % size);
    }

private:

    int size = 20;
    QStack<QPair<int, QString>>** table;
    const double v = 0.618033;

};

#endif // HASHTABLE_H
