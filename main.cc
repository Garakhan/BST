#include "Node.h"
#include "Tree.h"
#include <iostream>
using namespace std;

int main() {
    Tree tree;
    tree.insert(8);
    tree.insert(9);
    // cout<<tree.root->data<<endl;
    tree.print();
}