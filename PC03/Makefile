# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Programming Challenge 03 Solution

# gcc is for the GCC compiler for C
PP := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -std=c11 $(FLAGS)

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
# Command: make PC03

$(OBJ)/fenwick.o: $(SRC)/fenwick.c
	$(PP) $(CXXFLAGS) -c $(SRC)/fenwick.c -o $@
	
$(OBJ)/PC03.o: $(SRC)/PC03.c
	$(PP) $(CXXFLAGS) -c $(SRC)/PC03.c -o $@

PC03Objs :=  $(OBJ)/PC03.o $(OBJ)/fenwick.o

PC03: $(PC03Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PC03 $(PC03Objs)
	

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
