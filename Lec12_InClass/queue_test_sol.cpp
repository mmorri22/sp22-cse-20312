/**********************************
 * File name: queue_test_sol.cpp 
 * Author: Matthew Morrison 
 * Email: matt.morrison@nd.edu 
 *
 * This file contains the main driver function solution
 * for the in-class coding opportunity for Lecture 12
 ************************************/
 
#include <iostream>
#include <cstdlib>
#include "queue_sol.h"

#define COUT std::cout
#define ENDL std::endl
 
int main( const int argc, const char* argv[] ){
	 
	if( argc < 2 ){
		
		COUT << "Not enough arguments" << ENDL;
		return EXIT_FAILURE;
	}
	
	// Create a new list 
	queue<int>* the_queue = new queue<int>();


	// Code for back list
	for( int iter = 1; iter < argc; ++iter ){
		
		the_queue->push( atoi(argv[iter]) );
		
	}
	
	// Print the list 
	COUT << "Push Back List : ";
	
	while( !the_queue->empty() ){
		
		COUT << the_queue->front() << " ";
		
		the_queue->pop();
	}
	COUT << ENDL;
	
	// delete the lists
	delete the_queue;

	return EXIT_SUCCESS;
}