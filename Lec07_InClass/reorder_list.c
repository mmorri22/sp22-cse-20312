#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;

}sll_node;

// Step 3 - Create the struct for sllist
typedef struct sllist{

	// Make the private sll_node member called head_node
	struct sll_node* head_node;

}sllist;


// Step 6 - Create the constructor method for sllist
void insert( sllist* the_list, int the_value ){

	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );

	// Set the insert_node's data to the_value and next_node to NULL
	insert_node->data = the_value;
	insert_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the list is empty
	if( the_list->head_node == NULL ){

		// Set the head node equal to insert_node
		the_list->head_node = insert_node;

		// And return
		return;
	}

	// Otherwise, create a curr_ptr equal to the head_node
	sll_node* curr_ptr = the_list->head_node;

	// Iterate until the next_node is NULL
	while( curr_ptr->next_node != NULL ){

		curr_ptr = curr_ptr->next_node;
	}

	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next_node = insert_node;

}

// Step 8 - Print the Singly Linked List
void print_list( sll_node* head_node ){

	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){

		fprintf( stdout, "Node Base Address: %p, ", curr_ptr );
		fprintf( stdout, "Data Value: %d\n", curr_ptr->data );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}


// Step 10 - Free all the elements
void destructor( sll_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr == NULL )
		return;


	// Recursively call destructor on the next node
	destructor( curr_ptr->next_node );

	// Free the current pointer
	free( curr_ptr );

}

int reorder_recurse( sll_node** left_ptr , sll_node* right_ptr ){
	
	// Update to 1 if we reached the end
	int reached_end = 0;
	
	// First, recurse to the end of the Singly Linked List
	if( right_ptr->next_node != NULL ){
		
		reached_end = reorder_recurse( left_ptr, right_ptr->next_node );
	}
	
	// If we haven't reached the middle and performed the last swaps
	if( reached_end == 0 ){ 
	
		// Create the temp 
		sll_node* left_next = (*left_ptr)->next_node;
		
		// Reached the termination 
		if( right_ptr == *left_ptr || right_ptr == left_next ){
						
			// De-reference the right node's pointer and update the next node to NULL
			right_ptr->next_node = NULL;
			
			// Return 1 so we don't unintentionally swap those previous links again
			return 1;
			
		}
		else{

			// De-reference and update the right node's next pointer
			right_ptr->next_node = (*left_ptr)->next_node;
			
			sll_node* temp_head_head = (*left_ptr)->next_node;

			// De-reference and update the left node's next pointer
			(*left_ptr)->next_node = right_ptr;
			
			// Update where the previous left node's next node was
			(*left_ptr) = temp_head_head;
			
			return 0;
		}
	}

	// Otherwise, we already encountered terminal case
	return 1;

}

void reorder_call( sll_node* head_node ){
	
	// Either the list is empty or the list has one node 
	if( head_node == NULL || head_node->next_node == NULL )
		return;
	
	sll_node* left_ptr = head_node;
	sll_node* right_ptr = head_node;
	
	// Pass left pointer by reference, and right pointer by value
	reorder_recurse( &left_ptr, right_ptr );
	
}


int main( const int argc, const char* argv[] ){

	fprintf( stdout, "argc: %p %d\n", &argc, argc );
	fprintf( stdout, "argv: %p %p\n", &argv, argv );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d]: %p %p %s\n", iter, &argv[iter], argv[iter], argv[iter] );
	}

	fprintf( stdout, "\n\n" );
	
	// Step 4 - Dynamically allocate a sllist
	sllist* the_list = (sllist *)malloc( sizeof( sllist ) );

	// Step 4-1 - Set the head_node to NULL
	the_list->head_node = NULL;

	fprintf( stdout, "Base Addresses: %p %p\n", &the_list, the_list );

	// Step 11 - Replace 7 - Call insert with as many as we want to insert
	for( iter = 1; iter < argc; ++iter ){

		int the_value = atoi( argv[iter] );

		insert( the_list, the_value );

	}


	// Step 9 - Call in main
	fprintf( stdout, "Before Re-ordering:\n" );
	fprintf( stdout, "Register pointer: %p %p\n", &(the_list), the_list );
	fprintf( stdout, "Head Node Addresses: %p %p\n", &(the_list->head_node), the_list->head_node );
	print_list( the_list->head_node );
	
	
	// Re-Order the List 
	reorder_call( the_list->head_node );
	
	fprintf( stdout, "\n\nAfter Re-ordering:\n" );
	fprintf( stdout, "Register pointer: %p %p\n", &(the_list), the_list );
	fprintf( stdout, "Head Node Addresses: %p %p\n", &(the_list->head_node), the_list->head_node );
	print_list( the_list->head_node );

	// Step 11 - Call the destructor
	destructor( the_list->head_node );


	// Step 5 - Free the sllist
	free( the_list );

	return EXIT_SUCCESS;
}
