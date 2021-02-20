// An account object stores the begginning and end balances of every clients account
#include "account.h" 
#include <string>   

using namespace std; 
//----------------------------------------------------------------------------
//constructor
Account::Account(){
   endBalance = 0;
}
//----------------------------------------------------------------------------
//destructor
Account::~Account(){} 

//----------------------------------------------------------------------------
//getBeginningBalance()
int Account::getBeginningBalance(){
   return this->beginningBalance;
}

//----------------------------------------------------------------------------
//getEndBalance()
int Account::getEndBalance(){
   return this->endBalance;
}

//----------------------------------------------------------------------------
//setBeginningBalance()
void Account::setBeginningBalance(int balance){
   this->beginningBalance = balance;
}

//----------------------------------------------------------------------------
//setEndBalance()
void Account::setEndBalance(int balance){
   this->endBalance = balance;
} 