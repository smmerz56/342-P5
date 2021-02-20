#include "transaction.h"
#include <iostream>
#include <fstream> 

Transaction::Transaction(){}//constructor 
Transaction::Transaction(char d, int money, int transAcct){
   this->transactionType = d;
   this->funds = money;
   this->accountNumber = transAcct;   
}
Transaction::~Transaction(){} // Destructor

//---------------------------------------------------------------------------
// setData
// fills the Transaction object with its data from a text file
bool Transaction::setData(ifstream& infile){
   char transaction;
   infile >> transaction; 
   
   if(infile.eof()){
      return false;
   }

   switch(transaction){
      case 'D':
         transactionType = transaction;
         infile >> accountNumber >> funds;
         break;
      case 'W':
         transactionType = transaction;
         infile >> accountNumber >> funds;
         break;   
      case 'M':
         transactionType = transaction;
         infile >> accountNumber >> funds >> transferAcct;
         break;
      case 'H':
         transactionType = transaction;
         infile >> accountNumber;
         break;
      default:
         cout << "Unknown transaction type " << transaction << 
                                                   " requested." << endl;
         infile.ignore(1000, '\n');
         return false;
   } 
//---------------------------------------------------------------------------
   return true; 
}

//getters
char Transaction::getTransactionType(){
   return transactionType;
}
int Transaction::getAccountNumber(){
   return accountNumber;
}
int Transaction::getFunds(){
   return funds;
}
int Transaction::getTransferAcct(){
   return transferAcct;
}  