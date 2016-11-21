FLAGS = -Wall
all:  Driver.o Heap.o MaxHeap.o MinHeap.o PinHit.o
	g++ $(FLAGS) Driver.o Heap.o MaxHeap.o MinHeap.o PinHit.o -o driver.out

PinHit.o: PinHit.cpp
	g++ $(FLAGS) PinHit.cpp -c

MaxHeap.o: MaxHeap.cpp
	g++ $(FLAGS) MaxHeap.cpp -c
MinHeap.o: MinHeap.cpp
	g++ $(FLAGS) MinHeap.cpp -c
Heap.o: Heap.cpp
	g++ $(FLAGS) Heap.cpp -c
Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

.PHONY: run
run:
	./driver.out $(INPUT) $(FLAG)

.PHONY: clean
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#