#include "Node.h"

class DoublyLinkedList {
    private:
        Node *m_head { NULL };
        Node *m_tail { NULL };
        int m_size { 0 };

    public:
        DoublyLinkedList()
            : m_head(NULL), m_tail(NULL), m_size(0)
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

        void setHead(Node *node);
        void setTail(Node *node);

        int size();
        bool empty();
        void clear();
        void printList();
};
