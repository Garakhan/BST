template<typename _Type, typename _Enable>
    Node<_Type, _Enable>::Node(_Type key,
                                Node<_Type> *left,
                                Node<_Type> *right):
                                        data(key), left(left), right(right)
    {
        height = 0;
        balance = 0;
    }

template <typename _Type, typename _Enable>
    Node<_Type, _Enable>::~Node() {
        // std::cout<<"Node["<<data<<"] deleted."<<std::endl;
    }


template<typename _Type, typename _Enable>
int Node<_Type, _Enable>::getKey() {
    if (this==nullptr){
        std::cerr<<"Node is nullptr."<<std::endl;
        return -1;
    }
    return data;
}

template<typename _Type, typename _Enable>
Node<_Type>* Node<_Type, _Enable>::getLeft() {
    return left;
}

template<typename _Type, typename _Enable>
Node<_Type>* Node<_Type, _Enable>::getRight() {
    return right;
}