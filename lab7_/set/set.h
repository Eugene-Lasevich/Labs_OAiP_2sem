#ifndef SET_H
#define SET_H
#include"rbtree.h"
#include<QDebug>

template<class keyType>
class set
{
    RBTree<keyType> tree;
    int sz = 0;

public:
    bool insert(keyType input)
    {

        if(tree.insert(input))
        {
            sz++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool erase(keyType key)
    {

        if(tree.remove(key))
        {
            sz--;
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return sz;
    }



    struct list_iterator
    {
        RBTree<keyType> tree;
        std::list<typename RBTree<keyType>::RBTNode*> list;
        typename std::list<typename RBTree<keyType>::RBTNode*>::iterator it;

        list_iterator(RBTree<keyType> otherTree, bool begin)
        {
            tree = otherTree;

            tree.root->inorder(list,tree.root);

            if (begin)
            {
                it = list.begin();

                typename RBTree<keyType>::RBTNode* temp = nullptr;
                list.push_back(temp);
            }
            else
            {
                typename RBTree<keyType>::RBTNode* temp = nullptr;

                list.push_back(temp);

                it = list.end();
                it--;
            }
        }

        list_iterator& operator++()
        {
            it++;

            return *this;
        }

        list_iterator& operator--()
        {
            it--;

            return *this;
        }

        bool operator==(const list_iterator& other)
        {
            return *it == *(other.it);
        }

        bool operator!=(const list_iterator& other)
        {
            return !(*this == other);
        }

        keyType* operator->()
        {
            return &((*it)->pr);
        }
    };

    list_iterator lbegin()
    {
        return list_iterator(tree, 1);
    }

    list_iterator lend()
    {
        return list_iterator(tree, 0);
    }


    struct iterator
    {
        typename RBTree<keyType>::RBTNode* node = nullptr;
        RBTree<keyType> tree;

        iterator() {}

        iterator(const iterator& iter)
        {
            node = iter.node;
            tree = iter.tree;
        }

        iterator(typename RBTree<keyType>::RBTNode* other,RBTree<keyType> otherTree)
        {
            node = other;
            tree = otherTree;
        }

        iterator& operator++()
        {
            typename RBTree<keyType>::RBTNode* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (temp == node)
            {
                node = nullptr;

                return *this;
            }

            if (node->right != nullptr)
            {
                node = node->right;

                while (node->left)
                {
                    node = node->left;
                }
            }
            else
            {

                while (node->parent->key < node->key)
                {

                    node = node->parent;
                }

                node = node->parent;
            }

            return *this;
        }

        iterator& operator--()
        {
            typename RBTree<keyType>::RBTNode* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (node == nullptr)
            {
                node = temp;

                return *this;
            }

            if (node->left != nullptr)
            {
                node = node->left;

                while (node->right)
                {
                    node = node->right;
                }
            }
            else
            {

                while (node->parent->key > node->key)
                {
                    node = node->parent;
                }
            }
        }

        bool operator==(const iterator& other)
        {
            return other.node == node;
        }

        bool operator!=(const iterator& other)
        {
            return !(*this == other);
        }

        keyType operator*()
        {
            return node->key;
        }

        keyType* operator->()
        {
            return &(node->key);
        }
    };

    iterator begin()
    {
        typename RBTree<keyType>::RBTNode* temp = tree.root;

        if (!temp)
        {
            return iterator(temp, tree);
        }

        while (temp->left)
        {
            temp = temp->left;
        }

        return iterator(temp, tree);
    }

    iterator end()
    {
        typename RBTree<keyType>::RBTNode* temp = nullptr;
        return iterator(temp, tree);
    }

    std::pair<iterator, bool> search(keyType key)
    {
        typename RBTree<keyType>::RBTNode* temp = tree.search(key).first;
        bool tmp = tree.search(key).second;

        std::pair<iterator, bool> pr;
        pr.first = iterator(temp,tree);
        pr.second = tmp;
        return pr;
    }


};

#endif // SET_H
