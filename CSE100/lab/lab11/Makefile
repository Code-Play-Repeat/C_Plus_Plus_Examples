CC=g++
CFLAGS=-c -Wall


all: Q2

Q2: lab11q2.o 
	$(CC) lab11q2.o -o Q2

lab11q2.o: lab11q2.cpp Graph.cpp
	$(CC) $(CFLAGS) lab11q2.cpp Graph.cpp


clean:
	rm -rf *o Q2 


