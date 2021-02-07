#include <iostream>

using namespace std;

class Node {
    private:
        int m_data { 0 };
        Node *m_prev { NULL };
        Node *m_next { NULL };


    public:
        // Constructor with member initializer list
        Node(int data, Node *prev = NULL, Node *next = NULL) 
            : m_data(data), m_prev(prev), m_next(next) 
        {}

        // Getters and Setters
        int getData() { return m_data; };
        Node* getPrev() { return m_prev; };
        Node* getNext() { return m_next; };

        void setData(int data) { m_data = data; };
        void setPrev(Node *prev) { m_prev = prev; };
        void setNext(Node *next) { m_next = next; };
}
