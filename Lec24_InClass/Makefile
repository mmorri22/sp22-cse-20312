# This is the Makefile for the CSE 20312 course - Lecture 24

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
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


# Command: make SubsetSums
# Initial Examples of bitsets using Subset Sum problem
SubsetSumsObjs := $(OBJ)/SubsetSums.o 

SubsetSums: $(SubsetSumsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SubsetSums $(SubsetSumsObjs)
	$(EXE)/./SubsetSums

$(OBJ)/SubsetSums.o: $(SRC)/SubsetSums.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SubsetSums.cpp -o $@



# Command: make HammingDist
# Calculate the Hamming Distance of an unsigned integer
HammingDistObjs := $(OBJ)/HammingDist.o 

HammingDist: $(HammingDistObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HammingDist $(HammingDistObjs)
	$(EXE)/./HammingDist

$(OBJ)/HammingDist.o: $(SRC)/HammingDist.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HammingDist.cpp -o $@



# Command: make Reverse Dist
# Reverses the Bits of an unsigned int
ReverseBitsObjs := $(OBJ)/ReverseBits.o 

ReverseBits: $(ReverseBitsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ReverseBits $(ReverseBitsObjs)
	$(EXE)/./ReverseBits

$(OBJ)/ReverseBits.o: $(SRC)/ReverseBits.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/ReverseBits.cpp -o $@
	
	

# Command: make BloomURL
# Initial Examples of Bloom Filter
BloomURLObjs := $(OBJ)/BloomURL.o 

BloomURL: $(BloomURLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BloomURL $(BloomURLObjs)
	$(EXE)/./BloomURL $(SRC)/Access_URLs.txt $(SRC)/NDCSE_URLs.txt

$(OBJ)/BloomURL.o: $(SRC)/BloomURL.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BloomURL.cpp -o $@



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*

	

