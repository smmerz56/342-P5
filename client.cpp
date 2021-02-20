#include "client.h"
#include "account.h"
#include "list.h"
#include <fstream> 
#include <iomanip>
#include <iostream>

using namespace std;    
// --------------------------------------------------------------------------
// Constructor
Client::Client() {  

   arraySize = 10; 
   
   clientsAccounts = new Account[arraySize]; 
   clientsTransactionList = new List;  
} 

// --------------------------------------------------------------------------
// Target Constructor
// used for locating a Client in a Tree
Client::Client(int number){
   acctNum = number; 
   
   arraySize = 10;
   
   clientsAccounts = new Account[arraySize];  
   clientsTransactionList = new List; 
}

// --------------------------------------------------------------------------
// Destructor
Client::~Client() {

   delete[] clientsAccounts; 
   clientsAccounts = nullptr;
   clientsTransactionList->makeEmpty();
   delete clientsTransactionList;
}

// --------------------------------------------------------------------------
// deposit()
// deposits a funds into a Clients account
void Client::deposit(Transaction* transObj){

   int account = transObj->getAccountNumber()%10; 
   
   clientsAccounts[account].setEndBalance(
         clientsAccounts[account].getEndBalance() + transObj->getFunds());
   clientsTransactionList->insert(transObj); 
}

// --------------------------------------------------------------------------
// withdrawl()
// withdrawal funds from a Clients account
void Client::withdrawl(Transaction* transObj){    
   int account = transObj->getAccountNumber()%10;
   if(clientsAccounts[account].getEndBalance() >= transObj->getFunds()){
      clientsAccounts[account].setEndBalance(
         clientsAccounts[account].getEndBalance() - transObj->getFunds());
   }
   else {     
      if(account == 0 && clientsAccounts[1].getEndBalance() 
                                             >= transObj->getFunds()){
         clientsAccounts[1].setEndBalance(clientsAccounts[1].getEndBalance()
                                                   - transObj->getFunds());
      }
      else if(account == 0 && (clientsAccounts[1].getEndBalance() + 
               clientsAccounts[0].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - 
                                       clientsAccounts[0].getEndBalance();
         clientsAccounts[1].setEndBalance(clientsAccounts[1].getEndBalance()
                                                                  - cash);
         clientsAccounts[0].setEndBalance(0);
      }
      else if(account == 1 && clientsAccounts[0].getEndBalance() >= 
                                                   transObj->getFunds()){
         clientsAccounts[0].setEndBalance(clientsAccounts[0].getEndBalance()
                                                   - transObj->getFunds());
      }

      else if(account == 1 && (clientsAccounts[0].getEndBalance() + 
               clientsAccounts[1].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - clientsAccounts[1].getEndBalance();
         clientsAccounts[0].setEndBalance(clientsAccounts[0].getEndBalance() 
                                                                     - cash);
         clientsAccounts[1].setEndBalance(0);
      }
      else if(account == 2 && (clientsAccounts[3].getEndBalance() >= 
               transObj->getFunds() || clientsAccounts[4].getEndBalance() 
                                                >= transObj->getFunds())){
         if(clientsAccounts[3].getEndBalance() >= transObj->getFunds()){
            clientsAccounts[3].setEndBalance(clientsAccounts[3].getEndBalance()
                                                         - transObj->getFunds());
         }
         else{
            clientsAccounts[4].setEndBalance(clientsAccounts[4].getEndBalance()
                                                      - transObj->getFunds());
         }
      }

      else if(account == 2 && (clientsAccounts[2].getEndBalance() + 
            clientsAccounts[3].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - 
                                       clientsAccounts[2].getEndBalance();
         clientsAccounts[3].setEndBalance(
                                 clientsAccounts[3].getEndBalance()- cash);
                                                                     
         clientsAccounts[2].setEndBalance(0);
      }
      else if(account == 2 && (clientsAccounts[2].getEndBalance() + 
            clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - 
                                       clientsAccounts[2].getEndBalance();
         clientsAccounts[4].setEndBalance(clientsAccounts[4].getEndBalance() 
                                                                     - cash);
         clientsAccounts[2].setEndBalance(0);
      }
      else if(account == 2 && (clientsAccounts[2].getEndBalance() + 
               clientsAccounts[3].getEndBalance() + 
               clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - 
                                       clientsAccounts[2].getEndBalance();

         clientsAccounts[2].setEndBalance(0);
         if(clientsAccounts[3].getEndBalance() > 
                                       clientsAccounts[4].getEndBalance()){
            cash -= clientsAccounts[4].getEndBalance();
            clientsAccounts[4].setEndBalance(0);
            clientsAccounts[3].setEndBalance(
                                 clientsAccounts[3].getEndBalance() - cash);
         }
         if(clientsAccounts[4].getEndBalance() >= 
                                       clientsAccounts[3].getEndBalance()){
            cash -= clientsAccounts[3].getEndBalance();
            clientsAccounts[3].setEndBalance(0);
            clientsAccounts[4].setEndBalance(
                                 clientsAccounts[4].getEndBalance() - cash);
         }
      }

      else if(account == 3 && (clientsAccounts[2].getEndBalance() >=
               transObj->getFunds() || clientsAccounts[4].getEndBalance() 
                                                >= transObj->getFunds())){
         if(clientsAccounts[2].getEndBalance() >= transObj->getFunds()){
            clientsAccounts[2].setEndBalance(
                  clientsAccounts[2].getEndBalance() - transObj->getFunds());
         }
         else{
            clientsAccounts[4].setEndBalance(
                  clientsAccounts[4].getEndBalance() - transObj->getFunds());
         }
      }   
      else if(account == 3 && (clientsAccounts[3].getEndBalance() + 
            clientsAccounts[2].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - clientsAccounts[3].getEndBalance();
         clientsAccounts[2].setEndBalance(clientsAccounts[2].getEndBalance()
                                                                     - cash);
         clientsAccounts[3].setEndBalance(0);
      }
      else if(account == 3 && (clientsAccounts[3].getEndBalance() + 
            clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - clientsAccounts[3].getEndBalance();
         clientsAccounts[4].setEndBalance(clientsAccounts[4].getEndBalance()
                                                                     - cash);
         clientsAccounts[3].setEndBalance(0);
      }

      else if(account == 3 && (clientsAccounts[2].getEndBalance() + 
            clientsAccounts[3].getEndBalance() + 
               clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() - clientsAccounts[3].getEndBalance();
         clientsAccounts[3].setEndBalance(0);
         if(clientsAccounts[2].getEndBalance() > 
                                       clientsAccounts[4].getEndBalance()){
            cash -= clientsAccounts[4].getEndBalance();
            clientsAccounts[4].setEndBalance(0);
            clientsAccounts[2].setEndBalance(
                                 clientsAccounts[2].getEndBalance() - cash);
         }
         if(clientsAccounts[4].getEndBalance() >= 
                                       clientsAccounts[2].getEndBalance()){
            cash -= clientsAccounts[2].getEndBalance();
            clientsAccounts[2].setEndBalance(0);
            clientsAccounts[4].setEndBalance(
                                 clientsAccounts[4].getEndBalance() - cash);
         }
      }

      else if(account == 4 && (clientsAccounts[3].getEndBalance() >= 
            transObj->getFunds() || clientsAccounts[2].getEndBalance() 
                                                >= transObj->getFunds())){
         if(clientsAccounts[3].getEndBalance() >= transObj->getFunds()){
            clientsAccounts[3].setEndBalance(
                  clientsAccounts[3].getEndBalance() - transObj->getFunds());
         }
         else{
            clientsAccounts[2].setEndBalance(
                  clientsAccounts[2].getEndBalance()- transObj->getFunds());
         }
      }
      else if(account == 4 && (clientsAccounts[2].getEndBalance() + 
            clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() -clientsAccounts[4].getEndBalance();
         clientsAccounts[2].setEndBalance(clientsAccounts[2].getEndBalance()
                                                                     - cash);
         clientsAccounts[4].setEndBalance(0);
      }

      else if(account == 4 && (clientsAccounts[3].getEndBalance() + 
               clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() -clientsAccounts[4].getEndBalance();
         clientsAccounts[3].setEndBalance(
                                 clientsAccounts[3].getEndBalance() - cash);
         clientsAccounts[4].setEndBalance(0);
      }
      else if(account == 4 && (clientsAccounts[2].getEndBalance() + 
               clientsAccounts[3].getEndBalance() + 
               clientsAccounts[4].getEndBalance() >= transObj->getFunds())){
         int cash = transObj->getFunds() -clientsAccounts[4].getEndBalance();
         clientsAccounts[4].setEndBalance(0);
         if(clientsAccounts[2].getEndBalance() > 
                                       clientsAccounts[3].getEndBalance()){
            cash -= clientsAccounts[3].getEndBalance();
            clientsAccounts[3].setEndBalance(0);
            clientsAccounts[2].setEndBalance(
                                 clientsAccounts[2].getEndBalance() - cash);
         }
         if(clientsAccounts[3].getEndBalance() >= 
                                       clientsAccounts[2].getEndBalance()){
            cash -= clientsAccounts[2].getEndBalance();
            clientsAccounts[2].setEndBalance(0);
            clientsAccounts[3].setEndBalance(
                                 clientsAccounts[3].getEndBalance() - cash);
         }
      }

      else{
         switch(account){
            case 0:
               cout << "Withdrawal not performed on Money Market account ";                                         
               break;
            case 1:
               cout << "Withdrawal not performed on Prime Money Market "
                                                                  "account ";                                         
               break;
            case 2:
               cout << "Withdrawal not performed on Long-Term Bond ";                                         
               break;
            case 3:
               cout << "Withdrawal not performed on Short-Term Bond ";                                         
               break;
            case 4:
               cout << "Withdrawal not performed on 500 Index Fund ";                                         
               break;
            case 5:
               cout << "Withdrawal not performed on Capital Value Fund ";                                         
               break;
            case 6:
               cout << "Withdrawal not performed on Growth Equity Fund ";                                         
               break;
            case 7:
               cout << "Withdrawal not performed on Growth Index Fund ";                                         
               break;
            case 8:
               cout << "Withdrawal not performed on Value Fund ";                                         
               break;
            case 9:
               cout << "Withdrawal not performed on Value Stock Index ";                                         
               break;            
         }

         cout << "for client " << transObj->getAccountNumber()/10  
                       << " because of insufficient funds" << endl;
      }
   }
   if(transObj->getTransactionType() != 'M'){
      clientsTransactionList->insert(transObj); 
   }
}

// --------------------------------------------------------------------------
// move()
// moves money from one account to another
void Client::move(Transaction* transObj, Client*& transferClient){
   
   withdrawl(transObj); 
   int money = transObj->getFunds();
   int transAcct = transObj->getTransferAcct();
   Transaction* moveDeposit = new Transaction('D', money, transAcct);
   transferClient->deposit(moveDeposit);
   clientsTransactionList->insert(transObj);

}

// --------------------------------------------------------------------------
// history()
// prints a header then calls a display function in the Clients List of 
// personal transactions
void Client::history(Transaction* transObj){
   clientsTransactionList->insert(transObj); 
   cout << "History of transactions for client " << firstName << " " 
       << lastName << ", client ID = " << acctNum << endl;
   cout << "Type" << setw(12) << "Amount" << setw(8) << "Detail" << endl;
   cout <<"--------- ------- --------------------------------------"<<endl;
   clientsTransactionList->display();   
}

// --------------------------------------------------------------------------
// SetData
// reads in data from a txt file to help create a Client
bool Client::setData(ifstream& infile){
   infile >> lastName >> firstName >> acctNum;
   
   int funds;
   for(int i = 0; i < arraySize; i++){
      infile >> funds; 
      clientsAccounts[i].setBeginningBalance(funds);
      clientsAccounts[i].setEndBalance(funds);
   }
   return true;
}

// --------------------------------------------------------------------------
// printClient
// used in main to display Client
void Client::printClient() const{
   cout << *this << endl;
}

// --------------------------------------------------------------------------
// getAcctNum()
// for use in Manager Class
int Client::getAcctNum() const{ 
   return acctNum;   
}

// --------------------------------------------------------------------------
// operator<
// used to find a Clients place in a Tree
bool Client::operator<(const Client& right) const {
   return this->acctNum < right.acctNum;
}

// --------------------------------------------------------------------------
// operator == 
// used to compare Clients
bool Client::operator==(const Client& right) const {
   return this->acctNum == right.acctNum;
}

//----------------------------------------------------------------------------
// overloaded output
ostream& operator<<(ostream& output, const Client& obj) { 
   output << obj.acctNum << " " << obj.firstName << "  " 
          << obj.lastName << endl;
   output << "Initial Balances:";
   for(int i = 0; i < obj.arraySize; i++){
      output << setw(7) << obj.clientsAccounts[i].getBeginningBalance();
   }
   output << endl;
   output << "Final Balances:  ";
   for(int i = 0; i < obj.arraySize; i++){
      output << setw(7) << obj.clientsAccounts[i].getEndBalance();
   }
   output << endl;
   return output;
}