/*
Author: Jan Polzer
File:   LeftistHeap.h
Date:   4/9/2018
*/

#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "Node.h"
#include <iostream>
#include "Queue.h"
#include <math.h>

class LeftistHeap
{

private:
	Node *m_root;
	int m_size;

	// @pre:    Two heaps
	// @post:   Swapped heaps
	// @return: None
	void swap(Node *heap1, Node *heap2);

	// @pre:    Leftist heap
	// @post:   Node is destroyed
	// @return: None
	void adjustRank(Node *heap);

	// @pre:    Leftist heap
	// @post:   Heap is recursively destroyed
	// @return: None
	void destroyHeap(Node *node);
	;

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

public:
	LeftistHeap();
	~LeftistHeap();

	// @pre:    None
	// @post:   Runs program for leftist heap
	// @return: None
	void run(LeftistHeap *leftist);

	// @pre:    Leftist Heap
	// @post:   New node inserted into the heap
	// @return: True if success, false otherwise
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
