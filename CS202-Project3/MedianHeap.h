/**
* Title : MedianHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MedianHeap implement
*/
#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H
#include "MaxHeap.h"
#include "MinHeap.h"


class MedianHeap
{
    public:
    MedianHeap();
    void insert(int value);
    int findMedian();
    void display();

    protected:

    private:
    MaxHeap max;
    MinHeap min;
};

#endif // MEDIANHEAP_H
