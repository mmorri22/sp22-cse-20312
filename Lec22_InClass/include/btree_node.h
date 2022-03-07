#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <vector>
#include <iostream>
#include <algorithm>

#define VECTOR std::vector
#define COUT std::cout
#define ENDL std::endl
#define SIZE_T long unsigned int

template< typename T >
struct btree_node{


	/* Members */
	SIZE_T order;	/* Order of the B-Tree */
	SIZE_T curr_size; /* Current Number of Data Elements */
	bool is_leaf;
	VECTOR<T> data;	/* Vector containing the data values */
	VECTOR< btree_node<T>* > child_ptrs; /* Child pointers */
	
	/* Methods */
	btree_node( const SIZE_T& order_in, const bool is_leaf_in ) :
		order( order_in ), curr_size( 0 ), is_leaf( is_leaf_in ),
		data( order_in - 1 ), child_ptrs( order_in, NULL ) {}
		
	~btree_node() {}
	
	bool contains_key( const T& insert_val ){
		
		for( SIZE_T iter = 0; iter < this->curr_size; ++iter ){
			
			if( this->data.at(iter) == insert_val ){

				return true;
			}
		}
		
		return false;
	}
	
	void node_insert( const T& insert_val ){
		
		if( curr_size < order - 1 ){
		
			SIZE_T insert_iter = curr_size;
			
			while( insert_iter > 0 && data.at( insert_iter - 1 ) > insert_val ){
				
				// Copy value to the Righ
				data.at( insert_iter ) = data.at( insert_iter - 1 );
				
				// Decrement the iterator
				--insert_iter;
			}
			
			// The current location will be where we need to insert the value 
			data.at( insert_iter ) = insert_val;
			this->curr_size++;
			
		}
		
	}
	
	void print_node(){
		
		for( SIZE_T print_iter = 0; print_iter < curr_size; ++print_iter ){
			
			COUT << data.at( print_iter ) << " ";
		}
	}

};

#endif