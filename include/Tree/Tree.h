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
    int updateHeight(Node<_Type>*);
    /**
     * @brief Update individual node balance
     * Calculates by subtracting height of right child from left child
     * @param node Node to be calculated
     * @return <0 if left-heavy, >0 if right-heavy, 0 if perfectly balanced.
     */
    int updateBalance(Node<_Type>*);
    /**
     * @brief Rotate subtree at the given root node anti-clockwise
     * It should make the current node parent of its parent.
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
     * Since the nodes contain pointer to their parent nodes,
     * no additional arguments needed.
     * @param node Root of the subtree to be rotated (Node Z in the example above).
     * @return The new root of the rotated subtree (Node Y in this example)
     */
    Node<_Type>* rotateLeft(Node<_Type>*);
    /**
     * @brief Rotate subtree at the given root node clockwise
     * It should make the current node parent of its parent.
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
     * Since the nodes contain pointer to their parent nodes,
     * no additional arguments needed.
     * @param node Root of the subtree to be rotated (Node Z in the example above).
     * @return The new root of the rotated subtree (Node Y in this example)
     */
    Node<_Type>* rotateRight(Node<_Type>*);

public:
    Tree(Node<_Type> *root=nullptr);
    ~Tree();
    Node<_Type>* insert(_Type);
    void print();
};

#include "Tree.tcc"

#endif