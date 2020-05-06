#include "LinkedListOfItems.hpp"
#include <iostream>
using namespace std;

LinkedListOfItems::LinkedListOfItems()
{
    this->head = 0;
    this->count = 0;
}

void LinkedListOfItems::addFront(Item* s)
{
    ItemNode* sn = new ItemNode(s);
    if(!this->head)
    {
        this->head = sn;
    }
    else
    {
        sn->setNextNode(this->head);
        this->head = sn;
    }
    this->count++;
}

Item* LinkedListOfItems::getAtIndex(int index)
{
    //if they give us a bad index, return null
    if(index > this->count-1 || index < 0)
    {
        return 0;
    }
    else
    {
        ItemNode* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}

Item* LinkedListOfItems::removeAtIndex(int index)
{
    //is the list empty or is index out of range?
    if(!this->head || index < 0 || index > this->count - 1)
    {
        return 0;
    }
    else
    {
        Item* studentToReturn = 0;

        if(index == 0)
        {
            //remove from front
            studentToReturn = this->head->getPayload();
            this->head = this->head->getNextNode();
        }
        else if(index == this->count - 1)
        {
            //remove from the end
            ItemNode* currNode = this->head;
            //positions currNode to the guy before the last guy
            for(int i = 0; i < this->count-2; i++)
            {
                currNode = currNode->getNextNode();
            }
            studentToReturn = currNode->getNextNode()->getPayload();
            ItemNode* nodeToDelete = currNode->getNextNode();
            currNode->setNextNode(0);
            delete nodeToDelete;
        }
        else
        {
            //remove from the middle
            ItemNode* currNode = this->head;
            for(int i = 0; i < index-1; i++)
            {
                currNode = currNode->getNextNode();
            }
            studentToReturn = currNode->getNextNode()->getPayload();
            ItemNode* nodeToDelete = currNode->getNextNode();
            currNode->setNextNode(nodeToDelete->getNextNode());
            nodeToDelete->setNextNode(0);
            delete nodeToDelete;
        }
        this->count--;
        return studentToReturn;
    }

    
}

int LinkedListOfItems::indexOf(Item* s)
{
    ItemNode* currNode = this->head;
    if(currNode->getPayload() == s){
        return 0;
    } else {
        for(int i = 1; i < this->count; i++){
            currNode = currNode->getNextNode();
            if(currNode->getPayload() == s){
                return i;
            }
        }
        return -1;
    }

}
void LinkedListOfItems::display(){
    ItemNode* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload()->getName() << " ";
        currNode = currNode->getNextNode();
    }
}
void LinkedListOfItems::removeFront(){
    ItemNode* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    delete nodeToReturn;
    this->count--;
}
int LinkedListOfItems::getCount(){
    return this->count;
}
int LinkedListOfItems::findIndexByName(string name){
    ItemNode* currNode = this->head;
    for(int i = 0; i < this->count; i++){
        if(currNode->getPayload()->getName() == name){
            return i;
        } else {
            currNode = currNode->getNextNode();
        }
    }
    return -1;

}