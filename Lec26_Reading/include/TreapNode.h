#ifndef TREAPNODE_H
#define TREAPNODE_H

#include <cstdlib>	// Needed for NULL keyword

template< class T >
struct TreapNode{
	
	// Struct Members
	T     data;
	double priority;
	TreapNode* left;
	TreapNode* right;	
	
	// Default Constructor
	TreapNode() : data(), priority(), left(NULL), right(NULL){ }
	
	// Overloaded Constructor
	TreapNode(T dataIn, double priorityIn) : data(dataIn), priority(priorityIn), left(NULL), right(NULL){ }

	// Destructor
	~TreapNode(){}
	
	// Copy Constructor
	TreapNode(const TreapNode<T>& copy) : data(copy.data), priority( copy.priority ), left(NULL), right(NULL) { }
	
	// Assignment Operator
	TreapNode<T>& operator=(const TreapNode<T>& assign){
		
		if(this != &assign){
			this->data = assign.data;
			this->priority = assign.priority;
		}
		return *this;
	}
};

#endif

