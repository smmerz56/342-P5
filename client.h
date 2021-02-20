#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "account.h" 
#include "list.h"
#include "transaction.h"
//#include "manager.h"
//#include "bstree.h"
using namespace std;

// -----------------------------Client class----------------------------------
// Implementation and assumptions:
//   -- Data has to be formatted correctly in text file
//   -- Can create an Account and place it into an array of its Accounts      
//   -- Keeps track of all its transactions from the Queue in its own personal
//      List
//   -- A Client is what makes up the nodes of a Tree 
//   -- If a Money Market doesnt have enough money in it to make withdrawal  
//      or move from, the program will look to take all the funds from another 
//      bond. If the other bond can not cover it, then it will try taking
//      from both. Bonds work in a similar way
//   -- If a Client has money moved from another account, it will be stored
//      in the Transaction List as a move Transaction not a deposit
//----------------------------------------------------------------------------
class Client{

friend ostream& operator<<(ostream &, const Client &);    
 
public:   
   Client(); // constructor
   Client(int);
   ~Client(); // destructor

   bool setData(ifstream&); // fill Client with data from file.
   void printClient() const; // prints the Clients name and their accounts
                     
   void deposit(Transaction*); // create a deposit into a Clients account
   void withdrawl(Transaction*); // create a withdrawl from a Clients account
   void move(Transaction*, Client*&); // move money from a Clients account
   void history(Transaction*); // prints the Clients transaction history
   int getAcctNum() const;
   
   bool operator<(const Client&) const;  // to figure out where in the  
                                         // tree to put the Client.
                                        
   bool operator==(const Client&) const; // Helps find the Client

private:
  
   string lastName;                      
   string firstName;                      
   int acctNum;    
   
   int arraySize;
   Account* clientsAccounts; // the array of the clients 
                                        // 10 different accounts

   List* clientsTransactionList; // would be added from the queue to the 
                            // clients personal transaction log 
};
#endif