#CXX=clang++
CXX=g++

FLAGS = -g -std=c++14

BINARIES=project1

project1: bucket.o hashTable.o main.o
	${CXX} $^ -o $@

all:
	${CXX} ${FLAGS} *.cpp

clean:
	/bin/rm -f ${BINARIES} *.o 