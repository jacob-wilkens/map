#include "Node.hpp"

Node::Node(Student* payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

Student* Node::getPayload()
{
    return this->payload;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}