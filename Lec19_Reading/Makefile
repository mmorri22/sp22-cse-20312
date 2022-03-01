# This is the Makefile for the CSE 20312 course Lecture 19

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

	

# Command: make Dijkstra
DijkstraObjs := $(OBJ)/Dijkstra.o 

Dijkstra: $(DijkstraObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Dijkstra $(DijkstraObjs)

$(OBJ)/Dijkstra.o: $(SRC)/Dijkstra.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Dijkstra.cpp -o $@

	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)



# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
