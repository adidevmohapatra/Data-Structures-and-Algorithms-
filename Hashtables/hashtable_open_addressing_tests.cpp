////////Opening Comment: Purpose of the .cpp file is to implement functions for the open addressing hash
////////like test remove, insert, etc. in .cpp file
#include <iostream>
#include <sstream>
#include "hashtable_open_addressing.h"

using std::cout, std::endl;

int main() {
    // Example test case in lab document
    std::cout << "make an empty hash table with 11 buckets for strings" << std::endl;
    HashTable<std::string> table(11);

    std::cout << "initial size is " << table.size() << std::endl;
    std::cout << "initial table size is " << table.table_size() << std::endl;

    std::cout << "insert several strings" << std::endl;   
    table.insert("And them who hold High Places");
    table.insert("Must be the ones to start");
    table.insert("To mold a new Reality");
    table.insert("Closer to the Heart");
    table.insert("The Blacksmith and the Artist");
    table.insert("Reflect it in their Art");
    table.insert("Forge their Creativity");
    table.insert("Closer to the Heart");
    table.insert("Philosophers and Plowmen");
    table.insert("Each must know their Part");
    table.insert("To sow a new Mentality");
    table.insert("Closer to the Heart");
    table.insert("You can be the Captain");
    table.insert("I will draw the Chart");
    table.insert("Sailing into Destiny");
    table.insert("Closer to the Heart");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "table size is " << table.table_size() << std::endl;

    {
    std::cout << "print the table" << std::endl;
    std::stringstream ss;
    table.print_table(ss);
    std::cout << ss.str() << std::endl;
    }

    std::cout << "remove \"Philosophers and Plowmen\"" << std::endl;
    table.remove("Philosophers and Plowmen");
    std::cout << "remove \"Each must know their Part\"" << std::endl;
    table.remove("Each must know their Part");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "table size is " << table.table_size() << std::endl;

    {
    std::cout << "print the table" << std::endl;
    std::stringstream ss;
    table.print_table(ss);
    std::cout << ss.str() << std::endl;
    }

    std::cout << "find \"The Blacksmith and the Artist\"" << std::endl;
    size_t index = table.position("The Blacksmith and the Artist");
    std::cout << " ==> cell " << index << std::endl;

    std::cout << "make the table empty" << std::endl;
    table.make_empty();

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "table size is " << table.table_size() << std::endl;

    {
    std::cout << "print the table" << std::endl;
    std::stringstream ss;
    table.print_table(ss);
    std::cout << ss.str() << std::endl;
    }

    /////////additional test cases by me/////

    try{
        table.rehash(0);

    }
    catch(const std::invalid_argument){
        std::cout << "First Catch" << std::endl;
    }

    return 0;
}
