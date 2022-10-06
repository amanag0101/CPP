#include <iostream>
#include "Stack.h"

using namespace std;

int main() 
{
    unsigned long long int size = 0;

    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack = Stack<int>(size);

    while(true) 
    {
        int option = 0;

        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Size\n";
        cout << "5. Is Empty ?\n";
        cout << "6. Is Full ?\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        
        cin >> option;

        switch(option) 
        {
            case 0:
                exit(0);
            case 1:
                try
                {
                    int element;
                    cout << "Enter value: ";
                    cin >> element;
                    stack.push(element);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 2:
                try
                {
                    cout << "Popped element: " << stack.pop() << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                
                break;
            case 3:
                try
                {
                    cout << "Top element: " << stack.peek() << endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 4:
                cout << "Size: " << stack.getSize() << endl;
                break;
            case 5:
                stack.isEmpty()
                    ? cout << "Yes!\n"
                    : cout << "No!\n";
                break;
            case 6:
                stack.isFull()
                    ? cout << "Yes!\n"
                    : cout << "No!\n";
                break;
            default:
                cout << "Invalid option! \n";
        }
    }

    return 0;
}