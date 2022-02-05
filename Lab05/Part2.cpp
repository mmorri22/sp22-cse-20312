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


void insert( bst_node** curr_node, int value ){
	
	// Dr. Morrison's Golden rule of pointers 
	if( *curr_node == NULL ){
		
		// We found the place to insert! Now create the node.
		bst_node* insert_node = (bst_node*)malloc( sizeof(bst_node) );
		insert_node->value = value;
		insert_node->left = NULL;
		
		// Guess what, the error is here!
		insert_node->right = insert_node;
		
		// Finally, set the curr_node equal to insert_node
		*curr_node = insert_node;
	
		return;
	
	}
	
	else if( value < (*curr_node)->value )
		insert( &((*curr_node)->left), value );
	
	else if( (*curr_node)->value < value )
		insert( &((*curr_node)->right), value );
	
	else
		fprintf( stdout, "%d is already in the tree\n", value );
}


void in_order_traversal( bst_node* curr_node ){
	
	if( curr_node == NULL )
		return;
	
	in_order_traversal( curr_node->left );
	
	fprintf( stdout, "%d ", curr_node->value );
	
	in_order_traversal( curr_node->right );
	
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

void destructor( bst_node* curr_node ){
	
	if( curr_node == NULL )
		return;
	
	destructor( curr_node->left );
	
	destructor( curr_node->right );
	
	free( curr_node );
	
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
		
		insert( &(int_bst->root), input_value );
		
	}
	
	// Print outputs
	fprintf( stdout, "In-order traversal  : " );
	in_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );
	
	fprintf( stdout, "Pre-order traversal : " );
	pre_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );

	fprintf( stdout, "Post-order traversal: " );
	post_order_traversal( int_bst->root );
	fprintf( stdout, "\n" );
	
	// Call the destructor on the root 
	destructor( int_bst->root );
	
	// Free the Binary Search Tree pointer 
	free( int_bst );
	
	return 0;
	
}