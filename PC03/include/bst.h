#ifndef BST_H
#define BST_H

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


void constructor( bst* int_bst );

void insert( bst_node** curr_node, int value );

void in_order_traversal( bst_node* curr_node );

void pre_order_traversal( bst_node* curr_node );

void post_order_traversal( bst_node* curr_node );

void destructor( bst_node* curr_node );

void find_kth_element( bst_node* curr_node, int kth, int* curr_val, int* solution );

long unsigned int maximum_depth( bst_node* curr_node );

void reverse_tree( bst_node** curr_node );


#endif