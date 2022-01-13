#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;

}sll_node;


int main( void ){

	// Create four sll_nodes with dynamic memory allocation
	sll_node* node_0 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_1 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_2 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_3 = (sll_node*)malloc( sizeof(sll_node) );

	// Make their values 10, -20, 15, and 4 and link them in that order
	node_0->data = 10;
	node_1->data = -20;
	node_2->data = 15;
	node_3->data = 4;

	// Point to the next one in this order, and set the last to NULL
	node_0->next_node = node_1;
	node_1->next_node = node_2;
	node_2->next_node = node_3;
	node_3->next_node = NULL;

	// Creating a node pointer iterator
	sll_node* curr_ptr = node_0;

  // Printing the Register address of the nodes and curr_ptr
  fprintf( stdout, "Register address of node_0 = %p\n", &node_0);
  fprintf( stdout, "Register address of node_1 = %p\n", &node_1);
  fprintf( stdout, "Register address of node_2 = %p\n", &node_2);
  fprintf( stdout, "Register address of node_3 = %p\n", &node_3);
  fprintf( stdout, "Register address of curr_ptr = %p\n", &curr_ptr);

  // Printing the addresses and data on the data heap
	while( curr_ptr != NULL ){

		fprintf( stdout, "Node Base Address: %p, ", curr_ptr );
		fprintf( stdout, "Data Address: %p, ", &(curr_ptr->data) );
		fprintf( stdout, "Data Value: %d, ", curr_ptr->data );
		fprintf( stdout, "Location of Next Node: %p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "Value of Next Node: %p\n", curr_ptr->next_node );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;
	}
	fprintf( stdout, "\n" );

	// Step 2-5 -  Free four sll_nodes with dynamic memory allocation
	free( node_0 );
	free( node_1 );
	free( node_2 );
	free( node_3 );

	return EXIT_SUCCESS;

}
