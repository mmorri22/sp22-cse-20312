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

void insert( bst_node** curr_node, int value ){
	
	// Dr. Morrison's Golden rule of pointers 
	if( *curr_node == NULL ){
		
		// We found the place to insert! Now create the node.
		bst_node* insert_node = (bst_node*)malloc( sizeof(bst_node) );
		insert_node->value = value;
		insert_node->left = NULL;
		insert_node->right = NULL;
		
		// Finally, set the curr_node equal to insert_node
		*curr_node = insert_node;
		
		fprintf( stdout, "In insert, %p %d\n", *curr_node, (*curr_node)->value );
		
	}
}



int main(  ){
	
	// Create the Binary Search Tree 
	bst* int_bst = constructor();
	
	insert( &(int_bst->root), 10 );
	
	fprintf( stdout, "In main %p %d\n", int_bst->root, int_bst->root->value );
	
	destructor( int_bst );
	
	return 0;
}