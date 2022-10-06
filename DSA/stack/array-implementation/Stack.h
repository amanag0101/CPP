#include <iostream>
#include <cstdlib>

template <class T>
class Stack 
{
    private:
        T *arr;
        unsigned long long int topIndex;
        unsigned long long int size;
        unsigned long long int allocatedSize;
    public:
        Stack(unsigned long long int aloccatedSize);
        void push(T element);
        T pop();
        T peek();
        unsigned long long int getSize();
        bool isFull();
        bool isEmpty();
};

// Constructor
template <class T>
Stack<T>::Stack(unsigned long long int allocatedSize) 
{
    arr = (T *) malloc(allocatedSize);
    this->allocatedSize = allocatedSize;
    this->size = 0;
    this->topIndex = -1;
}

// Push function
template <class T>
void Stack<T>::push(T element)
{
    if(isFull())
        throw std::overflow_error("Stack is full!");
    else {
        this->arr[this->size++] = element;
        this->topIndex++;
    }
}

// Pop function
template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
        throw std::underflow_error("Stack is empty!");
    else {
        this->size--;
        return this->arr[this->topIndex--];
    }
}

// Peek function
template <class T>
T Stack<T>::peek() 
{
    if(!isEmpty())
        return this->arr[this->topIndex];
    else 
        throw std::underflow_error("Stack is empty!");
}

// Returns the size of the stack
template <class T>
unsigned long long int Stack<T>::getSize() 
{
    return this->size;
}

// isEmpty function
template <class T>
bool Stack<T>::isEmpty() 
{
    return this->size == 0 ? true : false;
}

// isFull function
template <class T>
bool Stack<T>::isFull() 
{
    return this->allocatedSize == this->size ? true : false;
}