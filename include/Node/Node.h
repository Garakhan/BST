#ifndef __NODE_H__
#define __NODE_H__

#include <type_traits>
#include <cstddef>
#include <iostream>

template<typename _Type>
class Tree;

template<typename _Type = int, typename = std::enable_if_t<
    std::is_same_v<decltype(std::declval<_Type>() < std::declval<_Type>()), bool>
    >>
struct Node {
    _Type data;
    Node<_Type>* left;
    Node<_Type>* right;
    int height;
    int balance;
    friend class Tree<_Type>;

public:
    int getKey();
    Node<_Type>* getLeft();
    Node<_Type>* getRight();
    Node(_Type key, Node<_Type> *left=nullptr, Node<_Type> *right = nullptr);
    ~Node();
};

#include "Node.tcc"

#endif