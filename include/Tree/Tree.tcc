// #include "Tree.h"

template<typename _Type>
Tree<_Type>::Tree(Node<_Type> *root):root(root) {}

template<typename _Type>
Tree<_Type>::~Tree(){
    destruct(root);
}

template<typename _Type>
void Tree<_Type>::destruct(Node<_Type> *node) {
    if (node==nullptr) {
        return;
    }
    if (node->left!=nullptr) {
        destruct(node->left);
    }
    if (node->right!=nullptr) {
        destruct(node->right);
    }
    delete node;
    node=nullptr;
}


template<typename _Type>
Node<_Type>* Tree<_Type>::insert(_Type key){
    if (root==nullptr){
        root = new Node<_Type>(key);
        return root;
    }
    return __insert(key, root);
}


template<typename _Type>
Node<_Type> *Tree<_Type>::__insert(_Type key, Node<_Type>*& node){
    if (node==nullptr){
        node = new Node<_Type>(key);
        return node;
    }
    if (key<node->data) {
        return __insert(key, node->left);
    } else if (key>node->data) {
        return __insert(key, node->right);
    } else {
        return node;
    }
}

template<typename _Type>
void Tree<_Type>::__print(Node<_Type> *node) {
    if (node==nullptr) {
        return;
    }
    __print(node->left);
    __print(node->right);
    std::cout<<"Node["<<node->data<<"]"<<std::endl;
}

template<typename _Type>
void Tree<_Type>::print() {
    __print(root);
}
