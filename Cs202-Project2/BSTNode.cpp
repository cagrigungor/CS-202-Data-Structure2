/**
* Title : Binary Search Trees
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 02
* Assignment : 2
* Description : BSTNode.cpp
*/

#include "BSTNode.h"
#include <string>
#include <iostream>

using namespace std;
BSTNode::BSTNode()
{}

BSTNode::BSTNode(const int& nodeItem,BSTNode* left,BSTNode* right,BSTNode* parentk)
{
    left = NULL;
    right = NULL;
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    parent = parentk;
}
BSTNode::~BSTNode()
{
    if(leftChildPtr)
        delete leftChildPtr;
    if(rightChildPtr)
        delete rightChildPtr;
}
int BSTNode::getItem()
{
    return item;
}

