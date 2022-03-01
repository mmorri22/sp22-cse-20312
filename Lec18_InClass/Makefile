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

	

# Command: make MST
MSTObjs := $(OBJ)/MST.o 

MST: $(MSTObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST $(MSTObjs)

$(OBJ)/MST.o: $(SRC)/MST.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST.cpp -o $@
	
	
# Command: make MST2
MST2Objs := $(OBJ)/MST2.o 

MST2: $(MST2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST2 $(MST2Objs)

$(OBJ)/MST2.o: $(SRC)/MST2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST2.cpp -o $@
	
	
# Command: make MST3
MST3Objs := $(OBJ)/MST3.o 

MST3: $(MST3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST3 $(MST3Objs)

$(OBJ)/MST3.o: $(SRC)/MST3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST3.cpp -o $@

	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)



# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
