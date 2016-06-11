CC = g++
FLAGS = -g -std=c++11 -Wextra -Wall
.PHONY: IntMatrix tar clean

IntMatrixMainDriver: IntMatrixDriver.cpp IntMatrix.o
	$(CC) $(FLAGS) -c IntMatrixDriver.cpp
	$(CC) $(FLAGS) IntMatrix.o IntMatrixDriver.o -o IntMatrixMainDriver

IntMatrix: IntMatrix.o

IntMatrix.o: IntMatrix.cpp IntMatrix.h
	$(CC) $(FLAGS) -c IntMatrix.cpp

tar: IntMatrix.h IntMatrix.cpp IntMatrixDriver.cpp
	tar -cvf ex1.tar IntMatrix.h IntMatrix.cpp IntMatrixDriver.cpp Makefile

clean:
	rm -f *.o IntMatrixMainDriver ex1.tar

all: IntMatrixMainDriver tar