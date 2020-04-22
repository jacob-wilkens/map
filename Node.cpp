#include "Node.hpp"

Node::Node(string payload)
{
    this->payload = payload;
}

string Node::getPayload()
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