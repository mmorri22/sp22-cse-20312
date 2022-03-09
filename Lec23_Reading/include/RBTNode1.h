// Set the constructors and Rule of 3 for RBTNode struct

#ifndef RBTNODE1_H
#define RBTNODE1_H

#include <cstdlib>
#include <iostream> 
  
 /* Problem 3 Starts Here */
enum COLOR { RED, BLACK }; 
  
template<class T>
struct RBTNode {  
 
 	T value; // Data itself
  	COLOR color; // Indicates if red or black
  	RBTNode<T> *left, *right, *parent; // Keeps track of the nodes for rotation

	// Default constructor
  	RBTNode<T>() : value(), color(RED), left(NULL), right(NULL), parent(NULL) { } 

	// Overloaded Constructor
  	RBTNode<T>(const T& valueIn) : value(valueIn), color(RED), left(NULL), right(NULL), parent(NULL) { } 
	
	// Destructor
	~RBTNode() {
		
		if( right != NULL )
			delete right;
		
		if( left != NULL )
			delete left;
		
	}
	
	// Copy Constructor
	RBTNode<T>(const RBTNode<T>& copy) : value(copy.value), color(copy.color), left(NULL), right(NULL), parent(NULL) { }
	
	// Assignment Operator
	RBTNode<T>& operator=(const RBTNode<T>& assign){
		
		if(this != &assign){
			
			this->value = assign->value;
			this->color = assign->color;
		}
		return *this;
	}
	
	// Assignment Operator
	RBTNode<T>* operator=(const RBTNode<T>* assign){
		
		if(this != &assign){
			
			this->value = assign->value;
			this->color = assign->color;
		}
		return *this;
	}

}; 

#endif
