/*****************************************
** File:    priority_queue_tests.cpp
** Project: CSCE 221 Lab 7 Spring 2022
** Author:  Adidev Mohapatra
** Date:    04/22/2022
** Section: 512
** E-mail:  adidev@tamu.edu
**
** This file contains the .cpp file for the test implementation
** for a heap to displays the results to get 90% code coverage 
** 
***********************************************/
#include <iostream>
#include <vector>
#include <deque>

#include "heap.h"

using std::cout, std::endl;

int main() {
    // Example test case
    std::vector<int> heap{150,80,40,30,10,70,110,100,20,90,60,50,120,140,130};

    cout << "before heapify: ";
    for (int i : heap) { cout << i << " "; }
    cout << endl;

    heapify(&heap);

    /////////additional test cases by me/////
    try{
        percolate_down(&heap, 10000);

    }
    catch(const std::invalid_argument){
        std::cout << "First Catch" << std::endl;
    }

    cout << "after heapify: ";
    for (int i : heap) { cout << i << " "; }
    cout << endl;

    for (unsigned j = 0; j < 4; j++) {
        cout << "minimum is " << heap_get_min(heap) << endl;
        
        cout << "delete min" << endl;
        heap_delete_min(&heap);
        /////////additional test cases by me/////
        const int min= heap_get_min(heap);
        cout << "Minimum: " << min << endl;

        cout << "heap: ";
        for (int i : heap) { cout << i << " "; }
        cout << endl;
    }

    int values[] = {47,54,57,43,120,3};
    for (unsigned j = 0; j < 6; j++) {
        cout << "insert " << values[j] << endl;
        heap_insert(&heap, values[j]);

        cout << "heap: ";
        for (int i : heap) { cout << i << " "; }
        cout << endl;
    }

    // TODO(student): write tests


    /////////additional test cases by me/////

    heap.clear();

    heapify(&heap);

    try{
        percolate_down(&heap, 0);

    }
    catch(const std::invalid_argument){
        std::cout << "Second Catch" << std::endl;
    }

    try{
        percolate_down(&heap, -1);

    }
    catch(const std::invalid_argument){
        std::cout << "Third Catch" << std::endl;
    }

    try{
        heap_delete_min(&heap);

    }
    catch(const std::invalid_argument){
        std::cout << "Fourth Catch" << std::endl;
    }

    try{
        cout << "Minimum: " << heap_get_min(heap) << endl;
    }
    catch(const std::invalid_argument){
        std::cout << "Fourth Catch" << std::endl;
    }
    heap.push_back(5);
    heap.push_back(7);
    cout << "Size of Heap: " << heap.size() << endl;
    heap_delete_min(&heap);




    


    return 0;
}
