#include "../inc/RBTNode1.h"
#include <iostream>
#include <queue>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

template< class T >
void setNode( RBTNode< T >*& theNode, const COLOR color,  RBTNode< T >* parent,  RBTNode< T >* left,  RBTNode< T >* right){
	
	// Set node1
	theNode->parent = parent;
	theNode->color = color;
	theNode->left = left;
	theNode->right = right;	
}

template< class T >
void printValues( const RBTNode<T>* x ){
	
	// Print values 
	COUT << "{" << x->value;
	
	// Print Color 
	if( x->color == RED ){
		COUT << ", Color: RED} ";
	}
	else{
		COUT << ", Color: BLACK} ";
	}
	
}

template< class T >
void inOrder( const RBTNode<T>* x ) { 

	if (x == NULL){
		return; 
	}
	
	// Call left 
	inOrder(x->left); 
	
	// Print values 
	printValues(x);
	
	// Call Right
	inOrder(x->right); 
} 

template< class T >
void preOrder( const RBTNode<T>* x) { 

	if (x == NULL){
		return; 
	}
	
	// Print values 
	printValues(x);
	
	// Call left 
	preOrder(x->left); 
	
	// Call Right
	preOrder(x->right); 
}


template< class T >
void postOrder( const RBTNode<T>* x ) { 

	if (x == NULL){
		return; 
	}
	
	// Call Right
	postOrder(x->right); 
	
	// Call left 
	postOrder(x->left); 
	
	// Print values 
	printValues(x);
	
} 

// Printing Post Order
template< class T >
void levelOrder( const RBTNode< T >* treeRoot ){
	
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
		printValues(currNode);
		
		if( currNode->left != NULL ){
			levelQueue.push( (void *)(currNode->left) );
		}
		
		if( currNode->right != NULL ){
			levelQueue.push( (void *)(currNode->right) );
		}
	}
}

template< class T >
void printResults( RBTNode<T>* root ){
	
	// Print in-order traversal 
	COUT << "In-order traversal: ";
	inOrder( root );
	COUT << ENDL << ENDL;
	
	// Print pre-order traversal 
	COUT << "Pre-order traversal: ";
	preOrder( root );
	COUT << ENDL << ENDL;
	
	// Print post-order traversal 
	COUT << "Post-order traversal: ";
	postOrder( root );
	COUT << ENDL << ENDL;

	// Print leve;-order traversal 
	COUT << "Level-order traversal: ";
	levelOrder( root );
	COUT << ENDL << ENDL;
	
}

// Create the tress found at the end of Lecture 19 - Part 1 - Slide 28
int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob3.txt" );
	
	// Set root node as a pointer to node 1
	RBTNode< int >* root = new RBTNode<int>(15);
	
	// Create a null pointer to pass to functions 
	RBTNode< int >* rbtNULL = NULL;
	
	// Set node1
	setNode( root, BLACK, rbtNULL, new RBTNode<int>(10), new RBTNode<int>(25) );

	// Set node2
	setNode( root->left, RED, root, new RBTNode<int>(4), new RBTNode<int>(12) );

	// Set node3 - Pass null pointers as left and right child
	setNode( root->right, BLACK, root, rbtNULL, rbtNULL );

	// Set node4 
	setNode( root->left->left, BLACK, root->left, new RBTNode<int>(3), new RBTNode<int>(5) );

	// Set node5 - Pass null pointers as left and right child
	setNode( root->left->right, BLACK, root->left, rbtNULL, rbtNULL );

	// Set node6 - Pass null pointers as left and right child
	setNode( root->left->left->left, RED, root->left->left, rbtNULL, rbtNULL );
	
	// Set node7 - Pass null pointers as left and right child
	setNode( root->left->left->right, RED, root->left->left, rbtNULL, rbtNULL );

	// Print the results 
	printResults( root );
	

	file_out << "Student successfully answered Problem 3 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	
}