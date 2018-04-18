
Lab10: main.o SkewHeap.o LeftistHeap.o Node.o Queue.o
	g++ -g -std=c++11 -Wall main.o SkewHeap.o LeftistHeap.o Node.o Queue.o -o Lab10

main.o:  SkewHeap.h LeftistHeap.h Node.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

SkewHeap.o: SkewHeap.h SkewHeap.cpp Node.cpp Node.h Queue.cpp Queue.h
	g++ -g -std=c++11 -Wall -c SkewHeap.cpp

LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp Node.cpp Node.h Queue.cpp Queue.h
	g++ -g -std=c++11 -Wall -c LeftistHeap.cpp

Queue.o: Queue.cpp Queue.h
	g++ -g -std=c++11 -Wall -c Queue.cpp

Node.o: Node.cpp Node.h
	g++ -g -std=c++11 -Wall -c Node.cpp

clean:
	rm *.o Lab10
