#ifndef BITSET_H
#define BITSET_H

#include <map>
#include <iostream>
#include <bitset>
#include <set>
#include <unordered_map>
#include <string>
#include <intrin.h>


#include <cstring>

template<size_t size>
class bitset
{
    static const int elemSize = 8 * sizeof(unsigned long long);
    static const size_t arraySize = (size - 1) / elemSize + 1;
    unsigned long long bits[arraySize];



    struct reference
    {
        friend bitset<size>;

        bitset<size>* arr;
        size_t pos;

        reference(bitset<size>& set, size_t position)
        {
            arr = &set;
            pos = position;
        }

        reference& operator=(bool val)
        {
            unsigned long long& currentElem = arr->bits[pos / arr->elemSize], temp = 1;

            if (val)
            {
                currentElem |= (temp << (pos % arr->elemSize));
            }
            else
            {
                currentElem &= ~(temp << (pos % arr->elemSize));
            }

            return *this;
        }

        operator bool()
        {
            return arr->test(pos);
        }
    };

public:

    bitset()
    {

        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = 0;
        }
    }

    reference operator[](int pos)
    {
        return reference(*this, pos);
    }


    bitset(unsigned long long input)
    {
        for(int i = 0; i < arraySize; i++)
        {
            bits[i] = 0;
        }

        bits[0] = input;
    }

    bitset(const bitset& other)
    {

        for (int i = 0; i < other.arraySize; i++)
        {
            bits[i] = other.bits[i];
        }
    }

    bool all()
    {
        bool complited = ((size % elemSize) == 0);

        for (int i = 0; i < arraySize + complited - 1; i++)
        {
            if (bits[i] != ULLONG_MAX)
            {
                return false;
            }
        }

        unsigned long long temp = 1;

        return complited || bits[arraySize - 1] == ((!temp << (size % elemSize)) - 1);
    }

    bool any()
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (bits[i] != 0)
            {
                return true;
            }
        }

        return false;
    }

    size_t count()
    {
        size_t number = 0;
        for(int i = 0; i < arraySize * 64; i++)
        {
            number += test(i);
        }

        return number;
    }

    void flip()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = ~bits[i];
        }

        unsigned long long temp = 1;

        bits[arraySize - 1] &= ((!temp << (size % elemSize)) - 1);
    }

    void flip(int pos)
    {
        reference(*this, pos) = !test(pos);
    }

    bool none()
    {
        return !any();
    }

    void reset()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = 0;
        }
    }

    void reset(int pos)
    {
        reference(*this, pos) = 0;
    }

    void set()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = ULLONG_MAX;
        }
    }

    void set(int pos)
    {
        reference(*this, pos) = 1;
    }

    bool test(size_t pos)
    {
        unsigned long long temp = 1;

        return bits[pos / elemSize] & (temp << (pos % elemSize));
    }

    size_t getSize()
    {
        return size;
    }

    std::string to_string()
    {
        std::string out;

        for (int i = size - 1; i >= 0; i--)
        {
            out.push_back(test(i) + '0');
        }

        return out;
    }

    unsigned long to_ulong()
    {
        return static_cast<unsigned long>(bits[0]);
    }

    unsigned long long to_ullong()
    {
        return bits[0];
    }

    bitset& operator&=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] &= other.bits[i];
        }

        return *this;
    }

    bitset& operator|=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] |= other.bits[i];
        }

        return *this;
    }

    bitset& operator^=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] ^= other.bits[i];
        }

        return *this;
    }
};

#endif // BITSET_H
