#ifndef QVEVE_H
#define QVEVE_H


#include <iostream>
#include <cstdlib>
using namespace std;

// Define the default queue capacity
#define SIZE 1000

// A class for storing queue
class Queue
{
    // array for storing queue elements
    int* arr;       
    // maximum capacity queue
    int capacity;  
    // front points to the front element in the queue (if there is one)
    int front; 
    // rear points to the last item in the queue
    int rear;  
    // current size queue
    int count;      

public:
    // constructor
    Queue(int size = SIZE);   
    // destructor
    ~Queue();                  

    int pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();

   
};

void clear(string input);

#endif
