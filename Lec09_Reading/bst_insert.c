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
				
	}
	
	// Recurse Left
	// curr_node is the current pointer 
	// *curr_node is the de-referenced pointer 
	// (*curr_node)->left is the address of the left child
	// Just like fscanf, we need to pass by reference using &((*curr_node)->left)
	else if( value < (*curr_node)->value )
		insert( &((*curr_node)->left), value );
	
	// Recurse Right 
	else if( value > (*curr_node)->value )
		insert( &((*curr_node)->right), value );
	
	// Duplicate Element
	else{
		
		fprintf( stdout, "%d is already in the tree\n", value );
	}
	
	
}



int main( const int argc, const char* argv[] ){
	
	// Create the Binary Search Tree 
	bst* int_bst = constructor();
	
	int iter;
	for( iter = 1; iter < argc; ++iter ){
	
		int input_value = atoi( argv[iter] );
		
		insert( &(int_bst->root), input_value );
		
	}
		
	destructor( int_bst );
	
	return 0;
}