// Initialize the Red-Black Tree
#ifndef RBTREE2_H
#define RBTREE2_H 

#include "RBTNode.h"
#include <queue>		// Level Order Traversal only
#include <iostream>

template<class T> 
class RBTree { 

	private:

		// Red-Black Tree root node 
		RBTNode<T> *root; 
		
		// Return a pointer to either the location or where the node should be
		RBTNode<T>* search(const T& searchVal) { 
		
			// Set temp to the root node
			RBTNode<T> *temp = root; 
			
			// While temp is NULL
			while (temp != NULL) { 
			
				// If the input value is less than the temp Value
				if (searchVal < temp->value) { 
				
					// Break the loop if we have found the smallest element
					if (temp->left == NULL) 
						break; 
					
					// Otherwise, set the temp to the left child
					else
						temp = temp->left; 
				} 
				
				// If the input value is equal to the value				
				else if (searchVal == temp->value) { 
					break; 
				} 
				else { 
					// Break the loop if we have found the largest element
					if (temp->right == NULL) 
						break; 
					// Otherwise, set the temp to the right child					
					else
						temp = temp->right; 
				} 
			} 
			
			// Retrn the pointer to the result
			return temp; 
		} 
		
		/* Problem 5 Starts Here */
		// Rotate left about node x
		void leftRotate(RBTNode<T>*& x) { 
		
			// new parent will be node's right child 
			RBTNode<T> *nParent = x->right; 
			
			// update root if current node is root 
			if (x == root) 
				root = nParent; 
			
			// Move down nParent
			x->moveDown(nParent); 
			
			// connect x with new parent's left element 
			x->right = nParent->left; 
			
			// connect new parent's left element with node 
			// if it is not null 
			if (nParent->left != NULL) 
				nParent->left->parent = x; 
			
			// connect new parent with x 
			nParent->left = x; 
		} 
		
		// Rotate right about the x node
		void rightRotate(RBTNode<T>*& x) { 
		
			// new parent will be node's left child 
			RBTNode<T> *nParent = x->left; 
			
			// update root if current node is root 
			if (x == root) 
				root = nParent; 
			
			// Move down the new Parent
			x->moveDown(nParent); 
			
			// connect x with new parent's right element 
			x->left = nParent->right; 
			
			// connect new parent's right element with node 
			// if it is not null 
			if (nParent->right != NULL) 
				nParent->right->parent = x; 
			
			// connect new parent with x 
			nParent->right = x; 
		}

		// Swap the colors of two RBTree Nodes
		void swapColors(RBTNode<T>*& x1, RBTNode<T>*& x2) {
			
			COLOR temp; 
			temp = x1->color; 
			x1->color = x2->color; 
			x2->color = temp; 
			
		} 
		
		// Swap Values of two nodes
		void swapValues(RBTNode<T>*& u, RBTNode<T>*& v) { 
		
			T temp; 
			temp = u->value; 
			u->value = v->value; 
			v->value = temp; 
			
		} 
		
		// Fix the scenario where a node and a parent are both red
		void fixRedRed(RBTNode<T>*& x) { 
		
			// if x is root color it black and return 
			if (x == root) { 
				x->color = BLACK; 
				return; 
			} 
			
			// initialize parent, grandparent, uncle 
			RBTNode<T>* parent = x->parent;
			RBTNode<T>* grandparent = parent->parent; 
			RBTNode<T>* uncle = x->uncle(); 
			
			// If the parent's color is BLACK - Cases 2 and 3
			if (parent->color != BLACK) { 
			
				// If the UNCLE not NULL and color is RED
				if (uncle != NULL && uncle->color == RED) {
					
					// Swap the Colors
					parent->color = BLACK; 
					uncle->color = BLACK; 
					grandparent->color = RED; 
					
					// Recursively call fixRedRed on he grandparent
					fixRedRed(grandparent); 
				} 
				
				// Else case means Uncle is a Black Node
				else { 
				
					// Else perform LR, LL, RL, RR 
					if (parent->isOnLeft()) { 
						if (x->isOnLeft()) { 
							// for left right 
							swapColors(parent, grandparent); 
						} 
						else { 
							leftRotate(parent); 
							swapColors(x, grandparent); 
						} 
						// for left left and left right 
						rightRotate(grandparent); 
					} 
					
					// Parent is a right child
					else { 
						if (x->isOnLeft()) { 
							// for right left 
							rightRotate(parent); 
							swapColors(x, grandparent); 
						} 
						else { 
							swapColors(parent, grandparent); 
						} 
				
						// for right right and right left 
						leftRotate(grandparent); 
					} 
				} 
			} 
		} 
		
		// Private method for a copy
		void copyTree( RBTNode<T>*& destin, RBTNode<T>* origin ){
			
			// Return if NULL
			if( origin == NULL ){
				destin = NULL;
				return;
			}
			
			// Use pre-order traversal to copy
			destin = new RBTNode<T>( origin->value );
			destin->color = origin->color;
			
			//destin = temp;
			copyTree( destin->left, origin->left );
			copyTree( destin->right, origin->right );
			
			// Update the Parents of the nodes
			if( destin->left != NULL ){
				destin->left->parent = destin;
			}
			
			if( destin->right != NULL ){
				destin->right->parent = destin;
			}

		}
		
		// Use Post-Order Traversal to Clean Up tree
		void deleteTree( RBTNode<T>*& currPtr ){
			
			if( currPtr == NULL ){
				return;
			}
			
			// Delete right subtree
			deleteTree( currPtr->right );
			
			// Delete left subtree
			deleteTree( currPtr->left );
			
			// Delete the current pointer
			delete currPtr;
		}

		// Print the value
		void printValues( const RBTNode<T>* x, std::ostream& output ) const{
			
			// Print values 
			output << "{" << x->value;
			
			// Print Color 
			if( x->color == RED ){
				output << ", Color: RED} ";
			}
			else{
				output << ", Color: BLACK} ";
			}
			
		}

		// Print the In Order Traversal
		void inOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Call left 
			inOrder(x->left, output); 
			
			// Print values 
			printValues(x, output);
			
			// Call Right
			inOrder(x->right, output); 
		} 

		// Print the Pre Order Traversal
		void preOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Print values 
			printValues(x, output);
			
			// Call left 
			preOrder(x->left, output); 
			
			// Call Right
			preOrder(x->right, output); 
		}

		// Print the post order traversal
		void postOrder( const RBTNode<T>* x, std::ostream& output ) const{ 

			if (x == NULL){
				return; 
			}
			
			// Call Right
			postOrder(x->right, output); 
			
			// Call left 
			postOrder(x->left, output); 
			
			// Print values 
			printValues(x, output);
			
		} 

		// Printing Post Order
		void levelOrder( const RBTNode< T >* treeRoot, std::ostream& output ) const{
			
			// Return if currNode is null 
			if( treeRoot == NULL ){
				return;
			}
			
			// Create a queue of void pointers
			std::queue< void * > levelQueue;

			// Cast the treeRoot to void * and push onto the queue
			levelQueue.push( (void *)treeRoot );
			
			// Just like BFS, iterate until the queue is empty
			while( !levelQueue.empty() ){
				
				// Take the address from the front of the queue and 
				// cast to a RBTNode<T>* and set to a temp value currNode
				RBTNode< T >* currNode = ( RBTNode< T >* )levelQueue.front();
				
				// Remove the element from the front of the queue
				levelQueue.pop();
				
				// Print values 
				printValues(currNode, output);
				
				if( currNode->left != NULL ){
					levelQueue.push( (void *)(currNode->left) );
				}
				
				if( currNode->right != NULL ){
					levelQueue.push( (void *)(currNode->right) );
				}
			}
		}			
		
	public: 
		
		// Default Constructor
		RBTree() : root(NULL) { } 
		
		// Destructor
		~RBTree() {
			
			delete root;
		} 
		
		// Copy Constructor
		RBTree( const RBTree<T>& copy ) : root( NULL ){
			
			copyTree( root, copy.root );
			
		}
		
		// Assignment Operator
		RBTree<T>& operator=( const RBTree<T>& rhs ){
			
			if( this != &rhs ){
				this->root = new RBTNode<T>( rhs.root->value );
				copyTree( this->root, rhs.root );
			}
			return *this;
		}
		
		// Insert a value
		void insert(const T& insertVal) { 
		
			// Create a new node with the value
			RBTNode<T> *newNode = new RBTNode<T>(insertVal); 
			
			// If the root is null, inset at the root
			if (root == NULL) { 
				newNode->color = BLACK; 
				root = newNode; 
			} 
			
			// Otherwise, find the location where the node should be
			else { 
				
				// Get the location where we need to put the value
				RBTNode<T> *temp = search(insertVal); 
			
				// return if value already exists
				if (temp->value == insertVal) { return; } 
			
				// if value is not found, search returns the node 
				// where the value is to be inserted 
				// connect new node to correct node 
				newNode->parent = temp; 
			
				// If the value to insert is less than the temp's value
				if (insertVal < temp->value) 
					// Make it temp's left child
					temp->left = newNode; 
				
				// Otherwise, make it temp's right child
				else
					temp->right = newNode; 
			
				// Check if the insertion created a  
				fixRedRed(newNode); 
			} 
		} 

		// Friend Method to Print the Tree 
		friend std::ostream& operator<<( std::ostream& output, const RBTree<T>& printTree ){
			
			// Print in-order traversal 
			output << "In-order traversal: ";
			printTree.inOrder( printTree.root, output );
			output << std::endl << std::endl;
			
			// Print pre-order traversal 
			output << "Pre-order traversal: ";
			printTree.preOrder( printTree.root, output );
			output << std::endl << std::endl;
			
			// Print post-order traversal 
			output << "Post-order traversal: ";
			printTree.postOrder( printTree.root,output );
			output << std::endl << std::endl;

			// Print leve;-order traversal 
			output << "Level-order traversal: ";
			printTree.levelOrder( printTree.root, output );
			output << std::endl << std::endl;			
			
			return output;
		}

};

#endif
