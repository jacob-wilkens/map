#include "LinkedListOfStudents.hpp"
#include <iostream>
using namespace std;

LinkedListOfStudents::LinkedListOfStudents()
{
    this->head = 0;
    this->count = 0;
}

void LinkedListOfStudents::addFront(Student* s)
{
    StudentNode* sn = new StudentNode(s);
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

Student* LinkedListOfStudents::getAtIndex(int index)
{
    //if they give us a bad index, return null
    if(index > this->count-1 || index < 0)
    {
        return 0;
    }
    else
    {
        StudentNode* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}

Student* LinkedListOfStudents::removeAtIndex(int index)
{
    //is the list empty or is index out of range?
    if(!this->head || index < 0 || index > this->count - 1)
    {
        return 0;
    }
    else
    {
        Student* studentToReturn = 0;

        if(index == 0)
        {
            //remove from front
            studentToReturn = this->head->getPayload();
            this->head = this->head->getNextNode();
        }
        else if(index == this->count - 1)
        {
            //remove from the end
            StudentNode* currNode = this->head;
            //positions currNode to the guy before the last guy
            for(int i = 0; i < this->count-1; i++)
            {
                currNode = currNode->getNextNode();
            }
            studentToReturn = currNode->getNextNode()->getPayload();
            StudentNode* nodeToDelete = currNode->getNextNode();
            currNode->setNextNode(0);
            delete nodeToDelete;
        }
        else
        {
            //remove from the middle
            //write code here
        }
        return studentToReturn;
    }
    
}

int LinkedListOfStudents::indexOf(Student* s)
{
    StudentNode* currNode = this->head;
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
void LinkedListOfStudents::display(){
    StudentNode* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        cout << currNode->getPayload()->getName() << " ";
        currNode = currNode->getNextNode();
    }
}
void LinkedListOfStudents::removeFront(){
    StudentNode* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    delete nodeToReturn;
    this->count--;
}