CXX=g++

FLAGS = -g -std=c++14

BINARIES=project2

project2: Heap.o MinMedianMaxSketch.o main.o
	${CXX} $^ -o $@

all:
	${CXX} ${FLAGS} *.cpp

clean:
	/bin/rm -f ${BINARIES} *.o 