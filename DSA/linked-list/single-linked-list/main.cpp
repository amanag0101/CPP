#include "SingleLinkList.h"

using namespace std;
using namespace linkedList;

int main() {
    SingleLinkedList<int> ll;
    
    ll.append(10);
    
    cout << ll.pop() << endl;

    ll.append(20);
    ll.append(30);
    ll.append(40);
    ll.append(50);
    
    ll.traverse();

    cout << "\nSize: " << ll.getSize();
    
    return 0;
}