#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
#include "array_list.h"

template <typename Object>
class Stack {
private:
	// TODO(student): implement Stack
    ArrayList<Object> stack_implement;

public:
	Stack(){
    }
//-------------------------------------------------------
// Name:copy constructor 
// PreCondition: copy the elements of the array
// PostCondition: elements are copied from the array
//---------------------------------------------------------
	Stack(const Stack& other){
        stack_implement=other.stack_implement;
    }
	~Stack(){
    }
//-------------------------------------------------------
// Name:operator overload
// PreCondition: make a deep copy 
// PostCondition: returns a deep copy of the array implementation
//---------------------------------------------------------
	Stack& operator=(const Stack& other){
        if (this!=&other){//deep copy
        stack_implement=other.stack_implement;
        }
        return *this;

    }
//-------------------------------------------------------
// Name: Push
// PreCondition: be able to add elements on top of the array
// PostCondition: the function adds element as well as provides last element the be added
//---------------------------------------------------------
	void push(const Object& item){

        this->stack_implement.insert(this->size(),item);//takes the insert method and pushed at the end

    }
//-------------------------------------------------------
// Name: Pop
// PreCondition: be able to remove the the element and take it out  
// PostCondition: the topmost/last element has been removed and returned as the value 
//---------------------------------------------------------
	Object pop(){
        
        if(this->size()==0){//see if the size is 0 
            throw std::out_of_range("Pop is empty");
        }
        Object item=this->stack_implement[this->size()-1];//makes an item to add 
        this->stack_implement.remove(this->size()-1);//removes from the array
        return item;
    }
//-------------------------------------------------------
// Name: Top
// PreCondition:  Lets us know the top of the array essentially
// PostCondition: The function returns the top value and throws error when needed
//---------------------------------------------------------
	Object& top(){
        
        if(this->size()==0){//check if the size is 0 or else return size
            throw std::out_of_range("Pop is empty");
        }
        return this->stack_implement[this->size()-1];

    }
//-------------------------------------------------------
// Name: Size 
// PreCondition: needs to show the size of the array
// PostCondition: returns the array size 
//---------------------------------------------------------
	size_t size() const{

        return stack_implement.size();//return size

    }
};

#endif  // STACK_H