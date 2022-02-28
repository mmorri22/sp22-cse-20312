# This is the Makefile for the CSE 20312 course Lab 08

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := objects

	

# Command: make BFS
BFSObjs := $(OBJ)/BFS.o 

BFS: $(BFSObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BFS $(BFSObjs)
	$(EXE)/./BFS

$(OBJ)/BFS.o: $(SRC)/BFS.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BFS.cpp -o $@


# Command: make BFS2
BFS2Objs := $(OBJ)/BFS2.o 

BFS2: $(BFS2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BFS2 $(BFS2Objs)
	$(EXE)/./BFS2

$(OBJ)/BFS2.o: $(SRC)/BFS2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BFS2.cpp -o $@
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)



# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
