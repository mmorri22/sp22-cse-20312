#ifndef BST_SOL_H
#define BST_SOL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node{
	
	int value;
	
	struct bst_node* left;
	
	struct bst_node* right;
	
} bst_node;


typedef struct bst{
	
	struct bst_node* root;
	
} bst;


typedef struct queue_node{

	bst_node* data;

	struct queue_node* prev_node;

	struct queue_node* next_node;

}queue_node;


// Step 3 - Create the struct for queue
typedef struct queue{

	struct queue_node* head_node;

	struct queue_node* tail_node;

}queue;


void constructor( bst* int_bst );

void insert( bst_node** curr_node, int value );

void in_order_traversal( bst_node* curr_node );

void pre_order_traversal( bst_node* curr_node );

void post_order_traversal( bst_node* curr_node );

void destructor( bst_node* curr_node );

void find_kth_element( bst_node* curr_node, int kth, int* curr_val, int* solution );

long unsigned int maximum_depth( bst_node* curr_node );

void reverse_tree( bst_node** curr_node );

int queue_is_empty( queue* the_queue );

void queue_destructor( queue_node* curr_ptr );

bst_node* front( queue* the_queue );

queue* queue_constructor();

void push_back( queue* the_queue, bst_node* the_value );

void pop_front( queue* the_queue );

void level_order_traversal( bst* int_bst, queue* level_queue );



#endif