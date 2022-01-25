#include <stdio.h>
#include <stdlib.h>

void print_inputs( int argc, char* argv[] ){

	fprintf( stdout, "argc = %d\n", argc );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d] = %s\tat %p\n", 
				iter, argv[iter], &argv[iter] );

	}

}

int main( int argc, char* argv[] ){

	fprintf( stdout, "Initial argc: %d\n", argc );

	print_inputs( argc, argv );

	argc += 1;
	print_inputs( argc, argv );

	return 0;
}
