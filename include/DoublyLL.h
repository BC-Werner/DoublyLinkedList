#include "Node.h"

class DoublyLinkedList {
    private:
        Node *m_head { NULL };
        Node *m_tail { NULL };

    public:
        DoublyLinkedList()
            : m_head(NULL), m_tail(NULL)
        {}

        ~DoublyLinkedList();

        void push_front(int data);
        void push_back(int data);
        void insert(const int position, int data);
        void pop_front();
        void pop_back();
        void erase(const int position);
        void erase(const int first, const int last);

        Node* head();
        Node* tail();
        Node* back();
        Node* next();

        int size();
        bool empty();
        void clear();
        void printList();
}
