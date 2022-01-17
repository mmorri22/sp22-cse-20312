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

void constructor( bst* int_bst ){
	
	// Set the root to NULL
	int_bst->root = NULL;
	
}


void destructor( bst* int_bst ){
	
	if( int_bst->root == NULL )
		return;
	
}

/* Note: Deliberate logical error in function declaration */
void insert( bst_node* curr_node, int value ){
	

}


void in_order_traversal( bst_node* curr_node ){
	

	
}


void pre_order_traversal( bst_node* curr_node ){
	
	if( curr_node == NULL )
		return;
	
	fprintf( stdout, "%d ", curr_node->value );
	
	pre_order_traversal( curr_node->left );
	
	pre_order_traversal( curr_node->right );
	
}


void post_order_traversal( bst_node* curr_node ){
	
	if( curr_node == NULL )
		return;
	
	post_order_traversal( curr_node->left );
	
	post_order_traversal( curr_node->right );
	
	fprintf( stdout, "%d ", curr_node->value );
	
}


int main( const int argc, const char* argv[] ){
	
	if( argc < 2 ){
		
		fprintf( stderr, "Needs more than one input.\n" );
		
		return EXIT_FAILURE;
	}
	
	// Create the Binary Search Tree 
	bst* int_bst = (bst*)malloc( sizeof(bst) );
	
	constructor( int_bst );
	
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int input_value = atoi( argv[iter] );
		
		insert( int_bst->root, input_value );
		
	}
	
	// Print outputs
	/* 
	fprintf( stdout, "In-order traversal  : " );
	in_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );
	
	fprintf( stdout, "Pre-order traversal : " );
	pre_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );

	fprintf( stdout, "Post-order traversal: " );
	post_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );
	*/
	
	
	// Free the Binary Search Tree pointer 
	free( int_bst );
	
	return 0;
	
}