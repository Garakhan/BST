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
            curr->left = rotateLeft(curr->left);
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
    // if (node!=nullptr && node->data==200) {
    //     std::cout<<"Height: "<<node->height<<std::endl;
    // }
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
Node<_Type>* Tree<_Type>::__remove(_Type key, Node_t* node){
    Node_t* curr = node;
    if(node==nullptr){
        std::cerr<<"Key not in tree. Aborting __remove."<<std::endl;
        // return;
        return root;
    }
    // removing leaf node
    if (node->left!=nullptr && key<node->data) {
        node->left = __remove(key, node->left);
    } else if (node->right!=nullptr && key>node->data) {
        node->right = __remove(key, node->right);
    }
    else {
        // __remove leaf node
        if(node->left==nullptr && node->right==nullptr){
            delete node;
            node = nullptr;
        // __remove node has only right child
        } else if(node->left==nullptr && node->right!=nullptr){
            node=node->right;
            delete curr;
        // __remove node has only left child
        } else if(node->left!=nullptr && node->right==nullptr){
            node=node->left;
            delete curr;
        // node has two children
        } else {
            _Type maxVal = __findMax(node->right);
            node->data = maxVal;
            node->right = __remove(maxVal, node->right);
        }
    }
    updateHeight(node);
    updateBalance(node);
    if (node!=nullptr && node->balance==2){
        if (updateBalance(node->right)==-1){//nullptr case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        } else {
            return rotateLeft(node);
        }
    } else if (node!=nullptr && node->balance==-2) {
        if (updateBalance(node->left)==1){ //nullptr case
            node->left = rotateLeft(node->right);
            return rotateRight(node);
        } else {
            return rotateRight(node);
        }
    }
    // if (node!=nullptr){
    //     std::cout<<"- "<<node->data<<std::endl;
    // } else {
    //     std::cout<<"- "<<"NULL"<<std::endl;
    // }
    return node;
}

template<typename _Type>
Node<_Type>* Tree<_Type>::remove(_Type key){
    root = __remove(key, root);
    return root;
}

template<typename _Type>
_Type Tree<_Type>::__findMax(Node_t* node){
    if (node->left==nullptr){
        return node->data;
    }
    return __findMax(node->left);
}

#undef __TYPEALIAS_