CXX=g++

FLAGS = -g -std=c++14

BINARIES=project3

project3: Vertex.h GraphGenerator.o AdjacencyNode.h AVLtree.o main.o GraphOperator.o AdjacencyList.h
	${CXX} $^ -o $@

all:
	${CXX} ${FLAGS} *.cpp

clean:
	/bin/rm -f ${BINARIES} *.o 