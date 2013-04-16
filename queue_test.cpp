#include "Priority_Queue.h"
#include "Queue.cpp"

int main()
{
    priority_queue qu(5);
    qu.Insert(1, -4);
    qu.Dump();
    qu.Insert(6, -2);
    qu.Dump();
    qu.Insert(5, -1);
    qu.Dump();
    qu.Insert(10, -3);
    qu.Dump();
    qu.Extract_Elem();
    qu.Dump();
    return 0;
}
