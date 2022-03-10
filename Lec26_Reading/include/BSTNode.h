#ifndef BSTNODE_H
#define BSTNODE_H

#include <cstdlib>	// Needed for NULL keyword

template< class T >
struct BSTNode{
	
	// Struct Members
	T     data;
	BSTNode* left;
	BSTNode* right;	
	
	// Default Constructor
	BSTNode() : data(), left(NULL), right(NULL){ }
	
	// Overloaded Constructor
	BSTNode(T dataIn) : data(dataIn), left(NULL), right(NULL){ }

	// Destructor
	~BSTNode(){}
	
	// Copy Constructor
	BSTNode(const BSTNode<T>& copy){
		data = copy.data;
		left = copy.left;
		right = copy.right;
	}
	
	// Assignment Operator
	BSTNode<T>& operator=(const BSTNode<T>& assign){
		
		if(this != &assign){
			this->data = assign.data;
			this->left = assign.left;
			this->right = assign.right;
		}
		return *this;
	}
	
};

#endif

