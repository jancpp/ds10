/*
Author: Jan Polzer
File:   LeftistHeap.h
Date:   4/9/2018
*/


#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "Node.h"
#include <iostream>
#include <queue>
#include <math.h>

class LeftistHeap {

private:
	Node *m_root;
	int m_size;

	bool deleteMinHelper(Node *parent);
	bool deleteMaxHelper(Node *parent);
    void swap(Node *heap1, Node *heap2);
    void adjustRank(Node *heap);
//    Node *concat(Node *heap1, Node *heap2);

	void setRoot(Node *root);

	// @pre:    Leftist heap
	// @post:   Heaps merged into one
	// @return: Node pointer of root of merged heaps
    Node *concate(Node *heap1, Node *heap2);

	// @pre:    Leftist heap
	// @post:   Printed values in preorder traversal
	// @return: None
	void preorderHelper(Node *root);

	// @pre:    Leftist heap
	// @post:   Printed values in inorder traversal
	// @return: None
	void inorderHelper(Node *root);

	// @pre:    Leftist heap
	// @post:   Printed values in postorder traversal
	// @return: None
	void levelorderHelper(Node *root);

	// @pre:    Leftist heap
	// @post:   Serching in root
	// @return: Node pointer of element to be found
	Node *findMinHelper(Node *root);

	// @pre:    Leftist heap
	// @post:   Searching in root
	// @return: Node pointer of element to be found
	Node *findMaxHelper(Node *root);

	// @pre:    Leftist heap
	// @post:   deleted node from the Heap
	// @return: True if deleted, false otherwise
	bool deleteHelper(int value, Node *root);

public:
	LeftistHeap();
	~LeftistHeap();

	// @pre:    Binary search Heap
	// @Post:   New node inserted into the Heap:    as root if empty,
	//                                              as left node if value is smaller then root value
	//                                              as right node if value is same or larger then root
	// @Return: True if success, false otherwise
	bool insert(int value);

	// @pre:    Leftist heap
	// @post:   deleted min value
	// @return: True if deleted, false otherwise
	bool deleteMin();

	// @pre:    Leftist heap
	// @post:   Printed out all the elements of the Leftist heap using preorder traversal.
	// @return: None
	void preorder();

	// @pre:    Leftist heap
	// @post:   Printed out all the elements of the Leftist heap using inorder traversal.
	// @return: None
	void inorder();

	// @pre:    Leftist heap
	// @post:   Printed out all the elements of the Leftist heap using levelorder traversal.
	// @return: None
	void levelorder();
};

#endif
