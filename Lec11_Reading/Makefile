# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 11 - CSE 20312

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)



# C++ Hello, World Example
# Command: make hello
$(OBJ)/hello_cpp.o: $(SRC)/hello_cpp.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/hello_cpp.cpp -o $@
	
hello_cpp_objs := $(OBJ)/hello_cpp.o

hello_cpp: $(hello_cpp_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/hello_cpp $(hello_cpp_objs)
	

# C++ New, Delete Example
# Command: make new_delete
$(OBJ)/new_delete.o: $(SRC)/new_delete.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/new_delete.cpp -o $@
	
new_delete_objs := $(OBJ)/new_delete.o

new_delete: $(new_delete_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/new_delete $(new_delete_objs)
	
	
# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*