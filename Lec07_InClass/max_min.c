#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int front( stack* the_stack ){
	
	return the_stack->head_node->data;
	
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


void add_max_min( stack* the_stack, stack* max_stack, stack* min_stack, int the_value){
		
		
	if( max_stack->head_node == NULL || the_value >= max_stack->head_node->data )
		push( max_stack, the_value );

	if( min_stack->head_node == NULL || the_value <= min_stack->head_node->data )
		push( min_stack, the_value );
	
	push( the_stack, the_value );

}


void remove_max_min( stack* the_stack, stack* max_stack, stack* min_stack){

	if( max_stack->head_node != NULL && the_stack->head_node->data == max_stack->head_node->data )
		pop( max_stack );
	
	if( min_stack->head_node != NULL && the_stack->head_node->data == min_stack->head_node->data )
		pop( min_stack );
	
	if( the_stack != NULL )
		pop( the_stack );
}

int main( ){

	
	// Dynamically allocate a stack 
	stack* the_stack = (stack *)malloc( sizeof( stack ) );
	stack* max_stack = (stack *)malloc( sizeof( stack ) );
	stack* min_stack = (stack *)malloc( sizeof( stack ) );

	
	// Set the head_node's to NULL 
	the_stack->head_node = NULL;
	max_stack->head_node = NULL;
	min_stack->head_node = NULL;

	
	// Set up the stack size and max value variables
	int stack_size, val_max;
	fprintf( stdout, "Enter the number of elements and the maximum value: ");
	fscanf( stdin, "%d %d", &stack_size, &val_max );
	
	// Seed the random number generator
	srand( (unsigned int)time(NULL) );
	
	// Push random elements onto the stack for testing the solution
	fprintf( stdout, "Pushing elements to the stack...\n");
	int i;
	for(i = 0; i < stack_size; i++){
		
		int curr_value = rand() % val_max;
		
		add_max_min( the_stack, max_stack, min_stack, curr_value );
		
		fprintf( stdout, "Top: %d, Max: %d, Min: %d\n",
			the_stack->head_node->data,
			max_stack->head_node->data,
			min_stack->head_node->data );
	}
	
	
	// Call in main
	fprintf( stdout, "\nThe current stack: ");
	print_stack( the_stack->head_node );
	
	
	// We are going to iterate and print 
	fprintf( stdout, "\nThe removal process...\n" );
	while( the_stack->head_node != NULL ){

		fprintf( stdout, "Top: %d, Max: %d, Min: %d\n",
			the_stack->head_node->data,
			max_stack->head_node->data,
			min_stack->head_node->data );

		
		remove_max_min( the_stack, max_stack, min_stack );

	}

	
	// Step 11 - Call the destructor
	destructor( the_stack->head_node );

	
	// Step 5 - Free the stack 
	free( the_stack );
	
	return EXIT_SUCCESS;
}