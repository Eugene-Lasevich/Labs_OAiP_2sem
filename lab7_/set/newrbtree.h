#ifndef NEWRBTREE_H
#define NEWRBTREE_H
#include<QString>
#include<QDebug>


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

    void insert(std::pair<int, QString>);
    bool remove(T key);
    std::pair<RBTNode<T>*, bool> search(T key);


private:
    void leftRotate(RBTNode<T>* x);
    void rightRotate(RBTNode<T>* y);

    void insert(RBTNode<T>* node);
    void InsertFixUp(RBTNode<T>* node);
    void destroy(RBTNode<T>* node);


    void remove(RBTNode<T>*node);
    void removeFixUp(RBTNode<T>* node);

    std::pair<RBTNode<T>*, bool> search(RBTNode<T>*node, T key);

    void preOrder(RBTNode<T>* tree)const;
    void inOrder(RBTNode<T>* tree)const;
    void postOrder(RBTNode<T>* tree)const;

    void rbTransplant(RBTNode<T>* u, RBTNode<T> * v);
    RBTNode<T>* minimum(RBTNode<T>* node);
    RBTNode<T>* maximum(RBTNode<T>* node);


public:
    RBTNode<T>*root;
    RBTNode<T>*nil = nullptr;
};


template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* node)
{
    while(node->left != nullptr) node =node->left;
    return node;
}

template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* node)
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
RBTree<T>::~RBTree<T>()
{
    destroy(root);
}


template<class T>
void RBTree<T>::destroy(RBTNode<T> *node)
{
    if (node == nullptr) return;

    destroy(node->left);
    destroy(node->right);
    delete node;
    node = nullptr;
}

template<class T>
void RBTree<T>::leftRotate( RBTNode<T>* x)
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
void RBTree<T>::rightRotate( RBTNode<T>*y)
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
void RBTree<T>::insert(std::pair<int, QString> pr)
{
    RBTNode<T>*z = new RBTNode<T>(pr, Red, nullptr, nullptr, nullptr);
    insert(z);
};

template<class T>
void RBTree<T>::insert(RBTNode<T>* node)
{
    RBTNode<T>* y = this->nil;
    RBTNode<T>* x = this->root;

    while(x != this->nil)
    {
        y = x;
        if(node->key < x->key) x = x->left;
        else x  = x->right;
    }

    node->parent = y;

    if(y == this->nil) this->root = node;
    else if(node->key < y->key) y->left = node;
    else y->right = node;

    node->left = this->nil;
    node->right = this->nil;
    node->color = Red;
    InsertFixUp(node);
}

template<class T>
void RBTree<T>::InsertFixUp(RBTNode<T>* node)
{
    while (node != root && node->parent->color == Red)
    {
        if (node->parent == node->parent->parent->left)
        {
            RBTNode<T>* y = node->parent->parent->right;
            if (y && y->color == Red)
            {
                node->parent->color = Black;
                y->color = Black;
                node->parent->parent->color = Red;
                node = node->parent->parent;
            }

            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }

                node->parent->color = Black;
                node->parent->parent->color = Red;
                rightRotate(node->parent->parent);
            }
        }

        else
        {
            RBTNode<T>* y = node->parent->parent->left;
            if (y && y->color == Red)
            {
                node->parent->color = Black;
                y->color = Black;
                node->parent->parent->color = Red;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }

                node->parent->color = Black;
                node->parent->parent->color = Red;
                leftRotate(node->parent->parent);
            }
        }
    }
    this->root->color = Black;
}


template<class T>
void RBTree<T>:: rbTransplant(RBTNode<T>* u, RBTNode<T>* v)
{
        if (u->parent == nullptr) root= v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;

        if(v) v->parent = u->parent;
}


template<class T>
std::pair<RBTNode<T>*, bool>RBTree<T>::search(T key)
{
return search(root, key);
}


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


template<class T>
bool RBTree<T>::remove(T key)
{
    std::pair<RBTNode<T>*, bool> pr;
    pr = search(root,key);
    RBTNode<T>*deletenode = pr.first;

    if(pr.second)
    {

        if (deletenode != nullptr)
            remove( deletenode);
        return true;
    }
    else return false;
}

template<class T>
void RBTree<T>::remove(RBTNode<T>*node)
{
    RBTNode<T>* y = node;
    RBTNode<T>* x = nil;
    RBTColor colorNode = y->color;

    if(node->left == nil)
    {
        x = node->right;
        this->rbTransplant(node, node->right);
    }

    else if(node->right == nil)
    {
        x = node->left;
        this->rbTransplant(node, node->left);
    }

    else
    {
        y = this->minimum(node->right);
        colorNode = y->color;
        x = y->right;
        qDebug()<<"X = "<<x;

        if(y->parent == node)
            x->parent = y;


        else
        {
            this->rbTransplant(y,y->right);
            y->right = node->right;
            y->right->parent = y;
        }

        this->rbTransplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;


    }

    if(colorNode == Black) this->removeFixUp(x);

//    RBTNode<T> *child, *parent;
//    RBTColor color;
//    // Левый и правый узлы удаленного узла не пусты (не конечные узлы)
//    if (node->left != nullptr && node->right != nullptr)
//    {
//        RBTNode<T> *replace = node;
//        // Найти узел-преемник (самый нижний левый узел правого поддерева текущего узла)
//        replace = node->right;
//        while (replace->left != nullptr)
//        {
//            replace = replace->left;
//        }
//        // Случай, когда удаленный узел не является корневым узлом
//        if (node->parent != nullptr)
//        {
//            if (node->parent->left == node)
//                node->parent->left = replace;
//            else
//                node->parent->right = replace;
//        }
//        // Ситуация с корневым узлом
//        else
//            root = replace;
//        // child - это правильный узел, который заменяет узел и является узлом, который требует последующей корректировки
//        // Поскольку замена является преемником, он не может иметь левого дочернего узла
//        // Аналогично, у узла-предшественника не может быть правого дочернего узла
//        child = replace->right;
//        parent = replace->parent;
//        color = replace->color;

//        // Удаленный узел является родительским узлом замещающего узла (repalce)
//        if (parent == node)
//            parent = replace;
//        else
//        {
//            // Существование дочернего узла
//            if (child != nullptr)
//                child->parent = parent;
//            parent->left = child;

//            replace->right = node->right;
//            node->right->parent = replace;
//        }
//        replace->parent = node->parent;
//        replace->color = node->color;
//        replace->left = node->left;
//        node->left->parent = replace;
//        if (color == Black)
//            removeFixUp(child);

//        delete node;
//        return;
//    }
//    // Когда в удаленном узле только левый (правый) узел пуст, найдите дочерний узел удаленного узла
//    if (node->left != nullptr)
//        child = node->left;
//    else
//        child = node->right;

//    parent = node->parent;
//    color = node->color;
//    if (child)
//    {
//        child->parent = parent;
//    }
//    // Удаленный узел не является корневым узлом
//    if (parent)
//    {
//        if (node == parent->left)
//            parent->left = child;
//        else
//            parent->right = child;
//    }
//    // Удаленный узел является корневым узлом
//    else
//        RBTree::root = child;

//    if (color == Black)
//    {
//        removeFixUp(child);
//    }
//    delete node;
}


template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>*node)
{
    if (!node) return;
    while (node != root && node->color == Black)
    {
        if (node == node->parent->left)
        {
            RBTNode<T>* w = node->parent->right;
            if (w->color == Red)
            {
                w->color = Black;
                node->parent->color = Red;
                leftRotate(node->parent);
                w = node->parent->right;
            }
            if (w->left->color == Black && w->right->color == Black)
            {
                w->color = Red;
                node = node->parent;
            }
            else {
                if (w->right->color == Black)
                {
                    w->left->color = Black;
                    w->color = Red;
                    rightRotate(w);
                    w = node->parent->right;
                }
                w->color = node->parent->color;
                node->parent->color = Black;
                w->right->color = Black;
                leftRotate(node->parent);
                node = root;
            }
        }
        else
        {
            RBTNode<T>* w = node->parent->left;
            if (w->color == Red)
            {
                w->color = Black;
                node->parent->color = Red;
                rightRotate(node->parent);
                w = node->parent->left;
            }

            if (w->right->color == Black && w->left->color == Black)
            {
                w->color = Red;
                node = node->parent;
            }
            else
            {
                if (w->left->color == Black)
                {
                    w->right->color = Black;
                    w->color = Red;
                    leftRotate(w);
                    w = node->parent->left;
                }
                w->color = node->parent->color;
                node->parent->color = Black;
                w->left->color = Black;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    node->color = Black;
}

#endif // NEWRBTREE_H
