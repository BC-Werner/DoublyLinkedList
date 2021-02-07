#include "../include/DoublyLL.h"

DoublyLinkedList::~DoublyLinkedList() {

}

// Push a new Node to the head of the List
void DoublyLinkedList::push_front(int data) {
    if (this->head() == NULL) {
        Node *node = new Node(data);
        this->setHead(node);
        this->setTail(node);
        this->m_size++;
    } else {
        Node *node = new Node(data, NULL, this->head());
        this->setHead(node);
        this->m_size++;
    }
}


// Push a new Node to the tail of the List
void DoublyLinkedList::push_back(int data) {
    if (this->head() == NULL && this->tail() == NULL) {
        Node *node = new Node(data);

        this->setHead(node);
        this->setTail(node);
        this->m_size++;
        return;
    }

    if (this->head() != NULL && this->tail() == NULL) {
        Node *node = new Node(data, this->head(), NULL);

        this->head()->setNext(node);
        this->setTail(node);
        this->m_size++;
        return;  
    }

    if (this->head() != NULL && this->tail() != NULL) {
        Node *node = new Node(data, this->tail(), NULL);

        this->tail()->setNext(node);
        this->setTail(node);
        this->m_size++;
        return;
    }

    cout << "Error in push_back()" << endl;
}


// Insert a new Node at a give position in the List
void DoublyLinkedList::insert(const int position, int data) {

}


// Pop an existing Node from the head of the List
void DoublyLinkedList::pop_front() {
    if (this->head() == NULL) return;
    if (this->head() == this->tail()) {

        Node *temp = this->head();
        this->setHead(NULL);
        this->setTail(NULL);
        this->m_size--;

        delete temp;
    } else {

        Node *temp = this->head();
        this->setHead(this->head()->getNext());
        this->m_size--;

        delete temp;
    }
}


// Pop an existing Node from the tail of the List
void DoublyLinkedList::pop_back() {
    if (this->head() == NULL) return;
    if (this->head() == this->tail()) {
        Node *temp = this->head();
        this->setHead(NULL);
        this->setTail(NULL);
        this->m_size--;

        delete temp;
    }

    if (this->head() != NULL && this->tail() != NULL) {
        Node *temp = this->tail();

        this->setTail(this->tail()->getPrev());
        this->tail()->setNext(NULL);

        delete temp;
    }
}


// Erase an existing Node from a given position in the List
void DoublyLinkedList::erase(const int position) {

}


// Erase a range of existing Nodes from a given range in the List
void DoublyLinkedList::erase(const int first, const int last) {

}


// Return the Head of the List
Node* DoublyLinkedList::head() {
    return this->m_head;
}


// Return the tail of the List
Node* DoublyLinkedList::tail() {
    return this->m_tail;
}


// Set the head of the List
void DoublyLinkedList::setHead(Node *node) {
    this->m_head = node;
}


// Set the tail of the List
void DoublyLinkedList::setTail(Node *node) {
    this->m_tail = node;
}


// Return the size of the List
int DoublyLinkedList::size() {
    return this->m_size;
}


// Return if the List is empty
bool DoublyLinkedList::empty() {
    return this->head() == NULL;
}


// Clear the List
void DoublyLinkedList::clear() {
    if (this->head() == NULL) return;

    Node *prev = NULL; 
    Node *current = this->head();

    while (current != NULL ) {
        prev = current;
        current = current->getNext();

        delete prev;
        this->m_size--;
    }

    this->setHead(NULL);
    this->setTail(NULL);
    delete current;
    this->m_size--;
}


// Print the List
void DoublyLinkedList::printList() {
    if (this->head() == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    cout << "{- ";

    Node *current = this->head();
    while (current != NULL) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << "-}" << endl;
}



