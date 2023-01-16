#include <iostream>
#include "stack.h"

int main() {
    // TODO(student): test your code
    Stack<int> stack;

    // push 3 values onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);


    // remove the top element
    stack.pop();

    cout<<stack.pop()<<endl;


    // access the top element
    stack.top();

    cout<<stack.top()<<endl;

    //see the size 
    stack.size();

    cout<<"Size:"<< stack.size()<<endl;

    /////////////////////////////////////////////char

    Stack<char> stack2;

    stack2.push('a');
    stack2.push('b');
    stack2.push('c');

    // remove the top element
    stack2.pop();

    cout<<stack2.pop()<<endl;


    // access the top element
    stack2.top();

    cout<<stack2.top()<<endl;

    //see the size 
    stack2.size();

    cout<<"Size:"<< stack2.size()<<endl;


    //////////////////////////////////////////bad cases
    Stack<int>x;

    try{
        x.pop();
    }
    catch(std::out_of_range){
        cout<<"First Catch"<<endl;
    }

    try{
        x.top();
    }
    catch(std::out_of_range){
        cout<<"Second Catch"<<endl;
    }


    cout<<"End of Test Cases"<<endl;



}
