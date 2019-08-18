/**
* Title : MinHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MinHeap implement
*/
#ifndef MINHEAP_H
#define MINHEAP_H
const int MIN_HEAP = 100;

class MinHeap
{
    public:
    MinHeap();
    void insert(const int & newItem);
    int peek();
    int extractMin();
    int sizeGet();
    int get(int index);

    protected:
    void heapRebuild(int root);


    private:
    int items[MIN_HEAP];
    int size;
};

#endif // MIXHEAP_H
