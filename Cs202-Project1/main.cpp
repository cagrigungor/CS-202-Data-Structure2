/**
* Title : Algorithm Efficiency and Sorting
* Author : Mustafa Çaðrý Güngor
* ID: 21602251
* Section : 2
* Assignment : 1
* Description : This is main class that sorts the given array with different sorting methods and calls performAnalysis method
*/

#include <iostream>
#include "sorting.h"
#include <string>
using namespace std;
int main()
{

    sorting cs202;

    int sizeBubble = 16;
    int* arrBubble = new int[sizeBubble];
    arrBubble[0] = 7;
    arrBubble[1] = 3;
    arrBubble[2] = 6;
    arrBubble[3] = 12;
    arrBubble[4] = 13;
    arrBubble[5] = 4;
    arrBubble[6] = 1;
    arrBubble[7] = 9;
    arrBubble[8] = 15;
    arrBubble[9] = 0;
    arrBubble[10] = 11;
    arrBubble[11] = 14;
    arrBubble[12] = 2;
    arrBubble[13] = 8;
    arrBubble[14] = 10;
    arrBubble[15] = 5;

    int compCountBubble = 0,moveCountBubble=0;
    cs202.bubbleSort(arrBubble, sizeBubble, compCountBubble, moveCountBubble);
    cout<<"Bubble Sorting:"<<endl;
    cs202.printArray(arrBubble,sizeBubble);

    int sizeQuick = 16;
    int* arrQuick = new int[sizeQuick];
    arrQuick[0] = 7;
    arrQuick[1] = 3;
    arrQuick[2] = 6;
    arrQuick[3] = 12;
    arrQuick[4] = 13;
    arrQuick[5] = 4;
    arrQuick[6] = 1;
    arrQuick[7] = 9;
    arrQuick[8] = 15;
    arrQuick[9] = 0;
    arrQuick[10] = 11;
    arrQuick[11] = 14;
    arrQuick[12] = 2;
    arrQuick[13] = 8;
    arrQuick[14] = 10;
    arrQuick[15] = 5;

    int compCountQuick = 0,moveCountQuick=0;
    cs202.quickSort(arrQuick, 0, sizeQuick-1, compCountQuick, moveCountQuick);
    cout<<"Quick Sorting:"<<endl;
    cs202.printArray(arrQuick,sizeQuick);

    int sizeMerge = 16;
    int* arrMerge = new int[sizeMerge];
    arrMerge[0] = 7;
    arrMerge[1] = 3;
    arrMerge[2] = 6;
    arrMerge[3] = 12;
    arrMerge[4] = 13;
    arrMerge[5] = 4;
    arrMerge[6] = 1;
    arrMerge[7] = 9;
    arrMerge[8] = 15;
    arrMerge[9] = 0;
    arrMerge[10] = 11;
    arrMerge[11] = 14;
    arrMerge[12] = 2;
    arrMerge[13] = 8;
    arrMerge[14] = 10;
    arrMerge[15] = 5;

    int compCountMerge = 0,moveCountMerge=0;
    cs202.mergeSort(arrMerge,0, sizeMerge-1, compCountMerge, moveCountMerge);
    cout<<"Merge Sorting:"<<endl;
    cs202.printArray(arrMerge,sizeMerge);

    int sizeRadix = 16;
    int* arrRadix = new int[sizeRadix];
    arrRadix[0] = 7;
    arrRadix[1] = 3;
    arrRadix[2] = 6;
    arrRadix[3] = 12;
    arrRadix[4] = 13;
    arrRadix[5] = 4;
    arrRadix[6] = 1;
    arrRadix[7] = 9;
    arrRadix[8] = 15;
    arrRadix[9] = 0;
    arrRadix[10] = 11;
    arrRadix[11] = 14;
    arrRadix[12] = 2;
    arrRadix[13] = 8;
    arrRadix[14] = 10;
    arrRadix[15] = 5;

    cs202.radixSort(arrRadix, sizeRadix, 10);
    cout<<"Radix Sorting:"<<endl;
    cs202.printArray(arrRadix,sizeRadix);

    cs202.performanceAnalysis();
    delete[] arrBubble;
    delete[] arrQuick;
    delete[] arrMerge;
    delete[] arrRadix;
    return 0;
}
