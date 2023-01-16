#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>

using namespace std;



template <typename Object>
struct Node{//make a struct to set node
  Object obj;
  Node<Object> *prev =nullptr;
  Node<Object> *next = nullptr;

};

template <typename Object>
class DoublyLinkedList {

private:
    // TODO(student): implement DoublyLinkedList
    Node<Object>* head;
    Node<Object>* tail;
    size_t count=0;

public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implemnt later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    DoublyLinkedList(){
        head=nullptr;//set values to nullptr or 0
        tail=nullptr;
        count=0;

    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the array
    // PostCondition: elements are copied from the linkedlist
    //---------------------------------------------------------
    DoublyLinkedList(const DoublyLinkedList& other){
        head=nullptr;
        tail=nullptr;
        if(other.head==nullptr){//check to see if the head is nullptr then defaault follows
            head=nullptr;
            tail=nullptr;
            count=0;
        }
        else{

        head = new Node<Object>();
        head->obj=other.head->obj;

        Node<Object>* newposition=head;//create nodes to go through and copy 
        Node<Object>* mainposition=other.head;
        Node<Object>* previous=nullptr;

        while(mainposition->next!=nullptr){//loop though to get every element copied
            
            newposition->prev=previous;
            newposition->next=new Node<Object>();
            newposition->next->obj=mainposition->next->obj;

            previous=newposition;
            newposition=newposition->next;
            mainposition=mainposition->next;
       
        }
        tail=newposition;
        count=other.size();
    }
    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the linkedlist and remove all elments 
    // PostCondition: elements are all removed from the linkedlist
    //---------------------------------------------------------
    ~DoublyLinkedList(){

        Node<Object> *tempnode;

        while(head!=nullptr){//the node is walking to each next node and deleting 
            tempnode=head;
            head=head->next;
            delete tempnode;
        }
        tail=nullptr;
        head=nullptr;
        count=0;

    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the linkedlist implementation
    //---------------------------------------------------------
        DoublyLinkedList& operator=(const DoublyLinkedList& other){
        
        if (this==&other){//deep copy 
            return *this;
        }

        //rest is copied from copy constructor and destructor
        Node<Object> *tempnode;
        while(head!=nullptr){
            tempnode=head;
            head=head->next;
            delete tempnode;
        }
        tail=nullptr;
        head=nullptr;
        count=0;

        head=nullptr;
        tail=nullptr;
        if(other.head==nullptr){
            head=nullptr;
            tail=nullptr;
            count=0;
        }

        head = new Node<Object>();
        head->obj=other.head->obj;

        Node<Object>* newposition=head;
        Node<Object>* mainposition=other.head;
        Node<Object>* previous=nullptr;

        while(mainposition->next!=nullptr){
            
            newposition->prev=previous;
            newposition->next=new Node<Object>();
            newposition->next->obj=mainposition->next->obj;

            previous=newposition;
            newposition=newposition->next;
            mainposition=mainposition->next;
       
        }
        tail=newposition;
        count=other.size();

        return *this;
         
    }
    //-------------------------------------------------------
    // Name: Size 
    // PreCondition: needs to show the size of the linkedlist
    // PostCondition: returns the linkedlist size 
    //---------------------------------------------------------

    size_t size() const{

        return count;

    }
    //-------------------------------------------------------
    // Name: Operator [] 
    // PreCondition: tries to get the index of linkedlist
    // PostCondition: returns linkedlist to the object type 
    //---------------------------------------------------------
    Object& operator[](size_t index){

        if (index >=size()|| index<0 ){//test case to see if index out of bounds
            throw std::out_of_range("Index out of Bounds");
        }

        Node<Object>* current=head;

        size_t counttracker=0;
        while(current!=nullptr){
            if (counttracker==index)
                return(current->obj);
            counttracker++;
            current=current->next;
        }
        return current->obj;


    }
    //-------------------------------------------------------
    // Name: Insert 
    // PreCondition: insert an element anywhere in the linkedlist
    // PostCondition: function made that can insert in middle, tail, head of linkedlist
    //---------------------------------------------------------
    void insert(size_t index, const Object& obj){

        
        if (index > size()|| index<0 ){//test case to see if index out of bounds
            throw std::out_of_range("Index out of Bounds");
        }
        Node<Object>* current=head; 
        Node<Object>* insertnode=new Node<Object>();  
        insertnode->obj=obj;


        //head
        if(index==0){
            insertnode->next=head;
            if(head==nullptr){
                head=insertnode;
                head->next=nullptr;
                tail=insertnode;
                count++;
                return;
            }
            head->prev=insertnode;
            head=insertnode;
            count++;
            return;
        }
        //tail
        if(index==size()){
            tail->next=insertnode;
            insertnode->next=nullptr;
            insertnode->prev=tail;
            tail=insertnode;
            count++;
            return;
        }
        //middle
        size_t tracker=0;
        while (current!=nullptr){
            if(tracker==index){
            insertnode->next=current;
            insertnode->prev=current->prev;
            current->prev=insertnode;
            insertnode->prev->next=insertnode;
            break;
            }
            tracker++;
            current=current->next;
        }
        count++;
    }
    //-------------------------------------------------------
    // Name: Remove 
    // PreCondition: remove an element anywhere in the linkedlist
    // PostCondition: function made that can remove in middle, tail, head of linkedlist
    //---------------------------------------------------------
    void remove(size_t index){

        if (index >= size()|| index<0 ){//test case to see if index out of bounds
            throw std::out_of_range("Index out of Bounds");
        }

        //head
        Node<Object>* d = nullptr;
        if (index == 0) {
            if (this->size() == 1) {
                d = head;
                delete d;
                head = nullptr;
                tail = nullptr;
                d = nullptr;
            }
            else {
                d = head;
                head = head->next;
                head->prev = nullptr;
                delete d;
                d = nullptr;
            }
        }
        //tail
        else if (index == this->size()-1) {
            d = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete d;
            d = nullptr;
        }
        //middle
        else {
            size_t i = 0;
            Node<Object>* current = head;
            while (i < index) {
                current = current->next;
                i++;
            }

            d = current;
            current = current->prev;
            current->next = d->next;
            d->next->prev = current;
            delete d;
            d = nullptr;
        }
        count--;
    }


};

#endif  // DOUBLY_LINKED_LIST_H