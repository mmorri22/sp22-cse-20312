/**********************************
 * File name: dllist_sol.h 
 * Author: Matthew Morrison 
 * Email: matt.morrison@nd.edu 
 *
 * This file contains the class definition solution
 * for the templated dllist we will co-develop in class
 ************************************/
 
#ifndef DLLIST_SOL_H
#define DLLIST_SOL_H

#include <iostream>
 
template< typename T >
struct dllist_node{

	T data;
	dllist_node<T>* prev_node;
	dllist_node<T>* next_node;
	
	// Default Constructor
	dllist_node<T>( ) : data( ), prev_node(NULL), next_node(NULL) {}
	
	// Overloaded Constructor - When we know the data 
	dllist_node<T>( const T& data_in ) : data(data_in), prev_node(NULL), next_node(NULL) {}
	
};

template< typename T >
struct dllist{
	
	private:
	
		dllist_node<T>* head_node;
		dllist_node<T>* tail_node;
		
		// Private recursive destructor call
		void destructor( dllist_node<T>* curr_node ){
			
			// Base Case - End of the List
			if( curr_node == NULL )
				return;
			
			// Recursive Case - Call the next node
			destructor( curr_node->next_node );
			
			// On the way back up - Delete the current node
			delete curr_node;
		}

	public:
	
		dllist<T>( ): head_node( NULL ), tail_node( NULL ) {}
		
		// Public Destructor Call
		~dllist<T>(){
			
			// Do nothing if the list is empty
			if( this->head_node == NULL && this->tail_node == NULL ){
				return;
			}
			
			// Call the private, recursive destructor
			destructor( this->head_node );
		}
		
		// Check if the Linked List is empty
		bool empty(){
			
			return this->head_node == NULL && this->tail_node == NULL;
		}
		
		// Return a copy of the element at the front of the Linked List
		T front(){
			
			return this->head_node->data;
		}
		
		// Return a copy of the element at the bacl of the Linked List
		T end(){
			
			return this->tail_node->data;
		}
		
		// Push to the front of the Doubly Linked List 
		void push_front( const T& insert_val ){
			
			dllist_node<T>* insert_node = new dllist_node<T>( insert_val );
			
			// Empty Case
			if( this->empty() ){
				
				this->head_node = insert_node;
				this->tail_node = insert_node;
				
				return;
			}
			
			// Otherwise
			dllist_node<T>* reference = this->head_node;
			
			// Set the insert_node's next node to the reference 
			insert_node->next_node = reference;
			
			// Set reference's previous node to insert_node
			reference->prev_node = insert_node;
			
			// Update the head_node pointer to the insert_node
			this->head_node = insert_node;
		}
		
		// Push to the back of the Doubly Linked List 
		void push_back( const T& insert_val ){
			
			dllist_node<T>* insert_node = new dllist_node<T>( insert_val );
			
			// Empty Case
			if( this->empty() ){
				
				this->head_node = insert_node;
				this->tail_node = insert_node;
				
				return;
			}
			
			// Otherwise
			dllist_node<T>* reference = this->tail_node;
			
			// Set the insert_node's previous node to the reference 
			insert_node->prev_node = reference;
			
			// Set reference's next node to insert_node
			reference->next_node = insert_node;
			
			// Update the tail_node pointer to the insert_node
			this->tail_node = insert_node;
		}
		
		// Sorted Insert into Doubly Linked List 
		void insert_sort( const T& insert_val ){
						
			// Empty Case
			if( this->empty() ){
				
				dllist_node<T>* insert_node = new dllist_node<T>( insert_val );
				
				this->head_node = insert_node;
				this->tail_node = insert_node;
				
				return;
			}

			// If the value is the smallest, push front!
			if( insert_val < this->front() ){
				this->push_front( insert_val );
				return;
			}
			
			// If the value is the largest, push back!
			if( insert_val > this->end() ){
				this->push_back( insert_val );
				return;
			}
			
			// We create the node here to pass valgrind
			// We didn't need it before
			// Using the previous methods instead
			dllist_node<T>* insert_node = new dllist_node<T>( insert_val );
			
			// Otherwise, we now know the node will go between two nodes!
			dllist_node<T>* before = this->head_node;
			dllist_node<T>* after = this->head_node->next_node;
			
			// We must account for duplicates!
			while( before->data < insert_val && after->data < insert_val ){
				
				// Move the nodes to the next location
				before = after;
				after = after->next_node;
			}
			
			// Finally, we insert the node between before and after 
			before->next_node = insert_node;
			insert_node->prev_node = before;
			
			after->prev_node = insert_node;
			insert_node->next_node = after;
			
		}
		
		// Pop from the front of the Doubly Linked List 
		void pop_front( ){
						
			// Empty Case
			if( this->empty() ){
				
				// Do not try to delete from an empty list
				
				return;
			}
			else if( this->head_node == this->tail_node ){
				
				delete this->head_node;
				
				this->head_node = NULL;
				this->tail_node = NULL;
				
				return;
			}
			
			// Otherwise
			dllist_node<T>* reference = this->head_node;
			
			// Set the current head_node's next_node's previous node to NULL 
			reference->next_node->prev_node = NULL;
			
			// Set the current head_node's next_node to eb the new head_node
			this->head_node = reference->next_node;
			
			// delete the previous head node 
			delete reference;
		}
		
		
		// Pop from the back of the Doubly Linked List 
		void pop_back( ){
						
			// Empty Case
			if( this->empty() ){
				
				// Do not try to delete from an empty list
				
				return;
			}
			else if( this->head_node == this->tail_node ){
				
				delete this->head_node;
				
				this->head_node = NULL;
				this->tail_node = NULL;
				
				return;
			}
			
			// Otherwise
			dllist_node<T>* reference = this->tail_node;
			
			// Set the current tail_node's prev_node's next node to NULL 
			reference->prev_node->next_node = NULL;
			
			// Set the current tail_node's next_node to eb the new head_node
			this->tail_node = reference->prev_node;
			
			// delete the previous head node 
			delete reference;
		}
	
		void print_list(){
			
			dllist_node<T>* curr_node = this->head_node;
			
			std::cout << "List values: ";
			while( curr_node != NULL ){
			
				std::cout << curr_node->data << " ";
				
				curr_node = curr_node->next_node;
			
			}
			std::cout << std::endl;
		}
		
};
 
#endif