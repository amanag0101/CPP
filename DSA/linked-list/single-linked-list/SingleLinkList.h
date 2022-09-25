#include <iostream>
#include "Node.h"

namespace linkedList 
{
    template <class T>
    class SingleLinkedList {
        private:
            Node<T> *head;
            Node<T> *tail;
            unsigned long long int size;
        public:
            SingleLinkedList();
            void append(T data);
            T pop();
            void traverse();
            bool isEmpty();
            unsigned long long int getSize();
            void temp();
    };
}

template <class T>
linkedList::SingleLinkedList<T>::SingleLinkedList() 
{
    this->head = new Node<T>();
    this->tail = this->head;
    this->size = 0;
}

template <class T>
void linkedList::SingleLinkedList<T>::append(T data) 
{
    Node<T> *node = new Node(data);
    this->tail->next = node;
    this->tail = this->tail->next;
    this->size++;
}

template <class T>
T linkedList::SingleLinkedList<T>::pop() 
{
    if(isEmpty())
        throw new std::underflow_error("Linked List is empty!");

    if(this->size == 1) {
        T data = this->head->next->data;
        this->head->next = NULL;
        this->tail = this->head;
        this->size--;
        return data;
    }
    else {
        
    }

    return -1;
}

template <class T>
void linkedList::SingleLinkedList<T>::traverse() 
{
    if(!isEmpty()) 
    {
        Node<T> *ptr = this->head->next;
        while(ptr != NULL) 
        {
            std::cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

template <class T>
bool linkedList::SingleLinkedList<T>::isEmpty() 
{
    return size == 0 ? true : false;
}

template <class T>
unsigned long long int linkedList::SingleLinkedList<T>::getSize() {
    return this->size;
}

template <class T>
void linkedList::SingleLinkedList<T>::temp() 
{
    std::cout << this->tail->data;
}