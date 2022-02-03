#ifndef SN_QUEUE_H
#define SN_QUEUE_H


// M x N matrix
#define M 10
#define N 10


// queue search_node used in BFS
typedef struct search_node
{
	int x;	// x value of the coordinate 
	int y;	// y value of the coordinate
	int dist;	// Distance traveled from source
	
} search_node;



typedef struct sn_queue_node{

	search_node* data;

	struct sn_queue_node* prev_node;

	struct sn_queue_node* next_node;

}sn_queue_node;


// Step 3 - Create the struct for queue
typedef struct sn_queue{

	struct sn_queue_node* head_node;

	struct sn_queue_node* tail_node;

}sn_queue;


// Step 13 - Push Front
void push_back( sn_queue* the_queue, search_node* the_value ){

	// 13 - 1 We can copy everything up through the empty head node from Insert

	// Create a sn_queue_node pointer called insert_node
	sn_queue_node* insert_node = (sn_queue_node*)malloc( sizeof(sn_queue_node) );

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
	sn_queue_node* reference = the_queue->tail_node;

	// Set the head_node to the new node
	the_queue->tail_node = insert_node;

	// Set the new head_node's next to the reference
	the_queue->tail_node->prev_node = reference;
	reference->next_node = the_queue->tail_node;

}



// Step 8 - Print the Singly Linked List
void print_list( sn_queue_node* head_node ){

	// We can just copy and paste from queue_part2.c

	// Just change node_0 to head_node

	sn_queue_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}


// Step 10 - Free all the elements
void destructor( sn_queue_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr == NULL )
		return;


	// Recursively call destructor on the next node
	destructor( curr_ptr->next_node );

	// Free the search node 
	free( curr_ptr->data );

	// Free the current pointer
	free( curr_ptr );

}

search_node* front( sn_queue* the_queue ){
	
	return the_queue->head_node->data;
	
}


// Step 15 - Pop Front
// Step 15 - Pop Front
void pop_front( sn_queue* the_queue ){

	// Check if the list is not empty
	if( the_queue->head_node == NULL && the_queue->tail_node == NULL )
		return;

	else if( the_queue->head_node == the_queue->tail_node ){
		
		if( the_queue->head_node->data != NULL ){
			free( the_queue->head_node->data );
		}
		else if( the_queue->head_node->data == NULL ){
			fprintf( stdout, "not expected\n" );
		}
		
		free( the_queue->head_node );

		the_queue->head_node = NULL;
		the_queue->tail_node = NULL;

		return;
	}

	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	sn_queue_node* reference = the_queue->head_node;

	the_queue->head_node = reference->next_node;
	the_queue->head_node->prev_node = NULL;

	// Free the sn_node pointer 
	free( reference->data );

	// Free the reference
	free( reference );

}


#endif