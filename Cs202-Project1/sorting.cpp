/**
* Title : Algorithm Efficiency and Sorting
* Author : Mustafa Çaðrý Güngor
* ID: 21602251
* Section : 2
* Assignment : 1
* Description : This is sorting.cpp that includes several methods
*/

#include <iostream>
#include "sorting.h"
#include <string>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <ctime>
using namespace std;


void sorting::bubbleSort(int *arr, int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;
    bool sorted = false;
    for(int pass = 1; (pass < size) && !sorted; ++pass ) {
        sorted = true;
        for(int index = 0; index < size - pass; ++index) {
            int nextIndex = index +1;
            compCount++;
            if( arr[index] > arr[nextIndex] ){
                swap(arr[index], arr[nextIndex]);
                moveCount = moveCount + 3;
                sorted = false;
            }
        }
    }
}

void sorting::quickSort(int *arr, int first ,int last, int &compCount, int &moveCount)
{
    int pivotIndex;

    if( first < last ){
        int pivot = arr[first];
        int lastS1 = first;
        int firstUnknown = first + 1;

        for( ; firstUnknown <= last; ++ firstUnknown){
            compCount++;
            if(arr[firstUnknown] < pivot){
                ++lastS1;
                swap(arr[firstUnknown], arr[lastS1]);
                moveCount = moveCount + 3;
            }
        }
        swap(arr[first], arr[lastS1]);
        moveCount = moveCount + 3;
        pivotIndex = lastS1;

        quickSort(arr,first,pivotIndex-1,compCount,moveCount);
        quickSort(arr,pivotIndex+1,last,compCount,moveCount);
    }
}
void sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if( first < last ){
        int mid = (first + last)/2;

        mergeSort(arr,first,mid,compCount,moveCount);
        mergeSort(arr, mid + 1, last,compCount,moveCount);

        int tempArr[last];

        int first1 = first;
        int last1 = mid;
        int first2 = mid + 1;
        int last2 = last;
        int index = first1;

        for(;(first1<=last1) && (first2<=last2); ++index){
            if(arr[first1] < arr[first2]){
                tempArr[index] = arr[first1];
                ++first1;
            }
            else{
                tempArr[index] = arr[first2];
                ++first2;
            }
            moveCount++;
            compCount++;

        }
        for(; first1 <= last1; ++first1, ++index){
            tempArr[index] = arr[first1];
            moveCount++;
        }

        for(; first2 <= last2; ++first2, ++index){
            tempArr[index] = arr[first2];
            moveCount++;
        }

        for(index = first; index <= last; ++index){
            arr[index] = tempArr[index];
            moveCount++;
        }
        //delete[] tempArr;
    }
}

void sorting::radixSort(int *arr, int size, int d){

    /*int** group = new int*[10];
    for(int i = 0; i < 10; i++)
        group[i] = new int[size];*/

    for( int i = 1; i<=d ; i = i*10)
    {
        //for(int i = 0; i < 10; i++)
          //  group[i] = {0};
        int group[10][size];
        int counter[10] = {0};
        for(int j = 0; j < size ; j++)
        {
            int k = (arr[j] / i) % 10;
            group[k][counter[k]] = arr[j];
            counter[k]++;
        }
        int tempIndexArr = 0;
        for(int k = 0; k < 10; k++)
        {
            for(int l = 0; l < counter[k]; l++)
            {
                arr[tempIndexArr] = group[k][l];
                tempIndexArr++;
            }
        }
    }

   /* for(int i = 0; i < 10; i++)
        delete[] group[i];
    delete group;*/
}
void sorting::printArray(int* arr, int size)
{
    for( int i = 0; i < size-1; i++ )
        cout<<arr[i]<<",";
    cout<<arr[size-1]<<endl;
}

void sorting::performanceAnalysis()
{

    //Creating arrays with 2000 integer
    int* array2000Bubble = new int[2000];
    for( int i = 0; i < 2000; i++ )
        array2000Bubble[i] = rand() % 30000;

    int* array2000Quick = new int[2000];
    for( int i = 0; i < 2000; i++ )
        array2000Quick[i] = array2000Bubble[i];

    int* array2000Merge = new int[2000];
    for( int i = 0; i < 2000; i++ )
        array2000Merge[i] = array2000Bubble[i];

    int* array2000Radix = new int[2000];
    for( int i = 0; i < 2000; i++ )
        array2000Radix[i] = array2000Bubble[i];

    //Creating arrays with 6000 integer
    int* array6000Bubble = new int[6000];
    for( int i = 0; i < 6000; i++ )
        array6000Bubble[i] = rand() % 30000;

    int* array6000Quick = new int[6000];
    for( int i = 0; i < 6000; i++ )
        array6000Quick[i] = array6000Bubble[i];

    int* array6000Merge = new int[6000];
    for( int i = 0; i < 6000; i++ )
        array6000Merge[i] = array6000Bubble[i];

    int* array6000Radix = new int[6000];
    for( int i = 0; i < 6000; i++ )
        array6000Radix[i] = array6000Bubble[i];

    //Creating arrays with 10000 integer
    int* array10000Bubble = new int[10000];
    for( int i = 0; i < 10000; i++ )
        array10000Bubble[i] = rand() % 30000;

    int* array10000Quick = new int[10000];
    for( int i = 0; i < 10000; i++ )
        array10000Quick[i] = array10000Bubble[i];

    int* array10000Merge = new int[10000];
    for( int i = 0; i < 10000; i++ )
        array10000Merge[i] = array10000Bubble[i];

    int* array10000Radix = new int[10000];
    for( int i = 0; i < 10000; i++ )
        array10000Radix[i] = array10000Bubble[i];


    //Creating arrays with 14000 integer
    int* array14000Bubble = new int[14000];
    for( int i = 0; i < 14000; i++ )
        array14000Bubble[i] = rand() % 30000;

    int* array14000Quick = new int[14000];
    for( int i = 0; i < 14000; i++ )
        array14000Quick[i] = array14000Bubble[i];

    int* array14000Merge = new int[14000];
    for( int i = 0; i < 14000; i++ )
        array14000Merge[i] = array14000Bubble[i];

    int* array14000Radix = new int[14000];
    for( int i = 0; i < 14000; i++ )
        array14000Radix[i] = array14000Bubble[i];

    //Creating arrays with 18000 integer
    int* array18000Bubble = new int[18000];
    for( int i = 0; i < 18000; i++ )
        array18000Bubble[i] = rand() % 30000;

    int* array18000Quick = new int[18000];
    for( int i = 0; i < 18000; i++ )
        array18000Quick[i] = array18000Bubble[i];

    int* array18000Merge = new int[18000];
    for( int i = 0; i < 18000; i++ )
        array18000Merge[i] = array18000Bubble[i];

    int* array18000Radix = new int[18000];
    for( int i = 0; i < 18000; i++ )
        array18000Radix[i] = array18000Bubble[i];


    //Creating arrays with 22000 integer
    int* array22000Bubble = new int[22000];
    for( int i = 0; i < 22000; i++ )
        array22000Bubble[i] = rand() % 30000;

    int* array22000Quick = new int[22000];
    for( int i = 0; i < 22000; i++ )
        array22000Quick[i] = array22000Bubble[i];

    int* array22000Merge = new int[22000];
    for( int i = 0; i < 22000; i++ )
        array22000Merge[i] = array22000Bubble[i];

    int* array22000Radix = new int[22000];
    for( int i = 0; i < 22000; i++ )
        array22000Radix[i] = array22000Bubble[i];

    //Creating arrays with 26000 integer
    int* array26000Bubble = new int[26000];
    for( int i = 0; i < 26000; i++ )
        array26000Bubble[i] = rand() % 30000;

    int* array26000Quick = new int[26000];
    for( int i = 0; i < 26000; i++ )
        array26000Quick[i] = array26000Bubble[i];

    int* array26000Merge = new int[26000];
    for( int i = 0; i < 26000; i++ )
        array26000Merge[i] = array26000Bubble[i];

    int* array26000Radix = new int[26000];
    for( int i = 0; i < 26000; i++ )
        array26000Radix[i] = array26000Bubble[i];


    //Creating arrays with 30000 integer
    int* array30000Bubble = new int[30000];
    for( int i = 0; i < 30000; i++ )
        array30000Bubble[i] = rand() % 30000;

    int* array30000Quick = new int[30000];
    for( int i = 0; i < 30000; i++ )
        array30000Quick[i] = array30000Bubble[i];

    int* array30000Merge = new int[30000];
    for( int i = 0; i < 30000; i++ )
        array30000Merge[i] = array30000Bubble[i];

    int* array30000Radix = new int[30000];
    for( int i = 0; i < 30000; i++ )
        array30000Radix[i] = array30000Bubble[i];



    //Calculation of 2000 for Quick
    int compCount2000Quick = 0;
    int moveCount2000Quick = 0;
    double durationQuick2000;
    clock_t startTime = clock();
    for(int i = 0; i <100;i++){
        compCount2000Quick = 0;
        moveCount2000Quick = 0;
        for( int i = 0; i < 2000; i++ )
            array2000Quick[i] = array2000Bubble[i];
        quickSort(array2000Quick,0,1999,compCount2000Quick,moveCount2000Quick);
    }
    durationQuick2000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick2000 = durationQuick2000 /100;

    //Calculation of 2000 for Merge
    int compCount2000Merge = 0;
    int moveCount2000Merge = 0;
    double durationMerge2000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount2000Merge = 0;
        moveCount2000Merge = 0;
        for( int i = 0; i < 2000; i++ )
            array2000Merge[i] = array2000Bubble[i];
        mergeSort(array2000Merge,0,1999,compCount2000Merge,moveCount2000Merge);
    }
    durationMerge2000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge2000 = durationMerge2000 /100;

    //Calculation of 2000 for Radix
    double durationRadix2000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        for( int i = 0; i < 2000; i++ )
            array2000Radix[i] = array2000Bubble[i];
        radixSort(array2000Radix,2000,10000);
    }
    durationRadix2000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix2000 = durationRadix2000 / 100;

    //Calculation of 2000 for Bubble
    int compCount2000Bubble = 0;
    int moveCount2000Bubble = 0;
    double durationBubble2000;
    startTime = clock();
    bubbleSort(array2000Bubble,2000,compCount2000Bubble,moveCount2000Bubble);
    durationBubble2000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;



    //Calculation of 6000 for Quick
    int compCount6000Quick = 0;
    int moveCount6000Quick = 0;
    double durationQuick6000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount6000Quick = 0;
        moveCount6000Quick = 0;
        for( int i = 0; i < 6000; i++ )
            array6000Quick[i] = array6000Bubble[i];
        quickSort(array6000Quick,0,5999,compCount6000Quick,moveCount6000Quick);
    }
    durationQuick6000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick6000 = durationQuick6000 /100;

    //Calculation of 6000 for Merge
    int compCount6000Merge = 0;
    int moveCount6000Merge = 0;
    double durationMerge6000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount6000Merge = 0;
        moveCount6000Merge = 0;
        for( int i = 0; i < 6000; i++ )
            array6000Merge[i] = array6000Bubble[i];
        mergeSort(array6000Merge,0,5999,compCount6000Merge,moveCount6000Merge);
    }
    durationMerge6000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge6000 = durationMerge6000 /100;

    //Calculation of 6000 for Radix
    double durationRadix6000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array6000Radix,6000,10000);
    durationRadix6000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix6000 = durationRadix6000 / 100;

    //Calculation of 6000 for Bubble
    int compCount6000Bubble = 0;
    int moveCount6000Bubble = 0;
    double durationBubble6000;
    startTime = clock();
    bubbleSort(array6000Bubble,6000,compCount6000Bubble,moveCount6000Bubble);
    durationBubble6000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;



    //Calculation of 10000 for Quick
    int compCount10000Quick = 0;
    int moveCount10000Quick = 0;
    double durationQuick10000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount10000Quick = 0;
        moveCount10000Quick = 0;
        for( int i = 0; i < 10000; i++ )
            array10000Quick[i] = array10000Bubble[i];
        quickSort(array10000Quick,0,9999,compCount10000Quick,moveCount10000Quick);
    }
    durationQuick10000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick10000 = durationQuick10000 / 100;

    //Calculation of 10000 for Merge
    int compCount10000Merge = 0;
    int moveCount10000Merge = 0;
    double durationMerge10000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount10000Merge = 0;
        moveCount10000Merge = 0;
        for( int i = 0; i < 10000; i++ )
            array10000Merge[i] = array10000Bubble[i];
        mergeSort(array10000Merge,0,9999,compCount10000Merge,moveCount10000Merge);
    }
    durationMerge10000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge10000 = durationMerge10000 /100;

    //Calculation of 10000 for Radix
    double durationRadix10000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array10000Radix,10000,10000);
    durationRadix10000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix10000 = durationRadix10000 / 100;

    //Calculation of 10000 for Bubble
    int compCount10000Bubble = 0;
    int moveCount10000Bubble = 0;
    double durationBubble10000;
    startTime = clock();
    bubbleSort(array10000Bubble,10000,compCount10000Bubble,moveCount10000Bubble);
    durationBubble10000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


    //Calculation of 14000 for Quick
    int compCount14000Quick = 0;
    int moveCount14000Quick = 0;
    double durationQuick14000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount14000Quick = 0;
        moveCount14000Quick = 0;
        for( int i = 0; i < 14000; i++ )
            array14000Quick[i] = array14000Bubble[i];
        quickSort(array14000Quick,0,13999,compCount14000Quick,moveCount14000Quick);
    }
    durationQuick14000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick14000 = durationQuick14000 /100;

    //Calculation of 14000 for Merge
    int compCount14000Merge = 0;
    int moveCount14000Merge = 0;
    double durationMerge14000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount14000Merge = 0;
        moveCount14000Merge = 0;
        for( int i = 0; i < 14000; i++ )
            array14000Merge[i] = array14000Bubble[i];
        mergeSort(array14000Merge,0,13999,compCount14000Merge,moveCount14000Merge);
    }
    durationMerge14000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge14000 = durationMerge14000 /100;

    //Calculation of 14000 for Radix
    double durationRadix14000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array14000Radix,14000,10000);
    durationRadix14000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix14000 = durationRadix14000 / 100;

        //Calculation of 14000 for Bubble
    int compCount14000Bubble = 0;
    int moveCount14000Bubble = 0;
    double durationBubble14000;
    startTime = clock();
    bubbleSort(array14000Bubble,14000,compCount14000Bubble,moveCount14000Bubble);
    durationBubble14000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;



    //Calculation of 18000 for Quick
    int compCount18000Quick = 0;
    int moveCount18000Quick = 0;
    double durationQuick18000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount18000Quick = 0;
        moveCount18000Quick = 0;
        for( int i = 0; i < 18000; i++ )
            array18000Quick[i] = array18000Bubble[i];
        quickSort(array18000Quick,0,17999,compCount18000Quick,moveCount18000Quick);
    }
    durationQuick18000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick18000 = durationQuick18000 /100;

    //Calculation of 18000 for Merge
    int compCount18000Merge = 0;
    int moveCount18000Merge = 0;
    double durationMerge18000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount18000Merge = 0;
        moveCount18000Merge = 0;
        for( int i = 0; i < 18000; i++ )
            array18000Merge[i] = array18000Bubble[i];
        mergeSort(array18000Merge,0,17999,compCount18000Merge,moveCount18000Merge);
    }
    durationMerge18000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge18000 = durationMerge18000 / 100;

    //Calculation of 18000 for Radix
    double durationRadix18000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array18000Radix,18000,10000);
    durationRadix18000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix18000 = durationRadix18000 / 100;

    //Calculation of 18000 for Bubble
    int compCount18000Bubble = 0;
    int moveCount18000Bubble = 0;
    double durationBubble18000;
    startTime = clock();
    bubbleSort(array18000Bubble,18000,compCount18000Bubble,moveCount18000Bubble);
    durationBubble18000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


    //Calculation of 22000 for Quick
    int compCount22000Quick = 0;
    int moveCount22000Quick = 0;
    double durationQuick22000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount22000Quick = 0;
        moveCount22000Quick = 0;
        for( int i = 0; i < 22000; i++ )
            array22000Quick[i] = array22000Bubble[i];
        quickSort(array22000Quick,0,21999,compCount22000Quick,moveCount22000Quick);
    }
    durationQuick22000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick22000 = durationQuick22000 /100;

    //Calculation of 22000 for Merge
    int compCount22000Merge = 0;
    int moveCount22000Merge = 0;
    double durationMerge22000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount22000Merge = 0;
        moveCount22000Merge = 0;
        for( int i = 0; i < 22000; i++ )
            array22000Merge[i] = array22000Bubble[i];
        mergeSort(array22000Merge,0,21999,compCount22000Merge,moveCount22000Merge);
    }
    durationMerge22000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge22000 = durationMerge22000 / 100;

    //Calculation of 22000 for Radix
    double durationRadix22000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array22000Radix,22000,10000);
    durationRadix22000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix22000 = durationRadix22000 / 100;

    //Calculation of 22000 for Bubble
    int compCount22000Bubble = 0;
    int moveCount22000Bubble = 0;
    double durationBubble22000;
    startTime = clock();
    bubbleSort(array22000Bubble,22000,compCount22000Bubble,moveCount22000Bubble);
    durationBubble22000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


    //Calculation of 26000 for Quick
    int compCount26000Quick = 0;
    int moveCount26000Quick = 0;
    double durationQuick26000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount26000Quick = 0;
        moveCount26000Quick = 0;
        for( int i = 0; i < 26000; i++ )
            array26000Quick[i] = array26000Bubble[i];
        quickSort(array26000Quick,0,25999,compCount26000Quick,moveCount26000Quick);
    }
    durationQuick26000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick26000 = durationQuick26000 / 100;

    //Calculation of 26000 for Merge
    int compCount26000Merge = 0;
    int moveCount26000Merge = 0;
    double durationMerge26000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount26000Merge = 0;
        moveCount26000Merge = 0;
        for( int i = 0; i < 26000; i++ )
            array26000Merge[i] = array26000Bubble[i];
        mergeSort(array26000Merge,0,25999,compCount26000Merge,moveCount26000Merge);
    }
    durationMerge26000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge26000 = durationMerge26000 / 100;

    //Calculation of 26000 for Radix
    double durationRadix26000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array26000Radix,26000,10000);
    durationRadix26000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix26000 = durationRadix26000 / 100;

    //Calculation of 26000 for Bubble
    int compCount26000Bubble = 0;
    int moveCount26000Bubble = 0;
    double durationBubble26000;
    startTime = clock();
    bubbleSort(array26000Bubble,26000,compCount26000Bubble,moveCount26000Bubble);
    durationBubble26000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


    //Calculation of 30000 for Quick
    int compCount30000Quick = 0;
    int moveCount30000Quick = 0;
    double durationQuick30000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount30000Quick = 0;
        moveCount30000Quick = 0;
        for( int i = 0; i < 30000; i++ )
            array30000Quick[i] = array30000Bubble[i];
        quickSort(array30000Quick,0,29999,compCount30000Quick,moveCount30000Quick);
    }
    durationQuick30000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationQuick30000 = durationQuick30000 / 100;

    //Calculation of 30000 for Merge
    int compCount30000Merge = 0;
    int moveCount30000Merge = 0;
    double durationMerge30000;
    startTime = clock();
    for(int i = 0; i <100;i++){
        compCount30000Merge = 0;
        moveCount30000Merge = 0;
        for( int i = 0; i < 30000; i++ )
            array30000Merge[i] = array30000Bubble[i];
        mergeSort(array30000Merge,0,29999,compCount30000Merge,moveCount30000Merge);
    }
    durationMerge30000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationMerge30000 = durationMerge30000 / 100;

    //Calculation of 30000 for Radix
    double durationRadix30000;
    startTime = clock();
    for(int i = 0; i <100;i++)
        radixSort(array30000Radix,30000,10000);
    durationRadix30000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    durationRadix30000 = durationRadix30000 /100;

    //Calculation of 30000 for Bubble
    int compCount30000Bubble = 0;
    int moveCount30000Bubble = 0;
    double durationBubble30000;
    startTime = clock();
    bubbleSort(array30000Bubble,30000,compCount30000Bubble,moveCount30000Bubble);
    durationBubble30000 = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    //Print
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of Radix Sort"<<endl;
    cout<<"Array Size      Time Elapsed    "<<endl;
    cout<<"  2000               "<<durationRadix2000<<endl;
    cout<<"  6000               "<<durationRadix6000<<endl;
    cout<<"  10000              "<<durationRadix10000<<endl;
    cout<<"  14000              "<<durationRadix14000<<endl;
    cout<<"  18000              "<<durationRadix18000<<endl;
    cout<<"  22000              "<<durationRadix22000<<endl;
    cout<<"  26000              "<<durationRadix26000<<endl;
    cout<<"  30000              "<<durationRadix30000<<endl;

    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of Bubble Sort"<<endl;
    cout<<"Array Size      Time Elapsed     compCount      moveCount"<<endl;
    cout<<"  2000               "<<durationBubble2000<<"          "<<compCount2000Bubble<<"        "<<moveCount2000Bubble <<endl;
    cout<<"  6000               "<<durationBubble6000<<"         "<<compCount6000Bubble<<"       "<<moveCount6000Bubble <<endl;
    cout<<"  10000              "<<durationBubble10000<<"         "<<compCount10000Bubble<<"       "<<moveCount10000Bubble <<endl;
    cout<<"  14000              "<<durationBubble14000<<"        "<<compCount14000Bubble<<"       "<<moveCount14000Bubble <<endl;
    cout<<"  18000              "<<durationBubble18000<<"        "<<compCount18000Bubble<<"      "<<moveCount18000Bubble <<endl;
    cout<<"  22000              "<<durationBubble22000<<"        "<<compCount22000Bubble<<"      "<<moveCount22000Bubble <<endl;
    cout<<"  26000              "<<durationBubble26000<<"        "<<compCount26000Bubble<<"      "<<moveCount26000Bubble <<endl;
    cout<<"  30000              "<<durationBubble30000<<"        "<<compCount30000Bubble<<"      "<<moveCount30000Bubble <<endl;

    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of Quick Sort"<<endl;
    cout<<"Array Size      Time Elapsed     compCount      moveCount"<<endl;
    cout<<"  2000               "<<durationQuick2000<<"        "<<compCount2000Quick<<"          "<<moveCount2000Quick <<endl;
    cout<<"  6000               "<<durationQuick6000<<"        "<<compCount6000Quick<<"          "<<moveCount6000Quick <<endl;
    cout<<"  10000              "<<durationQuick10000<<"        "<<compCount10000Quick<<"         "<<moveCount10000Quick <<endl;
    cout<<"  14000              "<<durationQuick14000<<"        "<<compCount14000Quick<<"         "<<moveCount14000Quick <<endl;
    cout<<"  18000              "<<durationQuick18000<<"        "<<compCount18000Quick<<"         "<<moveCount18000Quick <<endl;
    cout<<"  22000              "<<durationQuick22000<<"        "<<compCount22000Quick<<"         "<<moveCount22000Quick <<endl;
    cout<<"  26000              "<<durationQuick26000<<"        "<<compCount26000Quick<<"         "<<moveCount26000Quick <<endl;
    cout<<"  30000              "<<durationQuick30000<<"        "<<compCount30000Quick<<"         "<<moveCount30000Quick <<endl;

        cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of Merge Sort"<<endl;
    cout<<"Array Size      Time Elapsed     compCount      moveCount"<<endl;
    cout<<"  2000               "<<durationMerge2000<<"        "<<compCount2000Merge<<"          "<<moveCount2000Merge <<endl;
    cout<<"  6000               "<<durationMerge6000<<"        "<<compCount6000Merge<<"          "<<moveCount6000Merge <<endl;
    cout<<"  10000              "<<durationMerge10000<<"        "<<compCount10000Merge<<"         "<<moveCount10000Merge <<endl;
    cout<<"  14000              "<<durationMerge14000<<"        "<<compCount14000Merge<<"         "<<moveCount14000Merge <<endl;
    cout<<"  18000              "<<durationMerge18000<<"        "<<compCount18000Merge<<"         "<<moveCount18000Merge <<endl;
    cout<<"  22000              "<<durationMerge22000<<"        "<<compCount22000Merge<<"         "<<moveCount22000Merge <<endl;
    cout<<"  26000              "<<durationMerge26000<<"        "<<compCount26000Merge<<"         "<<moveCount26000Merge <<endl;
    cout<<"  30000              "<<durationMerge30000<<"        "<<compCount30000Merge<<"         "<<moveCount30000Merge <<endl;

    delete[] array2000Bubble;
    delete[] array2000Quick;
    delete[] array2000Radix;
    delete[] array2000Merge;

    delete[] array6000Bubble;
    delete[] array6000Quick;
    delete[] array6000Radix;
    delete[] array6000Merge;

    delete[] array10000Bubble;
    delete[] array10000Quick;
    delete[] array10000Radix;
    delete[] array10000Merge;

    delete[] array14000Bubble;
    delete[] array14000Quick;
    delete[] array14000Radix;
    delete[] array14000Merge;

    delete[] array18000Bubble;
    delete[] array18000Quick;
    delete[] array18000Radix;
    delete[] array18000Merge;

    delete[] array22000Bubble;
    delete[] array22000Quick;
    delete[] array22000Radix;
    delete[] array22000Merge;

    delete[] array26000Bubble;
    delete[] array26000Quick;
    delete[] array26000Radix;
    delete[] array26000Merge;

    delete[] array30000Bubble;
    delete[] array30000Quick;
    delete[] array30000Radix;
    delete[] array30000Merge;

}






