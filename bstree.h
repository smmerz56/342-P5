#ifndef BSTREE_H
#define BSTREE_H

#include "client.h"
using namespace std; 

//---------------------------------------------------------------------------
// BSTree class: A Tree made up of Client objects and their data
//    - allows inserting and retrieving of clients
//    - allows displaying and emptying
//    - can find if the tree is empty
//
// Implementation and assumptions:
//    - The tree is made of Nodes which have pointers to Clients, and left
//      and right node pointers
//    - Every Tree has a root pointer
//    - The Tree is built from the Manager Class
//---------------------------------------------------------------------------

class BSTree
{ 
   private:
   struct Node { // glue that holds data properly 
      Client* data;
      Node* right; 
      Node* left; 
   }; 
   Node* root; // root of the tree
   public:
   BSTree();
   ~BSTree(); // calls makeEmpty which deallocates all memory
   // insert object into the tree, parameter holds pointer to object to insert
   bool insert(Client*);

   // retrieve object, first parameter is object to retrieve
   // second parameter holds pointer to found object, nullptr if not found
   bool retrieve(const Client&, Client*&) const;
   bool retrieveHelper(const Client&, Client*&, Node*) const;
   void display() const; // displays the contents of a tree to cout
   void displayHelper(Node*) const; 
   void makeEmpty();     // empties the current tree, deallocates all memory
   void makeEmptyHelper(Node*);
   bool isEmpty() const; // returns true if tree is empty
};
#endif