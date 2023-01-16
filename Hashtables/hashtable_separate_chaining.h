////////Opening Comment: Purpose of the .h file is to implement functions for the seperate chaining hash
////////like remove, insert, etc. and test it in the .cpp file
#ifndef HASHTABLE_SEPARATE_CHAINING_H
#define HASHTABLE_SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <stdexcept>
#include <functional>
#include <iostream>

using std::list, std::vector;
template <class Key, class Hash=std::hash<Key>>
class HashTable {
public:
    // Member Types - do not modify
    using key_type = Key;
    using value_type = Key;
    using hash = Hash;
    using size_type = size_t;
    // you can write your code below this

private:
    // TODO: student implementation
    vector<list<key_type>> hashtable;
    size_type size_counter;
    float load;

public:
    //-------------------------------------------------------
    // Name:default 
    // PreCondition: gets all the default values to use and implement later on in the class
    // PostCondition: sets everything to initial value and sets it for later use.
    //---------------------------------------------------------
    HashTable(){
        load=1;
        size_counter=0;
        hashtable.resize(11);
    } 
    //-------------------------------------------------------
    // Name:copy constructor 
    // PreCondition: copy the elements of the table
    // PostCondition: elements are copied from the table
    //---------------------------------------------------------
    HashTable(const HashTable& other){ 
        load=other.load;
        size_counter=other.size_counter;
        hashtable = other.hashtable;
    }
    //-------------------------------------------------------
    // Name:destructer 
    // PreCondition: objective is to take the table and remove all elements 
    // PostCondition: elements are all removed from the table
    //---------------------------------------------------------
    ~HashTable() {
        hashtable.clear();
    }
    //-------------------------------------------------------
    // Name:operator overload
    // PreCondition: make a deep copy 
    // PostCondition: returns a deep copy of the table
    //---------------------------------------------------------
    HashTable& operator=(const HashTable& other) {
        
        if(this==&other){
            return *this;
        }
        
        if (this != &other) {
            hashtable = other.hashtable;
            size_counter = other.size_counter;
            load = other.load;
        }
        return *this;
    }
    //-------------------------------------------------------
    // Name:buckets
    // PreCondition: gets the new bucket value
    // PostCondition: returns the table with adjusted bucket value
    //---------------------------------------------------------
    HashTable(size_type buckets){
        load=1;
        size_counter=0;
        hashtable.resize(buckets);
    }
    //-------------------------------------------------------
    // Name:is_empty
    // PreCondition: checks if/if not empty
    // PostCondition: returns if/if not empty
    //---------------------------------------------------------
    bool is_empty() const {
        return size_counter == 0;
    }
    //-------------------------------------------------------
    // Name:size
    // PreCondition: checks size
    // PostCondition: returns size
    //---------------------------------------------------------
    size_t size() const {
        return size_counter;
    }
    //-------------------------------------------------------
    // Name:make_empty
    // PreCondition: makes if/if not empty
    // PostCondition: does empty the hashtable
    //---------------------------------------------------------
    void make_empty() {
        if (!is_empty()) {
            size_t original = hashtable.size();
            hashtable.clear();
            hashtable.resize(original);
            size_counter = 0;
        }
        return;
    }
    //-------------------------------------------------------
    // Name:insert
    // PreCondition: gives an insert value
    // PostCondition: returns an insert value 
    //---------------------------------------------------------
    bool insert(const value_type& value) { 
        size_t hash_val = bucket(value);
        for (value_type x:hashtable[hash_val]) {
            if (x == value) {
                return false;
            }
        }
        hashtable[hash_val].push_front(value);
        size_counter++;
        if (load_factor() > max_load_factor()) {
            rehash(nextprime(2*hashtable.size()));
        }
        return true;

    }
    //-------------------------------------------------------
    // Name:remove
    // PreCondition: gives a remove value
    // PostCondition: returns a remove value from insert_helper
    //---------------------------------------------------------
    size_t remove(const key_type& key) {
        size_t hash_val = bucket(key);
        if (!contains(key)){
            return false;
        }
        else {
            hashtable[hash_val].remove(key);
            size_counter--;
            return true;
        }
        return false;

    }
    //-------------------------------------------------------
    // Name:contains
    // PreCondition: gives a contain value
    // PostCondition: returns a contain value 
    //---------------------------------------------------------
    bool contains(const key_type& key) {
        size_t hash_val = bucket(key);
        for (value_type x: hashtable[hash_val]) {
            if (x == key) {
                return true;
            }
        }
        return false;
    }
    //-------------------------------------------------------
    // Name:bucketcount
    // PreCondition: gives a value of hashtable count
    // PostCondition: returns a hashtable count 
    //---------------------------------------------------------
    size_t bucket_count() const {
        return hashtable.size();
    }
    //-------------------------------------------------------
    // Name:bucket_size
    // PreCondition: gives a value of hashtable size
    // PostCondition: returns a hashtable size
    //---------------------------------------------------------
    size_t bucket_size(size_t n) const {
        if (hashtable.size()< n) {
            throw std::out_of_range("Bucket Size out of Range");
        }
        if (hashtable.size()== n) {
            throw std::out_of_range("Bucket Size out of Range");
        }
        return hashtable[n].size();
    }
    //-------------------------------------------------------
    // Name:bucket
    // PreCondition: reset the bucket value
    // PostCondition: returns the reset value of of the bucket
    //---------------------------------------------------------
    size_t bucket(const key_type& key) const {
        return Hash{}(key) % hashtable.size();
    }
    //-------------------------------------------------------
    // Name:load_factor
    // PreCondition: gives a value of the load factor
    // PostCondition: returns a value of load factor from size and table size
    //---------------------------------------------------------
    float load_factor() const {
        return (float) size_counter / (float) hashtable.size();
    }
    //-------------------------------------------------------
    // Name:max_load_factor
    // PreCondition: gives biggest load factor
    // PostCondition: returns the biggest load factor
    //---------------------------------------------------------
    float max_load_factor() const {
        return load;
    }
    //-------------------------------------------------------
    // Name:max_load_factor
    // PreCondition: gives a the greated mlf
    // PostCondition: returns the mlf by calling rehash
    //---------------------------------------------------------
    void max_load_factor(float mlf) { 
        if (mlf == 0) {
            throw std::invalid_argument("Invalid MLF");
        }
        if (mlf < 0) {
            throw std::invalid_argument("Invalid MLF");
        }
        load = mlf;
        float clf = load_factor();

        if (clf>mlf) {
            size_t new_size = size_counter / mlf;
            rehash(new_size);
        }
    }
    //-------------------------------------------------------
    // Name:rehash
    // PreCondition: gives a reset table
    // PostCondition: returns a reset table
    //---------------------------------------------------------
    void rehash(size_type count) {
        if (count == hashtable.size()) {
            return;
        }
        if (count == 0) {
            throw std::invalid_argument("Invalid Rehash");
        }
        if (is_empty()) {
            hashtable.resize(count);
            return;
        }
        vector<list<value_type>> newTable;
        float newload = (float) size_counter / (float) count;
        size_t new_size = count;
        if (load < newload) {
            new_size = nextprime(4*(hashtable.size() / load));
        }
        newTable.resize(new_size);
        for (list<value_type> x : hashtable) {
            for (value_type val : x) {
                size_t hash_val = Hash{}(val) % newTable.size();
                newTable[hash_val].push_front(val);
            }
        }
        hashtable.clear();
        hashtable = newTable;
    }
    //-------------------------------------------------------
    // Name:print_table
    // PreCondition: gives a printed hashtable
    // PostCondition: returns a printed hashtable
    //---------------------------------------------------------
    void print_table(std::ostream& os=std::cout) const {
        
        if (!is_empty()){
            for (size_t i = 0 ; i < hashtable.size(); i++) {
                if (hashtable[i].size() > 0) {
                    for (value_type x : hashtable[i]) {    
                        os << i << ": " << x << std::endl;
                    }
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
    size_t nextprime(size_t n){
        
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
        for (int i = 5; i * i <= n; i += 6){
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};

#endif  // HASHTABLE_SEPARATE_CHAINING_H
