# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Coding Challenge 02 Solution

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
# Command: make PC02

$(OBJ)/life.o: $(SRC)/life.c
	$(PP) $(CXXFLAGS) -c $(SRC)/life.c -o $@

$(OBJ)/PC02.o: $(SRC)/PC02.c
	$(PP) $(CXXFLAGS) -c $(SRC)/PC02.c -o $@

PC02Objs :=  $(OBJ)/PC02.o $(OBJ)/life.o

PC02: $(PC02Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PC02 $(PC02Objs)


# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
