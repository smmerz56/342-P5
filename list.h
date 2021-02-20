#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#ifndef LIST_H
#define LIST_H

#include "transaction.h"
//----------------------------------------------------------------------------
// ADT List:A collection of Transaction objects. A limited functionality List
//
// Assumptions:
//    -- The user will only be using Transaction objects.
//    -- Making the memory for the data is up to the user.
//----------------------------------------------------------------------------
class List
{
 
private:   
   // the nodes which make up the list
   struct Node {
      Transaction* data;
      Node* next;
   };
   Node* head;
  
   public:
   // constructors and destructor
   List(); 
   ~List();

   void insert(Transaction* dataPtr);
   void display()const;
   void displayHelper(int) const;  

   bool isEmpty() const;
   void makeEmpty();

};

#endif