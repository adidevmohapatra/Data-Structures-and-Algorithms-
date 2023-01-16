#include <iostream>
#include "doubly_linked_list.h"
using namespace std;
int main() {
    // TODO(student): test your code

        DoublyLinkedList<int> list;
    // insert 3 values at the end of the list
        list.insert(0, 1);

        list.insert(1, 2);

        list.insert(2, 3);

        list.insert(0, 4);//front

        list.insert(2, 7);//middle

        list.insert(5, 6);//end

        for (size_t i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        // access the element at index 1
        list[1];
        cout<<"Element Access:"<<list[1]<<endl;
        // access the element at index 4
        list[4];
        cout<<"Element Access:"<<list[4]<<endl;
    

        //get the size
        list.size();
        cout<< "List Size:"<<list.size()<<endl;
        //remove last element
        list.remove(5);
        for (size_t i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        cout<<endl;

        // remove the middle element
        list.remove(1);
        for (size_t i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        cout<<endl;
        //remove the first element
        list.remove(0);
        for (size_t i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        cout<<endl;

        //remove last element
        list.remove(0);
        for (size_t i=0;i<list.size();++i){
            cout<<list[i]<<endl;
        }
        cout<<endl;
        //////////////////////////////////////////char cases
        DoublyLinkedList<char> list2;
    // insert 3 values at the end of the list
        list2.insert(0, 'a');

        list2.insert(1, 'b');

        list2.insert(2, 'c');

        list2.insert(0, 'd');//front

        list2.insert(2, 'e');//middle

        list2.insert(5, 'f');//end

        for (size_t i=0;i<list2.size();++i){
            cout<<list2[i]<<endl;
        }
        // access the element at index 1
        list2[1];
        cout<<"Element Access:"<<list2[1]<<endl;
        // access the element at index 4
        list2[4];
        cout<<"Element Access:"<<list2[4]<<endl;
    

        //get the size
        list2.size();
        cout<< "List Size:"<<list2.size()<<endl;
        //remove last element
        list2.remove(5);
        for (size_t i=0;i<list2.size();++i){
            cout<<list2[i]<<endl;
        }
        cout<<endl;

        // remove the middle element
        list2.remove(1);
        for (size_t i=0;i<list2.size();++i){
            cout<<list2[i]<<endl;
        }
        cout<<endl;
        //remove the first element
        list2.remove(0);
        for (size_t i=0;i<list2.size();++i){
            cout<<list2[i]<<endl;
        }
        cout<<endl;

        //remove last element
        list2.remove(0);
        for (size_t i=0;i<list2.size();++i){
            cout<<list2[i]<<endl;
        }
        cout<<endl;

        //////////////////////////////////////////bad cases

        DoublyLinkedList<int>x;

        try{
            x.insert(4,6);
        }
        catch(std::out_of_range){
            cout<<"First Catch"<<endl;
        }



        cout<<"End of Test Cases"<<endl;


    
}