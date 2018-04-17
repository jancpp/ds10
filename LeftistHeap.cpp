/*
 Author: Jan Polzer
 File:   LeftistHeap.cpp
 Date:   4/9/2018
 */

#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(): m_root(nullptr), m_size(0) {}

LeftistHeap::~LeftistHeap() {
    delete m_root;
}

void LeftistHeap::setRoot(Node *root) {
    m_root = root;
}

bool LeftistHeap::insert(int key) {
    bool inserted = false;
    Node *newNode = new Node();
    newNode->setKey(key);
    m_root = concate(m_root, newNode);
    if (m_root != nullptr) {
        inserted = true;
        m_size++;
    }
    return inserted;
}

//Node *LeftistHeap::insertHelper(Node *root, Node *newNode) {
//    // Base case - empty Heap
//    if ( root == nullptr) {
//        return newNode;
//    } else if (newNode->key() < root->key()) {
//        Node *temp = new Node();
//        temp = insertHelper(root->left(), newNode);
//        root->setLeft(temp);
//    } else {
//        Node *temp = new Node();
//        temp = insertHelper(root->right(), newNode);
//        root->setRight(temp);
//    }
//    return root;
//}
void LeftistHeap::adjustRank(Node *node) {
    if ((node->left() == nullptr) && (node->left() == nullptr)) {
        node->setRank(1);
    } else {
        node->setRank( (std::min(node->left()->rank(), node->right()->rank()))+1 );
    }
}

Node *LeftistHeap::concate(Node *heap1, Node *heap2) {
//    levelorder();
	if (heap1 == nullptr) {
		return heap2;
	} else if (heap2 == nullptr) {
		return heap1; 		
    } else if (heap1->key() > heap2->key()) {
        concate(heap2, heap1);
        return heap2;
    }
    heap1->setRight(concate(heap1->right(), heap2));
    adjustRank(heap1);
    if ((heap1->left() == nullptr) || (heap1->left()->rank() < heap1->right()->rank())) {
        heap1->swap();
    }
    return heap1;
}

bool LeftistHeap::deleteMin() {
    if (m_root == nullptr) {
        return false;
    } else {
        Node *left = m_root->left();
        Node *right = m_root->right();
        delete m_root;
        concate(left, right);
        return true;
    }
}

bool LeftistHeap::deleteMinHelper(Node *parent) {
    bool deleted = false;
//    if (m_size == 1){
//        delete m_root;
//        m_root = nullptr;
//        deleted = true;
//        m_size--;
//    } else if ((parent->right() == nullptr) && (parent->left() != nullptr) && (parent->left()->left() == nullptr) && (parent->left()->right() == nullptr)) {
//        delete parent->left();
//        parent->setLeft(nullptr);
//        deleted = true;
//        m_size--;
//    } else if (parent->left() == nullptr) {
//        setRoot(parent->right());
//        deleted = true;
//        m_size--;
//    }
//    else if ((parent->left()->left() == nullptr) && (parent->left()->right() != nullptr)) {
//        parent->setLeft(parent->left()->right());
//        deleted = true;
//        m_size--;
//    }
//    else if ((parent->left()->left() == nullptr) && (parent->left()->right() == nullptr)) {
//        delete parent->left();
//        parent->setLeft(nullptr);
//        deleted = true;
//        m_size--;
//    }else {
//        return deleteMinHelper(parent->left());
//    }
    return deleted;
}

void LeftistHeap::preorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        preorderHelper(m_root);
    }
}

void LeftistHeap::preorderHelper(Node *root) {
    if (root != nullptr) {
        std::cout << " " << root->key();
        preorderHelper(root->left());
        preorderHelper(root->right());
    }
}

void LeftistHeap::inorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        inorderHelper(m_root);
    }
}

void LeftistHeap::inorderHelper(Node *root) {
    if (root != nullptr) {
        inorderHelper(root->left());
        std::cout << " " << root->key();
        inorderHelper(root->right());
    }
}

void LeftistHeap::levelorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        levelorderHelper(m_root);
    }
}

void LeftistHeap::levelorderHelper(Node *root) {
    
    
    if (!m_root) {
        return;
    }
    Queue *q = new Queue();
        q->push(m_root);
        while (1){
            int nodeCount = q->size();
            if (nodeCount == 0) {
                break;
            }
            while (nodeCount > 0) {
                Node * temp = q->front();
                std::cout << " " << temp->key();
                q->pop();
                if (temp->left()  != nullptr) {
                    q->push(temp->left());
                }
                if (temp->right() != nullptr) {
                    q->push(temp->right());
                }
                nodeCount--;
            }
            std::cout << "\n";
        }
    }
    
//
//
//    Node * temp = q->peek();
//    q->pop();
//    std::cout << " " << temp->key();
//    std::cout << "\n";
//    while (!q->isEmpty()){
//         if (temp->left()  != nullptr) {
//             q->push(temp->left());
//             std::cout << " " << temp->key();
//         }
//         if (temp->right() != nullptr) {
//             q->push(temp->right());
//             std::cout << " " << temp->key();
//         }
//        std::cout << "\n";
//    }
//}
//    int levels = 1;
//    std::cout << "\n\nL" << levels << ": ";
//    int newLevel = 0;
//    if (root != nullptr) {
//         Queue queue;
//         // Enqueue all nodes from level 0 to last level
//         queue.push(root);
//
//        for (int i=0; i<m_size; i++) {
//            The jth child of A[i] is at A[5i+j], 1<= j <=5, if it exists.
//
//             Node *temp = queue.front();
////             // Print all nodes
//             std::cout << " " << temp->key();
//             queue.pop();
            
            // push children
            // new level
            //recurse
//            while ((temp->left() != nullptr) && (temp->right() != nullptr)){
//             if (temp->left()  != nullptr) {
//                 queue.push(temp->left());
//             }
//             if (temp->right() != nullptr) {
//                 queue.push(temp->right());
//             }
//            std::cout << "\n";
//
//            temp = temp->left();
//            }
            
            
            
            
//             if (temp->left()  != nullptr) {
//                 queue.push(temp->left());
//             }
//             if (temp->right() != nullptr) {
//                 queue.push(temp->right());
//             }
////             std::cout << "\n";
//
//             if ((newLevel == i) && ((i%2 == 0) || (i == 2))) {
//                 std::cout << "\n";
//                 newLevel += pow(2, levels);
//                 levels++;
//                 std::cout << "L" << levels << ": ";
//             }
//         }
//    }

//}
