#include "Node.h"
#include "Tree.h"
#include <iostream>
using namespace std;


/**
 *                50
 *             /     \
 *            0      100
 *          /  \        \
 *       -100  25       200
 *                        \
 *                        300
 *                          \
 *                          400
 * 
 */


/**
 *                50
 *             /       \
 *            0        200
 *          /  \      /   \
 *       -100  25    100   300
 *                          \
 *                          400
 */


int main() {
    Tree tree;
    // Node<> *root = tree.insert(50);
    // Node<> *n1 = tree.insert(0);
    // Node<> *n2 = tree.insert(-100);
    // Node<> *n3 = tree.insert(25);
    // Node<> *n4 = tree.insert(100);
    // Node<> *n5 = tree.insert(200);
    // Node<> *n6 = tree.insert(300);
    // Node<> *n7 = tree.insert(400);
    tree.insert(9);
    tree.insert(5);
    tree.insert(10);
    tree.insert(0);
    tree.insert(6);
    tree.insert(11);
    tree.insert(-1);
    tree.insert(1);
    tree.insert(2);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    tree.remove(0);
    // tree.remove(50);
    // cout<<tree.root->data<<endl;
    // cout<<tree.root->left->data<<endl;
    // cout<<tree.root->right->right->data<<endl;
    tree.print();
}