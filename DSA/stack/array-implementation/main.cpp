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
                int element;
                cout << "Enter value: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                cout << "Popped element: " << stack.pop() << endl;
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                cout << "Size: " << stack.getSize() << endl;
                break;
            case 5:
                cout << "isEmpty: " << stack.isEmpty() << endl;
                break;
            case 6:
                cout << "isFull: " << stack.isFull() << endl;
                break;
            default:
                cout << "Invalid option! \n";
        }
    }

    return 0;
}