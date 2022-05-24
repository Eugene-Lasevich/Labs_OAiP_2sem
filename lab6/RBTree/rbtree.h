#ifndef RBTREE_H
#define RBTREE_H

#include<QString>
#include<QDebug>
#include<iostream>

enum RBTColor { Black, Red };

template<class KeyType>
struct  RBTNode
{
    std::pair<int,QString> pr;
    int key = pr.first;
    QString value = pr.second;

    RBTColor color;
    RBTNode<KeyType> * left = nullptr;
    RBTNode<KeyType> * right = nullptr;
    RBTNode<KeyType> * parent = nullptr;
    RBTNode( std::pair<int,QString> pr, RBTColor c, RBTNode* p, RBTNode*l, RBTNode*r) :
        key(pr.first),value(pr.second), color(c), parent(p), left(l), right(r) { };
};

template<class T>
class  RBTree
{
public:
    RBTree();
    ~RBTree();

    bool insert(std::pair<int, QString>);
    bool remove(T key);
    std::pair<RBTNode<T>*, bool> search(T key);



private:
    void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
    void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);

    bool insert(RBTNode<T>* &root, RBTNode<T>* node);
    void InsertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
    void destory(RBTNode<T>* &node);

    void remove(RBTNode<T>*& root, RBTNode<T>*node);
    void removeFixUp(RBTNode<T>* &root, RBTNode<T>* node, RBTNode<T>*parent);

    std::pair<RBTNode<T>*, bool> search(RBTNode<T>*node, T key);
    void preOrder(RBTNode<T>* tree)const;
    void inOrder(RBTNode<T>* tree)const;
    void postOrder(RBTNode<T>* tree)const;

    RBTNode<T> minimum(RBTNode<T>* node);
    RBTNode<T> maximum(RBTNode<T>* node);


public:
    RBTNode<T>*root;
};


template<class T>
RBTNode<T> RBTree<T>::minimum(RBTNode<T>* node)
{
    while(node->left != nullptr) node =node->left;
    return node;
}

template<class T>
RBTNode<T> RBTree<T>::maximum(RBTNode<T>* node)
{
    while(node->right != nullptr) node = node->right;
    return node;
}

template<class T>
RBTree<T>::RBTree() :root(nullptr)
{
    root = nullptr;
}


template<class T>
RBTree<T>::~RBTree()
{
    destory(root);
}


template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
    RBTNode<T>*y = x->right;
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


template<class T>
void RBTree<T>::rightRotate(RBTNode<T>*&root, RBTNode<T>*y)
{
    RBTNode<T>*x = y->left;
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


template<class T>
bool RBTree<T>::insert(std::pair<int, QString> pr)
{
    RBTNode<T>*z = new RBTNode<T>(pr, Red, nullptr, nullptr, nullptr);
    return insert(root, z);
};


template<class T>
bool RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T> *x = root;
    RBTNode<T> *y = nullptr;

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


template<class T>
void RBTree<T>::InsertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
    RBTNode<T>*parent;
    parent = node->parent;

    while (node != RBTree::root  && parent->color == Red)
    {
        RBTNode<T>*gparent = parent->parent;
        if (gparent->left == parent)
        {
            RBTNode<T>*uncle = gparent->right;
            if (uncle != NULL && uncle->color == Red)
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
            RBTNode<T>*uncle = gparent->left;
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


template<class T>

void RBTree<T>::destory(RBTNode<T>* &node)
{
    if (node == nullptr) return;

    destory(node->left);
    destory(node->right);
    delete node;
    node = nullptr;
}


template<class T>
bool RBTree<T>::remove(T key)
{
    std::pair<RBTNode<T>*, bool> pr;
    pr = search(root,key);
    RBTNode<T>*deletenode = pr.first;

    if(pr.second)
    {

        if (deletenode != nullptr)
            remove(root, deletenode);
        return true;
    }
    else return false;
}


template<class T>
void RBTree<T>::remove(RBTNode<T>*&root, RBTNode<T>*node)
{
    RBTNode<T> *child, *parent;
    RBTColor color;

    if (node->left != nullptr && node->right != nullptr)
    {
        RBTNode<T> *replace = node;

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


template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>* &root, RBTNode<T>* node,RBTNode<T>*parent)
{
    RBTNode<T>*othernode;
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




template<class T>
 std::pair<RBTNode<T>*, bool> RBTree<T>::search(T key)
 {
     return search(root, key);
 };



 template<class T>
 std::pair<RBTNode<T>*, bool> RBTree<T>::search(RBTNode<T>*node,T key)
{

 if (node == nullptr)
 {
     std::pair<RBTNode<T>*, bool> pr;
     pr.first = nullptr;
     pr.second = false;
     return pr;
 }

 if( node->key == key)
 {
     std::pair<RBTNode<T>*, bool> pr;
     pr.first = node;
     pr.second = true;
 }

 else
 if (key > node->key) return search(node->right, key);
 else return search(node->left, key);
}







#endif // RBTREE_H
