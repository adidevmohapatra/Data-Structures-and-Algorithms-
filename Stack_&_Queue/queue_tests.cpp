#include <iostream>
#include "queue.h"

int main() {
    // TODO(student): test your code
    // make an empty queue
    Queue<int> queue;

    // enqueue 3 values into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    


    // remove the front element
    queue.dequeue();
    cout<<queue.dequeue()<<endl;
    // access the front element
    queue.front();
    cout<<queue.front()<<endl;
    //////////////////////////////////////////char

    Queue<char> queue1;

    // enqueue 3 values into the queue
    queue1.enqueue('a');
    queue1.enqueue('b');
    queue1.enqueue('c');
    


    // remove the front element
    queue1.dequeue();
    cout<<queue1.dequeue()<<endl;

    // access the front element
    queue1.front();
    cout<<queue1.front()<<endl;


//////////////////////////////////////////Bad cases
    Queue<int>x;

    try{
        x.dequeue();
    }
    catch(std::out_of_range){
        cout<<"First Catch"<<endl;
    }

    try{
        x.front();
    }
    catch(std::out_of_range){
        cout<<"Second Catch"<<endl;
    }


    cout<<"End of Test Cases"<<endl;
}
