# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 22

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj

# Command: make Prob1
Prob1Objs := $(OBJ)/Prob1.o

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@


# Command: make Prob2
Prob2Objs := $(OBJ)/Prob2.o

Prob2: $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)
	$(EXE)/./Prob2

$(OBJ)/Prob2.o: $(SRC)/Prob2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@


# Command: make testRBTNode1
# Successfully create and allocate Red-Black Tree Nodes
testRBTNode1Objs := $(OBJ)/testRBTNode1.o

testRBTNode1: $(testRBTNode1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTNode1 $(testRBTNode1Objs)
	$(EXE)/./testRBTNode1

$(OBJ)/testRBTNode1.o: $(SRC)/testRBTNode1.cpp $(INC)/RBTNode1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTNode1.cpp -o $@
	
	
	
# Command: make testRBTNode2
# Obtain and print the node's uncle
testRBTNode2Objs := $(OBJ)/testRBTNode2.o

testRBTNode2: $(testRBTNode2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTNode2 $(testRBTNode2Objs)
	$(EXE)/./testRBTNode2

$(OBJ)/testRBTNode2.o: $(SRC)/testRBTNode2.cpp $(INC)/RBTNode2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTNode2.cpp -o $@


# Command: make testRBTNode1
# Test initial class for compilation
testRBTree1Objs := $(OBJ)/testRBTree1.o

testRBTree1: $(testRBTree1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree1 $(testRBTree1Objs)
	$(EXE)/./testRBTree1

$(OBJ)/testRBTree1.o: $(SRC)/testRBTree1.cpp $(INC)/RBTree1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree1.cpp -o $@



# Command: make testRBTNode2
# Test initial class for compilation
testRBTree2Objs := $(OBJ)/testRBTree2.o

testRBTree2: $(testRBTree2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testRBTree2 $(testRBTree2Objs)
	$(EXE)/./testRBTree2

$(OBJ)/testRBTree2.o: $(SRC)/testRBTree2.cpp $(INC)/RBTree2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testRBTree2.cpp -o $@	


# Command: make Prob6
Prob6Objs := $(OBJ)/Prob6.o

Prob6: $(Prob6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob6 $(Prob6Objs)
	$(EXE)/./Prob6

$(OBJ)/Prob6.o: $(SRC)/Prob6.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob6.cpp -o $@


# Command: make RBTreeTest
# Shows a successful RBTree Tree Test
RBTreeTestObjs := $(OBJ)/RBTreeTest.o

RBTreeTest: $(RBTreeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBTreeTest $(RBTreeTestObjs)
	$(EXE)/./RBTreeTest

$(OBJ)/RBTreeTest.o: $(SRC)/RBTreeTest.cpp $(INC)/RBTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/RBTreeTest.cpp -o $@
	

# Command: make RBDelTest
# Shows a successful RBTree Tree Test
RBDelTestObjs := $(OBJ)/RBDelTest.o

RBDelTest: $(RBDelTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBDelTest $(RBDelTestObjs)
	$(EXE)/./RBDelTest

$(OBJ)/RBDelTest.o: $(SRC)/RBDelTest.cpp $(INC)/RBTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/RBDelTest.cpp -o $@


# Command: make RBTreePrintAddr
# Shows a successful RBTree Tree Test
RBTreePrintAddrObjs := $(OBJ)/RBTreePrintAddr.o

RBTreePrintAddr: $(RBTreePrintAddrObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/RBTreePrintAddr $(RBTreePrintAddrObjs)

$(OBJ)/RBTreePrintAddr.o: $(SRC)/RBTreePrintAddr.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/RBTreePrintAddr.cpp -o $@
	

# Command: make treeTest
# Shows a successful RBTree Tree Test
treeTestObjs := $(OBJ)/treeTest.o

treeTest: $(treeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/treeTest $(treeTestObjs)
	$(EXE)/./treeTest

$(OBJ)/treeTest.o: $(SRC)/treeTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/treeTest.cpp -o $@



# Command: make multiSet
# Shows a successful RBTree Tree Test
multiSetObjs := $(OBJ)/multiSet.o

multiSet: $(multiSetObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/multiSet $(multiSetObjs)
	$(EXE)/./multiSet

$(OBJ)/multiSet.o: $(SRC)/multiSet.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/multiSet.cpp -o $@


# Make all
all: Prob1 Prob2 Prob3


# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
	
	

