#include "../include/DoublyLL.h"

int main() {

    DoublyLinkedList DLL;

    DLL.push_front(5);
    DLL.push_front(4);
    DLL.push_front(3);
    DLL.push_front(2);
    DLL.push_front(1);
    DLL.push_front(0);
    DLL.push_back(6);
    DLL.push_back(7);
    DLL.push_back(8);
    DLL.pop_front();

    DLL.printList();

    return 0;
}
