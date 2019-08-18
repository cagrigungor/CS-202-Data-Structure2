/**
* Title : MedianHeap
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : MedianHeap implement
*/
#include "MedianHeap.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
MedianHeap::MedianHeap()
{

}

void MedianHeap::MedianHeap::insert(int value)
{
    if(max.sizeGet() <= 0)
        max.insert(value);
    else if(min.sizeGet() <= 0 )
        min.insert(value);
    else
    {
        if(findMedian() < value)
            min.insert(value);
        else
            max.insert(value);
    }

    if( abs(max.sizeGet()- min.sizeGet()) > 1 )
    {

        if(max.sizeGet() > min.sizeGet())
        {
            int temp = max.extractMax();
            min.insert(temp);
        }
        else
        {
            int temp = min.extractMin();
            max.insert(temp);
        }
    }
}
int MedianHeap::findMedian()
{
    if(max.sizeGet() > min.sizeGet())
        return max.peek();
    else
        return min.peek();
}
void MedianHeap::display()
{
    cout<<"Max Heap = ";
    for(int i = 0; i < max.sizeGet(); i++)
    {
        cout<<max.get(i)<<" ";
    }
    cout<<endl;
    cout<<"Min Heap = ";
    for(int i = 0; i < min.sizeGet(); i++)
    {
        cout<<min.get(i)<<" ";
    }
}
