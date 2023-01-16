////////Opening Comment: Purpose of the .cpp file is to test cases for the rbt tree
////////that was implemented in the .h file by conducting various tests.


#include <iostream>
#include <sstream>
#include "red_black_tree.h"

using std::cout; 
using std::endl;

int main() {
    // example test case given in lab assignment
    // make an empty tree
    RedBlackTree<int> tree;

    // insert 5 values into the tree
    std::cout << "insert 6, 4, 2, 8, 10, -2 " << std::endl;


    tree.insert(6);
  
    tree.insert(4);
  
    tree.insert(2);
   
    tree.insert(8);
 
    tree.insert(10);

    tree.insert(-2);

    tree.get_root();

    // // print the tree
    // std::cout << "tree: " << std::endl;
    {
    std::ostringstream ss;
    tree.print_tree(ss);  
    std::cout << ss.str() << std::endl;
    }

    std::cout << "contains 4? " << std::boolalpha <<tree.contains(4) << std::endl;
    std::cout << "contains 7? " << std::boolalpha << tree.contains(7) << std::endl;

    // // remove the root
    std::cout << "remove 4" << std::endl;
    tree.remove(4);

    // find the minimum element
    std::cout << "min: " << tree.find_min() << std::endl;

    // find the maximum element
    std::cout << "max: " << tree.find_max() << std::endl;

    // print the tree
    std::cout << "tree: " << std::endl;
    {
    std::ostringstream ss;
    tree.print_tree(ss);
    std::cout << ss.str() << std::endl;
    }


    RedBlackTree<int> tree1;

    try{
            tree1.find_min();
        }
        catch(std::invalid_argument){
            cout<<"First Catch"<<endl;
        }

    try{
            tree1.find_max();
        }
        catch(std::invalid_argument){
            cout<<"Second Catch"<<endl;
        }
    
    RedBlackTree<int> tree2;

    tree2.insert(5);
    tree2.insert(1);
    tree2.insert(2);
    tree2.insert(6);
    tree2.insert(8);

    tree2.get_root();
    
    std::ostringstream ss;
    tree2.print_tree(ss);
    std::cout << ss.str() << std::endl;

    tree=tree2;

   


    return 0;
}