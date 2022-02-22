# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 16 Reading

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


# Command: make test_min_heap
# Tests the Treap Insert Results
test_min_heapObjs := $(OBJ)/test_min_heap.o 

test_min_heap: $(test_min_heapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/test_min_heap $(test_min_heapObjs)

$(OBJ)/test_min_heap.o: $(SRC)/test_min_heap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/test_min_heap.cpp -o $@
	
	
# Command: make test_max_heap
# Tests the Treap Insert Results
test_max_heapObjs := $(OBJ)/test_max_heap.o 

test_max_heap: $(test_max_heapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/test_max_heap $(test_max_heapObjs)

$(OBJ)/test_max_heap.o: $(SRC)/test_max_heap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/test_max_heap.cpp -o $@
	

# Command: make testBH
# Tests the Treap Insert Results
testBHObjs := $(OBJ)/testBH.o 

testBH: $(testBHObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testBH $(testBHObjs)

$(OBJ)/testBH.o: $(SRC)/testBH.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testBH.cpp -o $@



# Command: make testPQ
# Tests the Treap Insert Results
testPQObjs := $(OBJ)/testPQ.o 

testPQ: $(testPQObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testPQ $(testPQObjs)

$(OBJ)/testPQ.o: $(SRC)/testPQ.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testPQ.cpp -o $@
	


# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
	
	

