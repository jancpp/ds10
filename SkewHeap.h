/*
Author: Jan Polzer
File:   SkewHeap.h
Date:   4/9/2018
*/


#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include "Node.h"
#include <iostream>
#include <queue>

class SkewHeap {

private:
    Node *m_root;
    int m_size;
    
    // @pre:    Two heaps
    // @post:   Swapped heaps
    // @return: None
    void swap(Node *heap1, Node *heap2);
    
    // @pre:    Skew heap
    // @post:   Heap is recursively destroyed
    // @return: None
    void destroyHeap(Node *node);;
    
    // @pre:    Skew heap
    // @post:   Heaps merged into one
    // @return: Node pointer of root of merged heaps
    Node *concate(Node *heap1, Node *heap2);
    
    // @pre:    Skew heap
    // @post:   Printed values in preorder traversal
    // @return: None
    void preorderHelper(Node *root);
    
    // @pre:    Skew heap
    // @post:   Printed values in inorder traversal
    // @return: None
    void inorderHelper(Node *root);
    
    // @pre:    Skew heap
    // @post:   Printed values in postorder traversal
    // @return: None
    void levelorderHelper(Node *root);
    
public:
    SkewHeap();
    ~SkewHeap();
    
    // @pre:    None
    // @post:   Runs program for skew heap
    // @return: None
    void run(SkewHeap *skew);
    
    // @pre:    Skew Heap
    // @post:   New node inserted into the heap
    // @return: True if success, false otherwise
    bool insert(int value);
    
    // @pre:    Skew heap
    // @post:   deleted min value
    // @return: True if deleted, false otherwise
    bool deleteMin();
    
    // @pre:    Skew heap
    // @post:   Printed out all the elements of the Skew heap using preorder traversal.
    // @return: None
    void preorder();
    
    // @pre:    Skew heap
    // @post:   Printed out all the elements of the Skew heap using inorder traversal.
    // @return: None
    void inorder();
    
    // @pre:    Skew heap
    // @post:   Printed out all the elements of the Skew heap using levelorder traversal.
    // @return: None
    void levelorder();
};

#endif
