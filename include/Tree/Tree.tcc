// #include "Tree.h"
#define BREAKPOINT std::cout<<"==>BREAK<=="<<std::endl
#define __TYPEALIAS_
#ifdef __TYPEALIAS_
template<typename _Type>
using Node_t =  Node<_Type>;
#endif

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
    root = __insert(key, root);
    return root;
}


template<typename _Type>
Node<_Type>* Tree<_Type>::__insert(_Type key, Node<_Type>*& node){
    Node<_Type> *curr = node;
    if (node==nullptr){
        node = new Node<_Type>(key);
        curr = node;
        return curr;
    }
    else if (key<node->data) {
        curr->left = __insert(key, node->left);
    } else if (key>node->data) {
        curr->right = __insert(key, node->right);
    } else {
        return node;
    }
    updateHeight(curr);
    updateBalance(curr);
    if (curr->balance==2){
        if (updateBalance(curr->right)==-1){//nullptr case
            curr->right = rotateRight(curr->right);
            return rotateLeft(curr);
        } else {
            return rotateLeft(curr);
        }
    } else if (curr->balance==-2) {
        if (updateBalance(curr->left)==1){ //nullptr case
            curr->left = rotateLeft(curr->right);
            return rotateRight(curr);
        } else {
            return rotateRight(curr);
        }
    }
    return curr;
}


template<typename _Type>
void Tree<_Type>::__print(Node<_Type> *node) {
    if (node==nullptr) {
        return;
    }
    __print(node->left);
    __print(node->right);
    std::cout<<"Node["<<node->data<<"], height: "<<node->height<<", balance: "<<node->balance<<std::endl;
}

template<typename _Type>
void Tree<_Type>::print() {
    __print(root);
}

template<typename _Type>
int Tree<_Type>::updateHeight(Node<_Type>* node) {
    if(node==nullptr){
        return 0;
    }
    int left=-1, right=-1;
    if (node->left!=nullptr){
        left = node->left->height;
    }
    if (node->right!=nullptr){
        right = node->right->height;
    }
    node->height = std::max(left, right)+1;
    return node->height;
}


template<typename _Type>
int Tree<_Type>::updateBalance(Node<_Type>* node){
    if(node==nullptr){
        return 0;
    }
    int left=-1;
    int right=-1;
    if (node->left!=nullptr){
        left = node->left->height;
    }
    if (node->right!=nullptr){
        right = node->right->height;
    }
    node->balance = right-left;
    return node->balance;
}



template<typename _Type>
Node<_Type>* Tree<_Type>::rotateLeft(Node<_Type>* node){
    if(node==nullptr) {
        return node;
    }
    Node<_Type> *right = node->right;
    Node<_Type> *rleft = right->left;

    right->left = node;
    node->right = rleft;

    updateHeight(node);
    updateHeight(right);
    updateBalance(node);
    updateBalance(right);
    return right;
}


template<typename _Type>
Node<_Type>* Tree<_Type>::rotateRight(Node<_Type>* node){
    if(node==nullptr) {
        return node;
    }
    Node<_Type> *left = node->left;
    Node<_Type> *lright = left->right;

    left->right = node;
    node->left = lright;
    updateHeight(node);
    updateHeight(left);
    updateBalance(node);
    updateBalance(left);
    return left;
}


template<typename _Type>
Node<_Type>* Tree<_Type>::getNodeByKey(_Type key, Node<_Type>* node){
    if (key==node->data){
        return node;
    } else if (key<node->data){
        return getNodebyKey(key, node->left);
    } else if (key>node->data){
        return getNodeByKey(key, node->right);
    } else {
        return nullptr;
    }
}


template<typename _Type>
Node_t* Tree<_Type>::remove(_Type key){
    Node<_Type>* node = getNodeByKey(key, root);
    if(node==nullptr){
        std::cerr<<"Key not in tree. Aborting remove."<<std::endl;
        // return;
    }
    
}

#undef __TYPEALIAS_