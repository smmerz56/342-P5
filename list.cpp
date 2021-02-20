#include "list.h"
#include <iostream>

#include <iomanip>
#include <fstream>
using namespace std;
//----------------------------------------------------------------------------
// Constructor
// this sets the head node of the newly created list to null
List::List()      
{
   head = nullptr;  
}

//----------------------------------------------------------------------------
// Destructor
// calls makeEmpty to delete everything in the list
List::~List()
{
   makeEmpty();
}

//----------------------------------------------------------------------------
// display()
// displays the Transactions of the List
void List::display()const { 
   Node* current = head;
   
   while(current != nullptr) { 
      char transType = current->data->getTransactionType();
      int acctType = current->data->getAccountNumber()%10;

      switch(transType){ 
         case 'D':
            cout << "deposit" << setw(5) << "$" << setw(5) << 
                           current->data->getFunds() << setw(6) << "into ";
            displayHelper(acctType);
            cout << endl;
            break;
         case 'W':
            cout << "withdrawal" << setw(2) << "$" << setw(5) << 
                                    current->data->getFunds() << " from ";
            displayHelper(acctType);
            cout << endl;
            break;
         case 'M':
            cout << "move" << setw(8) << "$" << setw(5) << 
                                    current->data->getFunds() << " from "; 
            displayHelper(acctType);
            cout << " to ";
            displayHelper(current->data->getTransferAcct()%10);
            cout << " for " << current->data->getTransferAcct()/10 << endl;
            break;
         case 'H':
            cout << "history" << endl;
            break;
      }

      current = current->next;      
   }
   cout << endl;
}

//----------------------------------------------------------------------------
// displayHelper()
// assists display in printing the different accounts
void List::displayHelper(int acctType) const{
         switch(acctType){
         case 0:
            cout << "Money Market account";                                         
            break;
         case 1:
            cout << "Prime Money Market account";                                         
            break;
         case 2:
            cout << "Long-Term Bond";                                         
            break;
         case 3:
            cout << "Short-Term Bond";                                         
            break;
         case 4:
            cout << "500 Index Fund";                                         
            break;
         case 5:
            cout << "Capital Value Fund";                                         
            break;
         case 6:
            cout << "Growth Equity Fund";                                         
            break;
         case 7:
            cout << "Growth Index Fund";                                         
            break;
         case 8:
            cout << "Value Fund";                                         
            break;
         case 9:
            cout << "Value Stock Index";                                         
            break;   
      }
}

//---------------------------------------------------------------------------
// insert
// inserts a Transaction into the List
void List::insert(Transaction* dataPtr){ 
  
   Node* ptr = new Node;

   ptr->data = dataPtr;   
   
   if(isEmpty()) {       
      ptr->next = head;
      head = ptr;
   } else {
      
      Node* current = head;
      
      while(current->next != nullptr) {
         
         current = current->next;
      }      
      current->next = ptr;
      ptr->next = nullptr;
   }   
}

//---------------------------------------------------------------------------
// isEmpty
// check to see if List is empty as defined by a nullptr head
bool List::isEmpty() const{
   return head == nullptr;
}

//---------------------------------------------------------------------------
// makeEmpty
// empty the list, deallocate all memory for all the nodes and each object
void List::makeEmpty(){
   Node* current = head;
   Node* next;

   while(current != nullptr) {
      next = current->next;
      delete current->data;
      current->data = nullptr;
      delete current;
      current = next;
   }
   head = nullptr;
   current = nullptr;
   next = nullptr;
}