#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node{

	int data;
	
	struct dll_node* prev_node;	
	
	struct dll_node* next_node;	
	
}dll_node;


// Step 3 - Create the struct for dllist
typedef struct dllist{

	struct dll_node* head_node;
	
	struct dll_node* tail_node;
	
}dllist;




// Step 13 - Push Front 
void push_front( dllist* the_list, int the_value ){
	
	// Create a dll_node pointer called insert_node
	dll_node* insert_node = (dll_node*)malloc( sizeof(dll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		the_list->tail_node = insert_node;
		
		return;
	}
	
	// Otherwise, we perform the pointer arithmetic
	dll_node* reference = the_list->head_node;
	
	// Set the head_node to the new node 
	the_list->head_node = insert_node;
	
	// Set the new head_node's next to the reference 
	the_list->head_node->next_node = reference;
	reference->prev_node = the_list->head_node;
	
}

// Step 13 - Push Front 
void push_back( dllist* the_list, int the_value ){
	
	// Create a dll_node pointer called insert_node
	dll_node* insert_node = (dll_node*)malloc( sizeof(dll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->prev_node = NULL;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->tail_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		the_list->tail_node = insert_node;
		
		// And return
		return;
	}
	
	// 13-2 Now we just need to use a reference pointer and put them in front
	dll_node* reference = the_list->tail_node;
	
	// Set the head_node to the new node 
	the_list->tail_node = insert_node;
	
	// Set the new head_node's next to the reference 
	the_list->tail_node->prev_node = reference;
	reference->next_node = the_list->tail_node;
	
}



// Step 8 - Print the Singly Linked List 
void print_list( dll_node* head_node ){
	
	// We can just copy and paste from dllist_part2.c
	
	// Just change node_0 to head_node

	dll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Step 17 - Only print the value
		fprintf( stdout, "%d ", curr_ptr->data );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Step 10 - Free all the elements 
void destructor( dll_node* curr_ptr ){
	
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
void pop_front( dllist* the_list ){
	
	// Check if the list is not empty
	if( the_list->head_node == NULL )
		return;
	
	else if( the_list->head_node == the_list->tail_node ){
		
		// free( the_list->head_node );
		
		dll_node* reference = the_list->head_node;
		
		the_list->head_node = NULL;
		the_list->tail_node = NULL;
		
		free( reference );
		
		return;
	}
	
	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	dll_node* reference = the_list->head_node;
	
	// Set the head_node to head_node's next_node;
	the_list->head_node = reference->next_node;
	the_list->head_node->prev_node = NULL;

	
	// Free the reference 
	free( reference );
	
}


// Step 15 - Pop Front 
void pop_back( dllist* the_list ){
	
	// Check if the list is not empty
	if( the_list->head_node == NULL )
		return;
	
	else if( the_list->head_node == the_list->tail_node ){
		
		free( the_list->head_node );
		
		the_list->head_node = NULL;
		the_list->tail_node = NULL;
		
		return;
	}
	
	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	dll_node* reference = the_list->tail_node;
	
	// Set the head_node to head_node's next_node;
	the_list->tail_node = reference->prev_node;
	the_list->tail_node->next_node = NULL;

	
	// Free the reference 
	free( reference );
	
}


int main( const int argc, const char* argv[] ){

	
	dllist* the_list = (dllist *)malloc( sizeof( dllist ) );
	
	the_list->head_node = NULL;
	the_list->tail_node = NULL;
	
	
	// Step 14 - Replace 11 - Call push_front with as many as we want to insert
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		
		push_back( the_list, the_value );
		
	}
	
	
	// Step 9 - Call in main
	print_list( the_list->head_node );
	
	
	// Step 16 - We are going to iterate and print 
	while( the_list->head_node != NULL ){
		
		pop_front( the_list );
		
		print_list( the_list->head_node );
		
	}

	// Step 11 - Call the destructor
	destructor( the_list->head_node );
	
	// Step 5 - Free the dllist 
	free( the_list );
	
	return EXIT_SUCCESS;
}