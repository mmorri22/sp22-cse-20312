/**********************************
 * File name: queue_sol.h 
 * Author: Matthew Morrison 
 * Email: matt.morrison@nd.edu 
 *
 * This file contains the class definition solution
 * for the templated queue we will co-develop in class
 ************************************/
 
#ifndef QUEUE_SOL_H
#define QUEUE_SOL_H

#include "dllist_sol.h"

template< typename T >
struct queue{
	
	private:
	
		dllist<T>* internal_list;
		
	public:
	
		queue<T>() : internal_list( new dllist<T>() ) {}
		
		~queue<T>(){
			
			delete internal_list;
			
		}
		
		void push( const T& insert_val ){
			
			internal_list->push_back( insert_val );
		}
	
		void pop( ){
			
			internal_list->pop_front( );
		}	
		
		T front(){
			
			return internal_list->front();
		}
		
		T back(){
			
			return internal_list->back();
		}
		
		bool empty(){
			
			return internal_list->empty();
		}
};


#endif