////////Opening Comment: Purpose of the .h file is to implement functions for the open addressing hash
////////like remove, insert, etc. and test it in the .cpp file
#ifndef HASHTABLE_OPEN_ADDRESSING_H
#define HASHTABLE_OPEN_ADDRESSING_H

#include <functional>
#include <iostream>
#include <vector>
#include <list>

using std::vector, std::list;
using std::move;

template <class Key, class Hash=std::hash<Key>>
class HashTable {
public:
    // Member Types - do not modify
    using key_type = Key;
    using value_type = Key;
    using hash = Hash;
    using size_type = size_t;
    // you can write your code below this
    enum Type {ACTIVE, EMPTY, DELETED};
private:
    // TODO: student implementation
    struct Entry{
        Key element;
        Type value = EMPTY;
    };
    size_t load;
    vector<Entry> hashtable;

public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    HashTable(){
        load = 0;
        hashtable.resize(11);
    }
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the table
    // PostCondition: elements are copied from the table
    //---------------------------------------------------------
    HashTable(const HashTable& other){  
        load = other.load;
        hashtable=other.hashtable;
    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the table and remove all elements 
    // PostCondition: elements are all removed from the table
    //---------------------------------------------------------
    ~HashTable(){
        hashtable.clear(); 
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the table
    //---------------------------------------------------------
    HashTable& operator=(const HashTable& other){ 
        if(this==&other){
            return *this;
        }
        
        if (this != &other) {
            hashtable = other.hashtable;
            load = other.load;
        }
        return *this;
    }
    //-------------------------------------------------------
    // Name:cells
    // PreCondition: gets the new cell value
    // PostCondition: returns the table with adjusted cell value
    //---------------------------------------------------------
    HashTable(size_type cells){
        load = 0;
        hashtable.resize(cells);
    }
    //-------------------------------------------------------
    // Name:is_empty
    // PreCondition: checks if/if not empty
    // PostCondition: returns if/if not empty
    //---------------------------------------------------------
    bool is_empty() const{
        return load==0;
    }
    //-------------------------------------------------------
    // Name:size
    // PreCondition: checks size
    // PostCondition: returns size
    //---------------------------------------------------------
    size_t size() const{
        return load;
    }
    //-------------------------------------------------------
    // Name:table_size
    // PreCondition: checks table size
    // PostCondition: returns table size
    //---------------------------------------------------------
    size_t table_size() const{
        return hashtable.size();
    }
    //-------------------------------------------------------
    // Name:make_empty
    // PreCondition: makes if/if not empty
    // PostCondition: does empty the hashtable
    //---------------------------------------------------------
    void make_empty(){
        if (!is_empty()) {
            size_t original = hashtable.size();
            hashtable.clear();
            hashtable.resize(original);
            load= 0;
        }
        return;
    }
    //-------------------------------------------------------
    // Name:insert
    // PreCondition: gives an insert value
    // PostCondition: returns an insert value 
    //---------------------------------------------------------
    bool insert(const value_type& value){
        size_t hash_val = position(value);
        if(hashtable[hash_val].value == DELETED || hashtable[hash_val].value == EMPTY ){
            hashtable[hash_val].element = value;
            load++;
            hashtable[hash_val].value = ACTIVE;
            float newload = (float)load / (float)hashtable.size();
            if(newload>0.5){
                rehash(nextprime());
            }
            return true;
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:remove
    // PreCondition: gives a remove value
    // PostCondition: returns a remove value from insert_helper
    //---------------------------------------------------------
    size_t remove(const key_type& key){
        size_t hash_val = position(key);
        if (!contains(key)){
            return false;
        }
        else{
        hashtable[hash_val].value = DELETED;
        load--;
        return true;
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:contains
    // PreCondition: gives a contain value
    // PostCondition: returns a contain value 
    //---------------------------------------------------------
    bool contains(const key_type& key){
        size_t hash_val = position(key);
        if(hashtable[hash_val].value == EMPTY || hashtable[hash_val].value == DELETED){
            return false;
        }
        return true;
    }
    //-------------------------------------------------------
    // Name:postition
    // PreCondition: gives a position value
    // PostCondition: returns a position value 
    //---------------------------------------------------------
    size_t position(const key_type& key) const{
        size_t hash_val = Hash{}(key) % hashtable.size();
        size_t position = 1;
        while((hashtable[hash_val].value == ACTIVE || hashtable[hash_val].value == DELETED) && hashtable[hash_val].element != key){
            hash_val += position;
            if(hash_val >= hashtable.size())
                hash_val = 0;
        }
        return hash_val;
    }
    //-------------------------------------------------------
    // Name:print_table
    // PreCondition: gives a printed hashtable
    // PostCondition: returns a printed hashtable
    //---------------------------------------------------------
    void print_table(std::ostream& os=std::cout) const{
        if (!is_empty()){
            for(const Entry& x : hashtable){
                if(x.value != EMPTY ){
                    size_t i = position(x.element);
                    os << i << ": ";
                    os << x.element << std::endl;
                }
            }
        }
        if (is_empty()) {
            os << "<empty>\n";
        }
    }
//////////////////////////////////*Helper Functions*/////////////////////////////////////////////////////
    //-------------------------------------------------------
    // Name:nextprime
    // PreCondition: gives next prime value
    // PostCondition: returns next prime value
    //---------------------------------------------------------
    size_t nextprime() {
        size_t start = 2 * hashtable.size();
        size_t stop = 3 * hashtable.size();
        for(size_t i=start; i<stop; i++){
            if(isPrime(i) == true){
                return i;
            }
        }
        return false;
       
    }
    //-------------------------------------------------------
    // Name:isPrime
    // PreCondition: gives a prime value
    // PostCondition: returns a prime value
    //---------------------------------------------------------
    bool isPrime(int n) {
        if (n == 2 || n == 3)
            return true;
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    //-------------------------------------------------------
    // Name:rehash
    // PreCondition: gives a reset table
    // PostCondition: returns a reset table
    //---------------------------------------------------------
    void rehash(size_t count){
        if (count <= 0) {
            throw std::invalid_argument("Invalid Rehash");
        }
        vector<Entry> hash_val = hashtable;
        hashtable.resize(count);
        for(size_t i=0; i<hashtable.size(); ++i){
            hashtable[i].value = EMPTY;
        }
        load = 0;
        for(const Entry& x : hash_val){
            if(x.value != EMPTY){
                insert(move(x.element));
            }  
        }
    }
};

#endif  // HASHTABLE_OPEN_ADDRESSING_H

