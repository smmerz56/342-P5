#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;  
//-------------------------------Transaction Class----------------------------
// --------A storage class for use in the Queue and Client Class--------------
// Implementation and assumptions:
//    - Data has to be formatted correctly in the text file.
//---------------------------------------------------------------------------
class Transaction{

public:
  
   Transaction();//constructor 
   Transaction(char, int, int);
   ~Transaction(); // Destructor
   bool setData(ifstream&);// fill Transaction with data from file
   
   //getters 
   char getTransactionType(); 
   int getAccountNumber(); 
   int getFunds(); 
   int getTransferAcct(); 

private:
   char transactionType; // char from the file being read in                      
   int accountNumber;  // account number from file being read in                 
   int funds;            // money in the account
   int transferAcct;     // account to transfer to                     
                        
};

#endif