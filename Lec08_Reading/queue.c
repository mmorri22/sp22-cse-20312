#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{

	int data;
	
	struct queue_node* prev_node;	
	
	struct queue_node* next_node;	
	
}queue_node;


// Step 3 - Create the struct for queue
typedef struct queue{

	struct queue_node* head_node;
	
	struct queue_node* tail_node;
	
}queue;



// Step 13 - Push Front 
void push_back( queue* the_queue, int the_value ){
	
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



// Step 8 - Print the Singly Linked List 
void print_list( queue_node* head_node ){
	
	// We can just copy and paste from queue_part2.c
	
	// Just change node_0 to head_node

	queue_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Step 17 - Only print the value
		fprintf( stdout, "%d ", curr_ptr->data );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Step 10 - Free all the elements 
void destructor( queue_node* curr_ptr ){
	
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


int main( const int argc, const char* argv[] ){

	
	queue* the_queue = (queue *)malloc( sizeof( queue ) );
	
	the_queue->head_node = NULL;
	the_queue->tail_node = NULL;
	
	
	// Step 14 - Replace 11 - Call push_front with as many as we want to insert
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		
		push_back( the_queue, the_value );
		
	}
	
	
	// Step 9 - Call in main
	print_list( the_queue->head_node );
	
	
	// Step 16 - We are going to iterate and print 
	while( the_queue->head_node != NULL ){
		
		pop_front( the_queue );
		
		print_list( the_queue->head_node );
		
	}

	// Step 11 - Call the destructor
	destructor( the_queue->head_node );
	
	// Step 5 - Free the queue 
	free( the_queue );
	
	return EXIT_SUCCESS;
}