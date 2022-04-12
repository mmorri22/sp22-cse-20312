# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lecture 25

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



# Command: make Prob1
# Class Example
Prob1Objs := $(OBJ)/Prob1.o

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@


# Command: make Prob2
# Class Example: Note - Deliberate compiler error
Prob2Objs := $(OBJ)/Prob2.o

Prob2: $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)

$(OBJ)/Prob2.o: $(SRC)/Prob2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@
	

# Command: make IrishTest
# Base class for First Inheritance Example
IrishTestObjs := $(OBJ)/IrishTest.o $(OBJ)/Irish.o 

IrishTest: $(IrishTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/IrishTest $(IrishTestObjs)

$(OBJ)/IrishTest.o: $(SRC)/IrishTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/IrishTest.cpp -o $@

$(OBJ)/Irish.o: $(SRC)/Irish.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Irish.cpp -o $@



# Command: make Inherit 
# Derived Classes for First Inheritance Example 
InheritObjs := $(OBJ)/Inherit.o $(OBJ)/Faculty.o $(OBJ)/Student.o $(OBJ)/Irish.o

Inherit: $(InheritObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Inherit $(InheritObjs)

# Inherit.cpp class both derived classes
$(OBJ)/Inherit.o: $(SRC)/Inherit.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Inherit.cpp -o $@

# Faculty inherits Irish
$(OBJ)/Faculty.o: $(SRC)/Faculty.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Faculty.cpp -o $@

# Student inherits Irish
$(OBJ)/Student.o: $(SRC)/Student.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Student.cpp -o $@

# Irish.o is already created in the Base Class
	


# Command: make Inherit2
# Example of this object in Inheritance Example 
Inherit2Objs := $(OBJ)/Inherit2.o $(OBJ)/Faculty.o $(OBJ)/Student.o $(OBJ)/Irish.o

Inherit2: $(Inherit2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Inherit2 $(Inherit2Objs)

# Inherit.cpp class both derived classes
$(OBJ)/Inherit2.o: $(SRC)/Inherit2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Inherit2.cpp -o $@

# Irish.o, Student.o, and Faculty.o are already created in make Inherit



# Command: make Lab11
PolymorphObjs := $(OBJ)/Polymorph.o $(OBJ)/BinNode.o $(OBJ)/NumNode.o $(OBJ)/AddNode.o $(OBJ)/SubNode.o $(OBJ)/DivNode.o $(OBJ)/MultNode.o

Polymorph: $(PolymorphObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Polymorph $(PolymorphObjs)

$(OBJ)/Polymorph.o: $(SRC)/Polymorph.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Polymorph.cpp -o $@

$(OBJ)/BinNode.o: $(SRC)/BinNode.cpp 
	$(PP) $(CXXFLAGS) -c $(SRC)/BinNode.cpp -o $@

$(OBJ)/NumNode.o: $(SRC)/NumNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/NumNode.cpp -o $@

$(OBJ)/AddNode.o: $(SRC)/AddNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/AddNode.cpp -o $@

$(OBJ)/SubNode.o: $(SRC)/SubNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SubNode.cpp -o $@

$(OBJ)/DivNode.o: $(SRC)/DivNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/DivNode.cpp -o $@

$(OBJ)/MultNode.o: $(SRC)/MultNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MultNode.cpp -o $@
	
	


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
