/*****************************************
** File:    priority_queue.h
** Project: CSCE 221 Lab 7 Spring 2022
** Author:  Adidev Mohapatra
** Date:    04/22/2022
** Section: 512
** E-mail:  adidev@tamu.edu
**
** This file contains the .h file for the function implementation
** for a priority_queue to results in the format specified in the project description.
**
***********************************************/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <functional>
#include "heap.h"

using std::cout, std::endl;
template <class Comparable, class Container=std::vector<Comparable>, class Compare=std::less<Comparable>>
class PriorityQueue {
private:
    // Member Types - do not modify
    using container_type = Container;
    using value_compare = Compare;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    // Member Types - do not modify
    // you can modify below here
    Compare compare;
    Container container;

public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    PriorityQueue() {
        container.resize(1);
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the queue
    // PostCondition: elements are copied from the queue
    //---------------------------------------------------------
    PriorityQueue(const PriorityQueue& other) {
        container = other.container;
        compare = other.compare;
    }
    //-------------------------------------------------------
    // Name:_compare 
    // PreCondition: see the elements of the queue for priority
    // PostCondition: elements are sorted by priority
    //---------------------------------------------------------
    PriorityQueue(const Compare& _compare) {
        container.resize(1);
        compare = _compare;
    }
    //-------------------------------------------------------
    // Name:_container
    // PreCondition: see the elements of the queue for contains
    // PostCondition: elements are sorted by priority for contains
    //---------------------------------------------------------
    PriorityQueue(const Container& _container) {
        container = _container;
        heapify(&container);
    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the table and remove all elements 
    // PostCondition: elements are all removed from the table
    //---------------------------------------------------------
    PriorityQueue(const Compare& _compare, const Container& _container): compare(_compare) {
        container = _container;
        heapify(&container, compare);
    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the queue and remove all elements 
    // PostCondition: elements are all removed from the queue
    //---------------------------------------------------------
    ~PriorityQueue() {
        container.clear();
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the queue
    //---------------------------------------------------------
    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this==&other){
            return *this;
        }
        if (this != &other) {
            if (other.container.size() != 0) { 
                container = other.container;
            }
            else if(other.container.size() == 0) {
                container.resize(1);
            }
        }
        return *this;
    }
    //-------------------------------------------------------
    // Name:top
    // PreCondition: takes the first element of the queue   
    // PostCondition: returns the first element of the queue 
    //---------------------------------------------------------
    const_reference top() const {
        if (empty()){
            throw std::invalid_argument("Empty Queue");
        }
        return container.at(1);
    }
    //-------------------------------------------------------
    // Name:empty
    // PreCondition: see if it is empty 
    // PostCondition: return true or false for empty 
    //---------------------------------------------------------
    bool empty() const { 
        return size() == 0;
    }
    //-------------------------------------------------------
    // Name:size
    // PreCondition: takes size queue   
    // PostCondition: returns the size of queue 
    //---------------------------------------------------------
    size_type size() const {
        return container.size()-1;
    }
    //-------------------------------------------------------
    // Name:make_empty
    // PreCondition: empties the queue   
    // PostCondition: make the queue empty
    //---------------------------------------------------------
    void make_empty() {
        container.clear();
        container.resize(1);
    }
    //-------------------------------------------------------
    // Name:push
    // PreCondition: takes the last element of the queue   
    // PostCondition: gets the last element of the queue 
    //---------------------------------------------------------
    void push(const value_type& value) {
        heap_insert(&container, value, compare);
    }
    //-------------------------------------------------------
    // Name:pop
    // PreCondition: takes the first element of the queue   
    // PostCondition: gets the first element of the queue 
    //---------------------------------------------------------
    void pop() {
        heap_delete_min(&container, compare);
    }
    //-------------------------------------------------------
    // Name:print
    // PreCondition: print the queue based on priority  
    // PostCondition: prints the queue based on the priority
    //---------------------------------------------------------
    void print_queue(std::ostream& os=std::cout) const {
        if (empty()) {
            os << "<empty>\n";
        }
        else {
            for (size_t i = 0; i < container.size(); i++){
                os<< container[i] << " ";
            }
            os<<std::endl;
        }
    }
};

#endif  // PRIORITY_QUEUE_H