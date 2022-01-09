#include <iostream>	// C++ equivalent of #include <stdio.h>
#include <cstdlib>	// C++ equivalent of #include <stdlib.h>
#include <vector>	// C++ Library for Dynamic Arrays
#include <string>	// C++ Library for char**

#define NUMSTRS 4

void init_values( std::vector< std::string >& str_vector ){
	
	str_vector.at(0) = "Notre";
	str_vector.at(1) = "Dame";
	str_vector.at(2) = "Fighting";
	str_vector.at(3) = "Irish";
	
}

void print_vector( const std::vector< std::string >& str_vector ){
	
	if( str_vector.size() == 0 )
		return;
	
	for( long unsigned int iter = 0; iter < str_vector.size(); ++iter ){
	
		std::cout << str_vector.at( iter ) << " ";
	
	}
	
	std::cout << std::endl;
	
}


void borrow_from_next( std::vector< std::string >& str_vector ){
	
	str_vector.erase ( str_vector.begin() + 0 );
	
}

int main( void ){
	
	// Create an array of array of strings of length NUMSTRS
	std::vector< std::string > str_vector( NUMSTRS );
	
	// Pass the values to the string 
	init_values( str_vector );
	
	// Print the initial value 
	print_vector( str_vector );
	
	// Iterate through
	while( str_vector.size() > 0 ){
		borrow_from_next( str_vector );
		print_vector( str_vector );
	}
	
	// std::string automatically frees all strings 
	// std::vector automatically frees all vectors 
	
	return 0;
}