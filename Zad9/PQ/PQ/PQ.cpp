#include <iostream>
#include "PriorityQueue.h"


int main()
{
    PriorityQueue pq;
    int l;
    for (int i = 0; i < 15; i++)
    {
        l = rand() % 20;
        pq.Queue(l);
        std::cout << l << "   ";
    }
    std::cout << '\n' << "   ";
    for (int i = 0; i < 15; i++)
    {
        std::cout << pq.Pop() << "   ";
    }
}
