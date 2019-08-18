/**
* Title : HuffmanHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanHeap implement
*/
#ifndef HUFFMANHEAP_H
#define HUFFMANHEAP_H
const int HUFFMAN_HEAP = 100;

    struct MinHeapNode
{
    char character;
    int freq;
    MinHeapNode *left,*right;
};
class HuffmanHeap
{
    public:
    HuffmanHeap();
    ~HuffmanHeap();
    bool isEmpty();
    void insert(MinHeapNode* newNode);
    MinHeapNode* peek();
    MinHeapNode* extractMin();
    int sizeGet();

    protected:
    void heapRebuild(int root);


    private:
    MinHeapNode** items;
    int size;
    int sizeM;
};

#endif // MIXHEAP_H
