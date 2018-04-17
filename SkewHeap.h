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

	bool deleteMinHelper(Node *parent);
	bool deleteMaxHelper(Node *parent);

	void setRoot(Node *root);

	// @pre:    BST
	// @post:   inserting node in root
	// @return: Node pointer of element to be inserted
	Node *insertHelper(Node *root, Node *node);

	// @pre:    BST
	// @post:   Printed values in preorder traversal
	// @return: None
	void preorderHelper(Node *root);

	// @pre:    BST
	// @post:   Printed values in inorder traversal
	// @return: None
	void inorderHelper(Node *root);

	// @pre:    BST
	// @post:   Printed values in levelorder traversal
	// @return: None
	void levelorderHelper(Node *root);

public:
	SkewHeap();
	~SkewHeap();
    void destroyNode(Node *node);

	// @pre:    Binary search Heap
	// @Post:   New node inserted into the Heap:    as root if empty,
	//                                              as left node if value is smaller then root value
	//                                              as right node if value is same or larger then root
	// @Return: True if success, false otherwise
	bool insert(int value);

	// @pre:    BST
	// @post:   deleted min value
	// @return: True if deleted, false otherwise
	bool deleteMin();

	// @pre:    BST
	// @post:   Printed out all the elements of the BST using preorder traversal.
	// @return: None
	void preorder();

	// @pre:    BST
	// @post:   Printed out all the elements of the BST using inorder traversal.
	// @return: None
	void inorder();

	// @pre:    BST
	// @post:   Printed out all the elements of the BST using levelorder traversal.
	// @return: None
	void levelorder();
};

#endif
