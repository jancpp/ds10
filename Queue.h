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
    Node **m_array = new Node*[500];
    
public:
    Queue();
    ~Queue();
    bool isEmpty();
    Node *peek();
    Node *pop();
    void push(Node *newNode);
    Node *front();
    int size();
};
#endif

