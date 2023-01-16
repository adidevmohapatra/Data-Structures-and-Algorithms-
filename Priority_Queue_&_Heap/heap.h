/*****************************************
** File:    heap.h
** Project: CSCE 221 Lab 7 Spring 2022
** Author:  Adidev Mohapatra
** Date:    04/22/2022
** Section: 512
** E-mail:  adidev@tamu.edu
**
** This file contains the .h file for the function implementation
** for a heap to results in the format specified in the project description.
**
***********************************************/
#ifndef HEAP_H
#define HEAP_H

#include <functional>
//-------------------------------------------------------
// Name:percolate_down
// PreCondition: given-but value to be inserted
// PostCondition: given-gives the heap insertion place
//---------------------------------------------------------
template <class Container, class Compare=std::less<typename Container::value_type>>
void percolate_down(Container* container, size_t index, Compare less=std::less<typename Container::value_type>{}) {
    // TODO(student): implement percolate_down
    if (index==0 || index >= container->size()) {
        throw std::invalid_argument("Invalid Index");
    }
    size_t childnode;
    auto temp = std::move(container->at(index));
    size_t index_hole = index;
    for (;index_hole*2<container->size();index_hole=childnode) {
        childnode=index_hole*2;
        if (childnode<container->size()-1 && less(container->at(childnode + 1), container->at(childnode))) {
            childnode++;
        }   
        if (!less(container->at(childnode), temp)) {
            break;
        }
        else if(less(container->at(childnode), temp)){
            container->at(index_hole)=std::move(container->at(childnode));
        }
    }
    container->at(index_hole) = std::move(temp);


}
//-------------------------------------------------------
// Name:heapify
// PreCondition: convert the binary tree to a heap structure 
// PostCondition: function lets the tree turn into a heap structure 
//---------------------------------------------------------
template <class Container, class Compare=std::less<typename Container::value_type>>
void heapify(Container* container, Compare less=std::less<typename Container::value_type>{}) {
    // TODO(student): implement heapify
    if (container->size() == 0) {
        return;
    }
    container->resize(container->size() + 1);
    for (size_t i = container->size()-1; i>0; i--) {
        std::swap(container->at(i), container->at(i-1));
    }
    for(size_t i = (container->size()-1) / 2; i > 0; i-- ) {
        percolate_down(container, i, less);
    }
}


// GIVEN: The functions below are given to you in the starter code
// you should NOT need to modify these
//-------------------------------------------------------
// Name:heap_insert
// PreCondition: given-but value to be inserted
// PostCondition: given-gives the heap insertion place
//---------------------------------------------------------
template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_insert(Container* container, const typename Container::value_type& value, Compare less=std::less<typename Container::value_type>{}) {
    if (container->size() <= 1) {
        container->resize(2);
        container->at(1) = std::move(value);
        return;
    }
    size_t index = container->size();
    container->push_back(value);
    size_t parent = index / 2;
    while (parent > 0 && less(value, container->at(parent))) {
        container->at(index) = std::move(container->at(parent));
        index = parent;
        parent = index / 2;
    }
    container->at(index) = std::move(value);
}
//-------------------------------------------------------
// Name:Container
// PreCondition: given-but value to be contained
// PostCondition: given-gives the heap contain place
//---------------------------------------------------------
template <class Container>
const typename Container::value_type& heap_get_min(const Container& container) {
    if (container.size() <= 1) {
        throw std::invalid_argument(__FUNCTION__);
    }
    return container[1];
}
//-------------------------------------------------------
// Name:heap_delete_min
// PreCondition: given-but value to be deleted
// PostCondition: given-gives the heap deletion place
//---------------------------------------------------------
template <class Container, class Compare=std::less<typename Container::value_type>>
void heap_delete_min(Container* container, Compare less=std::less<typename Container::value_type>{}) {
    if (container->size() <= 1) {
        throw std::invalid_argument(__FUNCTION__);
    }
    if (container->size() == 2) {
        container->pop_back();
        return;
    }
    container->at(1) = std::move(container->back());
    container->pop_back();
    percolate_down(container, 1, less);
}

#endif  // HEAP_H