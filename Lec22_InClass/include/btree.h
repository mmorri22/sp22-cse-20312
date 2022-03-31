#ifndef BTREE_H
#define BTREE_H

#include "btree_node.h"

template< typename T >
struct btree{
	
	private:
	
		SIZE_T order;
		btree_node<T>* root;
		
		void print_tree( const btree_node<T>* curr_node, SIZE_T level ) const{
			
			// Professor Morrison's Golden Rule of Pointers!
			if( curr_node == NULL )
				return;
			
			SIZE_T data_iter = 0;
			
			// Go through all the current data elements
			while( data_iter < curr_node->curr_size ){
				
				// Call the pointer recursively
				print_tree( curr_node->child_ptrs.at( data_iter ), level + 1 );
				
				// Print the current data element and the current level
				COUT << "{" << curr_node->data.at( data_iter ) << ", Level: " << level << "} ";

				++data_iter;
			}
			
			// Call the last node pointer that could possibly be used
			print_tree( curr_node->child_ptrs.at( data_iter ), level + 1 );
		}
		
		bool contains( const btree_node<T>* curr_node, const T& check_val ) const{
			
			// Professor Morrison's Golden Rule of Pointers!
			if( curr_node == NULL )
				return false;
			
			if( curr_node->curr_size == 0 )
				return false;
			
			SIZE_T data_iter = 0;
			
			// Go through all the current data elements
			while( data_iter < curr_node->curr_size && curr_node->data.at( data_iter ) < check_val ){

				++data_iter;
			}
			
			if( data_iter < curr_node->curr_size && curr_node->data.at( data_iter ) == check_val )
				return true;
			
			else{
				
				return contains( curr_node->child_ptrs.at( data_iter ), check_val );
				
			}
		}
		
		void destructor( btree_node<T>* curr_node ){
			
			if( curr_node == NULL )
				return;
			
			
			for( SIZE_T iter = 0; iter <= curr_node->curr_size; ++iter ){
				
				destructor( curr_node->child_ptrs.at(iter) );
			}
			
			delete curr_node;
		}
		
		void swap_and_delete( btree_node<T>*& curr_node, btree_node<T>*& parent ){
			
			// Create a reference node for deletion
			btree_node<T>* to_delete = curr_node;
		
			// Set the current node to the parent to recursively return
			curr_node = parent;
			
			// Delete the node we were pointing to
			delete to_delete;		
			
		}
		
		
		bool insert( btree_node<T>*& curr_node, const T& insert_val ){
			
			// Setting the current node to being a leaf
			if( curr_node == NULL )
				curr_node = new btree_node<T>( order, true );
			
			
			// If the current node is *not* a leaf, we need to traverse 
			if( curr_node->is_leaf == false ){
				
				// We know non-leaves are not full unless we propagate a value up
				SIZE_T iter = 0;
				while( iter < curr_node->curr_size && curr_node->data.at( iter ) < insert_val ){

					++iter;
				}
				
				// Recursively call the insert node 
				bool did_split = insert( curr_node->child_ptrs.at(iter), insert_val );
				
				// If the previous level did not split, then we do not need to check again
				if( !did_split ){
					
					return false;
				}
				// If the previous node split and the current node is not full
				else if( did_split && curr_node->curr_size < this->order - 1 ){
					
					SIZE_T jter = curr_node->curr_size;
					
					// Move the pointers to the right
					while( jter > iter ){
						curr_node->child_ptrs.at(jter + 1) = curr_node->child_ptrs.at(jter);
												
						curr_node->data.at(jter) = curr_node->data.at(jter - 1);
						
						--jter;
						
					}
					
					// Set the value and pointers 
					btree_node<T>* to_delete = curr_node->child_ptrs.at(iter);
					
					// Copy the value and increment curr_node's size
					curr_node->curr_size++;
					
					// Set the current iterators location to the node pointer
					curr_node->data.at( iter ) = curr_node->child_ptrs.at(iter)->data.at(0);
	
					// Must do them from right to left to not lose the ordering
					curr_node->child_ptrs.at(iter+1) = curr_node->child_ptrs.at(iter)->child_ptrs.at(1);				
					curr_node->child_ptrs.at(iter) = curr_node->child_ptrs.at(iter)->child_ptrs.at(0);
	
					
					// Delete the old node 
					delete to_delete;
					
					// Did not split again, so return false
					return false;
				
				}
				
				// The final case is when we split, and bringing the value up will split the current node as well
				else{
				
					/**********************************************
					 * In-Class Programming Begins Here 
					 *
					 * We will be reinforcing your understanding of pointers 
					 * and memory allocation and freeing
					 * to build programs that work together cleanly and safely
					 **********************************************/
				
					// We know the node with the data being pointed to is "in order"
					// But it is not in the current node
					// And the current node is full 
					// So we will need to split
					
					// Create a parent node to split up 
					
					
					// Create a first node (left) - This will be *not* a leaf
					
					
					// Create a second node (right) - This will be *not* a leaf
					
					
					// Set the left as the first child pointer of parent 
					
					
					// Set the right as the second child pointer of parent 
					
					
					
					// This time, we need to determine how we will bring up the original pointers 
					// We know that curr_node->child_ptrs.at( iter )->data.at(0) contains the element we are raising
					// Copy the raised value to a temp register for improved performance
					


					// Just like when the base nodes, we use our derived equation to split the middle 
					
					
					
					// The location of iter tells us the location
					// If iter is less than the curr_middle, then it will be to the left
					// if iter is equal to curr middle, it will be the value to raise!
					// If iter is greater than curr_middle, it will be to the right
					
					
					
					// Iterate through the elements until we either reach curr_middle or the raised value 
					
						// Insert the current value into the node
						
						// The pointer to the left in curr node will be the pointer to the left in the new node
						


					// If we didn't reach curr_middle, the insert_val is on the left 
												

						
						// Delete the child pointer since we no longer need that pointer - Essential to pass valgrind
						
						
						// The we go until the element BEFORE the current middle 
						

						// The curr middle needs to be the first element in the parent 
						

					
					// If we did reach curr_middle, then the insert_val is in the middle or right 
						
					
						// Case where insert_val is the middle value 
							
							// Set the parent's data to the data element we are raising
							
							// Place the raised value's first pointer at the end of left 
							
														
							// Delete the child pointer since we no longer need that pointer - Essential to pass valgrind

							
							
								
								
								
								
								
								
								

						

						// Case where insert_val will be on the right 
						
														
							
							
							// Insert the curr_middle in the parent
							
							
							// Add all the values to the right
							
							
							
								
								
								
															
							
														
							

							
							
							
														

							
								
									

									
																		
									
									
									
									
								
																
							
							
							
								
								

							// Delete the child pointer since we no longer need that pointer - Essential to pass valgrind
								
						
					
					
					
					// Update the curr_node to point at parent 
					// Create a reference node for deletion
					
				
					// Set the current node to the parent to recursively return
					
					
					// Delete the node we were pointing to
					
					
					// We split again, so we must return true
					
				}
			}
			
			// The current node is not is not full
			else if( curr_node->is_leaf && curr_node->curr_size < this->order - 1 ){
				
				// Insert the value					
				curr_node->node_insert( insert_val );
				
				// Did not split, so return false
				return false;
			}
			
			// The leaf is full 
			else{
				
				// Create a parent node to split up 
				btree_node<T>* parent = new btree_node<T>( order, false );
				
				// Create a first node (left) - This will be a leaf
				btree_node<T>* left = new btree_node<T>( order, true );
				
				// Create a second node (right) - This will be a leaf
				btree_node<T>* right = new btree_node<T>( order, true );
				
				// Set the left as the first child pointer of parent 
				parent->child_ptrs.at(0) = left;
				
				// Set the right as the second child pointer of parent 
				parent->child_ptrs.at(1) = right;	
				
				// We have three cases to address 
				// 1 - insert_val should end up on the left 
				// 2 - insert_val will be in the parent 
				// 3 - insert_val will be on the right 
				SIZE_T curr_middle; 
				
				if( this->order %2 == 1 )
					curr_middle	= (this->order) / 2;
				
				else	// Even sized order
					curr_middle	= (this->order) / 2 - 1;
				
				SIZE_T left_iter = 0;
				SIZE_T right_iter;
				
				// Go until we either reach the middle OR the insert_val is larger than the current value 
				while( left_iter < curr_middle && curr_node->data.at(left_iter) < insert_val ){
					
					left->node_insert( curr_node->data.at(left_iter) );
					
					++left_iter;
				}
				
				// If we didn't reach curr_middle, the insert_val is on the left 
				if( left_iter < curr_middle ){
					
					// First we insert the current value 
					left->node_insert( insert_val );
					
					// The we go until the element BEFORE the current value 
					while( left_iter < curr_middle - 1 ){
						
						left->node_insert( curr_node->data.at(left_iter) );
						
						++left_iter;						
					}
					
					// The curr middle needs to be the first element in the parent 
					parent->node_insert( curr_node->data.at(left_iter) );
					
					// In this case, the right iter should ALWAYS start at curr middle 				
					right_iter = curr_middle;
					while( right_iter < curr_node->curr_size ){
						
						right->node_insert( curr_node->data.at(right_iter) );
						
						++right_iter;
					}
				}
				
				// If we did reach curr_middle, then the insert_val is in the middle or right 
				else{
					
					// If we reached curr_middle AND the insert val is less than that curr_middle 
					if( left_iter == curr_middle && insert_val < curr_node->data.at(curr_middle) ){
						
						// The insert_val needs to be the parent 
						parent->node_insert( insert_val );
						
						// In this case, the right iter should ALWAYS start at curr middle 	
						right_iter = curr_middle;
						while( right_iter < curr_node->curr_size ){
							
							right->node_insert( curr_node->data.at(right_iter) );
							
							++right_iter;
						}
					}

					// Case where insert_val will be on the right 
					else{
						
						// The parent value should be the value in the middle 
						parent->node_insert( curr_node->data.at(curr_middle) );
						
						// Add all the values to the right
						right_iter = curr_middle + 1;
						
						// Continue going while the current value is less than the current size AND we are less than the insert value 
						while( right_iter < curr_node->curr_size 
								&& curr_node->data.at(right_iter) < insert_val ){
							
							right->node_insert( curr_node->data.at(right_iter) );
							++right_iter;							
						}
						
						right->node_insert( insert_val );
						
						while( right_iter < curr_node->curr_size  ){
							
							right->node_insert( curr_node->data.at(right_iter) );
							++right_iter;
						}
					}
				}
				
				// Update curr_node to point at parent and delete the old curr_node
				// Create a reference node for deletion
				btree_node<T>* to_delete = curr_node;
			
				// Set the current node to the parent to recursively return
				curr_node = parent;
				
				// Delete the node we were pointing to
				delete to_delete;	
								
				// We split, so return true
				return true;
			}
		}
	
	public:
		
		// Constructor
		btree( const SIZE_T& order_in ) : order( order_in ), root( NULL ) {};
		
		// Destructor
		~btree( ){
			
			if( this->root != NULL ){
				
				this->destructor( this->root );
			}
		}
		
		// Insert Method that calls the recursive insert
		void insert( const T& insert_val ){
			
			if( this->contains( this->root, insert_val ) == false ){
			
				insert( this->root, insert_val );
			
			}
			else{
				
				COUT << "No duplicates permitted. Excluding " << insert_val << ENDL;
			}
		}
		
		bool contains( const T& check_val ) const{
			
			return contains( this->root, check_val );
			
		}
		
		// Prints an in-order traversal 
		void print_tree( ) const{
			
			SIZE_T level = 1;
			
			COUT << "BTree - [ ";
			this->print_tree( this->root, level );
			COUT << " ]" <<ENDL;
		}
};

#endif