#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node{
	int value;
	struct bst_node* left;
	struct bst_node* right;
} bst_node;


typedef struct bst{
	struct bst_node* root;
} bst;

bst* constructor(  ){
	
	// Allocate the memory
	bst* temp_bst = (bst*)malloc( sizeof(bst) );
	
	// Set the root pointer equal to NULL
	temp_bst->root = NULL;
	
	return temp_bst;
}

void destructor( bst* int_bst ){
	
	if( int_bst != NULL ){
		
		// Free the BST root pointer
		free( int_bst );
	}	
}

int main(  ){
	
	// Create the Binary Search Tree 
	bst* int_bst = constructor();
	
	destructor( int_bst );
	
	return 0;
}