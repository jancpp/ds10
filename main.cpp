/*
Author: Jan Polzer
File:   main.cpp
Date:   4/9/2018
*/

#include "LeftistHeap.h"
#include "SkewHeap.h"
#include <iostream>

int main(int argc, char **argv) {
    std::string heaptype = argv[1];
    if (heaptype == "leftist") {
        LeftistHeap *leftist = new LeftistHeap();
        leftist->run(leftist);
        delete leftist;
    } else if (heaptype == "skew") {
        SkewHeap *skew = new SkewHeap();
        skew->run(skew);
        delete skew;
    } else {
        std::cout << "\nWrong input, choose\n./Lab10 leftist\n or\n ./Lab10 skew\n";
    }
	return (0);
}
