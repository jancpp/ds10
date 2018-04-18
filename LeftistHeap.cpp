/*
 Author: Jan Polzer
 File:   LeftistHeap.cpp
 Date:   4/9/2018
 */

#include "LeftistHeap.h"
#include <fstream>

LeftistHeap::LeftistHeap(): m_root(nullptr), m_size(0) {}

LeftistHeap::~LeftistHeap() {
    destroyHeap(m_root);
}

void LeftistHeap::run(LeftistHeap *leftist) {
    
    // Reads values from a file
    int value = -1;
    std::ifstream inputFile;
    inputFile.open("data.txt");
    if (!inputFile) {
        std::cout << "Error reading the input file.\n";
        inputFile.close();
    } else {
        std::cout << "Leftist heap:\ndata.txt elements: ";
        while(inputFile >> value) {
            std::cout << value << " ";
            leftist->insert(value);
        }
        std::cout << "\n";
    }
    inputFile.close();
    
    // User interacation
    int choice = -1;
    int inputValue = 0;
    
    while (choice != 6) {
        std::cout << "\n............................................\n\n";
        std::cout << "Please choose one of the following commands:\n\n";
        std::cout << "1- insert\n\n";
        std::cout << "2- deletemin\n\n";
        std::cout << "3- preorder\n\n";
        std::cout << "4- inorder\n\n";
        std::cout << "5- levelorder\n\n";
        std::cout << "6- exit\n\n";
        
        std::cout << "> ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                // Insert a value
                std::cout << "Enter a number to be inserted: ";
                std::cin >> inputValue;
                if (!leftist->insert(inputValue)) {
                    std::cout <<" Failed to insert " << inputValue << " .\n";
                } else {
                    std::cout << inputValue << " has been inserted.\n";
                }
                break;
            case 2:
            {
                // Delete min number
                if (leftist->deleteMin()) {
                    std::cout << "Min value has been deleted.\n";
                } else {
                    std::cout << "An Error happened during deletion of min number.\n";
                }
            }
                break;
            case 3:
                // Print using preodrer traversal
                leftist->preorder();
                break;
            case 4:
                // Print using inodrer traversal
                leftist->inorder();
                break;
            case 5:
                // Print using levelodrer traversal
                leftist->levelorder();
                break;
            case 6:
                // Exit
                std::cout << "Bye bye!\n";
                break;
            default:
                std::cout << "\nError: Wrong input.\n\n";
        }
    }
}

void LeftistHeap::destroyHeap(Node *node) {
    if (node != nullptr) {
        destroyHeap(node->left());
        destroyHeap(node->right());
        delete node;
        m_size--;
    }
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

void LeftistHeap::adjustRank(Node *node) {
    if ((node->left() == nullptr) && (node->left() == nullptr)) {
        node->setRank(1);
    } else {
        node->setRank( (std::min(node->left()->rank(), node->right()->rank()))+1 );
    }
}

Node *LeftistHeap::concate(Node *heap1, Node *heap2) {
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
        m_root = concate(left, right);
        return true;
    }
}

void LeftistHeap::preorder() {
    if (m_root == nullptr) {
        std::cout << "Heap is empty.\n";
    } else {
        std::cout << "Preorder:\n";
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
        std::cout << "Inorder:\n";
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
    std::cout << "Level order:\n";
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
