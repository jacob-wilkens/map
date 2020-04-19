#include "Queue.hpp"

Queue::Queue()
{
    this->head = 0;
    this->tail = 0;
    this->count = 0;
}

bool Queue::isEmpty()
{
    return this->count == 0;
}

void Queue::display()
{
    Node* currNode = this->head;
    while(currNode)
    {
        cout << currNode->getPayload() << " ";
        currNode = currNode->getNextNode();
    }
    cout << "\n";
}

void Queue::enqueue(Student* payload)
{
    Node* n = new Node(payload);
    if(this->tail)
    {
        this->tail->setNextNode(n);
        this->tail = n;
    }
    else
    {
        this->head = n;
        this->tail = n;
    }
    this->count++;
}

Student* Queue::dequeue()
{
    if(this->head)
    {
        Node* temp = this->head;
        this->head = this->head->getNextNode();
        Student* val2Return = temp->getPayload();
        delete temp;
        this->count--;
        return val2Return;
    }
    else
    {
        return 0; //this should never happen!!!!  Throw an exception
    }
    
}

int Queue::getCount()
{
    return this->count;
}