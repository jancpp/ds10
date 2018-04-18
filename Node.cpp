/*
Author: Jan Polzer
File:   Node.cpp
Date:   4/9/2018
*/

#include "Node.h"

Node::Node() : m_left (nullptr ), m_right (nullptr ){
    this->setKey(-1);
    this->setRank(1);
}

Node::~Node() {
//    if (this->right() != nullptr) {
//        delete right();
//    }
//    if (this->left() != nullptr) {
//        delete left();
//    }
//    delete this;
}

Node::Node(const int &rank, const int &key, Node *left , Node *right ) {
        setKey(key);
        setRank(rank);
        setLeft(left);
        setRight(right);
}

int Node::key() const {
        return m_key;
}

int Node::rank() const {
        return m_rank;
}

void Node::setRank (const int &rank) {
    m_rank = rank;
}

void Node::setKey (const int &key) {
        m_key = key;
}

void Node::setLeft (Node *node) {
        m_left  = node;
}

void Node::setRight (Node *node) {
        m_right  = node;
}

Node *Node::left () const {
        return m_left ;
}

Node *Node::right () const {
        return m_right ;
}

void Node::swap() {
    Node *temp = m_left;
    m_left = m_right;
    m_right = temp;
}
