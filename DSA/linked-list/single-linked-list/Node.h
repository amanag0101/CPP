#include <iostream>

namespace linkedList 
{
    template <class T>
    class Node 
    {
        public:
            T data;
            Node *next;

            Node();
            Node(T data);
    };
}

template <class T>
linkedList::Node<T>::Node() 
{
    this->next = NULL;
}

template <class T>
linkedList::Node<T>::Node(T data) 
{
    this->data = data;
    this->next = NULL;
}