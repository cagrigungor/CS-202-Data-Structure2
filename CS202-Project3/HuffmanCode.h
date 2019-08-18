/**
* Title : HuffmanCode
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanCode implement
*/
#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H
#include "HuffmanQueue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class HuffmanCode
{
    public:
    HuffmanCode();
    void HuffAlgo();
    void readData(string input);
    void writeCodingShemesAux(MinHeapNode* temp, string code,string& result);
    void writeCodingShemes(string output);

    protected:

    private:
    HuffmanQueue q;
};

#endif // HUFFMANCODE_H
