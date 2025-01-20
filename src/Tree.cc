// #include "Tree.h"

// template<typename _Type>
// Tree<_Type>::Tree(Node<_Type> *root):root(root){}
// template<typename _Type>
// Tree<_Type>::~Tree(){}


// template<typename _Type>
// Node<_Type>* Tree<_Type>::insert(_Type key) {
//     if(root==nullptr){
//         root = new Node(key);
//         return root;
//     }
//     return __insert(key, root);
// }

// template<typename _Type>
// Node<_Type>* Tree<_Type>::__insert(_Type key, Node<_Type>*& node){
//     if (node==nullptr){
//         node = new Node<_Type>(key);
//         return node;
//     }
//     if(key>node->data) {
//         return __insert(key, node->right);
//     } else if (key<node->data) {
//         return __insert(key, node->left);
//     } else {
//         return node;
//     }
// }