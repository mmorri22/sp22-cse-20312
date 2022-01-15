#ifndef SLLIST_H
#define SLLIST_H

#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

struct sllist{
	
	struct sll_node* head_node;
	
};


void insert( struct sllist* the_list, int new_data );


void push_front( struct sllist* the_list, int new_data );


int pop_front( struct sllist* the_list );


void print_list( struct sllist* the_list )	// Missing Semicolon!


void delete_node( struct sll_node** curr_node );


#endif
