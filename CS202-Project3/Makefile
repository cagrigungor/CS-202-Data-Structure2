hw3: main.o HuffmanCode.o HuffmanHeap.o HuffmanQueue.o MaxHeap.o MedianHeap.o MinHeap.o
	g++ main.o HuffmanCode.o HuffmanHeap.o HuffmanQueue.o MaxHeap.o MedianHeap.o MinHeap.o -o hw3 -std=gnu++11

main.o: main.cpp
	g++ -c main.cpp -std=gnu++11

HuffmanCode.o: HuffmanCode.cpp HuffmanCode.h 
	g++ -c HuffmanCode.cpp -std=gnu++11

HuffmanHeap.o: HuffmanHeap.cpp HuffmanHeap.h 
	g++ -c HuffmanHeap.cpp -std=gnu++11

HuffmanQueue.o: HuffmanQueue.cpp HuffmanQueue.h 
	g++ -c HuffmanQueue.cpp -std=gnu++11

MaxHeap.o: MaxHeap.cpp MaxHeap.h 
	g++ -c MaxHeap.cpp -std=gnu++11

MedianHeap.o: MedianHeap.cpp MedianHeap.h 
	g++ -c MedianHeap.cpp -std=gnu++11

MinHeap.o: MinHeap.cpp MinHeap.h 
	g++ -c MinHeap.cpp -std=gnu++11

clean: 
	rm *.o hw3