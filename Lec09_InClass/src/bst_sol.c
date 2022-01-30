#include "../include/bst_sol.h"

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
		insert_node->right = NULL;
		
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

void find_kth_element( bst_node* curr_node, int kth, int* curr_val, int* solution ){
	
	if( curr_node == NULL )
		return;	

	// Traverse Right
	find_kth_element( curr_node->right, kth, curr_val, solution );
	
	// At this current node, increment curr_val
	++(*curr_val);
	
	// If kth equals curr_val, then set the solution to the node's value
	if( kth == *curr_val )
		*solution = curr_node->value;
	
	// Traverse Left
	find_kth_element( curr_node->left, kth, curr_val, solution  );
	
}

long unsigned int maximum_depth( bst_node* curr_node ){
	
	if( curr_node == NULL )
		return 0;
	
	// Rest of logic goes here
	long unsigned int left = maximum_depth( curr_node->left );
	
	long unsigned int right = maximum_depth( curr_node->right );
	
	if( left > right )
		return left + 1;
	
	return right + 1;
	
}


void reverse_tree( bst_node** curr_node ){
	
	if( *curr_node == NULL )
		return;	
	
	reverse_tree( &((*curr_node)->left) );
	
	reverse_tree( &((*curr_node)->right) );
	
	bst_node* temp = (*curr_node)->left;
	
	(*curr_node)->left = (*curr_node)->right;
	
	(*curr_node)->right = temp;
}


int queue_is_empty( queue* the_queue ){
	
	if( the_queue->head_node == NULL && the_queue->tail_node == NULL )
		return 1;
	
	return 0;
}

// Step 10 - Free all the elements
void queue_destructor( queue_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr == NULL )
		return;


	// Recursively call queue_destructor on the next node
	queue_destructor( curr_ptr->next_node );

	// Free the current pointer
	free( curr_ptr );

}

bst_node* front( queue* the_queue ){
	
	return the_queue->head_node->data;
	
}

queue* queue_constructor(){
	
	queue* the_queue = (queue *)malloc( sizeof( queue ) );

	the_queue->head_node = NULL;
	the_queue->tail_node = NULL;	
	
	return the_queue;
	
}


// Step 13 - Push Front
void push_back( queue* the_queue, bst_node* the_value ){

	// 13 - 1 We can copy everything up through the empty head node from Insert

	// Create a queue_node pointer called insert_node
	queue_node* insert_node = (queue_node*)malloc( sizeof(queue_node) );

	// Set the insert_node's data to the_value and next_node to NULL
	insert_node->data = the_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the list is empty
	if( the_queue->tail_node == NULL ){

		// Set the head node equal to insert_node
		the_queue->head_node = insert_node;
		the_queue->tail_node = insert_node;

		// And return
		return;
	}

	// 13-2 Now we just need to use a reference pointer and put them in front
	queue_node* reference = the_queue->tail_node;

	// Set the head_node to the new node
	the_queue->tail_node = insert_node;

	// Set the new head_node's next to the reference
	the_queue->tail_node->prev_node = reference;
	reference->next_node = the_queue->tail_node;

}

void pop_front( queue* the_queue ){

	// Check if the list is not empty
	if( the_queue->head_node == NULL )
		return;

	else if( the_queue->head_node == the_queue->tail_node ){

		free( the_queue->head_node );

		the_queue->head_node = NULL;
		the_queue->tail_node = NULL;

		return;
	}

	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	queue_node* reference = the_queue->head_node;

	// Set the head_node to head_node's next_node;
	the_queue->head_node = reference->next_node;
	the_queue->head_node->prev_node = NULL;


	// Free the reference
	free( reference );

}

void level_order_traversal( bst* int_bst, queue* level_queue ){
	
	if( int_bst->root == NULL )
		return;
	
	push_back( level_queue, int_bst->root );
	
	while( queue_is_empty( level_queue ) == 0 ){
		
		bst_node* curr_node = front( level_queue );
		
		pop_front( level_queue );
		
		fprintf( stdout, "%d ", curr_node->value );
		
		if( curr_node->left != NULL )
			push_back( level_queue, curr_node->left );


		if( curr_node->right != NULL )
			push_back( level_queue, curr_node->right );		
	}
	
	fprintf(stdout, "\n" );
}
