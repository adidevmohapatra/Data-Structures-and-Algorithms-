#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <cstddef>
#include <stdexcept>
using namespace std;

template <typename Object>
class ArrayList {
private:
    // TODO(student): implement ArrayList
    Object *arr; 
    size_t capacity;
    size_t size1;

public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    ArrayList(){
        capacity=1;
        size1=0;
        arr= new Object[capacity];

    }
    //-------------------------------------------------------
    // Name:_capacity
    // PreCondition: find the _capacity of a array
    // PostCondition: elements are made to make a new capcity of the array 
    //---------------------------------------------------------
    ArrayList(size_t _capacity){

        capacity=_capacity;
        size1=0;
        arr= new Object[_capacity];



    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the array
    // PostCondition: elements are copied from the array
    //---------------------------------------------------------
    ArrayList(const ArrayList& other){
        
        capacity=other.capacity;
        size1=other.size1;
        arr= new Object[capacity];

        for(size_t i = 0; i<size1; ++i){
            arr[i]=other.arr[i];
        }

    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the array and remove all elments 
    // PostCondition: elements are all removed from the array
    //---------------------------------------------------------
    ~ArrayList(){
          delete [] arr;
          size1=0;
          capacity=0;

    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the array implementation
    //---------------------------------------------------------
    ArrayList& operator=(const ArrayList& other){
        
        if (this==&other){//deep copy
            return *this;
        }
        
        
        capacity=other.capacity;
        size1=other.size1;
        delete [] arr;
        arr= new Object[capacity];

        for(size_t i=0;i<size1;++i){
    
            arr[i]=other.arr[i];
        }
        return *this;

    }
    //-------------------------------------------------------
    // Name: Size 
    // PreCondition: needs to show the size of the array
    // PostCondition: returns the array size 
    //---------------------------------------------------------
    size_t size() const{
        return this->size1;
    }
    //-------------------------------------------------------
    // Name: Operator [] 
    // PreCondition: tries to get the index of array
    // PostCondition: returns array to the object type 
    //---------------------------------------------------------
    Object& operator[](size_t index){
        if (index<0 || index>=size() ){
            throw std::out_of_range("Index out of Bounds");
        }
        return this->arr[index];
    }
    //-------------------------------------------------------
    // Name: Insert 
    // PreCondition: insert an element anywhere in the array
    // PostCondition: function made that can insert in middle, tail, head of array
    //---------------------------------------------------------
    void insert(size_t index, const Object& obj){
        
        if (index<0 || index>size()){

            throw std::out_of_range("Index out of Bounds");
        }
        if (size1==capacity){
            capacity=capacity*2;
            Object* temp_arr;//created temp array to store values 
            temp_arr= new Object[capacity];
            for(size_t i=0;i<size1;++i){//fill in the temp array
                temp_arr[i]=arr[i];

            }
            delete [] arr;
            arr=temp_arr;//re-initialized temp array again
            temp_arr=nullptr;
        }
        for(size_t i=size1;i>index;--i){//crucial to go to size till index to shift one over
                arr[i]=arr[i-1];
        }
        arr[index]=obj;
        size1++;

    }
    //-------------------------------------------------------
    // Name: Remove 
    // PreCondition: remove an element anywhere in the array
    // PostCondition: function made that can remove in middle, tail, head of array
    //---------------------------------------------------------

    void remove(size_t index){

        if (index<0 || index >= size() ){
            throw std::out_of_range("Index out of Bounds");
        }
        //loop from the index to the end to override each value
        for(size_t i=index;i<size1-1;++i){
            arr[i]=arr[i+1];
        }
        size1--;


        
    }
};

#endif  // ARRAY_LIST_H