#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <forward_list>
#include <list>
#include <unordered_map>

template<class keyType, class valueType, class hash = std::hash<keyType>>
class unordered_map
{

    std::list<std::pair<keyType, valueType>> pairList;
    std::forward_list<std::pair<keyType, valueType>>* hashTable = nullptr;
    int sz = 0;
    int cap = 100;
    double maxFillFactor = 0.6;
    double numberBucket = 0.0;

public:

    unordered_map()
    {
        hashTable = new std::forward_list<std::pair<keyType, valueType>>[100];
    }

    void insert(std::pair<keyType, valueType> input)
    {
        if (contains(input.first))
        {
            return;
        }

        if (numberBucket / cap >= maxFillFactor)
        {
            this->rehash(cap * 2);
        }

        if (hashTable[hash{}(input.first) % cap].empty())
        {
            numberBucket++;
        }

        hashTable[hash{}(input.first) % cap].push_front(input);

        pairList.push_back(input);
        sz++;
    }

    void erase(const keyType& key)
    {
        int keyHash = hash{}(key) % cap;

        typename std::forward_list<std::pair<keyType, valueType>>::iterator it = hashTable[keyHash].begin();
        typename std::forward_list<std::pair<keyType, valueType>>::iterator itSpare = hashTable[keyHash].begin();


        for (int i = 0; it != hashTable[keyHash].end(); it++, i++)
        {
            if(i != 0)
            {
                itSpare++;
            }

            if (key == it->first)
            {
                if(i == 0)
                {
                    hashTable[keyHash].pop_front();
                }
                else
                {
                    hashTable[keyHash].erase_after(itSpare);
                }


                pairList.remove(std::make_pair(key, (*(this->find(key))).second));

                if (hashTable[keyHash].empty())
                {
                    numberBucket--;
                }

                sz--;

                break;
            }
        }
    }

    bool contains(keyType key)
    {
        int keyHash = hash{}(key) % cap;

        typename std::forward_list<std::pair<keyType, valueType>>::iterator it = hashTable[keyHash].begin();

        for (; it != hashTable[keyHash].end(); it++)
        {
            if (key == it->first)
            {
                return true;
            }
        }

        return false;
    }

    struct iterator
    {
        typename std::list<std::pair<keyType, valueType>>::iterator it;

        iterator(typename std::list<std::pair<keyType, valueType>>::iterator iter)
        {
            it = iter;
        }

        bool operator==(const iterator& other)
        {
            return it == other.it;
        }

        bool operator!=(const iterator& other)
        {
            return it != other.it;
        }


        iterator& operator++()
        {
            it++;

            return *this;
        }

        iterator& operator--()
        {
            it--;

            return *this;
        }

        std::pair<keyType, valueType>* operator->()
        {
            return &(*it);
        }

        std::pair<keyType, valueType> operator*()
        {
            return *it;
        }
    };

    iterator begin()
    {
        return iterator(pairList.begin());
    }

    iterator end()
    {
        return iterator(pairList.end());
    }

    int size()
    {
        return sz;
    }

    iterator find(keyType key)
    {
        typename std::list<std::pair<keyType, valueType>>::iterator it = pairList.begin();

        for (; it != pairList.end(); it++)
        {
            if (it->first == key)
            {
                return iterator(it);
            }
        }

        return iterator(it);
    }

    void rehash(const int newCap)
    {
        std::forward_list<std::pair<keyType, valueType>>* newHashTable = new std::forward_list<std::pair<keyType, valueType>>[newCap];

        iterator oldIt = begin();

        for (; oldIt != end(); ++oldIt)
        {
            newHashTable[hash{}(oldIt->first) % newCap].push_front(*oldIt);
        }

        cap = newCap;
        hashTable = newHashTable;
    }

    valueType& operator[](keyType key)
    {
        iterator it = this->find(key);

        if (it == end())
        {
            this->insert(std::make_pair(key, valueType()));

            return this->find(key)->second;
        }
        else
        {
            return it->second;
        }
    }

    int getCap()
    {
        return cap;
    }
};

#endif // UNORDEREDMAP_H
