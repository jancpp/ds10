/*
 Author: Jan Polzer
 File:   SkewHeap.cpp
 Date:   4/9/2018
 */

#include "SkewHeap.h"

SkewHeap::SkewHeap(): m_root(nullptr), m_size(0) {}
SkewHeap::~SkewHeap() {
    destroyNode(m_root);
}

void SkewHeap::destroyNode(Node *node) {
    if (node != nullptr) {
        destroyNode(node->left());
        destroyNode(node->right());
        delete node;
    }
}

void SkewHeap::setRoot(Node *root) {
    m_root = root;
}

bool SkewHeap::insert(int key) {
    bool inserted = false;
    Node *newNode = new Node();
    m_root = insertHelper(m_root, newNode);
    if (m_root != nullptr) {
        inserted = true;
        m_size++;
    }
    return inserted;
}

Node *SkewHeap::insertHelper(Node *root, Node *newNode) {
    // Base case - empty Heap
    if ( root == nullptr) {
        return newNode;
    } else if (newNode->key() < root->key()) {
        Node *temp = new Node();
        temp = insertHelper(root->left(), newNode);
        root->setLeft(temp);
    } else {
        Node *temp = new Node();
        temp = insertHelper(root->right(), newNode);
        root->setRight(temp);
    }
    return root;
}

bool SkewHeap::deleteMin() {
    if (m_root == nullptr) {
        return false;
    } else {
        return deleteMinHelper(m_root);
    }
}

bool SkewHeap::deleteMinHelper(Node *parent) {
    bool deleted = false;
    if (m_size == 1){
        delete m_root;
        m_root = nullptr;
        deleted = true;
        m_size--;
    } else if ((parent->right() == nullptr) && (parent->left() != nullptr) && (parent->left()->left() == nullptr) && (parent->left()->right() == nullptr)) {
        delete parent->left();
        parent->setLeft(nullptr);
        deleted = true;
        m_size--;
    } else if (parent->left() == nullptr) {
        setRoot(parent->right());
        deleted = true;
        m_size--;
    }
    else if ((parent->left()->left() == nullptr) && (parent->left()->right() != nullptr)) {
        parent->setLeft(parent->left()->right());
        deleted = true;
        m_size--;
    }
    else if ((parent->left()->left() == nullptr) && (parent->left()->right() == nullptr)) {
        delete parent->left();
        parent->setLeft(nullptr);
        deleted = true;
        m_size--;
    }else {
        return deleteMinHelper(parent->left());
    }
    return deleted;
}

void SkewHeap::preorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        preorderHelper(m_root);
    }
}

void SkewHeap::preorderHelper(Node *root) {
    if (root != nullptr) {
        std::cout << " " << root->key();
        preorderHelper(root->left());
        preorderHelper(root->right());
    }
}

void SkewHeap::inorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        inorderHelper(m_root);
    }
}

void SkewHeap::inorderHelper(Node *root) {
    if (root != nullptr) {
        inorderHelper(root->left());
        std::cout << " " << root->key();
        inorderHelper(root->right());
    }
}

void SkewHeap::levelorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        levelorderHelper(m_root);
    }
}

void SkewHeap::levelorderHelper(Node *root) {

}
