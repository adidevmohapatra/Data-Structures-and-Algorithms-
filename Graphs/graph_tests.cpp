/*****************************************
** File:    graph_tests.cpp
** Project: CSCE 221 Final Project Spring 2022
** Author:  Adidev Mohapatra & Kieran Beirne 
** Date:    05/09/2022
** Section: 512
** E-mail:  adidev@tamu.edu
**
** This file contains the .cpp file for the file testing
** of graph.h
***********************************************/

#include <iostream>
#include <sstream>
#include "graph.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "make an empty digraph" << std::endl;
    Graph G; //default graph
    
    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl; //these should both be 0 upon initialization
    std::cout << "G has " << G.edge_count() << " edges" << std::endl; //these should both be 0 upon initialization

    std::cout << "add vertices" << std::endl; //adding 7 vertices
    for (size_t n = 1; n <= 7; n++) {
        G.add_vertex(n);
    }

    std::cout << "add directed edges" << std::endl;
    G.add_edge(1,2,5);  // 1 ->{5} 2; (edge from 1 to 2 with weight 5)
    G.add_edge(1,3,3);
    G.add_edge(2,3,2);
    G.add_edge(2,5,3);
    
    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl; //this should both be 7
    std::cout << "G has " << G.edge_count() << " edges" << std::endl; //this should be 4
    G.add_edge(2,7,1); //adding five more edges
    G.add_edge(3,4,7);
    G.add_edge(3,5,7);
    G.add_edge(4,1,2);
    G.add_edge(4,6,6);
    
    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl; //this should be 7
    std::cout << "G has " << G.edge_count() << " edges" << std::endl; //this should be 9
    G.add_edge(5,4,2);
    G.add_edge(5,6,1);
    G.add_edge(7,5,1);
    G.add_edge(5,7,3); //adding eight more edges
    G.add_edge(1,3,4); //testing bigger graphs
    G.add_edge(5,6,8);
    G.add_edge(5,6,4);

    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl; //this should be 7
    std::cout << "G has " << G.edge_count() << " edges" << std::endl; //this should be 14
    std::cout << std::endl;
    /*
    std::cout << "compute mst path from 2" <<std::endl;
    G.prim(2);

    std::cout << "print minimum spanning paths" <<std::endl;
    for (size_t n = 1; n <= 7; n++) {
        std::cout << "minimum spanning path from 2 to " << n << std::endl;
        std::cout << "  ";
        G.print_path(n);
    }
    std::cout << std::endl;
    */
    std::cout << "compute shortest path from 2" <<std::endl;
    G.dijkstra(2); //calling dijk 2

    std::cout << "print shortest paths" <<std::endl;
    for (size_t n = 1; n <= 7; n++) {
        std::cout << "shortest path from 2 to " << n << std::endl;
        std::cout << "  ";
        G.print_shortest_path(n); //printing paths
    }


    //------------------------------------------------------------------------------
    // TODO(student): implement graph tests
    //added more functionality to default tests above, commented expected values
    G.add_edge(5,4,2);
    G.add_edge(5,6,1);
    G.add_edge(7,5,1);
    G.add_edge(5,7,3); //adding eight more edges
    G.add_edge(1,3,4); //testing bigger graphs
    G.add_edge(5,6,8);
    G.add_edge(5,6,4);

    std::cout << "G has " << G.vertex_count() << " vertices" << std::endl; //this should be 7
    std::cout << "G has " << G.edge_count() << " edges" << std::endl; //this should be 15
    std::cout << std::endl;

    return 0;
}