#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node{

	int data;
	struct stack_node* next_node;	
	
}stack_node;


typedef struct stack{

	struct stack_node* head_node;
	
}stack;



void push( stack* the_stack, int the_value ){
	
	stack_node* insert_node = (stack_node*)malloc( sizeof(stack_node) );
	
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_stack->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_stack->head_node = insert_node;
		
		// And return
		return;
	}
	
	// Now we just need to use a reference pointer and put them in front
	stack_node* reference = the_stack->head_node;
	
	// Set the head_node to the new node 
	the_stack->head_node = insert_node;
	
	// Set the new head_node's next to the reference 
	the_stack->head_node->next_node = reference;
	
}

// Print the Singly Linked List 
void print_stack( stack_node* head_node ){

	stack_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Only print the value
		fprintf( stdout, "%d ", curr_ptr->data );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Free all the elements 
void destructor( stack_node* curr_ptr ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( curr_ptr == NULL )
		return;
	

	// Recursively call destructor on the next node  
	destructor( curr_ptr->next_node );
		
	// Free the current pointer 
	free( curr_ptr );
	
}


// Pop Front 
void pop( stack* the_stack ){
	
	// Check if the list is not empty
	if( the_stack->head_node == NULL )
		return;
	
	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	stack_node* reference = the_stack->head_node;
	
	// Set the head_node to head_node's next_node;
	the_stack->head_node = the_stack->head_node->next_node;
	
	// Free the reference 
	free( reference );
	
}


int main( const int argc, const char* argv[] ){

	
	// Dynamically allocate a stack 
	stack* the_stack = (stack *)malloc( sizeof( stack ) );
	
	// Set the head_node to NULL 
	the_stack->head_node = NULL;
	
	
	// Call push with as many as we want to insert
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		
		push( the_stack, the_value );
		
	}
	
	
	// Call in main
	print_stack( the_stack->head_node );
	
	
	// We are going to iterate and print 
	while( the_stack->head_node != NULL ){
		
		pop( the_stack );
		
		print_stack( the_stack->head_node );
		
	}

	
	// Step 11 - Call the destructor
	destructor( the_stack->head_node );

	
	// Step 5 - Free the stack 
	free( the_stack );
	
	return EXIT_SUCCESS;
}