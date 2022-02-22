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



# Command: make LCS
LCSObjs := $(OBJ)/LCS.o

LCS: $(LCSObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LCS $(LCSObjs)
	$(EXE)/./LCS

$(OBJ)/LCS.o: $(SRC)/LCS.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/LCS.cpp -o $@
	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	


# Make all
all: 3Sum LCS

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
