/**
* Title : Binary Search Trees
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 02
* Assignment : 2
* Description : BST.cpp
*/


#include "BST.h"
#include "BSTNode.h"
#include <string>
#include <iostream>

using namespace std;
BST::BST()
{
    root = NULL;
    size = 0;
}

BST::BST(const int& rootItem)
{
    root = new BSTNode(rootItem,NULL,NULL,NULL );
    size = 1;
}
BST::~BST()
{

    if(root)
        delete root;
}

void BST::destroyHelper(BSTNode*& root)
{
    if(root)
    {

        destroyHelper(root->leftChildPtr);
        destroyHelper(root->leftChildPtr);
        delete root;
    }
}
void BST::insertItemHelper(BSTNode*& root,int key)
{
    if (root == NULL)
    {
        root = new BSTNode(key,NULL,NULL,NULL);
    }

    /* Otherwise, recur down the tree */
    if (key < root->item)
    {
        insertItemHelper(root->leftChildPtr, key);
        root->leftChildPtr->parent = root->leftChildPtr;
    }
    else if (key > root->item)
    {
        insertItemHelper(root->rightChildPtr, key);
        root->rightChildPtr->parent = root;
    }
}
void BST::insertItem(int key)
{
    insertItemHelper(root,key);
}

void BST::deleteItem(int key)
{
    deleteItemHelper(root,key);
}

void BST::deleteItemHelper(BSTNode*& root,int key)
{
    if(root == NULL)
        return;
    else if( key == root->item)
    {
        deleteNodeItem(root);
        size--;
    }
    else if(key < root->item)
        deleteItemHelper(root->leftChildPtr,key);
    else
        deleteItemHelper(root->rightChildPtr,key);
}
void BST::deleteNodeItem(BSTNode*& root)
{
    BSTNode* delPtr;
    int repItem;

    if( root->leftChildPtr == NULL && root->rightChildPtr == NULL )
    {
        delete root;
        root = NULL;
    }
    else if(root->leftChildPtr == NULL)
    {
        delPtr = root;
        root = root->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    else if(root->rightChildPtr == NULL)
    {
        delPtr = root;
        root = root->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    else
    {
        processLeftmost(root->rightChildPtr,repItem);
        root->item = repItem;
    }
}
void BST::processLeftmost(BSTNode*& nodePtr,int& repItem)
{
    if(nodePtr->leftChildPtr==NULL)
    {
        repItem = nodePtr->item;
        BSTNode*delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr=NULL;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr,repItem);
}

BSTNode* BST::retrieveItem(int key)
{
    BSTNode* returned = NULL;
    retrieveItemHelper(root,key,returned);
    return returned;
}

void BST::retrieveItemHelper(BSTNode*& root,int key,BSTNode*& returned)
{
    if(root == NULL)
        return;
    else if(key == root->item)
        returned = root;
    else if(key < root->item)
        retrieveItemHelper(root->leftChildPtr,key,returned);
    else if( key > root->item)
        retrieveItemHelper(root->rightChildPtr,key,returned);
}

int* BST::inorderTraversal(int& length)
{
    length = 0;
    int* arr = new int[size];
    inorderTraversalHelper(root,arr,length);
    length = length + 1;
    return arr;
}
void BST::inorderTraversalHelper(BSTNode*& root,int*& arr,int& length)
{
    if(root != NULL)
    {
        inorderTraversalHelper(root->leftChildPtr,arr,length);
        arr[length] = root->item;
        length++;
        inorderTraversalHelper(root->rightChildPtr,arr,length);
    }
}

bool BST::containsSequence(int*seq,int length)
{
    return containsSequenceHelper(root,seq,length);
}

bool BST::containsSequenceHelper(BSTNode*& root,int*seq,int length)
{
    int* arr = new int[length];
    bool check = true;
    while( seq[0] > root->item )
        root = root->rightChildPtr;
    int count = 0;
    containsSequenceHelperResult(root,seq,length,count,arr);
    for(int i = 0; i < length; i++)
    {
        if( seq[i] != arr[i] )
            check = false;
    }
    delete[] arr;
    return check;
}

void BST::containsSequenceHelperResult(BSTNode*& root,int*seq,int length, int&count, int*& arr)
{
    if(root != NULL && count < length )
    {

        containsSequenceHelperResult(root->leftChildPtr,seq,length,count,arr);

        cout<<"Traversed -> "<<root->item<<endl;
        if(root->item >= seq[0])
        {
            if( count < length )
                arr[count] = root->item;
            count++;
        }

        containsSequenceHelperResult(root->rightChildPtr,seq,length,count,arr);
    }
}

int BST::countNodesDeeperThan(int level)
{
    /*int number = 0;
    countNodesDeeperThanHelper(root,level,number);
    return number;*/
    int count = 0;
    return countNodesDeeperThanHelper(root,level,count);
}
int BST::countNodesDeeperThanHelper(BSTNode*& root,int level, int number)
{
    /*if( root == NULL )
        return;
    if( level <= 1 )
        number++;
    countNodesDeeperThanHelper(root->rightChildPtr,level-1,number);
    countNodesDeeperThanHelper(root->leftChildPtr,level-1,number);*/
    if(number >= level || root == NULL)
            return 0;
    else
    {
        int a =  1 + countNodesDeeperThanHelper(root->leftChildPtr,level,number+1) ;
        int b =  countNodesDeeperThanHelper(root->rightChildPtr,level,number+1);
        return a+b;
    }
}

int BST::maxBalancedHeight()
{
    int count = 1;
    if(findFullTree(root))
        return maxBalancedHeightHelper(root,count);
    else
        return maxBalancedHeightHelper(root,count) + 1;
}
int BST::maxBalancedHeightHelper(BSTNode*& root,int count)
{
    if( root->leftChildPtr == NULL || root->rightChildPtr == NULL )
    {
        return count;
    }

    int right = maxBalancedHeightHelper(root->rightChildPtr,count +1);
    int left = maxBalancedHeightHelper(root->leftChildPtr,count +1);

    if(right < left)
        return right;
    else
        return left;
}

int BST::findFullTree(BSTNode*& root)
{
    /*if( root->leftChildPtr != NULL && root->rightChildPtr == NULL )
        return false;
    if( root->leftChildPtr == NULL && root->rightChildPtr != NULL )
        return false;
    if( root->leftChildPtr == NULL && root->rightChildPtr == NULL )
        return true;

    bool right = findFullTree(root->rightChildPtr);
    bool left = findFullTree(root->leftChildPtr);

    if( !right || !left )
        return false;
    else
        return true;*/

    if(root == NULL)
        return 0;

    int left = 1 + findFullTree(root->leftChildPtr);
    int right = 1 + findFullTree(root->rightChildPtr);

    if(right > left)
        return right;
    else
        return left;

}
int BST::getSize()
{
    return size;
}

int BST::findMax(BSTNode*& root)
{
    if(root != NULL)
    {
        return root->getItem() + findMax(root->rightChildPtr) + findMax(root->leftChildPtr);
    }
}
void BST::findClosestPair(int&first, int&second)
{
    first = INT_MIN / 2;
    second = INT_MAX / 2;
    findClosestPairHelper(root,first,second);
}
void BST::findClosestPairHelper(BSTNode*& root, int&first, int&second)
{
    if(root != NULL)
    {
        findClosestPairHelper(root->leftChildPtr,first,second);
        if(abs(root->item-first)<abs(second-first))
            second = root->item;
        else if(abs(root->item - second) < abs(second-first))
            first = root->item;
        findClosestPairHelper(root->rightChildPtr,first,second);
    }
}
void BST::inorder()
{
    inorder(root);
}
void BST::inorder(BSTNode *root)
{
    bool leftcheck = false;

    // Start traversal from root
    while (root != NULL)
    {
        // If left child is not traversed, find the
        // leftmost child
        if (!leftcheck)
        {
            while (root->leftChildPtr)
                root = root->leftChildPtr;
        }

        // Print root's data
        cout<< root->item<<endl;

        // Mark left as done
        leftcheck = true;

        // If right child exists
        if (root->rightChildPtr != NULL)
        {
            leftcheck = false;
            root = root->rightChildPtr;
        }

        // If right child doesn't exist, move to parent
        else if (root->parent != NULL)
        {
            // If this node is right child of its parent,
            // visit parent's parent first
            while (root->parent != NULL &&
                   root == root->parent->rightChildPtr)
                   {
                       root = root->parent;
                       //cout<<root->parent->item<<endl;
                   }

            if (root->parent == NULL)
                break;
            root = root->parent;
            //root = root->parent;
        }
        else break;
    }
}
