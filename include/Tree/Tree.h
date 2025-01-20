#ifndef __TREE_H__
#define __TREE_H__

#include "Node"

template <typename _Type>
struct Tree {
    Node<_Type> *root;
    Node<_Type>* __insert(_Type, Node<_Type>*&);

public:
    Tree(Node<_Type> *root=nullptr);
    ~Tree();
    Node<_Type>* insert(_Type);
};

#endif