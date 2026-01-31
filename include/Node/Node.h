#ifndef _NODE_H_
#define _NODE_H_

#include <memory>
template <typename Type>
class Node {
    Type data;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

public:
    Node(Type value, Node* left = nullptr, Node* right = nullptr);
    ~Node();
    Type get_data() const noexcept;
};

#include "Node.tcc"

#endif // _NODE_H_
