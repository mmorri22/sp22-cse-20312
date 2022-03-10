#ifndef TREAP_H
#define TREAP_H

#include "TreapNode.h"
#include "queue.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 

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
		
		
		// Modification - Insert method 
		void Insert( TreapNode< T >*& currPtr, const T& value, const double priority ){
			
			/******** Part 1 - Insert like a Normal BST **************/
			
			// If the pointer is Null, we found our location 
			// Set the pointer to the new value
			if( currPtr == NULL ){
				
				currPtr = new TreapNode< T >(value, priority);
				return;
			}
			
			// If value is less than current data, recurse left
			else if( value < currPtr->data ){
				Insert( currPtr->left, value, priority );
			}
			
			// If value is greater than current data, recurse right
			else if( value > currPtr->data ){
				Insert( currPtr->right, value, priority );
			}
			else{
				// Found a duplicate - Do nothing;
			}

			/******** Part 2 - Recursively Fix Order like a Max Heap **************/
			
			// Check left - If the left child is not NULL and has a higher priority 
			if( currPtr->left != NULL && value == currPtr->left->data ){
				// Check left - If the left child is not NULL and has a higher priority 
				if( currPtr->left->priority > currPtr->priority ){
					
					// Create temp pointers to the two nodes 
					TreapNode<T>* tempPar = currPtr;
					TreapNode<T>* tempLeft = currPtr->left;
					
					// Rotate right 
					tempPar->left = tempLeft->right;
					tempLeft->right = tempPar;
					currPtr = tempLeft;
				}
			}
			
			// Check right - If the right child is not NULL and has a higher priority 
			else if( currPtr->right != NULL && value == currPtr->right->data ){
				
				// If the right child has a higher priority 
				if( currPtr->right->priority > currPtr->priority ){
					
					// Create temp pointers to the two nodes 
					TreapNode<T>* tempPar = currPtr;
					TreapNode<T>* tempRight = currPtr->right;
					
					// Rotate right 
					tempPar->right = tempRight->left;
					tempRight->left = tempPar;
					currPtr = tempRight;
				}
			}
			
		}
		
		// Printing In Order 
		void printInOrder( std::ostream& output, const TreapNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Recursively call the left child 
			printInOrder( output, currNode->left );
			
			output << "{" << currNode->data << ", " << currNode->priority << "} ";
			
			// Recursively call the right child 
			printInOrder( output, currNode->right );
			
		}
		
		// Printing Pre Order 
		void printPreOrder( std::ostream& output, const TreapNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Print the middle node first
			output << "{" << currNode->data << ", " << currNode->priority << "} ";
			
			// Recursively call the left child 
			printPreOrder( output, currNode->left );
			
			// Recursively call the right child 
			printPreOrder( output, currNode->right );
			
		}
		
		
		// Printing Post Order 
		void printPostOrder( std::ostream& output, const TreapNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Recursively call the left child 
			printPostOrder( output, currNode->right );
			
			// Recursively call the right child 
			printPostOrder( output, currNode->left );
			
			// Print the middle node last
			output << "{" << currNode->data << ", " << currNode->priority << "} ";
		}
		
		// Printing Post Order 
		void printLevelOrder( std::ostream& output, const TreapNode< T >* treeRoot ) const{
			
			// Return if currNode is null 
			if( treeRoot == NULL ){
				return;
			}
			
			// Create a queue of void pointers
			queue< void * > levelQueue;

			// Cast the treeRoot to void * and push onto the queue
			levelQueue.push( (void *)treeRoot );
			
			// Just like BFS, iterate until the queue is empty
			while( !levelQueue.empty() ){
				
				// Take the address from the front of the queue and 
				// cast to a TreapNode<T>* and set to a temp value currNode
				TreapNode< T >* currNode = ( TreapNode< T >* )levelQueue.front();
				
				// Remove the element from the front of the queue
				levelQueue.pop();
				
				// Print the value to the user
				output << "{" << currNode->data << ", " << currNode->priority << "} ";
				
				if( currNode->left != NULL ){
					levelQueue.push( (void *)(currNode->left) );
				}
				
				if( currNode->right != NULL ){
					levelQueue.push( (void *)(currNode->right) );
				}
				
			}
			
		}
		
		// Private method - Find the minimum element
		TreapNode<T>* findMin( TreapNode<T>* currPtr ) const {
			
			// If the pointer is null, return NULL
			if( currPtr == NULL ){
				return currPtr;
			}
			
			// If there is no way to go left, return currPtr 
			if( currPtr->left == NULL ){
				return currPtr;
			}
			
			// Otherwise, keep going left 
			return findMin( currPtr->left );
		}
		
		
		// Private method - Find the minimum element
		TreapNode<T>* findMax( TreapNode<T>* currPtr ) const {
			
			// If the pointer is null, return NULL
			if( currPtr == NULL ){
				return currPtr;
			}
			
			// If there is no way to go right, return currPtr 
			if( currPtr->right == NULL ){
				return currPtr;
			}
			
			// Otherwise, keep going right 
			return findMax( currPtr->right );
		}
		
		// Private method - Find and delete the element
		bool remove( TreapNode<T>*& currPtr, const T& element ){

			/******** Part 1 - Delete like a Normal BST **************/
			/******** Except set a bool to track so we go to Part 2 for recursive trickle **************/

			bool nodeDeleted = false;
			
			// If we hit NULL, element is not in the tree
			if( currPtr == NULL ){
				return false;
			}

			// Otherwise, check left if the element is less than the data
			if( element < currPtr->data ){
				nodeDeleted = remove( currPtr->left, element );
			}
			
			// Otherwise, check right if the element is greater than the data			
			else if( element > currPtr->data ) {
				nodeDeleted = remove( currPtr->right, element );
			}
			
			// If the parent has two children
			else if( currPtr->left != NULL && currPtr->right != NULL ){
				
				// Set the currNode's data to the min's value 
				// Pass currPtr->right to get the minimum to the right
				currPtr->data = findMin( currPtr->right )->data;
				
				// Now we have a duplicate value
				// so recursively delete the duplicate
				return remove( currPtr->right, currPtr->data );
			}
			
			// If there is only one child 
			else{
				
				// Create a temp Node pointer, just like in Linked Lists 
				// Make it point to the currPtr
				TreapNode<T>* temp = currPtr; 
				
				// Set the currPtr to the non NULL child
				currPtr = ( currPtr->left != NULL ) ? currPtr->left : currPtr->right;
				
				// Delete temp
				delete temp;
				
				nodeDeleted = true;
				
			}
			
			/******** Part 2 - Rotate down **************/
			
			// If both children are NULL, or we didn't delete anything, just return
			if( currPtr == NULL || ( currPtr->left == NULL && currPtr->right == NULL ) || !nodeDeleted ){
			
				return nodeDeleted;
				
			}
			
			// Check Right 
			trickleDownRight( currPtr );
			trickleDownLeft( currPtr );
			
			// If we got here, we had to have deleted
			return true;
		}
		
		void trickleDownRight(TreapNode<T>*& parent)
		{
			// If the node is NULL, just return to prevent seg fault
			if( parent == NULL ){
				return;
			}
			
			// Create nodes to the parent and the right child
			TreapNode<T>* tempPar = parent;
			TreapNode<T>* tempRight = parent->right;
			
			// If right isn't null and the right child has a higher priority
			if( tempRight != NULL && tempRight->priority > tempPar->priority ){
				
				// Rotate Left 
				tempPar->right = tempRight->left;
				tempRight->left = tempPar;
				
				// Reset called by reference parent to temp right
				parent = tempRight;
				
				// The node we are testing is now parent->left, so check trickle
				trickleDownRight( parent->left );
				trickleDownLeft( parent->left );
			}
		}

		void trickleDownLeft(TreapNode<T>*& parent)
		{
			// If the node is NULL, just return to prevent seg fault
			if( parent == NULL ){
				return;
			}
			
			// Create nodes to the parent and the left child
			TreapNode<T>* tempPar = parent;
			TreapNode<T>* tempLeft = parent->left;
			
			// If left isn't null and the left child has a higher priority
			if( tempLeft != NULL && tempLeft->priority > tempPar->priority ){
				
				// Rotate Right 
				tempPar->left = tempLeft->left;
				tempLeft->left = tempPar;
				
				// Reset called by reference parent to temp left
				parent = tempLeft;

				// Check Right and Left to continue to trickle down				
				trickleDownRight( parent->right );
				trickleDownLeft( parent->right );
			}
		}
		
		// Private Recursive Method to find the Max Height
		unsigned int maxHeight( TreapNode<T>* currPtr ){
			
			// Return 0 if there is a NULL ptr
			if( currPtr == NULL ){
				return 0;
			}
			
			// Find the max height of the left and right subtrees
			unsigned int maxHeightLeft = maxHeight( currPtr->left );
			unsigned int maxHeightRight = maxHeight( currPtr->right );
			
			// Return 1 + the maximum of maxHeightLeft and maxHeightRight
			return 1 + ( ( maxHeightLeft >= maxHeightRight ) ? maxHeightLeft : maxHeightRight );
			
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

		// Insertion with value and priority
		void Insert( const T& value ){
			
			// Seed the Random Number Generator
		
			double priority = rand() % 100;
			
			Insert( root, value, priority );
			
		}
		
		bool remove( const T& element ){
			
			// Call the private recursive method
			return remove( root, element );
			
		}
		
		// Public maxHeight method
		unsigned int maxHeight(){
			
			return maxHeight( root );
			
		}
		
		// Print the InOrder and Pre-Order Traversal 
		friend std::ostream& operator<<( std::ostream& output, const Treap<T>& theTree ){
			
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