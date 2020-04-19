class Node;
#ifndef Queue_hpp
#define Queue_hpp
#include "Node.hpp"
class Queue
{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        Queue();
        void enqueue(Student* payload);
        Student* dequeue();
        void display();
        int getCount();
        bool isEmpty();
        
};
#endif