#include <stdio.h>

int main( int argc, char** argv ){

	fprintf( stdout, "argc    = %15d,\t&argc    = %p\n", argc, &argc );
	
	fprintf( stdout, "&argv   = %p,\targv = %p\n", &argv, argv );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d] = %15s,\t&argv[%d] = %p, argv[%d] = %p\n", 
			iter, argv[iter], iter, &argv[iter], iter, argv[iter] );
		
		int jter;
		for( jter = 0; argv[iter][jter] != '\0'; ++jter ){
			
			fprintf( stdout, "argv[%d][%d] = %c,\t&argv[%d][%d] = %p\n", 
				iter, jter, argv[iter][jter], iter, jter, &argv[iter][jter] );
		}

	}

	return 0;

}


