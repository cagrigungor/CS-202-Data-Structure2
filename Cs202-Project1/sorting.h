/**
* Title : Algorithm Efficiency and Sorting
* Author : Mustafa Çaðrý Güngor
* ID: 21602251
* Section : 2
* Assignment : 1
* Description : This is sorting.h that describes several methods
*/

#ifndef SORTING_H
#define SORTING_H


class sorting
{
    public:
        void bubbleSort(int *arr, int size, int &compCount, int &moveCount);
        void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
        void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
        void radixSort(int *arr, int size, int d);
        void printArray(int* arr, int size);
        void performanceAnalysis();


    protected:

    private:
};

#endif // SORTING_H
