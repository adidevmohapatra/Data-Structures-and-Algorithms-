#include <iostream>
#include "array_list.h"

int main() {
    // TODO(student): test your code
    
    ArrayList<char> list2;
    ////char values 
    // insert 3 values at the end of the list
    list2.insert(0, 'a');
    list2.insert(1, 'b');
    list2.insert(2, 'c');
    list2.insert(0, 'd');  //add to first 
    list2.insert(2, 'e');  //add to middle
    list2.insert(5, 'f');  //add to end
    for(size_t i = 0; i < list2.size(); i++) {
        cout << list2[i] << endl;
    }
    // access the element at index 1 and 4
    list2[1];
    cout<<"Element Access:"<<list2[1]<<endl;
    list2[4];
    cout<<"Element Access:"<<list2[4]<<endl;


    // get the size
    list2.size();
    cout<<"List Size:"<<list2.size()<<endl;

    // remove the middle element
    list2.remove(1);
    for(size_t i = 0; i < list2.size(); i++) {
        cout << list2[i] << endl;
    }
    cout<<endl;
    //remove the first
    list2.remove(0);
    for(size_t i = 0; i < list2.size(); i++) {
        cout << list2[i] << endl;
    }
    cout<<endl;
    //remove the last 
    list2.remove(3);
    for(size_t i = 0; i < list2.size(); i++) {
        cout << list2[i] << endl;
    }
    cout<<endl;

////////////////////////////////////////////////////////////////////////////////
    ///int values 
    // insert 3 values at the end of the list
    ArrayList<int> list;
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.insert(0, 8);  //add to first 
    list.insert(2, 6);  //add to middle
    list.insert(5, 9);  //add to end
    for(size_t i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
    // access the element at index 1 and 4
    list[1];
    cout<<"Element Access:"<<list[1]<<endl;
    list[4];
    cout<<"Element Access:"<<list[4]<<endl;


    // get the size
    list.size();
    cout<<"List Size:"<<list.size()<<endl;

    // remove the middle element
    list.remove(1);
    for(size_t i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
    cout<<endl;
    //remove the first
    list.remove(0);
    for(size_t i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
    cout<<endl;
    //remove the last 
    list.remove(3);
    for(size_t i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }


    //////////////////////////////////////////bad cases

    ArrayList<int>x;

    
        try{
            x.insert(4,6);
        }
        catch(std::out_of_range){
            cout<<"First Catch"<<endl;
        }

        try{
            x.remove(3);
        }
        catch(std::out_of_range){
            cout<<"Second Catch"<<endl;
        }

    cout<<"End of Test Cases"<<endl;
    
}
