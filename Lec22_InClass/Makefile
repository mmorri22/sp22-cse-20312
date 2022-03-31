# This is the Makefile for the CSE 20312 course Lecture 21

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

	

# Command: make btree_node1_test
btree_node1_testObjs := $(OBJ)/btree_node1_test.o 

btree_node1_test: $(btree_node1_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_node1_test $(btree_node1_testObjs)

$(OBJ)/btree_node1_test.o: $(SRC)/btree_node1_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_node1_test.cpp -o $@

	
# Command: make btree_node2_test
btree_node2_testObjs := $(OBJ)/btree_node2_test.o 

btree_node2_test: $(btree_node2_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_node2_test $(btree_node2_testObjs)

$(OBJ)/btree_node2_test.o: $(SRC)/btree_node2_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_node2_test.cpp -o $@
	
	
# Command: make btree1_test
btree1_testObjs := $(OBJ)/btree1_test.o 

btree1_test: $(btree1_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree1_test $(btree1_testObjs)

$(OBJ)/btree1_test.o: $(SRC)/btree1_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree1_test.cpp -o $@


# Command: make btree2_test
btree2_testObjs := $(OBJ)/btree2_test.o 

btree2_test: $(btree2_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree2_test $(btree2_testObjs)

$(OBJ)/btree2_test.o: $(SRC)/btree2_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree2_test.cpp -o $@
	
	
# Command: make btree3_int_test
btree3_int_testObjs := $(OBJ)/btree3_int_test.o 

btree3_int_test: $(btree3_int_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree3_int_test $(btree3_int_testObjs)

$(OBJ)/btree3_int_test.o: $(SRC)/btree3_int_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree3_int_test.cpp -o $@
	
	
# Command: make btree3_str_test
btree3_str_testObjs := $(OBJ)/btree3_str_test.o 

btree3_str_test: $(btree3_str_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree3_str_test $(btree3_str_testObjs)

$(OBJ)/btree3_str_test.o: $(SRC)/btree3_str_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree3_str_test.cpp -o $@
	
	
# Command: make btree_int_O3_test
btree_int_O3_testObjs := $(OBJ)/btree_int_O3_test.o 

btree_int_O3_test: $(btree_int_O3_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_int_O3_test $(btree_int_O3_testObjs)

$(OBJ)/btree_int_O3_test.o: $(SRC)/btree_int_O3_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_int_O3_test.cpp -o $@
	
	
# Command: make btree_int_O4_test
btree_int_O4_testObjs := $(OBJ)/btree_int_O4_test.o 

btree_int_O4_test: $(btree_int_O4_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_int_O4_test $(btree_int_O4_testObjs)

$(OBJ)/btree_int_O4_test.o: $(SRC)/btree_int_O4_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_int_O4_test.cpp -o $@
	

# Command: make btree_str_O4_test
btree_str_O4_testObjs := $(OBJ)/btree_str_O4_test.o 

btree_str_O4_test: $(btree_str_O4_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_str_O4_test $(btree_str_O4_testObjs)

$(OBJ)/btree_str_O4_test.o: $(SRC)/btree_str_O4_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_str_O4_test.cpp -o $@
	
	
# Command: make btree_int_O5_test
btree_int_O5_testObjs := $(OBJ)/btree_int_O5_test.o 

btree_int_O5_test: $(btree_int_O5_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_int_O5_test $(btree_int_O5_testObjs)

$(OBJ)/btree_int_O5_test.o: $(SRC)/btree_int_O5_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_int_O5_test.cpp -o $@
	
	
# Command: make btree_adv_test
btree_adv_int_testObjs := $(OBJ)/btree_adv_int_test.o 

btree_adv_int_test: $(btree_adv_int_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_adv_int_test $(btree_adv_int_testObjs)

$(OBJ)/btree_adv_int_test.o: $(SRC)/btree_adv_int_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_adv_int_test.cpp -o $@
	

# Command: make btree_adv_str_test
btree_adv_str_testObjs := $(OBJ)/btree_adv_str_test.o 

btree_adv_str_test: $(btree_adv_str_testObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/btree_adv_str_test $(btree_adv_str_testObjs)

$(OBJ)/btree_adv_str_test.o: $(SRC)/btree_adv_str_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/btree_adv_str_test.cpp -o $@
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)



# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
