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
    queue_elem heap[QUEUE_SIZE];                   // contains the queue
    int heap_size;                                 // contains the number of elements
    void Heapify(int start_point);                 // to put elements in the correct order
    void Swap(queue_elem& el1, queue_elem& el2);   // to swap two elements in the heap
public:
    void Queue_Insert(Data value, int priority);   // to add element
    queue_elem Extract_Elem();                     // removes the elements with the highest prioiry from queue
    bool Queue_Is_Not_Empty();                     // checks if the queue is empty
    void Queue_Dump();                             // to print queue's contents
    priority_queue();
    ~priority_queue();
};

priority_queue::priority_queue()
{
    heap_size = 0;
    for (int i = 0; i < QUEUE_SIZE; ++i)
        heap[i] = {0, 0};
}

priority_queue::~priority_queue()
{

}

queue_elem priority_queue::Extract_Elem()
{
    assert( Queue_Is_Not_Empty() );
    queue_elem max = heap[0];
    heap[0] = heap[heap_size--];
    Heapify(0);
    return max;
}

bool priority_queue::Queue_Is_Not_Empty()
{
    if (heap_size == 0) return false; else return true;
}

void priority_queue::Heapify(int start_point)
{
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
