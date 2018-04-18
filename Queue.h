/*
 Author: Jan Polzer
 File:   Queue
 Date:   4/9/2018
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

class Queue
{
private:
  int m_size;
  Node **m_array = new Node *[500];

public:
  Queue();
  ~Queue();

  // @pre:    Queue
  // @post:   None
  // @return: True if queue is empty, false otherwise
  bool isEmpty();

  // @pre:    Queue
  // @post:   Head node dequeued
  // @return: Pointer to removed node
  Node *pop();

  // @pre:    Queue
  // @post:   New node enqueued
  // @return: None
  void push(Node *newNode);

  // @pre:    Queue
  // @post:   None
  // @return: Pointer to the first node
  Node *front();

  // @pre:    Queue
  // @post:   None
  // @return: Node count in the queue
  int size();
};
#endif
