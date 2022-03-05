#ifndef BTREE_NODE1_H
#define BTREE_NODE1_H

#include <vector>
#include <iostream>

#define VECTOR std::vector
#define COUT std::cout
#define ENDL std::endl
#define SIZE_T long unsigned int

template< typename T >
struct btree_node{


	/* Members */
	SIZE_T order;	/* Order of the B-Tree */
	SIZE_T curr_size; /* Current Number of Data Elements */
	VECTOR<T> data;	/* Vector containing the data values */
	VECTOR< btree_node<T>* > child_ptrs; /* Child pointers */
	
	/* Methods */
	btree_node( const SIZE_T& order_in ) :
		order( order_in ), curr_size( 0 ), 
		data( order_in - 1 ), child_ptrs( order_in, NULL ) {}
		
	~btree_node() {}

};

#endif