all: build run

build:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/CircularDoublyLinkedList.o -c ./src/CircularDoublyLinkedList.cpp
	g++ -I ./include/ -o ./lib/ArrayList.o -c ./src/ArrayList.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/ArrayList.o ./lib/Node.o ./lib/CircularDoublyLinkedList.o ./src/Test.cpp

run:
	./bin/Test
