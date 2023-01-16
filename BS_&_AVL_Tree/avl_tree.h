////////Opening Comment: Purpose of the .h file is to implment functions for the avl tree
////////like remove, insert, etc. and test it in the .cpp file
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstddef>
#include <iostream>

using namespace std;


template <typename Comparable>
struct avl{
    Comparable node_obj;
    avl<Comparable> *leftchildptr=nullptr;
    avl<Comparable> *rightchildptr=nullptr;
    int height=0;
};

template <typename Comparable>
class AVLTree {
    // TODO(student): implement AVLTree
private:
        avl<Comparable> *root;
        static const int balance_calc = 1;

public:

    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implemnt later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    AVLTree(){
        root=nullptr;
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the root
    // PostCondition: elements are copied from the root
    //---------------------------------------------------------
    AVLTree(const AVLTree& other){
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
    ~AVLTree(){
        destroy_destructor(root);
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the roots
    //---------------------------------------------------------
    AVLTree& operator=(const AVLTree& other){
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
        remove_helper(root, value);
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
        avl<Comparable>*newNode=root;
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
        avl<Comparable>*newNode=root;
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
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////*****HELPER FUNCTIONS****///////////////////////////////
    //-------------------------------------------------------
    // Name:copy_root
    // PreCondition: make a copy of the root for the rule of three
    // PostCondition: does make a copy that is recursivly called from both
    //---------------------------------------------------------
    void copy_root(avl<Comparable>*& upper, avl<Comparable> *p){
        if(p==nullptr){
            return;
        }
        upper= new avl<Comparable>();
        upper->node_obj=p->node_obj;  
        upper->height=p->height;
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
    void destroy_destructor(avl<Comparable> *p){
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
    bool contain_helper(avl<Comparable> *x, const Comparable& item )const{
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
    // Name:print_helper
    // PreCondition: make a function to print tree
    // PostCondition: does make a contain that is recursivly called from print
    //---------------------------------------------------------
    void print_helper(avl<Comparable>* t,size_t spaces, std::ostream& os=std::cout) const{
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
    //-------------------------------------------------------
    // Name:balancer
    // PreCondition: make a function to balance avl tree
    // PostCondition: does make the approprite change to balance it
    //---------------------------------------------------------
    void balancer(avl<Comparable>*& x) {
        if (x == nullptr) {
            return;
        }
        if (height(x->rightchildptr)-height(x->leftchildptr)>balance_calc) {
            if (height(x->rightchildptr->rightchildptr)>=height(x->rightchildptr->leftchildptr)) {
                rotateright(x);
            }
            else if((height(x->rightchildptr->rightchildptr)<height(x->rightchildptr->leftchildptr))){
                doublerotateright(x);
            }
        }
        else if (height(x->leftchildptr)-height(x->rightchildptr)>balance_calc) {
            if (height(x->leftchildptr->leftchildptr)>=height(x->leftchildptr->rightchildptr)) {
                rotateleft(x);
            }
            else if(height(x->leftchildptr->leftchildptr)<height(x->leftchildptr->rightchildptr)) {
                doublerotateleft(x);
            }
        }
        x->height = max(height(x->leftchildptr), height(x->rightchildptr)) + 1;
    }
    //-------------------------------------------------------
    // Name:node_min
    // PreCondition: used to fine the smalled node the remove 
    // PostCondition: returns the smallest value
    //---------------------------------------------------------
    avl<Comparable>* node_min(avl<Comparable>* p) {
        avl<Comparable>* current = p;
        while (current!= nullptr && current->leftchildptr!= nullptr) {
            current = current->leftchildptr;
        }
        return current;
    }
    //-------------------------------------------------------
    // Name:insert_helper
    // PreCondition: make a function to insert anywhere
    // PostCondition: does make a contain that is recursivly called from insert
    //---------------------------------------------------------
    void insert_helper(avl<Comparable>*& x, const Comparable& item) {
        if (x == nullptr) {
            avl<Comparable>* newnode= new avl<Comparable>();
            newnode->node_obj=item;
            x = newnode;
            return;
        }
        else if (item < x->node_obj) {
            insert_helper( x->leftchildptr, item);
        }
        else if (item > x->node_obj) {
            insert_helper( x->rightchildptr, item);
        }
        balancer(x);
    }
    //-------------------------------------------------------
    // Name:remove_helper
    // PreCondition: make a function to remove anywhere
    // PostCondition: does make a contain that is recursivly called from remove
    //---------------------------------------------------------
    void remove_helper(avl<Comparable>*& x, const Comparable& item ) {
        if (x == nullptr) {
            return;
        }
        if (item<x->node_obj) {
            remove_helper(x->leftchildptr, item);
        }
        else if (item>x->node_obj) {
            remove_helper(x->rightchildptr, item);
        }
        else if (x->leftchildptr != nullptr && x->rightchildptr != nullptr) {
            x->node_obj = node_min(x->rightchildptr)->node_obj;
            remove_helper(x->rightchildptr,x->node_obj);
        }
        else {
            avl<Comparable>* temp = x;
            if (x->leftchildptr == nullptr) {
                x = x->rightchildptr;
            }
            else if(x->leftchildptr != nullptr) {
                x = x->leftchildptr;
            }
            delete temp;
        }
        balancer(x);
    }
    //-------------------------------------------------------
    // Name: rotateleft
    // PreCondition: to balance the rotation must be done for left side
    // PostCondition: does make the rotation by switching around for left side
    //---------------------------------------------------------
    void rotateleft(avl<Comparable>*& node_two) {
        avl<Comparable>* node_one = node_two->leftchildptr;
        node_two->leftchildptr = node_one->rightchildptr;
        node_one->rightchildptr = node_two;
        node_two->height = max(height(node_two->leftchildptr),height(node_two->rightchildptr)) + 1;
        node_one->height = max(height(node_one->leftchildptr), node_two->height ) + 1;
        node_two = node_one;
    }
    //-------------------------------------------------------
    // Name: doublerotateleft
    // PreCondition: to balance the double rotation must be done for left side 
    // PostCondition: does make the double rotation by switching around for left side
    //---------------------------------------------------------
    void doublerotateleft(avl<Comparable>*& node_three) {
        rotateright(node_three->leftchildptr);
        rotateleft(node_three);
    }
    //-------------------------------------------------------
    // Name: rotateright
    // PreCondition: to balance the rotation must be done for right side
    // PostCondition: does make the rotation by switching around for right side
    //---------------------------------------------------------
    void rotateright(avl<Comparable>*& node_one) {
        avl<Comparable>* node_two = node_one->rightchildptr;
        node_one->rightchildptr = node_two->leftchildptr;
        node_two->leftchildptr = node_one;
        node_one->height = max(height(node_one->leftchildptr), height(node_one->rightchildptr)) + 1;
        node_two->height = max(height( node_two->rightchildptr ), node_one->height ) + 1;
        node_one = node_two;
    }
    //-------------------------------------------------------
    // Name: doublerotateright
    // PreCondition: to balance the double rotation must be done for left side 
    // PostCondition: does make the double rotation by switching around for left side
    //---------------------------------------------------------
    void doublerotateright(avl<Comparable>*& node_three) {
        rotateleft(node_three->rightchildptr);
        rotateright(node_three);
    }
    //-------------------------------------------------------
    // Name:height
    // PreCondition: find the height to help with balancer
    // PostCondition: returns height that is recursivly called for balancer
    //---------------------------------------------------------
    int height(avl<Comparable>* p){
        if(p == nullptr){
            return -1;
        }
        return p->height;
    }

};

#endif

