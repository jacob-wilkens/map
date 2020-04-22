#include "DirectionList.hpp"
#include <iostream>

DirectionList::DirectionList()
{
    this->count = 0;
}
void DirectionList::addFront(string payload)
{
    Node* n = new Node(payload);

    //if list is currently empty
    if(!this->head) 
    {
        this->head = n;
    }
    else //list has at least 1 thing in it
    {
        n->setNextNode(this->head);
        this->head = n;
    }
    this->count++;
}
string DirectionList::getIndex(int index)
{
    if(index == 0)
    {
        return this->getFront();
    }
    else if(index == this->count-1)
    {
        return this->getEnd();
    }
    else
    {
        Node* currNode = this->head; 
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}
string DirectionList::getEnd()
{
    Node* currNode = this->runToEndOfList();
    //currnode points to the end of the list
    return currNode->getPayload();
}
Node* DirectionList::runToEndOfList()
{
    Node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;
}
string DirectionList::getFront(){
    return this->head->getPayload();
}
int DirectionList::getCount(){
    return this->count;
}