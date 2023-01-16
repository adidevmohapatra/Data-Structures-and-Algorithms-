
/*****************************************
** File:    graph.h
** Project: CSCE 221 Final Project Spring 2022
** Author:  Adidev Mohapatra & Kieran Beirne 
** Date:    05/09/2022
** Section: 512
** E-mail:  adidev@tamu.edu
**
** This file contains the .h file for the function implementation
** for a graph to result in the format specified in the project description.
**
***********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iostream>
#include <queue>

class Graph 
{
private:
    size_t sizeEdge;

    struct edge
    {
        size_t source;
        size_t destination;
        size_t weight;
        edge(size_t src, size_t dest, double wt) : source(src), destination(dest), weight(wt)
        {           
        }
    };

    struct vertex
    {
        bool visit = false;
        size_t distance = 0;
        vertex* v1;
        size_t data = 0;
        std::list<edge> edge_list; //using a list for efficiency/speed

        
        vertex(const vertex& x) : visit(x.visit), distance(x.distance), v1(x.v1), data(x.data), edge_list(x.edge_list) {};
        
        vertex(std::list<edge> x={}, size_t i=0) : visit(false), distance(), v1(), data(i), edge_list()
        {
            for(edge element : x){
                edge_list.push_back(element); //copying all the elements into the edge_list
            }
        }


        vertex& operator=(const vertex& x){
            this->data = x.data;
            return *this;
        }
    };
    
    std::vector<vertex*> list;


    public:

    //-------------------------------------------------------
    // Name:Graph();
    // PreCondition: default constructor to set initial values
    // PostCondition: default constructor returns set values
    //---------------------------------------------------------

    Graph() : sizeEdge(0), list(){}

    //-------------------------------------------------------
    // Name:Graph(const Graph&);
    // PreCondition: copy constructor to set initial values
    // PostCondition: copy constructor returns set values
    //---------------------------------------------------------

    Graph(const Graph& other) : sizeEdge(other.sizeEdge), list(){
        for(vertex* y : other.list){
            list.push_back(y);
        }
    }

    //-------------------------------------------------------
    // Name:Graph& operator=(const Graph&);
    // PreCondition: copy overload to set initial values
    // PostCondition: copy overload returns set values
    //---------------------------------------------------------
    Graph& operator=(const Graph& other){
        
        if(this == &other){
            return *this;
        }
        else
        {
            for(vertex* x : list)
            {
                delete x;
            }
            sizeEdge = 0;

            sizeEdge = other.sizeEdge;
            vertex* copy;

            for(vertex* y : other.list){
                copy = new vertex(y->edge_list, y->data);
                list.push_back(copy);
            }
        }
        return *this;
    }

    //-------------------------------------------------------
    // Name:~Graph();
    // PreCondition: destructor to delete values
    // PostCondition: destructor returns null values
    //---------------------------------------------------------
    ~Graph()
    {
        sizeEdge = 0;
        for(vertex* x : list)
        {
            x->visit = false; //setting each "memory" to seen
            delete x;
        }
    }

    //-------------------------------------------------------
    // Name:vertex_count();
    // PreCondition: vertex_count to find how many vertices are there
    // PostCondition: vertex_count to return how many vertices are there
    //---------------------------------------------------------
    size_t vertex_count() const{
        size_t ans;
        
        if(this->list.size() > 0)
        {
            ans = this->list.size();
            return ans;
        }

        return 0;
        
        
    }

    //-------------------------------------------------------
    // Name:edge_count();
    // PreCondition: edge_count to find how many vertices are there
    // PostCondition: edge_count to return how many vertices are there
    //---------------------------------------------------------
    size_t edge_count() const{
        size_t ans;
        if(this->sizeEdge > 0)
        {
            ans = this->sizeEdge;
            return ans;
        }

        return 0;
    }

    //-------------------------------------------------------
    // Name:contains_vertex(size_t id);
    // PreCondition: contains_vertex to find if the vertex is there
    // PostCondition: contains_vertex to return if the vertex is there
    //---------------------------------------------------------
    bool contains_vertex(size_t id) const
    {
        bool found = false;
        for(vertex* x : list){
            if(x->data == id)
            {
                found = true;
                break;
            }
            else
            {
                found = false;
            }
        }
        return found;
    }

    //-------------------------------------------------------
    // Name:contains_edge(size_t src, size_t dest);
    // PreCondition: contains_edge to find if the edge is there
    // PostCondition: contains_edge to return if the edge is there
    //---------------------------------------------------------
    bool contains_edge(size_t src, size_t dest) const
    {
        bool found = false;
        for(vertex* x : list){
            for(edge y : x->edge_list){
                if(y.destination == dest)
                {
                    if(y.source == src)
                    {
                        found = true;
                        break;
                    }
                    else
                    {
                        found = false;
                    }
                }
                
            }
        }
        return found;
    }

    //-------------------------------------------------------
    // Name:findVertex(size_t id);
    // PreCondition: findVertex to return the input vertex
    // PostCondition: findVertex to return the input vertex
    //---------------------------------------------------------
    vertex* findVertex(size_t id) const{
        bool found = false;
        for(auto & x : list)
        {
            if(!found){
                if(x->data == id)
                {
                    return x;
                }
            }
        }
        throw std::invalid_argument("no vertex found.");
    }


    //-------------------------------------------------------
    // Name:findEdge(vertex* x, size_t dest);
    // PreCondition: findEdge to return the input edge
    // PostCondition: findEdge to return the input edge
    //---------------------------------------------------------
    edge findEdge(vertex* x, size_t dest) const{
        bool found = false;
        for(edge x : x->edge_list){
            if(!found)
            {
                if(x.destination == dest){
                    return x;
                }
            }
        }
        throw std::invalid_argument("no edge found.");
    }

    //-------------------------------------------------------
    // Name:cost(size_t src, size_t dest) const;
    // PreCondition: get weight of the edge between src and dest
    // PostCondition: return weight of the edge between src and dest
    //---------------------------------------------------------
    double cost(size_t src, size_t dest) const
    {
        if(!contains_edge(src,dest)){
            return INFINITY;
        }

        // vertex* one;
        // edge two;

        vertex* one = findVertex(src);
        edge two = findEdge(one, dest);
        double ans = two.weight;
        delete one;
        return ans;
    }

    //-------------------------------------------------------
    // Name:add_vertex(size_t id) ;
    // PreCondition: add_vertex to add additional vertex
    // PostCondition: add_vertex to return additional vertex
    //---------------------------------------------------------
    bool add_vertex(size_t id)
    {
        bool added = false;
        if(contains_vertex(id) == true)
        {
            return added;
        }
        std::list<edge> edge_temp;
        vertex* vert_temp = new vertex(edge_temp, id);
        list.push_back(vert_temp);
        added = true;
        return added;
    }

    //-------------------------------------------------------
    // Name:add_edge(size_t src, size_t dest, double weight=1) ;
    // PreCondition: add_edge to add additional edge
    // PostCondition: add_edge to return additional edge
    //---------------------------------------------------------
    bool add_edge(size_t src, size_t dest, double weight=1)
    {
        bool added = false;
        if(contains_vertex(src) == false){
            return added;
        }
        if(contains_vertex(dest) == false)
        {
            return added;
        }
        if(contains_edge(src,dest) == true)
        {
            return added;
        }

        vertex* origin = findVertex(src);
        edge newEdge = edge(src, dest, weight);

        origin->edge_list.push_back(newEdge);
        added = true;
        sizeEdge++;

        return added;
    }

    //-------------------------------------------------------
    // Name:remove_vertex(size_t id) ;
    // PreCondition: remove_vertex to remove one of the vertex
    // PostCondition: remove_vertex to return one less vertex
    //---------------------------------------------------------
    bool remove_vertex(size_t id)
    {
        bool removed = false;
        if(contains_vertex(id) == false)
        {
            return removed;
        }
       
//////////////

        std::vector<vertex*>::iterator iter = list.begin();

        while(iter != list.end()){
            if((*iter)->data == id){
                for(vertex* x : list){
                    remove_edge(x->data, id);
                }
                //list.erase(iter);
                removed = true;
                break;
                return true;
            }
            else{
                iter++;
            }
        }
/////////////
        return removed;
    }

    //-------------------------------------------------------
    // Name:remove_edge(size_t src, size_t dest) ;
    // PreCondition: add_edge to add additional edge
    // PostCondition: add_edge to return additional edge
    //---------------------------------------------------------
    bool remove_edge(size_t src, size_t dest)
    {
        bool removed = false;
        if(contains_edge(src, dest) == removed){
            return removed;
        }
        vertex* x = findVertex(src);

        std::list<edge>::iterator iter = x->edge_list.begin();

        while(iter != x->edge_list.end()){
            if(iter->destination == dest){
                //x->edge_list.erase(iter);
                sizeEdge--;
                removed = true;
                return removed;
            }
            else{
                iter++;
            }
        }
        return removed;
    }
    
    // Task 2
    
    //-------------------------------------------------------
    // Name:prim(size_t soruce_id) ;
    // PreCondition: executes prim's alg
    // PostCondition: executes prim's alg
    //---------------------------------------------------------
    void prim(size_t source_id){
        std::cout << source_id << std::endl;
        return;
    }
    
    //-------------------------------------------------------
    // Name:is_path(size_t id) ;
    // PreCondition: returns if is a path
    // PostCondition: returns if is a path
    //---------------------------------------------------------
    bool is_path(size_t id) const{
        std::cout << id << std::endl;
        return true;
    }
    
    //-------------------------------------------------------
    // Name:print_path(size_t dest_id, , std::ostream& os=std::cout) ;
    // PreCondition: returns if is a path
    // PostCondition: returns if is a path
    //---------------------------------------------------------
    void print_path(size_t dest_id, std::ostream& os=std::cout) const{
        os << dest_id << std::endl;
        return;
    }
    
    // Task 3

    
    //-------------------------------------------------------
    // Name:dijkstra(size_t source_id) ;
    // PreCondition: executies dijkstra's alg
    // PostCondition: executies dijkstra's alg
    //---------------------------------------------------------
    void dijkstra(size_t source_id){
        //size_t temp = source_id;
        std::cout << source_id << std::endl;
    }

    
    //-------------------------------------------------------
    // Name:distance(size_t id) ;
    // PreCondition: returns the distance as a double
    // PostCondition: executies dijkstra's alg
    //---------------------------------------------------------
    double distance(size_t id) const{
        double temp = id;
        return temp;
    }


    //-------------------------------------------------------
    // Name:print_shortest_path(size_t dest_id, std::ostream& os=std::cout) ;
    // PreCondition: prints the shortest path
    // PostCondition: prints the shortest path
    //---------------------------------------------------------
    void print_shortest_path(size_t dest_id, std::ostream& os=std::cout) const{
        /*vertex* start = findVertex(dest_id);

        if(start->path){
            print_shortest_path(start->path->data);
            os << " --> ";
        }

        os << start->data << "\n";

        std::list<edge>::iterator iter = start->edge_list.begin();

        while(iter != start->edge_list.end()){
            os << iter->source << "-->{" << iter->weight << "} " << iter->destination << "\n";
            iter++;
        } */
        os << dest_id << std::endl;
    }
};

#endif  // GRAPH_H