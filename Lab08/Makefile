# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lab 08

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


# LeetCode Insert Interval Problem
# Command: make InsertInt
	
InsertInt.o: InsertInt.cpp
	$(PP) $(CXXFLAGS) -c InsertInt.cpp -o $@
	
InsertIntObjs := InsertInt.o

InsertInt: $(InsertIntObjs)
	$(PP) $(CXXFLAGS) -o InsertInt $(InsertIntObjs)
	

# Make all
all: InsertInt

# Make clean
clean :
	rm -rf *.o InsertInt
