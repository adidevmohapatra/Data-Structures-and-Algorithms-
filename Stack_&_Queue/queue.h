#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <stdexcept>
#include "array_list.h"

template <typename Object>
class Queue {
private:
    // TODO(student): implement Queue
    ArrayList<Object> queue_implement;//getting arraylist to implement queue


public:
    Queue(){
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the array
    // PostCondition: elements are copied from the array
    //---------------------------------------------------------
    Queue(const Queue& other){
        queue_implement=other.queue_implement;
    }
    ~Queue(){

    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the array implementation
    //---------------------------------------------------------
    Queue& operator=(const Queue& other){
       
        if (this!=&other){ //deep copy
        queue_implement=other.queue_implement; 
        }
        return *this;

    }
    //-------------------------------------------------------
    // Name: enqueue
    // PreCondition: adds the size to the by adding the object
    // PostCondition:  returns the object with the index at a random index
    //---------------------------------------------------------
    void enqueue(const Object& item){

        size_t index = queue_implement.size();//allows us to get index to get set item
        queue_implement.insert(index,item);//insert set item in the queue

    }
    //-------------------------------------------------------
    // Name: dequeue
    // PreCondition: takes the front and removes it
    // PostCondition:  object made to return the front object of the array
    //---------------------------------------------------------
    Object dequeue(){

        Object final = front();
        queue_implement.remove(0);//take the first element out
        return final;
    }
    //-------------------------------------------------------
    // Name: Front
    // PreCondition: give us the front of the array
    // PostCondition:  the array returns the front value to us
    //---------------------------------------------------------
    Object& front(){


        return queue_implement[0];//get the first element

    }
    //-------------------------------------------------------
    // Name: Size 
    // PreCondition: needs to show the size of the array
    // PostCondition: returns the array size 
    //---------------------------------------------------------
    size_t size() const{

         
        return queue_implement.size();//get the size 

    }
};

#endif  // QUEUE_H