#include "Node.hpp"
class DirectionList{
  private: 
    Node* head;
    int count; 
    Node* runToEndOfList(); 
  public:
    DirectionList();
    void addFront(string payload);
    string getIndex(int index);
    string getFront();
    string getEnd();
    int getCount();

};