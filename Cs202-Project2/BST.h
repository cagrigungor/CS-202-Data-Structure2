/**
* Title : Binary Search Trees
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 02
* Assignment : 2
* Description : BST.h
*/

#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include <string>
#include <iostream>

using namespace std;

class BST
{
    public:

        BST();
        BST(const int& rootItem);
        ~BST();
        void insertItem(int key);
        void deleteItem(int key);
        BSTNode* retrieveItem(int key);
        int* inorderTraversal(int& length);
        bool containsSequence(int*seq,int length);
        int countNodesDeeperThan(int level);
        int maxBalancedHeight();
        int getSize();
        int findMax(BSTNode*& root);
        int findFullTree(BSTNode*& root);
        void findClosestPair(int&first, int&second);
        void findClosestPairHelper(BSTNode*& root, int&first, int&second);
        void inorder(BSTNode *root);
        void inorder();
    BSTNode* root;
    protected:

    private:

        int size;
        void destroyHelper(BSTNode*& root);
        void insertItemHelper(BSTNode*& root,int key);
        void deleteItemHelper(BSTNode*& root,int key);
        void deleteNodeItem(BSTNode*& root);
        void processLeftmost(BSTNode*& nodePtr,int& repItem);
        void retrieveItemHelper(BSTNode*& root,int key,BSTNode*& returned);
        void inorderTraversalHelper(BSTNode*& root,int*& arr,int& length);
        bool containsSequenceHelper(BSTNode*& root,int*seq,int length);
        void containsSequenceHelperResult(BSTNode*& root,int*seq,int length,int&count,int*& arr);
        int countNodesDeeperThanHelper(BSTNode*& root,int level, int number);
        int maxBalancedHeightHelper(BSTNode*& root,int number);

};
#endif // BST_H
