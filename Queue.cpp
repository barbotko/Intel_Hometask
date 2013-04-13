#include "Priority_Queue.h"

int main()
{
    return 0;
}


//---------------------------------------------------------------
//                  PUBLIC METHODS
//---------------------------------------------------------------

void priority_queue::Insert(data val, int priority)
{
    int el_num = ++heap_size;
    heap[el_num].value = val;
    heap[el_num].priority = priority;
    //  since (2i + 1) and (2i + 2) elements have the same i parent (int) ( (i - 1) / 2 ) is
    //  way to find out who is an element's parent
    while (el_num > 0 && heap[ (int)( (el_num - 1) / 2 ) ].priority < heap[el_num].priority )
    {
        Swap(heap[ (int)( (el_num - 1) / 2 ) ], heap[el_num]);
        el_num = (int)( (el_num - 1) / 2 );
    }
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

priority_queue::priority_queue(int queue_size)
{
    heap_size = 0;
    heap = new queue_elem[queue_size];
}

priority_queue::~priority_queue()
{
    delete [] heap;
}

//---------------------------------------------------------------
//                  PRIVATE METHODS
//---------------------------------------------------------------

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
