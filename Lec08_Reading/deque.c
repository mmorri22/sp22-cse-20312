#include <stdio.h>
#include <stdlib.h>

typedef struct deque_node{

	int data;

	struct deque_node* prev_node;

	struct deque_node* next_node;

}deque_node;


// Step 3 - Create the struct for deque
typedef struct deque{

	struct deque_node* head_node;

	struct deque_node* tail_node;

}deque;




// Step 13 - Push Front
void push_front( deque* the_deque, int the_value ){

	// Create a deque_node pointer called insert_node
	deque_node* insert_node = (deque_node*)malloc( sizeof(deque_node) );

	// Set the insert_node's data to the_value and next_node to NULL
	insert_node->data = the_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers
	if( the_deque->head_node == NULL ){

		// Set the head node equal to insert_node
		the_deque->head_node = insert_node;
		the_deque->tail_node = insert_node;

		return;
	}

	// Otherwise, we perform the pointer arithmetic
	deque_node* reference = the_deque->head_node;

	// Set the head_node to the new node
	the_deque->head_node = insert_node;

	// Set the new head_node's next to the reference
	the_deque->head_node->next_node = reference;
	reference->prev_node = the_deque->head_node;

}

// Step 13 - Push Front
void push_back( deque* the_deque, int the_value ){

	// Create a deque_node pointer called insert_node
	deque_node* insert_node = (deque_node*)malloc( sizeof(deque_node) );

	// Set the insert_node's data to the_value and next_node to NULL
	insert_node->data = the_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the list is empty
	if( the_deque->tail_node == NULL ){

		// Set the head node equal to insert_node
		the_deque->head_node = insert_node;
		the_deque->tail_node = insert_node;

		// And return
		return;
	}

	// 13-2 Now we just need to use a reference pointer and put them in front
	deque_node* reference = the_deque->tail_node;

	// Set the head_node to the new node
	the_deque->tail_node = insert_node;

	// Set the new head_node's next to the reference
	the_deque->tail_node->prev_node = reference;
	reference->next_node = the_deque->tail_node;

}



// Step 8 - Print the Singly Linked List
void print_list( deque_node* head_node ){


	deque_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){

		fprintf( stdout, "Node Base Address: %p, ", curr_ptr );
		fprintf( stdout, "Data Value: %d, ", curr_ptr->data );
		fprintf( stdout, "Location of Prev Node: %p, ", &(curr_ptr->prev_node) );
		fprintf( stdout, "Value of Prev Node: %p\n", curr_ptr->prev_node );
		fprintf( stdout, "Location of Next Node: %p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "Value of Next Node: %p\n", curr_ptr->next_node );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}


// Step 10 - Free all the elements
void destructor( deque_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr == NULL )
		return;


	// Recursively call destructor on the next node
	destructor( curr_ptr->next_node );

	// Free the current pointer
	free( curr_ptr );

}


// Step 15 - Pop Front
// Step 15 - Pop Front
void pop_front( deque* the_deque ){

	// Check if the list is not empty
	if( the_deque->head_node == NULL )
		return;

	else if( the_deque->head_node == the_deque->tail_node ){

		// free( the_deque->head_node );

		deque_node* reference = the_deque->head_node;

		the_deque->head_node = NULL;
		the_deque->tail_node = NULL;

		free( reference );

		return;
	}

	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	deque_node* reference = the_deque->head_node;

	// Set the head_node to head_node's next_node;
	the_deque->head_node = reference->next_node;
	the_deque->head_node->prev_node = NULL;


	// Free the reference
	free( reference );

}


// Step 15 - Pop Front
void pop_back( deque* the_deque ){

	// Check if the list is not empty
	if( the_deque->head_node == NULL )
		return;

	else if( the_deque->head_node == the_deque->tail_node ){

		free( the_deque->head_node );

		the_deque->head_node = NULL;
		the_deque->tail_node = NULL;

		return;
	}

	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	deque_node* reference = the_deque->tail_node;

	// Set the head_node to head_node's next_node;
	the_deque->tail_node = reference->prev_node;
	the_deque->tail_node->next_node = NULL;


	// Free the reference
	free( reference );

}


int main( ){


	deque* the_deque = (deque *)malloc( sizeof( deque ) );

	the_deque->head_node = NULL;
	the_deque->tail_node = NULL;

	fprintf( stdout, "Base Addresses: %p %p\n", &the_deque, the_deque );

	push_front( the_deque, 12 );
	push_back( the_deque, -13 );
	push_front( the_deque, 22 );
	push_back( the_deque, 18 );
	pop_front( the_deque );
	push_back( the_deque, 16 );
	pop_back( the_deque );

	fprintf( stdout, "Head Node Addresses: %p %p\n", &(the_deque->head_node), the_deque->head_node );
	fprintf( stdout, "Tail Node Addresses: %p %p\n", &(the_deque->tail_node), the_deque->tail_node );

	// Step 9 - Call in main
	print_list( the_deque->head_node );

	// Step 11 - Call the destructor
	destructor( the_deque->head_node );

	// Step 5 - Free the deque
	free( the_deque );

	return EXIT_SUCCESS;
}
