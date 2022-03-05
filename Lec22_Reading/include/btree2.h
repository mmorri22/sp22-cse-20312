#ifndef BTREE2_H
#define BTREE2_H

#include "btree_node2.h"

template< typename T >
struct btree{
	
	private:
	
		SIZE_T order;
		btree_node<T>* root;
	
	public:
		
		btree( const SIZE_T& order_in ) : order( order_in ), root( NULL ) {};
		
		~btree( ){
			
			if( this->root != NULL ){
				
				delete this->root;
			}
		}
		
		void insert( const T& insert_val ){
			
			if( this->root == NULL )
				this->root = new btree_node<T>( order );
			
			this->root->insert( insert_val );
			
		}
		
		void print_tree( ){
			
			if( this->root != NULL ){
				
				this->root->print_node();
				COUT << ENDL;
			}
		}
};

#endif