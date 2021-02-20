#include "account.h"
#include "manager.h"
#include "bstree.h"
#include "queue.h"
#include "transaction.h"
#include <iostream> 
#include <fstream>
using namespace std; 

//----------------------------------------------------------------------------
// Constructor
Manager::Manager(){} 

//----------------------------------------------------------------------------
// Destructor
Manager::~Manager(){}

//----------------------------------------------------------------------------
// buildTree()
// assists the BSTree Class in building the Client tree
void Manager::buildTree(ifstream& infile){       
   Client* ptr;
   bool successfulRead;
   bool success;

   for(;;) {
      ptr = new Client;   

      successfulRead = ptr->setData(infile);
      if(infile.eof()) {
         delete ptr;
         ptr = nullptr;
         break;
      }
      if(successfulRead) {
         success = loseFirm.insert(ptr);
      } else {                  
         delete ptr;
         ptr = NULL;
      }
      if(!success) {
         break; 
      }
   }
}

//----------------------------------------------------------------------------
// buildQueue()
// assists the Queue class in constructing the queue of Transactions
void Manager::buildQueue(ifstream& infile){ 

   Transaction* ptr;
   bool successfulRead;
   bool success;

   for(;;) {
      ptr = new Transaction;

      successfulRead = ptr->setData(infile);
      if(infile.eof()) {
         delete ptr;
         ptr = nullptr;
         break;
      }
      if(successfulRead) {
         success = queue.enqueue(ptr);  
      } else {                  
         delete ptr;
         ptr = NULL;
      }
      if(!success) {
         break; 
      }
   }
}

//----------------------------------------------------------------------------
// processQueue()
// processes the Transactions in the Queue on the Clients accounts
void Manager::processQueue(){  
   
   Client* oneClient;
   Transaction* currentTrans;
   Client* transferClient;
   while(queue.front != nullptr){
      int clientID;
      currentTrans = queue.front->data;
      char transType = queue.front->data->getTransactionType();
      if(transType == 'H'){         
         clientID = queue.front->data->getAccountNumber();
      }
      else{
         clientID = queue.front->data->getAccountNumber()/10;
      }
      Client target(clientID);
      bool success = loseFirm.retrieve(target, oneClient); 
      
      int clientTransferID;
      bool success2 = true;
      if(transType == 'M'){ 
         clientTransferID = queue.front->data->getTransferAcct()/10;
        
         Client target2(clientTransferID);
        
         success2 = loseFirm.retrieve(target2, transferClient); 
      }  
      
      if(success && success2){

         switch(transType){
            case 'D':
               oneClient->deposit(currentTrans);
               break;
            case 'W':
               oneClient->withdrawl(currentTrans);
               break;
            case 'M': 
               oneClient->move(currentTrans, transferClient);
               break;
            case 'H':
               oneClient->history(currentTrans);
               break;
         }
         queue.dequeue();
      }
      else{
         if(transType == 'M'){
            cout << "Unknown client ID " << clientID << " or " 
                        << clientTransferID << " requested" << endl;
         }
         else{
            cout << "Unknown client ID " << clientID << " requested"<< endl;
         }
         queue.dequeue();
         delete currentTrans;
      }   
   }
   transferClient = nullptr;
   currentTrans = nullptr;
   oneClient = nullptr;   
 }

//----------------------------------------------------------------------------
// displayTree()
// for displaying the Tree in main
void Manager::displayTree(){
   loseFirm.display();   
}

//----------------------------------------------------------------------------
// isEmpty()
// checks to see if tree is empty
bool Manager::isEmpty(){
   return loseFirm.isEmpty();
}

//----------------------------------------------------------------------------
// makeEmpty()
// deletes the Tree
void Manager::makeEmpty(){ 
   loseFirm.makeEmpty();
}