#ifndef PRIOR_Q_H
#define PRIOR_Q_H

#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

typedef int data;

struct queue_elem
{
    data value;
    int priority;
};

class priority_queue
{
private:
    // contains the queue
    queue_elem* heap;
    // contains the number of elements
    int heap_size;

    // to put elements in the correct order
    void Heapify(int start_point);
    // to swap two elements in the heap
    void Swap(queue_elem& el1, queue_elem& el2);
public:
    // to know how many elements are in the queue already
    int Get_Size() const;
    // adds an element
    void Insert(int priority, data val);
    // removes the element with the highest prioiry from queue (and returns it)
    queue_elem Extract_Elem();
    // checks if the queue is empty
    bool Is_Empty() const;
    // prints queue's contents
    void Dump() const;
    priority_queue(int queue_size);
    ~priority_queue();
};

#endif  // PRIOR_Q_H
