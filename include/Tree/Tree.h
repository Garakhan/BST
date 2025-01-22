#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"
#include <iostream>

template <typename _Type = int >
struct Tree {
    typedef Node<_Type> Node_t;
    Node_t *root;
    Node_t* __insert(_Type, Node_t*&);
    void destruct(Node_t*);
    void __print(Node_t*);
    int updateHeight(Node_t*);
    /**
     * @brief Update individual node balance
     * Calculates by subtracting height of right child from left child
     * @param node Node to be calculated
     * @return <0 if left-heavy, >0 if right-heavy, 0 if perfectly balanced.
     */
    int updateBalance(Node_t*);
    /**
     * @brief Rotate subtree at the given root node anti-clockwise
     * It should make the current node child of its child.
     * Example
     *              Z
     *             / \
     *            T1  Y
     *               / \
     *              T2  T3
     * where Z and Y are individual nodes, T1, T2, and T3 are subtrees.
     * Argument to function must be Node(Z).
     * After the rotation to left, the new structure should be
     *              Y
     *             / \
     *            Z   T3
     *           / \
     *          T1  T2
     * @param node Root of the subtree to be rotated (Node Z in the example above).
     * @return The new root of the rotated subtree (Node Y in this example)
     */
    Node_t* rotateLeft(Node_t*);
    /**
     * @brief Rotate subtree at the given root node clockwise
     * It should make the current node child of its child.
     * Examaple
     *              Z
     *             / \
     *            Y   T3
     *           / \
     *          T1  T2
     * where Z and Y are individual nodes, T1, T2 and T3 are subtrees.
     * Argument to function must be Node(Z).
     * After rotation to right, the new structure should be
     *              Y
     *             / \
     *            T1  Z
     *               / \
     *              T2  T3
     * @param node Root of the subtree to be rotated (Node Z in the example above).
     * @return The new root of the rotated subtree (Node Y in this example)
     */
    Node_t* rotateRight(Node_t*);
    Node_t* getNodeByKey(_Type, Node_t*);

public:
    Tree(Node_t *root=nullptr);
    ~Tree();
    Node_t* insert(_Type);
    Node_t* remove(_Type);
    void print();
};

#include "Tree.tcc"

#endif