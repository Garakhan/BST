template<typename _Type, typename _Enable>
    Node<_Type, _Enable>::Node(_Type key,
                                Node<_Type> *left,
                                Node<_Type> *right):
                                        data(key), left(left), right(right)
    {
        height = 0;
    }

template <typename _Type, typename _Enable>
    Node<_Type, _Enable>::~Node() {
        // std::cout<<"Node["<<data<<"] deleted."<<std::endl;
    }