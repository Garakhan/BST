#include "Node.h"

#include <iostream>
#include <utility>

template <typename Type>
Node<Type>::Node(Type value, Node* left, Node* right) : data(value), left(nullptr), right(nullptr) {
    if (left) {
        this->left = std::make_unique<Node<Type>>(*left);
    }
    if (right) {
        this->right = std::make_unique<Node<Type>>(*right);
    }
}

template <typename Type>
Node<Type>::~Node() {
    std::cout << "Node with value " << data << " is destroyed." << std::endl;
}

template <typename Type>
Type Node<Type>::get_data() const noexcept {
    // Return the data stored in the node
    // The Node is already initialized and data is set in the constructor
    return data;
}
