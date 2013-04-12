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
    queue_elem heap[QUEUE_SIZE];                        // contains the queue
    int heap_size;                                      // contains the number of elements

    void Heapify(int start_point);                      // to put elements in the correct order
    void Swap(queue_elem& el1, queue_elem& el2);        // to swap two elements in the heap
    void Heap_Increase_Key (int el_num, int new_prior); // to change some element's priority
public:
    void Insert(Data value, int priority);        // to add element
    queue_elem Extract_Elem();                          // removes the elements with the highest prioiry from queue
<<<<<<< HEAD
    bool Is_Empty() const;                        // checks if the queue is empty
    void Dump() const;                            // to print queue's contents
=======
    bool Queue_Is_Empty() const;                        // checks if the queue is empty
    void Queue_Dump() const;                            // to print queue's contents
>>>>>>> ec1d7fb86e4bdb35e8ddf702159d217b9f497dca
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
<<<<<<< HEAD
    assert( !( Is_Empty() ) );
=======
    assert( !( Queue_Is_Empty() ) );
>>>>>>> ec1d7fb86e4bdb35e8ddf702159d217b9f497dca
    queue_elem max = heap[0];
    heap[0] = heap[heap_size--];
    Heapify(0);
    return max;
}

<<<<<<< HEAD
bool priority_queue::Is_Empty() const
=======
bool priority_queue::Queue_Is_Empty() const
>>>>>>> ec1d7fb86e4bdb35e8ddf702159d217b9f497dca
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
