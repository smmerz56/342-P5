#ifndef MANAGER_H
#define MANAGER_H

#include <fstream>
#include <iostream>
#include "client.h"  
#include "bstree.h"
#include "queue.h"
#include "transaction.h" 
#include "account.h" 
using namespace std;

//----------------------------Manager Class-----------------------------------
// Implementation and assumptions: 
//   -- Performs the transactions from the Queue to the Clients Accounts
//   -- Builds and prints the Client Tree
//   -- Builds and processes the Queue of Transactions
//----------------------------------------------------------------------------
class Manager{ 
public: 
   Manager(); //constructor 
   ~Manager(); //destructor
   void buildTree(ifstream&); // Builds the Tree of Clients 
   void displayTree(); // Prints the clients and their Accounts                    
   bool isEmpty(); 
   void makeEmpty(); 
   void buildQueue(ifstream&); // Builds the queue with Transactions                                    
   void processQueue(); // performs the transactions to the loseFirm tree.
   

private:
   Queue queue;     // The Queue of Transactions
   BSTree loseFirm; // The LOSE Firm Clients
                    
};
#endif 