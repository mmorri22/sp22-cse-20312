#ifndef TREAP1_H
#define TREAP1_H

#include "TreapNode.h"
#include "queue.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

template< class T >
class Treap{
	
	private:
	
		// Copy Tree - Uses Pre-Order Traversal
		void copyTree(TreapNode< T >* originNode, TreapNode< T >*& destinNode){
			
			// Make the middle node
			destinNode = new TreapNode< T >( originNode->data, originNode->priority );
			
			// Recursively go left 
			if( originNode->left != NULL ){
				copyTree(originNode->left, destinNode->left);
			}
			
			// Recursively go right
			if( originNode->right != NULL ){
				copyTree(originNode->right, destinNode->right);
			}
		}
		
		// Delete the pointers using post-order traversal
		void deleteNode( TreapNode<T>*& currPtr ){
			
			// Return if NULL
			if( currPtr == NULL ){
				return;
			}
			
			// Recursively delete right
			deleteNode( currPtr->right );
			
			// Recursively delete left
			deleteNode( currPtr->left );
			
			// Delete the current pointer
			delete currPtr;
		}
	
		// Root node pointer
		TreapNode< T >* root;	
	
	public:
	
		Treap() : root() {}
		
		~Treap() { 
		
			// Recursively delete the pointers
			deleteNode( root ); 
		}
		
		// Copy constructor
		Treap(const Treap<T>& copy) : root(NULL) {
			// If assign.root is NULL, assign is an empty tree
			if( copy.root == NULL ){
				return;
			}
			
			// Set the root to the new data
			root = new TreapNode< T >( copy.root->data, copy->root.priority );
			
			// Set the root to the new data
			copyTree(copy.root, root);
		}
		
		// Assignment operator
		Treap<T>& operator=(const Treap<T>& assign){
			
			if( this != &assign ){
				// If assign.root is NULL, assign is an empty tree
				if( assign.root == NULL ){
					return *this;
				}
				
				// Set the root to the new data
				root = new TreapNode< T >( assign.root->data, assign->root.priority );
				
				// Set the root to the new data
				copyTree(assign.root, root);
			}
			
			return *this;	// Return de-referenced class ptr
		}
	
};


#endif