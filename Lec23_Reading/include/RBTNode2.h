// Modified from RBTNode1.h with isOnLeft, isOnRight, sibling, and uncle

#ifndef RBTNODE2_H
#define RBTNODE2_H

#include <cstdlib>
#include <iostream> 
  
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
	// Copy Constructor
	RBTNode<T>(const RBTNode<T>& copy) : value(copy.value), color(copy.color), left(NULL), right(NULL), parent(NULL) { }
	
	// Assignment Operator
	RBTNode<T>& operator=(const RBTNode<T>& assign) {
		
		if(this != &assign){
			
			this->value = assign->value;
			this->color = assign->color;
		}
		return *this;
	}
	
	// Assignment Operator
	RBTNode<T>* operator=(const RBTNode<T>* assign) {
		
		if(this != assign){
			
			this = assign;
			
		}
		return this;
	}
	
	// Returns true if this is the parent's left node
	bool isOnLeft() const{ 
	
		return this == parent->left; 
		
	} 
	 
	// Returns true if this is the parent's right node
	bool isOnRight() const{ 
	
		return this == parent->right; 
		
	} 
	  
	// returns pointer to sibling 
	RBTNode<T>* sibling() const{ 
	
		// sibling null if no parent 
		if (parent == NULL) 
			return NULL; 

		// Return a pointer to the Sibling
		return (isOnLeft()) ? parent->right : parent->left; 
	} 
	
	// Get the Node's Uncle 
	RBTNode<T>* uncle() const{ 

		// If no parent or grandparent, then no uncle 
		if (parent == NULL or parent->parent == NULL) 
			return NULL; 

		// Return a pointer to the uncle
		return (parent->isOnLeft()) ? parent->parent->right : parent->parent->left;
	}

}; 

#endif
