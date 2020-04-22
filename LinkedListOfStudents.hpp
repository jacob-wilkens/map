#ifndef LinkedListOfStudents_hpp
#define LinkedListOfStudents_hpp
#include "Student.hpp"
#include "StudentNode.hpp"

class Student;
class StudentNode;
using namespace std;
class LinkedListOfStudents
{
    private: 
        StudentNode* head;
        int count;

    public:
        LinkedListOfStudents();
        void addFront(Student* s);
        Student* getAtIndex(int index);
        Student* removeAtIndex(int index);
        int indexOf(Student* s); //returns index or -1 if not found
        void display();
        void removeFront();
        };

#endif