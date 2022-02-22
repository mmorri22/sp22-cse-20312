# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Programming Challenge 06
# Provided to the students

# g++ is for the GCC compiler for C++
CC := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)


# Run Compilation Command
# Command: make PC06

$(OBJ)/lru_cache.o: $(SRC)/lru_cache.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/lru_cache.cpp -o $@
	
$(OBJ)/PC06.o: $(SRC)/PC06.cpp
	$(CC) $(CXXFLAGS) -c $(SRC)/PC06.cpp -o $@

PC06Objs :=  $(OBJ)/PC06.o $(OBJ)/lru_cache.o

PC06: $(initialize) $(PC06Objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/PC06 $(PC06Objs)
	

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
