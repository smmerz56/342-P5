#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;  

//-----------------------------Account----------------------------------------
// ------------A storage class for use in the Client Class--------------------

//---------------------------------------------------------------------------
// Account class:  A storage class for use in the Client Class
//    - allows setting and getting of values
//---------------------------------------------------------------------------

class Account {  
public:
   Account();
   ~Account(); 
   //getters
   int getBeginningBalance();
   int getEndBalance();
   
   //setters
   void setBeginningBalance(int);
   void setEndBalance(int);
   
private:
   int beginningBalance; // beginning of the day balance
   int endBalance; // end of day balance
};
#endif