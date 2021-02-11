#include "../include/DoublyLL.h"

using namespace std;

DoublyLinkedList::~DoublyLinkedList() {
    this->clear();

    delete m_head;
    delete m_tail;
}

// Push a new Node to the head of the List
void DoublyLinkedList::push_front(int data) {
    if (this->empty()) {
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
    if (this->empty()) {
        Node *node = new Node(data);

        this->setHead(node);
        this->setTail(node);
        this->m_size++;
        return;
    }

    if (!this->empty() && this->tail() == NULL) {
        Node *node = new Node(data, this->head(), NULL);

        this->head()->setNext(node);
        this->setTail(node);
        this->m_size++;
        return;  
    }

    if (!this->empty()) {
        Node *node = new Node(data, this->tail(), NULL);

        this->tail()->setNext(node);
        this->setTail(node);
        this->m_size++;
        return;
    }

     cerr << "Error in push_back()" << endl;
}


// Insert a new Node at a give position in the List
void DoublyLinkedList::insert(const int position, int data) {
    if (this->empty()) {
        this->push_front(data);
        return;
    }

    if (position > this->size()) {
        this->push_back(data);
        return;
    }

    Node *node = new Node(data);
    Node *current = this->head();
    Node *prev = NULL;
    int count = 0;

    while (count < position && current->getNext() != NULL) {
        // if (current == NULL) break;

        prev = current;
        current = current->getNext();
        count++;
    }

    node->setNext(current);
    node->setPrev(prev);

    current->setPrev(node);
    prev->setNext(node);

    this->m_size++;
}


// Pop an existing Node from the head of the List
void DoublyLinkedList::pop_front() {
    if (this->empty()) return;
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
    if (this->empty()) return;
    if (this->head() == this->tail()) {
        Node *temp = this->head();
        this->setHead(NULL);
        this->setTail(NULL);
        this->m_size--;

        delete temp;
    }

    if (!this->empty() && this->tail() != NULL) {
        Node *temp = this->tail();

        this->setTail(this->tail()->getPrev());
        this->tail()->setNext(NULL);

        delete temp;
    }
}


// Erase an existing Node from a given position in the List
void DoublyLinkedList::erase(const int position) {
    if (this->empty()) return;
    if (position < 0 || position >= this->size()) return;

    Node *prev = NULL;
    Node *current = this->head();
    int count = 0;

    while (count < position && current->getNext() != NULL) {
        prev = current;
        current = current->getNext();
        count++;
    }

    prev->setNext(current->getNext());
    current->getNext()->setPrev(prev);

    delete current;
    this->m_size--;
}


// Erase a range of existing Nodes from a given range in the List
void DoublyLinkedList::erase(const int first, const int last) {
    if (first < 0) {
         cerr << "Error: Outside of Bounds" << endl;
        return;
    }
    if (last >= this->size()) {
         cerr << "Error: Outside of Bounds" << endl;
        return;
    }
    if (first > last) {
         cerr << "Error: Imporper range. Cannot erase Nodes between: (" << first << ", " << last << ")" << endl;
        return;
    }

    Node *prev = NULL;
    Node *current = this->head();
    Node *temp = NULL;
    int count = 0;

    while (count <= last && current->getNext() != NULL) {
        if (count >= first) {
            temp = current;
            prev->setNext(current->getNext());
            current->getNext()->setPrev(prev);
            current = prev;

            delete temp;
            this->m_size--;
        }

        prev = current;
        current = current->getNext();
        count++;
    }
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
    if (this->empty()) return;

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
    if (this->empty()) {
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



