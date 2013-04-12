#ifndef PRIOR_Q_H
#define PRIOR_Q_H

#include <iostream>
#include <assert.h>
#include <cmath>

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
    // checks if the queue is empty
    bool Queue_Is_Empty() const;
    priority_queue();
    ~priority_queue();
};

//---------------------------------------------------------------
//                  PUBLIC METHODS
//---------------------------------------------------------------

void priority_queue::Insert(Data value, int priority)
{

}

queue_elem priority_queue::Extract_Elem()
{
    assert( !( Is_Empty() ) );
    queue_elem max = heap[0];
    heap[0] = heap[heap_size--];
    Heapify(0);
    return max;
}

bool priority_queue::Is_Empty() const
{
    return (heap_size == 0);
}

void priority_queue::Dump() const
{

}

priority_queue::priority_queue()
{
    heap_size = 0;
    for (int i = 0; i < QUEUE_SIZE; ++i)
        heap[i] = {0, 0};
}

priority_queue::~priority_queue()
{

}

//---------------------------------------------------------------
//                  PRIVATE METHODS
//---------------------------------------------------------------

void priority_queue::Heap_Increase_Key (int el_num, int new_prior)
{
    assert(new_prior > heap[el_num].priority);
    heap[el_num].priority = new_prior;
    while (el_num > 0 && heap[ (int) trunc( (el_num - 1) / 2 ) ].priority < heap[el_num].priority )
    {
        Swap(heap[ (int) trunc( (el_num - 1) / 2 ) ], heap[el_num]);
        el_num = (int) trunc( (el_num - 1) / 2 );
    }
}

void priority_queue::Heapify(int start_point)
{
    if (start_point == heap_size) return;
    int largest = start_point;
    int left  = 2 * start_point + 1;
    int right = 2 * start_point + 2;
    if (left <= heap_size && heap[left].priority >= heap[largest].priority)
        largest = left;
    else if (right <= heap_size && heap[right].priority >= heap[largest].priority)
        largest = right;
    if (largest != start_point) Swap(heap[largest], heap[start_point]);
    Heapify(largest);
    return;
}

void priority_queue::Swap(queue_elem& el1, queue_elem& el2)
{
    queue_elem exch = el1;
    el1 = el2;
    el2 = exch;
    return;
}

#endif      // PRIOR_Q_H
