/*
Author: Jan Polzer
File:   Node.h
Date:   4/9/2018
*/

#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int m_rank;
	int m_key;
	Node *m_left ;
	Node *m_right ;

public:
	// @pre:    None
	// @post:   Initialized Node class
	// @return  None
	Node();
    
    // @pre:    None
    // @post:   Initialized Node class
    // @return  None
    Node(const int &rank, const int &key, Node *left , Node *right );
    
    // @pre:    Heap
    // @post:   Destructed heap
    // @return  None
    ~Node();

	// @pre:    Node
	// @post:   None
	// @return  m_rank
	int rank() const;

	// @pre:    Node
	// @post:   None
	// @return  m_key
	int key() const;

	// @pre:    Node
	// @post:   Set key
	// @return  None
	void setRank(const int &rank);

	// @pre:    Node
	// @post:   Set key
	// @return  None
	void setKey(const int &key);

	// @pre:    Node
	// @post:   Set left child
	// @return  None
	Node *left () const;

	// @pre:    Node
	// @post:   Set right child
	// @return  None
	Node *right () const;

	// @pre:    Node
	// @post:   None
	// @return  m_left
	void setLeft (Node *left );
    
    // @pre:    Node
    // @post:   None
    // @return  m_right
    void setRight (Node *right );

    // @pre:    Node
    // @post:   Swapped right and left children
    // @return  None
    void swap ();

};

#endif
