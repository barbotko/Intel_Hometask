#ifndef PRIOR_Q_H
#define PRIOR_Q_H

#include <iostream>
#include <assert.h>

const int QUEUE_SIZE = 100;
typedef int Data;

struct queue_elem
{
    Data value;
    int priority;
};

class priority_queue
{
private:
    // contains the queue
    queue_elem heap[QUEUE_SIZE];
    // contains the number of elements
    int heap_size;

    // to put elements in the correct order
    void Heapify(int start_point);
    // to swap two elements in the heap
    void Swap(queue_elem& el1, queue_elem& el2);
    // to increase some element's priority
    void Heap_Increase_Key (int el_num, int new_prior);
public:
    // adds an element
    void Insert(Data value, int priority);
    // removes the element with the highest prioiry from queue (and returns it)
    queue_elem Extract_Elem();
    // checks if the queue is empty
    bool Is_Empty() const;
    // prints queue's contents
    void Dump() const;
    priority_queue();
    ~priority_queue();
};

#endif  // PRIOR_Q_H
