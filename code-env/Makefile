# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 3

# CC is for the gcc compiler for C 
CC := gcc

# CFLAGS are the required compiler flags for the CSE 20133 course 
CFLAGS := -O0 -g -std=c11 -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror


# Compilation for the nothing program 
# Command: make nothing 
nothing: nothing.o
	$(CC) $(CFLAGS) -o nothing nothing.o

nothing.o: nothing.c
	$(CC) $(CFLAGS) -c nothing.c
	
	
	
# Compilation for the Hello, World 
# Command: make hello
hello: hello.o
	$(CC) $(CFLAGS) -o hello hello.o

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c


# Compilation for printing int and hex 
# Command: make specifiers
specifiers: specifiers.o
	$(CC) $(CFLAGS) -o specifiers specifiers.o

specifiers.o: specifiers.c
	$(CC) $(CFLAGS) -c specifiers.c


# Compilation for printing Hello World with a string specifier
# Command: make specifiers
helloSpec: helloSpec.o
	$(CC) $(CFLAGS) -o helloSpec helloSpec.o

helloSpec.o: helloSpec.c
	$(CC) $(CFLAGS) -c helloSpec.c

# Make all 
all: nothing hello specifiers helloSpec
	
# Make clean 
clean:
	rm -rf *.o *.swp nothing hello specifiers helloSpec                                            
