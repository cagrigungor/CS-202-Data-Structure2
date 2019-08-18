/**
* Title : HuffmanQueue
* Author : Mustafa �a�r� G�ng�r
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanQueue implement
*/
#include "HuffmanQueue.h"
#include <iostream>
using namespace std;
HuffmanQueue::HuffmanQueue()
{
    //ctor
}

int HuffmanQueue::getSize()
{
    return h.sizeGet();
}
bool HuffmanQueue::pqIsEmpty()
{
    return h.isEmpty();
}

void HuffmanQueue::pqInsert(MinHeapNode* newNode)
{
    h.insert(newNode);
}

MinHeapNode* HuffmanQueue::pqDelete()
{
    return h.extractMin();
}
