#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

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
	// COMMENTED OUT - stack_node* reference = the_stack->head_node;
	
	// Set the head_node to head_node's next_node;
	the_stack->head_node = the_stack->head_node->next_node;
	
	// Free the reference - Will comment out in class 
	// COMMENTED OUT  - free( reference );
	
	
}


void move(stack* source, stack* destination, int* numMoves){
	
	// De-reference and Increment the number of moves
	(*numMoves)++;
	
	// Get the data from the head node, and push on the top
	push( destination, source->head_node->data );
	
	// Remove the element from the source
	pop( source );
	
}


void hanoi( int n, stack* source, stack* destination, stack* auxillary, int* numMoves){
		
	if( n > 0 ){
		
		hanoi( n-1, source, auxillary, destination, numMoves );
		
		move( source, destination, numMoves );
		
		hanoi( n-1, auxillary, destination, source, numMoves );
	}
}


int main( const int argc, const char* argv[] ){


	if( argc != 2 ){
		
		fprintf( stdout, "Incorrect number of inputs\n " );
		exit(-1);
		
	}
	
	// Get the Stack Size 
	int stack_size = atoi( argv[1] );
	
	// Track the number of moves 
	int num_moves = 0;
	
	// Dynamically allocate three stacks  
	stack* tower_1 = (stack *)malloc( sizeof( stack ) );
	stack* tower_2 = (stack *)malloc( sizeof( stack ) );
	stack* tower_3 = (stack *)malloc( sizeof( stack ) );
	
	// Set the head_node to NULL 
	tower_1->head_node = NULL;
	tower_2->head_node = NULL;
	tower_3->head_node = NULL;
	
	// Insert elements in reverse
	int iter;
	for( iter = stack_size; iter > 0; --iter ){
		
		push( tower_1, iter );
		
	}
	
	// Run the algorithm
	hanoi( stack_size, tower_1, tower_2, tower_3, &num_moves );
	
	COUT << stack_size << " plates moved in " << num_moves << " moves" << ENDL;

	
	// Step 11 - Call the destructors
	destructor( tower_3->head_node );
	destructor( tower_2->head_node );
	destructor( tower_1->head_node );

	
	// Step 5 - Free the stacks 
	free( tower_3 );
	free( tower_2 );
	free( tower_1 );
	
	return EXIT_SUCCESS;
}