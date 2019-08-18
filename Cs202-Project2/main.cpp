/**
* Title : Binary Search Trees
* Author : Mustafa Çaðrý Güngör
* ID: 21602251
* Section : 02
* Assignment : 2
* Description : main.cpp
*/

#include "BSTNode.h"
#include "BST.h"
#include "maink.cpp"
#include <string>
#include <iostream>

using namespace std;
int main()
{
    Node * root = NULL;

    root = insert(root, 24);
    root = insert(root, 27);
    root = insert(root, 29);
    root = insert(root, 34);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 13);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 6);

    printf("Inorder traversal is \n");
    inorder(root);

    return 0;
    /* BST tree;
    int max = 0;
    tree.insertItem(20);
    tree.insertItem(7);
    tree.insertItem(50);
    tree.insertItem(13);
    tree.insertItem(30);
    tree.insertItem(23);
    tree.insertItem(42);

    int first,second;
    tree.findClosestPair(first,second);
    tree.inorder();

    return 0;*/
}
