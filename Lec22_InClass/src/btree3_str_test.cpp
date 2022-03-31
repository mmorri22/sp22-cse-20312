#include "../include/btree.h"

#include <string>
#define STRING std::string

int main( const int argc, const char* argv[] ){
	
	btree< STRING > tree_order_4(4);
	
	for( int iter = 1; iter < argc; ++iter ){
		
		tree_order_4.insert( argv[iter] );
		tree_order_4.print_tree();		
	}
	
	return EXIT_SUCCESS;
};
