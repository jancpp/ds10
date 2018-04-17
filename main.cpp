/*
Author: Jan Polzer
File:   main.cpp
Date:   4/9/2018
*/

#include "LeftistHeap.h"
#include "SkewHeap.h"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

//    leftistHeap *leftist = nullptr;
    LeftistHeap *leftist = nullptr;

	// Reads values from a file
	int value = -1;
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile) {
		std::cout << "Error reading the input file.\n";
		inputFile.close();
	} else {
		leftist = new LeftistHeap();
		while(inputFile >> value) {
			leftist->insert(value);
            leftist->levelorder();
		}
	}
	inputFile.close();
    leftist->levelorder(); //TODO remove

	// User interacation
	int choice = -1;
	int inputValue = 0;

	while (choice != 10) {
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
				if (leftist->deleteMin()) {
					std::cout << "Min value has been deleted.\n"; //min->value() << "
				} else {
					std::cout << "An Error happened during deletion of min number.\n";
				}
				leftist->inorder();
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
			// Print using postodrer traversal
			leftist->levelorder();
			break;
			case 6:
			std::cout << "Bye bye!\n";
			delete leftist;
			return (0);
			default:
			std::cout << "\nError: Wrong input.\n\n";
		}
	}
	delete leftist;
	return (0);
}
