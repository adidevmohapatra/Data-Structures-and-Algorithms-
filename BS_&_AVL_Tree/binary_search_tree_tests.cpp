////////Opening Comment: Purpose of the .cpp file is to test cases for the binary search tree
////////that was implemented in the .h file by conducting various tests.
#include <iostream>
#include "binary_search_tree.h"

using std::cout, std::endl;


int main() {
    // TODO(student): write tests

    BinarySearchTree<int> test;

    /////inserts
    test.insert(1);
    test.insert(4);
    test.insert(5);
    test.insert(6);
    test.insert(3);
    
    ///removes
    test.remove(3);
    test.remove(5);
    test.remove(10);
   ////see the contains
    cout<< test.contains(4)<< endl;

    cout<<test.find_min()<<endl;//find min

    cout<<test.find_max()<<endl;//find max

    cout<<test.is_empty()<<endl;//check if empty

    test.make_empty();//empty it 

    cout<<test.is_empty()<<endl;//check to empty
    /////////////Restart again

    //insert
    test.insert(6);
    test.insert(4);
    test.insert(2);
    test.insert(8);
    test.insert(10);

    // search the tree
    std::cout << "contains 4? " << std::boolalpha << test.contains(4) << std::endl;
    std::cout << "contains 7? " << std::boolalpha << test.contains(7) << std::endl;

    // remove the root
    test.remove(6);

    // find the minimum element
    std::cout << "min: " << test.find_min() << std::endl;

    // find the maximum element
    std::cout << "max: " << test.find_max() << std::endl;

    // print the tree
    std::cout << "tree: " << std::endl;
    test.print_tree();


    BinarySearchTree<int> test2;
    //making error statements with empty trees
        try{
            test2.find_min();
        }
        catch(std::invalid_argument){
            cout<<"First Catch"<<endl;
        }

        try{
            test2.find_max();
        }
        catch(std::invalid_argument){
            cout<<"Second Catch"<<endl;
        }

        test2.print_tree();

        


    


    


    


}