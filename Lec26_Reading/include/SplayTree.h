// Citation: This code is a modified version of the Splay Tree presented by 
// Daniel Sleator at https://www.link.cs.cmu.edu/splay/download/top-down-splay.c 
// Modifications are for C to C++, and to meet Production Quality Compilation Rules 
// Another modification is using BSTNodes, Inheritance, and Polymorphism 
// to reinforce concepts previously taught in the CSE 20312 course

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "BST.h"

template< class T >
class SplayTree : public BST<T>{
	
	private:
	
		/* Problem 3 begins here */
		BSTNode<T>* splay( BSTNode< T >*& currPtr, const T& value ){
			

			return currPtr;
			
		}

		BSTNode< T >* Insert( BSTNode< T >*& currPtr, const T& value ){
			
			BSTNode<T> * newNode = new BSTNode<T>( value );
			
			if (currPtr == NULL) {
				newNode->left = NULL; 
				newNode->right = NULL;
				return newNode;
			}
						
			currPtr = splay(currPtr, value);
						
			if (value < currPtr->data) {
				newNode->left = currPtr->left;
				newNode->right = currPtr;
				currPtr->left = NULL;
				return newNode;
			} 
			else if ( value > currPtr->data ) {
				newNode->right = currPtr->right;
				newNode->left = currPtr;
				currPtr->right = NULL;
				return newNode;
			} 
			else { /* We get here if it's already in the tree */
					 /* Don't add it again                      */
				delete newNode;
				return currPtr;
			}			
			
		}
		
		// Public method - Find and delete the element
		BSTNode<T>* remove( BSTNode<T>*& currPtr, const T& value ){
			
			BSTNode<T>* x;
			
			if (currPtr == NULL)
				return NULL;
				
			currPtr = splay(currPtr, value);
			
			/* If we found the item */
			if ( value == currPtr->data ) {
				
				if (currPtr->left == NULL) {
					x = currPtr->right;
				} 
				else {
					x = splay(currPtr->left, value);
					x->right = currPtr->right;
				}
				free(currPtr);
				return x;
			}
			
			/* We did not find the item */
			return currPtr;

		}
	
	public:
	
		SplayTree() : BST<T>() {}
	
		~SplayTree() {}
		
		void Insert( const T& valueIn ){
			
			// Insert in its correct location
			this->root = this->Insert( this->root, valueIn );
			
		}
		
		bool contains( const T& value ){
		
			if( this->root == NULL )
				return false;
			
			BSTNode<T>* seekPtr = this->root;
			
			while( true ){
				
				if( seekPtr->data == value )
					break;
				
				if( seekPtr->left == NULL && value < seekPtr->data )
					break;
				
				if( seekPtr->left != NULL && value < seekPtr->data )
					seekPtr = seekPtr->left;
				
				else if( seekPtr->right == NULL && value > seekPtr->data )
					break; 
				
				else if( seekPtr->right != NULL && value > seekPtr->data )
					seekPtr = seekPtr->right;
				
			}
						
			this->root = splay( seekPtr, value );
									
			return this->root->data == value;
			
		}
		
		bool remove( const T& element ){
			
			if( this->root == NULL )
				return false;
					
			this->root = this->remove( this->root, element );				
			
			return true;
		}
		
		// Print the InOrder and Pre-Order Traversal 
		friend std::ostream& operator<<( std::ostream& output, const SplayTree<T>& theTree ){
			
			// Pass the ostream and the root to print in order recursively
			output << "In-Order  : ";
			theTree.printInOrder( output, theTree.root );
			
			output << "\nPre-Order : ";
			theTree.printPreOrder( output, theTree.root );
			
			output << "\nPost-Order: ";
			theTree.printPostOrder( output, theTree.root );
			
			output << "\nLevel-Order: ";
			theTree.printLevelOrder( output, theTree.root );
			
			return output;
			
		}
	
};

#endif