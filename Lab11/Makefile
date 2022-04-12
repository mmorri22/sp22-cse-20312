# This is the Makefile for the CSE 20312 course Lecture 21

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

	

# Command: make Shape
Lab11Objs := $(OBJ)/Lab11.o

Lab11: $(Lab11Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Lab11 $(Lab11Objs)
	
$(OBJ)/Lab11.o: $(SRC)/Lab11.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Lab11.cpp -o $@
	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)



# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
