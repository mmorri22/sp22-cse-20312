# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lecture 15

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)


# Command: make containsDup
containsDupObjs := $(OBJ)/containsDup.o

containsDup: $(containsDupObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/containsDup $(containsDupObjs)
	$(EXE)/./containsDup

$(OBJ)/containsDup.o: $(SRC)/containsDup.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/containsDup.cpp -o $@


# Command: make TwoSums
TwoSumsObjs := $(OBJ)/TwoSums.o

TwoSums: $(TwoSumsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TwoSums $(TwoSumsObjs)
	$(EXE)/./TwoSums

$(OBJ)/TwoSums.o: $(SRC)/TwoSums.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TwoSums.cpp -o $@


# Command: make 3Sum
3SumObjs := $(OBJ)/3Sum.o

3Sum: $(3SumObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/3Sum $(3SumObjs)
	$(EXE)/./3Sum

$(OBJ)/3Sum.o: $(SRC)/3Sum.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/3Sum.cpp -o $@



# Command: make fibMemo
fibMemoObjs := $(OBJ)/fibMemo.o

fibMemo: $(fibMemoObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/fibMemo $(fibMemoObjs)

$(OBJ)/fibMemo.o: $(SRC)/fibMemo.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/fibMemo.cpp -o $@
	
	
# Command: make countSort
countSortObjs := $(OBJ)/countSort.o

countSort: $(countSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/countSort $(countSortObjs)

$(OBJ)/countSort.o: $(SRC)/countSort.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/countSort.cpp -o $@
	
	
# Command: make bucketSort
bucketSortObjs := $(OBJ)/bucketSort.o

bucketSort: $(bucketSortObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/bucketSort $(bucketSortObjs)

$(OBJ)/bucketSort.o: $(SRC)/bucketSort.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/bucketSort.cpp -o $@


# Make all
all: TwoSums 3Sum LCS containsDup

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
