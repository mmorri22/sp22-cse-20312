# This is the Makefile for the CSE 24312 course - Lecture 15 - Part 2

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


	
# Command: make TrieNodeTest
# Initial Examples of Trie Node
TrieNodeTestObjs := $(OBJ)/TrieNodeTest.o 

TrieNodeTest: $(TrieNodeTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TrieNodeTest $(TrieNodeTestObjs)
	$(EXE)/./TrieNodeTest

$(OBJ)/TrieNodeTest.o: $(SRC)/TrieNodeTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TrieNodeTest.cpp -o $@



# Command: make TrieTest
# Initial Examples of Trie Node
TrieTestObjs := $(OBJ)/TrieTest.o 

TrieTest: $(TrieTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TrieTest $(TrieTestObjs)
	$(EXE)/./TrieTest

$(OBJ)/TrieTest.o: $(SRC)/TrieTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TrieTest.cpp -o $@



# Command: make WordBreak
WordBreakObjs := $(OBJ)/WordBreak.o 

WordBreak: $(WordBreakObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/WordBreak $(WordBreakObjs)
	$(EXE)/./WordBreak $(SRC)/Dictionary.txt

$(OBJ)/WordBreak.o: $(SRC)/WordBreak.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/WordBreak.cpp -o $@


# Command: make WordSearch
WordSearchObjs := $(OBJ)/WordSearch.o 

WordSearch: $(WordSearchObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/WordSearch $(WordSearchObjs)
	$(EXE)/./WordSearch $(SRC)/Dictionary.txt

$(OBJ)/WordSearch.o: $(SRC)/WordSearch.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/WordSearch.cpp -o $@


# Make all
all: TrieNodeTest TrieTest WordBreak WordSearch


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*

	

