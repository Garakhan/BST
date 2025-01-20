#ifndef __NODE_H__
#define __NODE_H__

#include <type_traits>
#include <cstddef>

template<typename _Type>
class Tree;

template<typename _Type, typename = std::enable_if_t<
    std::is_same_v<decltype(std::declval<_Type>() < std::declval<_Type>()), bool>
    >>
struct Node {
    _Type data;
    Node<_Type>* left;
    Node<_Type>* right;
    size_t height;
    friend class Tree<_Type>;

public:
    Node(_Type key, Node<_Type> *left=nullptr, Node<_Type> *right = nullptr);
    ~Node();
};

#include "Node.tcc"

#endif