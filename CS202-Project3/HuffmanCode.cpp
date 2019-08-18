/**
* Title : HuffmanCode
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 2
* Assignment : 3
* Description : HuffmanCode implement
*/

#include "HuffmanCode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
HuffmanCode::HuffmanCode()
{

}

void HuffmanCode::HuffAlgo()
{
    int size = q.getSize();
    for(int i = 0; i < size-1; i++)
    {
        MinHeapNode* z = new MinHeapNode();
        z->left = q.pqDelete();
        z->right = q.pqDelete();
        z->freq = z->left->freq + z->right->freq;
        q.pqInsert(z);
    }
}
void HuffmanCode::readData(string input)
{
    string line;
    ifstream file(input.c_str());
    while(getline(file, line))
    {
        MinHeapNode* temp = new MinHeapNode();
        temp->character = line[0];
        stringstream parseInt(line.substr(2));
        int freq = 0;
        parseInt>>freq;
        temp->freq = freq;
        q.pqInsert(temp);
    }
}
void HuffmanCode::writeCodingShemesAux(MinHeapNode* temp, string code,string& result)
{
    if(temp->left == NULL && temp->right == NULL)
    {
        result = result + temp->character+code+" ";
        delete temp;
    }

    else{
        if(temp->left != NULL)
        {
            writeCodingShemesAux(temp->left,code+"0",result);
        }
        if(temp->right != NULL)
        {
            writeCodingShemesAux(temp->right,code+"1",result);
        }
        delete temp;
    }
}
void HuffmanCode::writeCodingShemes(string output)
{
    string result;
    MinHeapNode* temp = q.pqDelete();
    writeCodingShemesAux(temp,"",result);
    ofstream oFile(output);
    oFile<<result;
}
