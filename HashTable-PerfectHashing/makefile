CXX=g++

FLAGS = -g -std=c++14

BINARIES=project1b

project1b: hash24.o hashTable.o main.o Dictionary.o
	${CXX} $^ -o $@

all:
	${CXX} ${FLAGS} *.cpp

clean:
	/bin/rm -f ${BINARIES} *.o 