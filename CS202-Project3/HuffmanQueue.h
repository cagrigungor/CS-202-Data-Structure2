/**
* Title : HuffmanQueue
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanQueue implement
*/
#ifndef HUFFMANQUEUE_H
#define HUFFMANQUEUE_H
#include "HuffmanHeap.h"

class HuffmanQueue
{
    public:
    HuffmanQueue();
    int getSize();
    bool pqIsEmpty();
    void pqInsert(MinHeapNode* newNode);
    MinHeapNode* pqDelete();
    protected:

    private:
    HuffmanHeap h;
};

#endif // HUFFMANQUEUE_H
