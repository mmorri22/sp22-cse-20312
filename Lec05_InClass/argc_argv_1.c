#include <stdio.h>

int main( int argc, char** argv ){

	fprintf( stdout, "argc    = %15d,\t&argc    = %p\n", argc, &argc );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d] = %15s,\t&argv[%d] = %p\n", iter, argv[iter], iter, &argv[iter] );

	}

	return 0;

}


