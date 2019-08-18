/**
* Title : Main
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : Main class
*/
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"
#include "HuffmanCode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string input;
    cout<<"Enter the file name ie., input.txt(Data should be character,space,length for each in one line at the file)= "<<endl;
    cin>>input;
    string output;
    cout<<"Enter the output file name that will be created= "<<endl;
    cin>>output;
    HuffmanCode c;
    c.readData(input);
    c.HuffAlgo();
    c.writeCodingShemes(output);

    return 0;
}

