#ifndef QUEUE_H
#define QUEUE_H

#include "transaction.h" 


//----------------------------------------------------------------------------
// class Queue 
//
// ADT Queue: collection of zero or more items (list) with the restriction that
//            all insertions happen at one end, called the rear of the queue, 
//            and all removals occur at the other end, the front
//            (also known as FIFO -- First In, First Out)
//
// Implementation and assumptions:
//    -- Node (linked list implementation) is a struct made of just
//       a NodeData* and a Node*
//    -- Array implementation does not resize when full
//    -- Assumes NodeData is a class of actual data
//    -- The push allocates memory for a Node, ptr to the data is passed in.
//    -- May not be NodeData* in queue; data may be stored directly
//       in the Node or array element, e.g. queue of ints, queue of NodeData
//----------------------------------------------------------------------------

class Queue {
   friend ostream &operator<<(ostream&, const Queue&);
private:
   // for linked list implementation
   struct Node {
      Transaction* data;
      Node* next;
   };
   Node* front;                               // pointer to front of queue
   Node* rear;  
   
   friend class Manager;
public:
   Queue();                                   // default constructorclTabCtrl
   ~Queue();                                  // destructor
   Queue(const Queue&);                       // copy constructor
   void clear();                              // clear out queue
   bool isEmpty() const;                      // is the queue empty?
   bool isFull() const;                       // is the queue full?   
   

   // insert item, assume object passed in is valid, return whether successful
   bool enqueue(Transaction*);                  

   // remove item, parameter is removed item, return whether item is removed 
   bool dequeue();                  

   // retrieve item, parameter is item at top, return whether item exists
   bool peek(Transaction*&) const;    
                     
};

#endif