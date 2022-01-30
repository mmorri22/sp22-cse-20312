# This is the Makefile for Lecture 09 - In-Class Programming - CSE 20312

# gcc is for the compiler for C
PP := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe


# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)
	
	
# Create the Left Rotate Function Object
$(OBJ)/bst.o: $(SRC)/bst.c
	$(PP) $(CFLAGS) -c $(SRC)/bst.c -o $@
	
	
# Create the Left Rotate Function Object - Solution
$(OBJ)/bst_sol.o: $(SRC)/bst_sol.c
	$(PP) $(CFLAGS) -c $(SRC)/bst_sol.c -o $@
	
	
# Create the Lec09 object
$(OBJ)/Lec09.o: $(SRC)/Lec09.c
	$(PP) $(CFLAGS) -c $(SRC)/Lec09.c -o $@
	
	
# Create the Lec09 object
$(OBJ)/Lec09_sol.o: $(SRC)/Lec09_sol.c
	$(PP) $(CFLAGS) -c $(SRC)/Lec09_sol.c -o $@
	
	
# Binary Search Tree Objects
Lec09_objs := $(OBJ)/bst.o $(OBJ)/Lec09.o


# Binary Search Tree Executable and Run
Lec09: $(Lec09_objs)
	$(PP) $(CFLAGS) -o $(EXE)/Lec09 $(Lec09_objs)
	
	
# Binary Search Tree Objects
Lec09_sol_objs := $(OBJ)/bst_sol.o $(OBJ)/Lec09_sol.o


# Binary Search Tree Executable and Run
Lec09_sol: $(Lec09_sol_objs)
	$(PP) $(CFLAGS) -o $(EXE)/Lec09_sol $(Lec09_sol_objs)
	
	
# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*