#include <stdio.h>
#include <stdlib.h>


// Deliberately removing const because of input manipulation 
int main( int argc, char* argv[] ){
	
	fprintf( stdout, "Initial locations and values:\n" );
	
	fprintf( stdout, "argc: %p %d\n", &argc, argc );
	
	fprintf( stdout, "argv: %p %p\n", &argv, argv );

	while( argv[1] != NULL ){
		
		fprintf( stdout, "argv[1]: %p %p %p %p %s\n", &argv, argv, &argv[1], argv[1], argv[1] );
		
		argv = argv + 1;
		
	}
	
	
	return EXIT_SUCCESS;
}