#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"
#include <iostream>

template <typename _Type = int >
struct Tree {
    Node<_Type> *root;
    Node<_Type>* __insert(_Type, Node<_Type>*&);
    void destruct(Node<_Type>*);
    void __print(Node<_Type>*);
    void updateHeight(Node<_Type>*);

public:
    Tree(Node<_Type> *root=nullptr);
    ~Tree();
    Node<_Type>* insert(_Type);
    void print();
};

#include "Tree.tcc"

#endif