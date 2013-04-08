const int QUEUE_SIZE = 100;
typedef Data int;

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
    void Heapify();                                // to put elements in the correct order
public:
    void Queue_Insert(Data value, int priority);   // to add element
    void Extract_Elem();                           // removes the elements with the highest prioiry from queue
    bool Queue_Is_Empty();                         // checks if the queue is empty
    void Queue_Dump();                             // to print queue's contents
    priority_queue();
    ~priority_queue();
};

priority_queue::priority_queue()
{
    heap_size = 0;
    for (int i = 0, i < QUEUE_SIZE; ++i)
    {
        heap[i].priority = 0;
        heap[i].value = 0;
    }
}

priority_queue::~priority_queue()
{

}

