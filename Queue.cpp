/*
 Author: Jan Polzer
 File:   Queue.h\cpp
 Date:   4/9/2018
 */

#include "Queue.h"

Queue::Queue() : m_size(0)
{
    for (int i = 0; i < 500; i++)
    {
        m_array[i] = nullptr;
    }
}
Queue::~Queue() {}

bool Queue::isEmpty()
{
    return (m_size == 0);
}

Node *Queue::pop()
{
    Node *temp = m_array[0];
    for (int i = 0; i < (m_size - 1); i++)
    {
        m_array[i] = m_array[i + 1];
    }
    m_size--;
    return temp;
}

void Queue::push(Node *newNode)
{
    m_array[m_size] = newNode;
    m_size++;
}

Node *Queue::front()
{
    return m_array[0];
}

int Queue::size()
{
    return m_size;
}
