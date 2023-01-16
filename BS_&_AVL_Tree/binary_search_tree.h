////////Opening Comment: Purpose of the .h file is to implment functions for the binary search tree
////////like remove, insert, etc. and test it in the .cpp file
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cstddef>
#include <iostream>


template <typename Comparable>
struct bst{
    Comparable node_obj;
    bst<Comparable> *leftchildptr=nullptr;
    bst<Comparable> *rightchildptr=nullptr;
};

template <typename Comparable>
class BinarySearchTree {
    // TODO(student): implement BinarySearchTree
private:
        bst<Comparable> *root;
        
public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    BinarySearchTree(){
        root=nullptr;
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the root
    // PostCondition: elements are copied from the root
    //---------------------------------------------------------
    BinarySearchTree(const BinarySearchTree& other){

        if (other.root==nullptr){
            return;
        }
        copy_root(root, other.root);

    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the roots and remove all elements 
    // PostCondition: elements are all removed from the bst
    //---------------------------------------------------------
    ~BinarySearchTree(){
        destroy_destructor(root);
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the roots
    //---------------------------------------------------------
    BinarySearchTree& operator=(const BinarySearchTree& other){

        if (this==&other){
            return *this;
        }
        if(this!=&other){
            destroy_destructor(root);
            if(other.root==nullptr)
                return *this;

            root=other.root;
            copy_root(root, other.root);
        }
        return *this;
    }
    //-------------------------------------------------------
    // Name:contains
    // PreCondition: gives a contain value
    // PostCondition: returns a contain value from contain_helper
    //---------------------------------------------------------
    bool contains(const Comparable& value) const{
        return contain_helper(root, value);     
    }
    //-------------------------------------------------------
    // Name:insert
    // PreCondition: gives an insert value
    // PostCondition: returns an insert value from insert_helper
    //---------------------------------------------------------
    void insert(const Comparable& value){
        insert_helper(root,value); 
    }
    //-------------------------------------------------------
    // Name:remove
    // PreCondition: gives a remove value
    // PostCondition: returns a remove value from remove_helper
    //---------------------------------------------------------
    void remove(const Comparable& value){
        remove_helper(root,value);
    }
    //-------------------------------------------------------
    // Name:find_min
    // PreCondition: gives a minimum value
    // PostCondition: returns a minimum value
    //---------------------------------------------------------
    const Comparable& find_min() const{
        
        if(root==nullptr){    
            throw std::invalid_argument("Empty Tree");
        }

        bst<Comparable>*newNode=root;
        while (newNode->leftchildptr!=nullptr){
            newNode=newNode->leftchildptr;
        }
        return newNode->node_obj;

    }
    //-------------------------------------------------------
    // Name:find_max
    // PreCondition: gives a maximum value
    // PostCondition: returns a maximum value
    //---------------------------------------------------------
    const Comparable& find_max() const{

        if(root==nullptr){    
            throw std::invalid_argument("Empty Tree");
        }

        bst<Comparable>*newNode=root;
        while (newNode->rightchildptr!=nullptr){
            newNode=newNode->rightchildptr;
        }
        return newNode->node_obj;
    
    }
    //-------------------------------------------------------
    // Name:print_tree
    // PreCondition: gives the tree image
    // PostCondition: returns the tree image
    //---------------------------------------------------------
    void print_tree(std::ostream& os=std::cout) const{

        if (root==nullptr){
            os<< "<empty>\n";
        }
        else{
            print_helper(root,0, os);
        }
    }
    //-------------------------------------------------------
    // Name:is_empty
    // PreCondition: checks if/if not empty
    // PostCondition: returns if/if not empty
    //---------------------------------------------------------
    bool is_empty() const{

        if (root==nullptr){
            return true;
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:make_empty
    // PreCondition: makes if/if not empty
    // PostCondition: does empty the root from destroy_destructor
    //---------------------------------------------------------
    void make_empty(){
        destroy_destructor(root);
        root=nullptr;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////*****HELPER FUNCTIONS****///////////////////////////////
    //-------------------------------------------------------
    // Name:copy_root
    // PreCondition: make a copy of the root for the rule of three
    // PostCondition: does make a copy that is recursivly called from both
    //---------------------------------------------------------
    void copy_root(bst<Comparable>*& upper, bst<Comparable> *p){

        if(p==nullptr){
            return;
        }
        upper= new bst<Comparable>();
        upper->node_obj=p->node_obj;  
        if(p->leftchildptr!=nullptr){
            copy_root(upper->leftchildptr,p->leftchildptr);
        }
        if(p->rightchildptr!=nullptr){
            copy_root(upper->rightchildptr,p->rightchildptr);
        }
    }
    //-------------------------------------------------------
    // Name:destroy_destructor
    // PreCondition: make a deletion of the root for the empty functions
    // PostCondition: does make a deletion that is recursivly called for them
    //---------------------------------------------------------
    void destroy_destructor(bst<Comparable> *& p){

        if (p==nullptr){
            return;
        }
        if( p!=nullptr){
        destroy_destructor( p -> leftchildptr);
        destroy_destructor( p -> rightchildptr);      
        delete p;
        p=nullptr;
        }
        return;
    }
    //-------------------------------------------------------
    // Name:contain_helper
    // PreCondition: make a boolean to see if there or not
    // PostCondition: does make a contain that is recursivly called from contains
    //---------------------------------------------------------
    bool contain_helper(bst<Comparable> *x, const Comparable& item )const{
        if(x==nullptr){
            return false;
        }
        if(x->node_obj==item){
            return true;
        }
        else if(x->node_obj>item){
            return contain_helper(x->leftchildptr,item);
        }
        else if(x->node_obj<item){
            return contain_helper(x->rightchildptr,item);
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:insert_helper
    // PreCondition: make a function to insert anywhere
    // PostCondition: does make a contain that is recursivly called from insert
    //---------------------------------------------------------
    void insert_helper(bst<Comparable> *& x, const Comparable& item )const{

        if(x==nullptr){
            bst<Comparable>* newnode= new bst<Comparable>();
            newnode->node_obj=item;
            x = newnode;
            return;
        }
        if(item<x->node_obj){
            insert_helper(x->leftchildptr, item);
        }
        else if(item>x->node_obj){
            insert_helper(x->rightchildptr, item);
        }  
    }
    //-------------------------------------------------------
    // Name:remove_helper
    // PreCondition: make a function to remove anywhere
    // PostCondition: does make a remove that is recursivly called from remove
    //---------------------------------------------------------
    void remove_helper(bst<Comparable>*& x, const Comparable& item ) {
        if (x == nullptr) {
            return;
        }
        if (item < x->node_obj) {
            remove_helper(x->leftchildptr, item);
        }
        else if (item > x->node_obj) {
            remove_helper(x->rightchildptr, item);
        }
        else if (x->leftchildptr != nullptr && x->rightchildptr != nullptr) {
            x->node_obj = node_min(x->rightchildptr)->node_obj;
            remove_helper(x->rightchildptr,x->node_obj);
        }
        else {
            bst<Comparable>* temp = x;   
            if (x->leftchildptr == nullptr) {
                x = x->rightchildptr;
            }
            else if(x->leftchildptr != nullptr) {
                x = x->leftchildptr;
            }
            delete temp;
        }      
    }
    //-------------------------------------------------------
    // Name:node_min
    // PreCondition: used to fine the smalled node the remove 
    // PostCondition: returns the smallest value
    //---------------------------------------------------------
    bst<Comparable>* node_min(bst<Comparable>* p){
        bst<Comparable>* current = p;
        while (current!= nullptr && current->leftchildptr!= nullptr){
            current = current->leftchildptr;
        }
        return current;
    }
    //-------------------------------------------------------
    // Name:print_helper
    // PreCondition: make a function to print tree
    // PostCondition: does make a contain that is recursivly called from print
    //---------------------------------------------------------
    void print_helper(bst<Comparable>* t,size_t spaces, std::ostream& os=std::cout) const{   
        if (t == nullptr) {
            return;
        }
        print_helper(t->rightchildptr,spaces+2,os);
        for (size_t i=0;i<spaces;++i){
            os<<" ";
        }
        os << t->node_obj << std::endl;
        print_helper(t->leftchildptr,spaces+2,os);
    }
};

#endif