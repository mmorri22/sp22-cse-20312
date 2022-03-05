#ifndef BTREE_NODE2_H
#define BTREE_NODE2_H

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
	
	void insert( const T& insert_val ){
		
		if( this->curr_size < order - 1 ){
		
			SIZE_T insert_iter = this->curr_size;
			
			while( insert_iter > 0 && this->data.at( insert_iter - 1 ) > insert_val ){
				
				// Copy value to the Righ
				this->data.at( insert_iter ) = this->data.at( insert_iter - 1 );
				
				// Decrement the iterator
				--insert_iter;
			}
			
			// The current location will be where we need to insert the value 
			this->data.at( insert_iter ) = insert_val;
			this->curr_size++;
		}
	}
	
	void print_node(){
		
		for( SIZE_T print_iter = 0; print_iter < this->curr_size; ++print_iter ){
			
			COUT << this->data.at( print_iter ) << " ";
		}
	}

};

#endif