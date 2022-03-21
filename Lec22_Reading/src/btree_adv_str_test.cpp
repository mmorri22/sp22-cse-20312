#include "../include/btree.h"

#include <string>
#include <cstdlib>
#include <fstream>
#define STRING std::string

int main( const int argc, const char* argv[] ){
	
	if( argc != 3 )
		return EXIT_FAILURE;
	
	SIZE_T order = atol( argv[1] );
	
	btree< STRING > str_btree(order);
	
	std::ifstream in_file( argv[2] );
	
	
	STRING in_string;
	
	while( in_file >> in_string ){
	
		str_btree.insert( in_string );
			
	}
	
	COUT << "Final In-Order Traversal of B-Tree" << ENDL;
	str_btree.print_tree();	
	COUT << ENDL;
	
	in_file.close();
	
	return EXIT_SUCCESS;
};