#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "qveve.h"


// Constructor for initialising the queue
Queue::Queue(int size)
{
    arr = new int[size]; 
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to queue
Queue::~Queue() {
    delete[] arr;
}

// Auxiliary function for removing the front item from the queue
int Queue::pop()
{
    // check for empty queue
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];

    front = (front + 1) % capacity;
    count--;

    return x;
}

// Auxiliary function for adding an item to the queue
void Queue::push(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }


    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Auxiliary function to return the first queue item
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Auxiliary function to return queue size
int Queue::size() 
{
    return count;
}

// Auxiliary function to check whether the queue is empty or not
bool Queue::isEmpty() 
{
    return (size() == 0);
}

// Auxiliary function to check whether the queue is full or empty
bool Queue::isFull()
{
    return (size() == capacity);
}

// The main function this was all about
void clear(string input)
{
	Queue output;
	int leng = input.size();

	int dictionary[35];
	string dict[35];

	cout << endl << "source string > " << input;

	/*in this block of code, you need to make the string an array of numbers*/
	int j = 0;
	//there is a loop that breaks down the string into individual numbers
	for (int i = 0; i < leng; i++)
	{
		if (input[i] != ' ')
		{
			dict[j] = dict[j] + input[i];
		}
		else
		{
			j += 1;
			continue;
		}
	}

	for (int i = 0; i < 35; i++)
	{
		dictionary[i] = std::stoi(dict[i]);
	}

	//and now the fun part - clearing duplicates in microclusters
		for (int i = 34; i > 0; i--)
		{
			if (dictionary[i] == dictionary[i - 1])
				dictionary[i] = 0;
		}

		for (int i = 0; i < 35; i++)
		{
			if (dictionary[i] != 0)
				output.push(dictionary[i]);
		}

		cout << endl << "after the cleaning process > ";
		while (!output.isEmpty())
		{
			int val = output.peek();
			output.pop();
			cout << val << " ";
		}
}