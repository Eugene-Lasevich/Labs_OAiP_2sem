#ifndef RBTREE_H
#define RBTREE_H

#include<QString>
#include<QDebug>
#include<iostream>

enum RBTColor { Black, Red };


template<class T, class ValueType>
class  RBTree
{
public:
    RBTree();
    //~RBTree();

    struct  RBTNode
    {
        std::pair<T, ValueType> pr;
        T key = pr.first;
        ValueType value = pr.second;

        RBTColor color;
        RBTNode* left = nullptr;
        RBTNode* right = nullptr;
        RBTNode* parent = nullptr;
        RBTNode(std::pair<T, ValueType> pra, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
                    key(pra.first), value(pra.second), color(c), parent(p), left(l), right(r), pr(pra) { };
    };

    bool insert(std::pair<T, ValueType>);
    bool remove(T key);
    std::pair<RBTNode*, bool> search(T key)
    {
         return search(root, key);
    }

    void inorder(std::list<RBTNode*>& arr,RBTNode* node)
    {

        inOrder(node->left);
        arr.push_back(this);
        inOrder(node->right);
    }




private:
    void leftRotate(RBTNode* &root, RBTNode* x);
    void rightRotate(RBTNode* &root, RBTNode* y);

    bool insert(RBTNode* &root, RBTNode* node);
    void InsertFixUp(RBTNode* &root, RBTNode* node);
    void destory(RBTNode* &node);

    void remove(RBTNode*& root, RBTNode*node);
    void removeFixUp(RBTNode* &root, RBTNode* node, RBTNode* parent);

    std::pair<RBTNode*, bool> search(RBTNode*node, T key)
    {
        {

            if (node == nullptr)
            {
                std::pair<RBTNode*, bool> pr;
                pr.first = nullptr;
                pr.second = false;
                return pr;
            }

            if( node->key == key)
            {
                std::pair<RBTNode*, bool> pr;
                pr.first = node;
                pr.second = true;
            }

            else
                if (key > node->key) return search(node->right, key);
                else return search(node->left, key);
        }
    }
    void inOrder(RBTNode* tree)const;

   // RBTNode<T, ValueType> minimum(RBTNode<T, ValueType>* node);
   // RBTNode<T, ValueType> maximum(RBTNode<T, ValueType>* node);


public:
    RBTNode*root;


};

//template<class T,  class ValueType>
//RBTNode RBTree<T, ValueType>::minimum(RBTNode* node)
//{
//    while(node->left != nullptr) node =node->left;
//    return node;
//}

//template<class T, class ValueType>
//RBTNode<T, ValueType> RBTree<T, ValueType>::maximum(RBTNode<T, ValueType>* node)
//{
//    while(node->right != nullptr) node = node->right;
//    return node;
//}

template<class T, class ValueType>
RBTree<T, ValueType>::RBTree() :root(nullptr)
{
    root = nullptr;
}


//template<class T, class ValueType>
//RBTree<T, ValueType>::~RBTree()
//{
//    destory(root);
//}


template<class T, class ValueType>
void RBTree<T, ValueType>::leftRotate(RBTNode* &root, RBTNode* x)
{
    RBTNode*y = x->right;
    x->right = y->left;

    if (y->left != nullptr) y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr) root = y;

    else
    {
        if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

    }

    y->left = x;
    x->parent = y;
};


template<class T, class ValueType>
void RBTree<T, ValueType>::rightRotate(RBTNode*&root, RBTNode*y)
{
    RBTNode*x = y->left;
    y->left = x->right;

    if (x->right != nullptr) x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == nullptr)root = x;

    else
    {
        if  (y == y->parent->right) y->parent->right = x;
        else y->parent->left = x;
    }

    x->right = y;
    y->parent = x;
};


template<class T, class ValueType>
bool RBTree<T, ValueType>::insert(std::pair<T, ValueType> pr)
{
    RBTNode*z = new RBTNode(pr, Red, nullptr, nullptr, nullptr);
    return insert(root, z);
};


template<class T, class ValueType>
bool RBTree<T, ValueType>::insert(RBTNode* &root, RBTNode* node)
{

    RBTNode *x = root;
    RBTNode *y = nullptr;

    while (x != nullptr)
    {
        y = x;
        if(node->key == x->key) return false;
        if (node->key > x->key) x = x->right;
        else x = x->left;

    }

    node->parent = y;
    if(y!=nullptr)
    {
        if (node->key > y->key) y->right = node;
        else y->left = node;

    }
    else root = node;

    node->color = Red;
    InsertFixUp(root, node);
    return true;
};


template<class T, class ValueType>
void RBTree<T, ValueType>::InsertFixUp(RBTNode* &root, RBTNode* node)
{
    RBTNode*parent;
    parent = node->parent;

    while (node != RBTree::root  && parent->color == Red)
    {
        RBTNode*gparent = parent->parent;
        if (gparent->left == parent)
        {
            RBTNode*uncle = gparent->right;
            if (uncle !=nullptr && uncle->color == Red)
            {
                parent->color = Black;
                uncle->color = Black;
                gparent->color = Red;
                node = gparent;
                parent = node->parent;
            }

            else
            {
                if (parent->right == node)
                {
                    leftRotate(root, parent);
                    std::swap(node, parent);
                }
                rightRotate(root, gparent);
                gparent->color = Red;
                parent->color = Black;
                break;
            }
        }

        else
        {
            RBTNode*uncle = gparent->left;
            if (uncle != nullptr && uncle->color == Red)
            {
                gparent->color = Red;
                parent->color = Black;
                uncle->color = Black;

                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->left == node)
                {
                    rightRotate(root, parent);
                    std::swap(parent, node);
                }
                leftRotate(root, gparent);
                parent->color = Black;
                gparent->color = Red;
                break;
            }
        }
    }
    root->color = Black;
}


template<class T, class ValueType>

void RBTree<T, ValueType>::destory(RBTNode* &node)
{
    //if (node == nullptr) return;

    destory(node->left);
    destory(node->right);
    delete node;
    node = nullptr;
}


template<class T, class ValueType>
bool RBTree<T, ValueType>::remove(T key)
{
    std::pair<RBTNode*, bool> pr;
    pr = search(root,key);
    RBTNode* deletenode = pr.first;

    if(pr.second)
    {

        if (deletenode != nullptr)
            remove(root, deletenode);
        return true;
    }
    else return false;
}


template<class T, class ValueType>
void RBTree<T, ValueType>::remove(RBTNode* &root, RBTNode*node)
{
    RBTNode *child, *parent;
    RBTColor color;

    if (node->left != nullptr && node->right != nullptr)
    {
        RBTNode *replace = node;

        replace = node->right;
        while (replace->left != nullptr)
        {
            replace = replace->left;
        }

        if (node->parent != nullptr)
        {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }

        else
            root = replace;

        child = replace->right;
        parent = replace->parent;
        color = replace->color;


        if (parent == node)
            parent = replace;
        else
        {

            if (child != nullptr)
                child->parent = parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        if (color == Black)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }

    if (node->left != nullptr)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child)
    {
        child->parent = parent;
    }

    if (parent)
    {
        if (node == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }

    else
        RBTree::root = child;

    if (color == Black)
    {
        removeFixUp(root, child, parent);
    }
    delete node;

}


template<class T, class ValueType>
void RBTree<T, ValueType>::removeFixUp(RBTNode* &root, RBTNode* node,RBTNode* parent)
{
    RBTNode*othernode;
    if(node == root)
    {
        root == nullptr;
        return;
    }
    while ((!node) || (node->color == Black && node != RBTree::root))
    {
        if (parent && parent->left == node)
        {
            othernode = parent->right;
            if (othernode&&othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                leftRotate(root, parent);
                othernode = parent->right;
            }
            else
            {
                if (othernode&&(!(othernode->right) || othernode->right->color == Black) && othernode->left)
                {
                    othernode->left->color=Black;
                    othernode->color = Red;
                    rightRotate(root, othernode);
                    othernode = parent->right;
                }

                if(othernode&&othernode->right)
                {
                    othernode->color = parent->color;
                    parent->color = Black;
                    othernode->right->color = Black;
                    leftRotate(root, parent);
                    node = root;
                    break;
                }
                break;
            }
        }

        else
        {
            if(parent) othernode = parent->left;
            {
                if (othernode && othernode->color == Red)
                {
                    othernode->color = Black;
                    parent->color = Red;
                    rightRotate(root, parent);
                    othernode = parent->left;
                }
            }


            bool tmp = othernode;
            if (tmp && parent&&(!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black))
            {
                othernode->color = Red;
                node = parent;
                parent = node->parent;
            }

            else
            {
                if (tmp&&(!(othernode->left) || othernode->left->color == Black))
                {
                    othernode->right->color = Black;
                    othernode->color = Red;
                    leftRotate(root, othernode);
                    othernode = parent->left;
                }
                if(tmp)
                {
                othernode->color = parent->color;
                parent->color = Black;
                othernode->left->color = Black;
                rightRotate(root, parent);
                node = root;
                break;
                }
            }
        }
    }
    if (node)
        node->color = Black;
}




//template<class T, class ValueType>
//std::pair<RBTNode*, bool> RBTree<T, ValueType>::search(T key)
//{
//    return search(root, key);
//};



//template<class T,class ValueType>
//std::pair<RBTNode*, bool> RBTree<T, ValueType>::search(RBTNode*node,T key)
//{

//    if (node == nullptr)
//    {
//        std::pair<RBTNode*, bool> pr;
//        pr.first = nullptr;
//        pr.second = false;
//        return pr;
//    }

//    if( node->key == key)
//    {
//        std::pair<RBTNode*, bool> pr;
//        pr.first = node;
//        pr.second = true;
//    }

//    else
//        if (key > node->key) return search(node->right, key);
//        else return search(node->left, key);
//}




#endif // RBTREE_H
