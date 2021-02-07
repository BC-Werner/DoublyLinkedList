#include "../include/DoublyLL.h"

int main() {

    DoublyLinkedList DLL;

    DLL.push_front(5);
    DLL.push_front(4);
    DLL.push_back(6);
    DLL.push_back(10);

    DLL.printList();

    return 0;
}
