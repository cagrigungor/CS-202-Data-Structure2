/**
* Title : HuffmanHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanHeap implement
*/
#include "HuffmanHeap.h"
#include <string>
#include <iostream>

using namespace std;

HuffmanHeap::HuffmanHeap()
{
    items = new MinHeapNode*[HUFFMAN_HEAP];

    size = 0;
    sizeM = 0;
}
HuffmanHeap::~HuffmanHeap()
{
    for (int i=1; i<size; i++)
    {
        if(items[i])
        {
            delete[] items[i];
        }
    }

    delete[] items;

}
bool HuffmanHeap::isEmpty()
{
    return size == 0;
}
void HuffmanHeap::insert(MinHeapNode* newNode)
{
    if(size >= HUFFMAN_HEAP)
        cout<<"Heap Full."<<endl;
    else
    {
        items[size] = newNode;
        int place = size;
        int parent = (place-1)/2;
        while( (place > 0) && (items[place]->freq < items[parent]->freq))
        {
             MinHeapNode* temp = items[parent];
             items[parent] = items[place];
             items[place] = temp;
             place = parent;
             parent = (place - 1) / 2;
        }
        ++size;
        if(size > sizeM)
            sizeM = size;
    }
}
MinHeapNode* HuffmanHeap::peek()
{
    return items[0];
}
MinHeapNode* HuffmanHeap::extractMin()
{
    if( size <= 0 )
        cout<<"Heap Empty."<<endl;
    else
    {
        MinHeapNode* rootItem = items[0];
        items[0] = items[size-1];
        //delete items[size-1];
        //MinHeapNode* rootItem = new MinHeapNode();
        //items[0]->character = items[size-1]->character;
        //items[0]->freq = items[size-1]->freq;
        //items[0] = items[size-1];
        size--;

        heapRebuild(0);
        return rootItem;
    }
}
int HuffmanHeap::sizeGet()
{
    return size;
}


void HuffmanHeap::heapRebuild(int root)
{
    int child = 2 * root + 1;
    if( child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) &&
           (items[rightChild]->freq < items[child]->freq))
        {
            child = rightChild;
        }
        if(items[root]->freq > items[child]->freq)
        {
            MinHeapNode* temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}

