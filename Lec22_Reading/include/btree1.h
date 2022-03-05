#ifndef BTREE1_H
#define BTREE1_H

#include "btree_node1.h"

template< typename T >
struct btree{
	
	private:
	
		SIZE_T order;
		btree_node<T>* root;
	
	public:
		
		btree( const SIZE_T& order_in ) : order( order_in ), root( NULL ) {};
		
		~btree( ){
			
			if( root != NULL ){
				
				delete root;
			}
		}
};

#endif