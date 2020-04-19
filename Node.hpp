class Student;
#ifndef Node_hpp
#define Node_hpp
#include<iostream>
#include "Student.hpp"
using namespace std;

class Node
{
    public:
        Node(Student* payload);
        Student* getPayload();
        Node* getNextNode();
        void setNextNode(Node* n);

    private:
        Student* payload;
        Node* nextNode;

};
#endif