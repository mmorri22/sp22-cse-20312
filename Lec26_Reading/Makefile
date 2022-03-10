# This is the Makefile for the CSE 20312 course - Lecture 29

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := objects


# Command: make print_splay
# Shows a successful Splay Tree Test
print_splayObjs := $(OBJ)/print_splay.o

print_splay: $(print_splayObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/print_splay $(print_splayObjs)
	$(EXE)/./print_splay

$(OBJ)/print_splay.o: $(SRC)/print_splay.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/print_splay.cpp -o $@


# Command: make SplayTest
# Shows a successful Splay Tree Test
SplayTestObjs := $(OBJ)/SplayTest.o

SplayTest: $(SplayTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SplayTest $(SplayTestObjs)
	$(EXE)/./SplayTest

$(OBJ)/SplayTest.o: $(SRC)/SplayTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SplayTest.cpp -o $@



# Command: make CacheExample
# Shows a SplayTree accessing memory locations
CacheExampleObjs := $(OBJ)/CacheExample.o

CacheExample: $(CacheExampleObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/CacheExample $(CacheExampleObjs)
	$(EXE)/./CacheExample

$(OBJ)/CacheExample.o: $(SRC)/CacheExample.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/CacheExample.cpp -o $@
	

	
# Command: make TreapInsert
# Tests the Treap Insert Results
TreapInsertObjs := $(OBJ)/TreapInsert.o 

TreapInsert: $(TreapInsertObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapInsert $(TreapInsertObjs)
	$(EXE)/./TreapInsert

$(OBJ)/TreapInsert.o: $(SRC)/TreapInsert.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapInsert.cpp -o $@


# Command: make InsertRandom
# Tests the Treap Insert Results
InsertRandomObjs := $(OBJ)/InsertRandom.o 

InsertRandom: $(InsertRandomObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom $(InsertRandomObjs)
	$(EXE)/./InsertRandom

$(OBJ)/InsertRandom.o: $(SRC)/InsertRandom.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom.cpp -o $@
	
	
# Command: make InsertRandom2
# Tests height for 100 versions of 100 inserts
InsertRandom2Objs := $(OBJ)/InsertRandom2.o 

InsertRandom2: $(InsertRandom2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom2 $(InsertRandom2Objs)
	$(EXE)/./InsertRandom2

$(OBJ)/InsertRandom2.o: $(SRC)/InsertRandom2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom2.cpp -o $@
	
	
# Command: make TreapTest
# Tests the Treap Insert Results
TreapTestObjs := $(OBJ)/TreapTest.o 

TreapTest: $(TreapTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapTest $(TreapTestObjs)
	$(EXE)/./TreapTest

$(OBJ)/TreapTest.o: $(SRC)/TreapTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapTest.cpp -o $@



# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
