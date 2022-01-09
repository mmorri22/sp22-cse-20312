#include <stdio.h>
#include <stdlib.h>

int main( void ){

	FILE* the_input = fopen( "test.txt", "r" );

	// Remember Dr. Morrison's Golden Rule of Pointers
	if( the_input == NULL ){
		fprintf( stderr, "When NULL, the_input = %p\n", the_input );
		fprintf( stderr, "stderr is at %p\n", stderr );
		fprintf( stderr, "stdout is at %p\n", stdout );
		exit( EXIT_FAILURE );
	}

	fclose( the_input );

	return EXIT_SUCCESS;

}
