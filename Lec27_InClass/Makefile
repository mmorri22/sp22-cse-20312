# This is the Makefile for the CSE 20312 course - Lecture 27

# GCC is for the GCC compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CFLAGS := -std=c11 -lpthread $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := objects

# Command: make pthread_1
# Prints a pthread address an int - Not initialized yet, so PQC not included
pthread_1Objs := $(OBJ)/pthread_1.o 

pthread_1: $(pthread_1Objs)
	$(CC) -std=c11 -o $(EXE)/pthread_1 $(pthread_1Objs)
	$(EXE)/./pthread_1

$(OBJ)/pthread_1.o: $(SRC)/pthread_1.c
	$(CC) -std=c11 -c $(SRC)/pthread_1.c -o $@
	
	
# Command: make pthread_2
# Prints an initialized pthread
pthread_2Objs := $(OBJ)/pthread_2.o 

pthread_2: $(pthread_2Objs)
	$(CC) $(CFLAGS) -o $(EXE)/pthread_2 $(pthread_2Objs)
	valgrind --leak-check=full --track-origins=yes $(EXE)/./pthread_2

$(OBJ)/pthread_2.o: $(SRC)/pthread_2.c
	$(CC) $(CFLAGS) -c $(SRC)/pthread_2.c -o $@


# Command: make pthread_3
# Prints an initialized pthread
pthread_3Objs := $(OBJ)/pthread_3.o 

pthread_3: $(pthread_3Objs)
	$(CC) $(CFLAGS) -o $(EXE)/pthread_3 $(pthread_3Objs)
	valgrind --leak-check=full --track-origins=yes $(EXE)/./pthread_3

$(OBJ)/pthread_3.o: $(SRC)/pthread_3.c
	$(CC) $(CFLAGS) -c $(SRC)/pthread_3.c -o $@
	
	
# Command: make pthread_in_class
# Prints an initialized pthread
pthread_in_classObjs := $(OBJ)/pthread_in_class.o 

pthread_in_class: $(pthread_in_classObjs)
	$(CC) $(CFLAGS) -o $(EXE)/pthread_in_class $(pthread_in_classObjs)
	valgrind --leak-check=full --track-origins=yes $(EXE)/./pthread_in_class

$(OBJ)/pthread_in_class.o: $(SRC)/pthread_in_class.c
	$(CC) $(CFLAGS) -c $(SRC)/pthread_in_class.c -o $@
	
	
# Command: make pthread_in_class_rc
# Prints an initialized pthread - No Mutex Lock
pthread_in_class_rcObjs := $(OBJ)/pthread_in_class_rc.o 

pthread_in_class_rc: $(pthread_in_class_rcObjs)
	$(CC) $(CFLAGS) -o $(EXE)/pthread_in_class_rc $(pthread_in_class_rcObjs)
	valgrind --leak-check=full --track-origins=yes $(EXE)/./pthread_in_class_rc

$(OBJ)/pthread_in_class_rc.o: $(SRC)/pthread_in_class_rc.c
	$(CC) $(CFLAGS) -c $(SRC)/pthread_in_class_rc.c -o $@


# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
