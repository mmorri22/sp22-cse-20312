# This is the Makefile for the CSE 20312 course - Lecture 16 - In Class

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 $(FLAGS) 

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj


# Command: make Prob1 - Max Heap Review
Prob1Objs := $(OBJ)/Prob1.o 

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@


# Command: make testMaxHeap
testMaxHeapObjs := $(OBJ)/testMaxHeap.o 

testMaxHeap: $(testMaxHeapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap $(testMaxHeapObjs)
	$(EXE)/./testMaxHeap

$(OBJ)/testMaxHeap.o: $(SRC)/testMaxHeap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap.cpp -o $@

	
# Command: make testMinHeap
FindKthLargestObjs := $(OBJ)/FindKthLargest.o 

FindKthLargest: $(FindKthLargestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindKthLargest $(FindKthLargestObjs)
	$(EXE)/./FindKthLargest

$(OBJ)/FindKthLargest.o: $(SRC)/FindKthLargest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/FindKthLargest.cpp -o $@
	


# Command: make FindMedian
FindMedianObjs := $(OBJ)/FindMedian.o 

FindMedian: $(FindMedianObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindMedian $(FindMedianObjs)
	$(EXE)/./FindMedian

$(OBJ)/FindMedian.o: $(SRC)/FindMedian.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/FindMedian.cpp -o $@


# Command: make Prob3 - Min Heap Review
Prob3Objs := $(OBJ)/Prob3.o 

Prob3: $(Prob3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob3 $(Prob3Objs)
	$(EXE)/./Prob3

$(OBJ)/Prob3.o: $(SRC)/Prob3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob3.cpp -o $@


# Make all
all: FindKthLargest FindMedian Prob3 Prob1



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
