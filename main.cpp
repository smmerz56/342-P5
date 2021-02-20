#include "client.h"
#include "account.h"
#include "manager.h"
#include <iostream> 
#include <fstream>      
       
using namespace std;              
               
int main() {                 
   Manager firm;                      
         
   ifstream infile("lab5data.txt"), infile2("lab5command.txt");                   
           
   if(!infile2){  
      cout << "file not open" << endl;         
      return 0;                
   }              
         
   firm.buildTree(infile); // builds LOSE Firm Client Tree        
   firm.buildQueue(infile2); // builds the queue full of Transactions      
   firm.processQueue(); // preforms the Transactions on the Client accounts
   firm.displayTree();  // displays the Clients of the LOSE Firm       

   return 0;
} 