// Initialize the Red-Black Tree
#ifndef RBTREE_H
#define RBTREE_H 

#include "RBTNode.h"
#include <queue>		// Level Order Traversal only
#include <iostream>

template<class T> 
class RBTree { 

	private:
		
		// Private method for a copy
		void copyTree( RBTNode<T>*& destin, RBTNode<T>* origin ){
			
			// Return if NULL
			if( origin == NULL ){
				return;
			}
			
			// Use pre-order traversal to copy
			destin = origin;
			copyTree( destin->left, origin->left );
			copyTree( destin->right, origin->right );
			
		}
		
			
		// Red-Black Tree root node 
		RBTNode<T> *root; 
			
	public: 
		
		// Default Constructor
		RBTree() : root(NULL) { } 
		
		// Destructor
		~RBTree() {
			
			// Recursively Delete Tree
			delete root;
		} 
		
		// Copy Constructor
		RBTree( const RBTree<T>& copy ) : root( copy.root ){
			
			// Copy the values and colors from copy tree
			copyTree( root, copy.root );
		}
		
		// Assignment Operator
		RBTree<T>& operator=( const RBTree<T>& rhs ){
			
			if( this != &rhs ){
				// Copy the values and colors from rhs tree
				copyTree( this->root, rhs.root );
			}
			return *this;
		}

};

#endif
