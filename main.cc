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

int main() {
    Tree tree;
    Node<> *root = tree.insert(50);
    Node<> *n1 = tree.insert(0);
    Node<> *n2 = tree.insert(-100);
    Node<> *n3 = tree.insert(25);
    Node<> *n4 = tree.insert(100);
    Node<> *n5 = tree.insert(200);
    Node<> *n6 = tree.insert(300);
    Node<> *n7 = tree.insert(400);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<tree.root->getKey()<<endl;
    cout<<tree.root->left->data<<endl;
    cout<<tree.root->right->data<<endl;
    cout<<tree.root->right->right->data<<endl;
    cout<<tree.root->right->right->right->right->getKey()<<endl;
    // cout<<tree.root->left->left->data<<endl;
    tree.print();
}