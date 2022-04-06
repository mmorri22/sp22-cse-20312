#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define COUT std::cout 
#define ENDL std::endl
#define VECTOR std::vector 
#define SET std::set
#define SIZE_T long unsigned int

void print_set( const SET< std::pair<int, int> >& print_set ){
	
	for( std::pair<int, int> curr_pair : print_set ){
		
		COUT << curr_pair.first << " " << curr_pair.second << ENDL;
		
	}
}

int main( const int argc, const char* argv[] )
{
    
	SET< std::pair<int, int> > all_pairs;
	
	for( int iter = 1; iter < argc; iter += 2 ){
		
		std::pair<int, int> temp_pair;
		
		temp_pair.first = atoi( argv[iter] );
		temp_pair.second = atoi( argv[iter + 1] );
		
		all_pairs.insert( temp_pair );
	}
	
	print_set( all_pairs );
	
	return EXIT_SUCCESS;
}