#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "queue.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

template< class T >
class BST{
	
	protected:
	
		// Private Insert Method
		void Insert( BSTNode< T >*& currPtr, const T& value ){
			
			// If the pointer is Null, we found our location 
			// Set the pointer to the new value
			if( currPtr == NULL ){
				
				currPtr = new BSTNode< T >(value);
				return;
			}
			
			// If value is less than current data, recurse left
			else if( value < currPtr->data ){
				Insert( currPtr->left, value );
			}
			
			// If value is greater than current data, recurse right
			else if( value > currPtr->data ){
				Insert( currPtr->right, value );
			}
			else{
				// Print that we found a duplicate
				std::cout << value << " is a duplicate " << std::endl;
			}			
			
		}
		
		// Copy Tree - Uses Pre-Order Traversal
		void copyTree(BSTNode< T >* originNode, BSTNode< T >*& destinNode){
			
			// Make the middle node
			destinNode = new BSTNode< T >( originNode->data );
			
			// Recursively go left 
			if( originNode->left != NULL ){
				copyTree(originNode->left, destinNode->left);
			}
			
			// Recursively go right
			if( originNode->right != NULL ){
				copyTree(originNode->right, destinNode->right);
			}
		}
		
		// Printing In Order 
		void printInOrder( std::ostream& output, const BSTNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Recursively call the left child 
			printInOrder( output, currNode->left );
			
			output << currNode->data << " ";
			
			// Recursively call the right child 
			printInOrder( output, currNode->right );
			
		}
		
		// Printing Pre Order 
		void printPreOrder( std::ostream& output, const BSTNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Print the middle node first
			output << currNode->data << " ";
			
			// Recursively call the left child 
			printPreOrder( output, currNode->left );
			
			// Recursively call the right child 
			printPreOrder( output, currNode->right );
			
		}
		
		
		// Printing Post Order 
		void printPostOrder( std::ostream& output, const BSTNode< T >* currNode ) const{
			
			// Return if currNode is null 
			if( currNode == NULL ){
				return;
			}
			
			// Recursively call the left child 
			printPostOrder( output, currNode->right );
			
			// Recursively call the right child 
			printPostOrder( output, currNode->left );
			
			// Print the middle node first
			output << currNode->data << " ";			
		}
		
		// Printing Post Order 
		void printLevelOrder( std::ostream& output, const BSTNode< T >* treeRoot ) const{
			
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
				// cast to a BSTNode<T>* and set to a temp value currNode
				BSTNode< T >* currNode = ( BSTNode< T >* )levelQueue.front();
				
				// Remove the element from the front of the queue
				levelQueue.pop();
				
				// Print the value to the user
				output << currNode->data << " ";
				
				if( currNode->left != NULL ){
					levelQueue.push( (void *)(currNode->left) );
				}
				
				if( currNode->right != NULL ){
					levelQueue.push( (void *)(currNode->right) );
				}
				
			}
			
		}
		
		// Delete the pointers using post-order traversal
		void deleteNode( BSTNode<T>*& currPtr ){
			
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
		
		// Private contains method 
		bool contains( BSTNode<T>* currPtr, const T& element ) const{
			
			// If the node is NULL, return false
			if( currPtr == NULL ){
				return false;
			}
			
			// If the node's data is equal to the element, return true
			if( currPtr->data == element ){
				return true;
			}
			
			// Otherwise, check left is the element is less than the data
			else if( element < currPtr->data ){
				return contains( currPtr->left, element );
			}
			
			// Otherwise, check left is the element is less than the data			
			else{
				return contains( currPtr->right, element );
			}
			
		}
		
		// Private method - Find the minimum element
		BSTNode<T>* findMin( BSTNode<T>* currPtr ) const {
			
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
		BSTNode<T>* findMax( BSTNode<T>* currPtr ) const {
			
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
		
		// Public method - Find and delete the element
		bool remove( BSTNode<T>*& currPtr, const T& element ){
			
			// If we hit NULL, element is not in the tree
			if( currPtr == NULL ){
				return false;
			}

			// Otherwise, check left if the element is less than the data
			if( element < currPtr->data ){
				return remove( currPtr->left, element );
			}
			
			// Otherwise, check right if the element is greater than the data			
			else if( element > currPtr->data ) {
				return remove( currPtr->right, element );
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
				BSTNode<T>* temp = currPtr; 
				
				// Set the currPtr to the non NULL child
				currPtr = ( currPtr->left != NULL ) ? currPtr->left : currPtr->right;
				
				// Delete temp
				delete temp;
				
				return true;
				
			}
			
		}
		
		// Private Recursive Method to find the Max Height
		unsigned int maxHeight( BSTNode<T>* currPtr ){
			
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
		BSTNode< T >* root;
		
	public: 
		
		BST() : root() {}
		
		virtual ~BST() { 
		
			// Recursively delete the pointers
			deleteNode( root ); 
		}
		
		// Public Insert Method
		virtual void Insert( const T& value ){
			
			Insert( root, value );
		}
		
		// Copy constructor
		BST(const BST<T>& copy) : root(NULL) {
			// If assign.root is NULL, assign is an empty tree
			if( copy.root == NULL ){
				return;
			}
			
			// Set the root to the new data
			root = new BSTNode< T >( copy.root->data );
			
			// Set the root to the new data
			copyTree(copy.root, root);
		}
		
		// Assignment operator
		BST<T>& operator=(const BST<T>& assign){
			
			if( this != &assign ){
				// If assign.root is NULL, assign is an empty tree
				if( assign.root == NULL ){
					return *this;
				}
				
				// Set the root to the new data
				root = new BSTNode< T >( assign.root->data );
				
				// Set the root to the new data
				copyTree(assign.root, root);
			}
			
			return *this;	// Return de-referenced class ptr
		}
		
		// Public Contains Method
		bool contains( const T& element ) const {
			
			return contains( root, element );
			
		}
		
		T returnRootVal(){
			
			return root->data;
			
		}
		
		// Public findMin method
		BSTNode<T>* findMin(){
			
			return findMin( root );
			
		}
		
		// Public findMax method
		BSTNode<T>* findMax(){
			
			return findMax( root );
			
		}
		
		// Public remove method
		virtual bool remove( const T& element ){
			
			contains( element );
			
			// Call the private recursive method
			return remove( root, element );
			
		}
		
		// Public Method 
		unsigned int maxHeight() {
			
			// Pass the root to the private recursive method
			return maxHeight( root );
			
		}
		
		void printPreOrder( std::ostream& output ) const{
			
			printPreOrder( output, root );
			
		}

		void printLevelOrder( std::ostream& output ) const{
			
			printLevelOrder( output, root );
			
		}
		
		void printInOrder( std::ostream& output ) const{
			
			printInOrder( output, root );
			
		}
		
		void printPostOrder( std::ostream& output ) const{
			
			printPostOrder( output, root );
			
		}
		
		// Print the InOrder and Pre-Order Traversal 
		friend std::ostream& operator<<( std::ostream& output, const BST<T>& theTree ){
			
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