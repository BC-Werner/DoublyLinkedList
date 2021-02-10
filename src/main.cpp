#include "../include/DoublyLL.h"

int main() {

    DoublyLinkedList DLL;

    cout << "\n--Inserting into the List--" << endl;
    for (auto i : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) {
        DLL.push_back(i);
    }

    DLL.printList();

    cout << "\n--Inserting at a given index in the List--" << endl;
    DLL.insert(3, 50);
    DLL.insert(50, 100);

    DLL.printList();

    int index = 4;
    cout << "\nErasing the Node at index : " << index  << " :" << endl;
    DLL.erase(index);

    DLL.printList();

    int first = 3;
    int last = 5;
    cout << "\nErasing Nodes from the index : " << first << " : to : " << last << " :" << endl;
    DLL.erase(first, last);

    DLL.printList();

    first = 8;
    last = 4;
    cout << "\nErasing Nodes from the index : " << first << " : to : " << last << " :" << endl;
    DLL.erase(first, last);

    DLL.printList();

    cout << "\n--Clearing the List--" << endl;
    DLL.clear();
    DLL.printList();


    return 0;
}
