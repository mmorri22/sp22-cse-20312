/**********************************
 * File name: dll_test_sol.cpp 
 * Author: Matthew Morrison 
 * Email: matt.morrison@nd.edu 
 *
 * This file contains the main driver function solution
 * for the in-class coding opportunity for Lecture 12
 ************************************/
 
#include <iostream>
#include <cstdlib>
#include "dllist_sol.h"

#define COUT std::cout
#define ENDL std::endl
 
int main( const int argc, const char* argv[] ){
	 
	if( argc < 2 ){
		
		COUT << "Not enough arguments" << ENDL;
		return EXIT_FAILURE;
	}
	
	// Create a new list 
	dllist<int>* back_list = new dllist<int>();
	dllist<int>* front_list = new dllist<int>();
	dllist<int>* sorted_list = new dllist<int>();


	// Code for back list
	for( int iter = 1; iter < argc; ++iter ){
		
		back_list->push_back( atoi(argv[iter]) );
		
	}
	
	// Print the list 
	COUT << "Push Back List : ";
	back_list->print_list();
	COUT << ENDL;
	
	while( !back_list->empty() ){
		
		back_list->pop_back();
	}
	
	
	// Code for Front list
	for( int iter = 1; iter < argc; ++iter ){
		
		front_list->push_front( atoi(argv[iter]) );
		
	}
	
	// Print the list 
	COUT << "Push Front List: ";
	front_list->print_list();
	COUT << ENDL;
	
	while( !front_list->empty() ){
		
		front_list->pop_front();
	}
	
	
	// Code for the Sorted List
	for( int iter = 1; iter < argc; ++iter ){
		
		sorted_list->insert_sort( atoi(argv[iter]) );
	}
	
	COUT << "Sorted List    : ";
	// Print the list 
	sorted_list->print_list();
	COUT << ENDL;
	
	// delete the lists
	delete sorted_list;
	delete front_list;	
	delete back_list;

	return EXIT_SUCCESS;
}