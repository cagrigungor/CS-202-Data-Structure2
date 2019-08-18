/**
* Title : Binary Search Trees
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 02
* Assignment : 2
* Description : BSTNode.h
*/


#ifndef BSTNODE_H
#define BSTNODE_H
#include <string>
#include <iostream>

using namespace std;

class BSTNode
{
    public:
        BSTNode();
        ~BSTNode();
        BSTNode(const int& nodeItem,BSTNode* left,BSTNode* right,BSTNode* parentk );
        int getItem();

    private:
    int item;
    BSTNode* leftChildPtr;
    BSTNode* rightChildPtr;
    BSTNode* parent;

    friend class BST;
};

#endif // BSTNODE_H
