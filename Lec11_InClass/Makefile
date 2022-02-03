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
CXXFLAGS := -m64 -std=c++11 $(FLAGS)


# Cin Example
# Command: make cin
$(OBJ)/cin.o: $(SRC)/cin.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/cin.cpp -o $@
	
cin_objs := $(OBJ)/cin.o

cin: $(cin_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/cin $(cin_objs)
	

# C++ Call by Reference Example
# Command: make pass_call_comp
$(OBJ)/pass_call_comp.o: $(SRC)/pass_call_comp.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/pass_call_comp.cpp -o $@
	
pass_call_comp_objs := $(OBJ)/pass_call_comp.o

pass_call_comp: $(pass_call_comp_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/pass_call_comp $(pass_call_comp_objs)
	

	

# C++ New, Delete Example
# Command: make new_delete
$(OBJ)/new_delete.o: $(SRC)/new_delete.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/new_delete.cpp -o $@
	
new_delete_objs := $(OBJ)/new_delete.o

new_delete: $(new_delete_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/new_delete $(new_delete_objs)
	
	
	
# C++ Namespace Example
# Command: make namespace
$(OBJ)/namespace.o: $(SRC)/namespace.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/namespace.cpp -o $@
	
namespace_objs := $(OBJ)/namespace.o

namespace: $(namespace_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/namespace $(namespace_objs)
	
	
	
# C++ Namespace Direct Example
# Command: make namespace_direct
$(OBJ)/namespace_direct.o: $(SRC)/namespace_direct.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/namespace_direct.cpp -o $@
	
namespace_direct_objs := $(OBJ)/namespace_direct.o

namespace_direct: $(namespace_direct_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/namespace_direct $(namespace_direct_objs)
	
	
	
# C++ Namespace Fixed Example
# Command: make namespace_fixed
$(OBJ)/namespace_fixed.o: $(SRC)/namespace_fixed.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/namespace_fixed.cpp -o $@
	
namespace_fixed_objs := $(OBJ)/namespace_fixed.o

namespace_fixed: $(namespace_fixed_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/namespace_fixed $(namespace_fixed_objs)
	
	
	
# C++ Vector Example
# Command: make vector
$(OBJ)/vector.o: $(SRC)/vector.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/vector.cpp -o $@
	
vector_objs := $(OBJ)/vector.o

vector: $(vector_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/vector $(vector_objs)
	
	
# C++ Vector Capacity Example
# Command: make vector_capac
$(OBJ)/vector_capac.o: $(SRC)/vector_capac.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/vector_capac.cpp -o $@
	
vector_capac_objs := $(OBJ)/vector_capac.o

vector_capac: $(vector_capac_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/vector_capac $(vector_capac_objs)
	
	
# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*