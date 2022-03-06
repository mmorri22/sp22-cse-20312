#ifndef BTREE3_H
#define BTREE3_H

#include "btree_node2.h"

template< typename T >
struct btree{
	
	private:
	
		SIZE_T order;
		btree_node<T>* root;
		
		void print_tree( const btree_node<T>* curr_node, SIZE_T level ){
			
			if( curr_node == NULL )
				return;
			
			SIZE_T data_iter = 0;
			
			while( data_iter < curr_node->curr_size ){
				
				print_tree( curr_node->child_ptrs.at( data_iter ), level + 1 );
				
				COUT << "{" << curr_node->data.at( data_iter ) << ", Level: " << level << "} ";

				++data_iter;
			}
			
			// Call the last node pointer that could possibly be used
			print_tree( curr_node->child_ptrs.at( data_iter ), level + 1 );
		}
		
		void destructor( btree_node<T>* curr_node ){
			
			if( curr_node == NULL )
				return;
			
			for( SIZE_T iter = 0; iter <= curr_node->curr_size; ++iter ){
				
				destructor( curr_node->child_ptrs.at(iter) );
			}
			
			delete curr_node;
		}
	
	public:
		
		btree( const SIZE_T& order_in ) : order( order_in ), root( NULL ) {};
		
		~btree( ){
			
			if( this->root != NULL ){
				
				this->destructor( this->root );
			}
		}
		
		void insert( const T& insert_val ){
			
			if( this->root == NULL )
				this->root = new btree_node<T>( order );
			
			// The root is not full
			if( this->root->curr_size < this->order - 1 )
				this->root->insert( insert_val );
			
			// The root is full 
			else{
				
				// Create a parent node to split up 
				btree_node<T>* parent = new btree_node<T>( order );
				
				// Create a first node (left)
				btree_node<T>* left = new btree_node<T>( order );
				
				// Create a second node (right)
				btree_node<T>* right = new btree_node<T>( order );
				
				// Set the left as the first child pointer of parent 
				parent->child_ptrs.at(0) = left;
				
				// Set the right as the second child pointer of parent 
				parent->child_ptrs.at(1) = right;
				
				// We have three cases to address 
				// 1 - insert_val should end up on the left 
				// 2 - insert_val will be in the parent 
				// 3 - insert_val will be on the right 
				SIZE_T curr_middle = (root->curr_size) / 2;
				
				SIZE_T left_iter = 0;
				SIZE_T right_iter;
				while( left_iter < curr_middle && root->data.at(left_iter) < insert_val ){
					
					left->insert( root->data.at(left_iter) );
					
					++left_iter;
				}
				
				// If we didn't reach curr_middle, the insert_val is on the left 
				if( left_iter < curr_middle ){
					
					left->insert( insert_val );
					
					while( left_iter < curr_middle - 1 ){
						
						left->insert( root->data.at(left_iter) );
						
						++left_iter;
					}

					// The curr middle needs to be the first element in the parent 
					parent->insert( root->data.at(left_iter) );
					
					right_iter = curr_middle;
					while( right_iter < this->root->curr_size ){
						
						right->insert( root->data.at(right_iter) );
						
						++right_iter;
					}
				}
				
				// If we did reach curr_middle, then the insert_val is in the middle or right 
				else{
					
					// Case where insert_val is the middle value 
					if( insert_val <= root->data.at(curr_middle) ){
						
						// Set the parent's data to insert_val
						parent->insert( insert_val );
						
						// Add all the values to the right
						right_iter = curr_middle;
						while( right_iter < this->root->curr_size ){
							
							right->insert( root->data.at(right_iter) );
							
							++right_iter;
						}	
					}	

					// Case where insert_val will be on the right 
					else{
						
						parent->insert( root->data.at(curr_middle) );
						
						// Add all the values to the right
						right_iter = curr_middle + 1;
						
						while( right_iter < this->root->curr_size 
								&& root->data.at(right_iter) < insert_val ){
							
							right->insert( root->data.at(right_iter) );
							++right_iter;							
						}
						
						right->insert( insert_val );
						
						while( right_iter < this->root->curr_size  ){
							
							right->insert( root->data.at(right_iter) );
							++right_iter;
						}
					}
				}
				
				btree_node<T>* to_delete = this->root;
				
				this->root = parent;
				
				delete to_delete;
			}
		}
		
		void print_tree( ){
			
			SIZE_T level = 1;
			
			COUT << "BTree - [ ";
			this->print_tree( this->root, level );
			COUT << " ]" <<ENDL;
		}
};

#endif