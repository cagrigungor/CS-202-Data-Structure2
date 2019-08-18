/**
* Title : MaxHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MaxHeap implement
*/
#ifndef MAXHEAP_H
#define MAXHEAP_H
const int MAX_HEAP = 100;

class MaxHeap
{
    public:
    MaxHeap();
    void insert(const int & newItem);
    int peek();
    int extractMax();
    int sizeGet();
    int get(int index);

    protected:
    void heapRebuild(int root);


    private:
    int items[MAX_HEAP];
    int size;
};

#endif // MAXHEAP_H
