#include "../include/btree.h"
#include <cstdlib>	// For atoi 

int main( const int argc, const char* argv[] ){
	
	btree< int > tree_order_3(3);
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int insert_val = atoi( argv[iter] );
		tree_order_3.insert( insert_val );
		tree_order_3.print_tree();		
	}
	
	return EXIT_SUCCESS;
};