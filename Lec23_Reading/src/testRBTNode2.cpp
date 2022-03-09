#include "../inc/RBTNode2.h"
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
void printUncle( const RBTNode<T>* x ) { 

	if (x == NULL){
		COUT << "Cannot print NULL pointer" << ENDL;
		return; 
	}
	
	// Get the uncle
	RBTNode<T>* uncle = x->uncle();
	
	// If the Uncle is NULL, print NULL 
	if( uncle == NULL ){
		COUT << x->value << " has a NULL Uncle" << ENDL;
		return;
	}
	
	// Otherwise, print the Uncle
	COUT << x->value << "'s uncle is: ";
	printValues( uncle );
	COUT << ENDL;
	
} 

// Create the tress found at the end of Lecture
int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob4.txt" );
		
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
	printUncle( root );
	printUncle( root->left );
	printUncle( root->right );
	printUncle( root->left->left );
	printUncle( root->left->right );
	printUncle( root->left->left->left );
	printUncle( root->left->left->right );
	
	file_out << "Student successfully answered Problem 4 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	return 0;
	
}