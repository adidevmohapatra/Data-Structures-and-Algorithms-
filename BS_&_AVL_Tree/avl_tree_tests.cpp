////////Opening Comment: Purpose of the .cpp file is to test cases for the avl tree
////////that was implemented in the .h file by conducting various tests.
#include <iostream>
#include "avl_tree.h"

using std::cout, std::endl;

int main() {
    // TODO(student): write tests
// make an empty tree
AVLTree<int> tree;

// insert 5 values into the tree
tree.insert(6);
tree.insert(4);
tree.insert(2);
tree.insert(8);
tree.insert(10);

// search the tree
std::cout << "contains 4? " << std::boolalpha << tree.contains(4) << std::endl;
std::cout << "contains 7? " << std::boolalpha << tree.contains(7) << std::endl;


// print the tree
std::cout << "tree: " << std::endl;
tree.print_tree();


// remove the root
tree.remove(4);

// find the minimum element
std::cout << "min: " << tree.find_min() << std::endl;

// find the maximum element
std::cout << "max: " << tree.find_max() << std::endl;

// print the tree
std::cout << "tree: " << std::endl;
tree.print_tree();

//See if the container can see if real or not
bool containsone=false;
containsone=tree.contains(10);
cout << "true " << containsone << endl;

bool containstwo=false;
containstwo=tree.contains(100);
cout << "true " << containstwo << endl;


AVLTree<int> test2;
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

AVLTree<int> test3;

    std::cout << "tree: " << std::endl;
    test3.print_tree();
    test3.make_empty();


AVLTree<string> test4;
    //making error statements with empty trees
        try{
            test4.find_min();
        }
        catch(std::invalid_argument){
            cout<<"First Catch"<<endl;
        }

        try{
            test4.find_max();
        }
        catch(std::invalid_argument){
            cout<<"Second Catch"<<endl;
        }
        test4.print_tree();
    
AVLTree<int> t;
////AVL tree that is left heavy as well as having negative numbers as well
t.insert(10);
t.insert(10);
t.insert(8);
t.insert(-7);
t.insert(6);
t.insert(6);
t.insert(-4);
t.insert(3);
t.insert(-2);
t.insert(1);

}
