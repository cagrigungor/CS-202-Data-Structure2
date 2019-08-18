/**
* Title : MaxHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MaxHeap implement
*/
#include "MaxHeap.h"
#include <string>
#include <iostream>

using namespace std;
MaxHeap::MaxHeap()
{
    size = 0;
}


void MaxHeap::insert(const int& newItem)
{
    if(size >= MAX_HEAP)
        cout<<"Heap Full."<<endl;
    else
    {
        items[size] = newItem;

        int place = size;
        int parent = (place-1)/2;

        while( (place > 0) && (items[place] > items[parent]) )
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
int MaxHeap::peek()
{
    return items[0];
}
int MaxHeap::extractMax()
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
int MaxHeap::sizeGet()
{
    return size;
}


void MaxHeap::heapRebuild(int root)
{
    int child = 2 * root + 1;
    if( child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) &&
           (items[rightChild] > items[child]))
        {
            child = rightChild;
        }
        if(items[root] < items[child])
        {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}
int MaxHeap::get(int index)
{
    return items[index];
}
