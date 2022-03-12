#include "../include/btree.h"
#include <cstdlib>	// For atoi 
#include <ctime> // for time(0)

int main( const int argc, const char* argv[] ){
	
	if( argc != 4 )
		return EXIT_FAILURE;
	
	SIZE_T degree = atoi( argv[1] );
	
	btree< long int > test_tree( degree );
	
	SIZE_T num_elements = atol( argv[2] );
	
	// ASCII to long int uses atol instead of atoi
	long int range = atol( argv[3] );
	
	srand( (unsigned int)time(0) );
	
	for( SIZE_T iter = 0; iter < num_elements; ++iter ){
		
		long int insert_val = (long int)rand() % range;
		
		if( iter % 2 == 1 )
			insert_val *= iter;
		
		test_tree.insert( insert_val );
		//test_tree.print_tree();
	}
	
	COUT << "Final In-Order Traversal of B-Tree" << ENDL;
	test_tree.print_tree();	
	COUT << ENDL;
	
	return EXIT_SUCCESS;
};