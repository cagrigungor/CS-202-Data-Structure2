/**
* Title : MinHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MinHeap implement
*/
#include "MinHeap.h"
#include <string>
#include <iostream>

using namespace std;
MinHeap::MinHeap()
{
    size = 0;
}


void MinHeap::insert(const int& newItem)
{
    if(size >= MIN_HEAP)
        cout<<"Heap Full."<<endl;
    else
    {
        items[size] = newItem;

        int place = size;
        int parent = (place-1)/2;

        while( (place > 0) && (items[place] < items[parent]) )
        {
             int temp = items[parent];
             items[parent] = items[place];
             items[place] = temp;

             place = parent;
             parent = (place - 1) / 2;
        }
        ++size;
    }
}
int MinHeap::peek()
{
    return items[0];
}
int MinHeap::extractMin()
{
    if( size <= 0 )
        cout<<"Heap Empty."<<endl;
    else
    {
        int rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
        return rootItem;
    }
}
int MinHeap::sizeGet()
{
    return size;
}


void MinHeap::heapRebuild(int root)
{
    int child = 2 * root + 1;
    if( child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) &&
           (items[rightChild] < items[child]))
        {
            child = rightChild;
        }
        if(items[root] > items[child])
        {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}
int MinHeap::get(int index)
{
    return items[index];
}
