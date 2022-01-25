#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ){

	/* The first part is identical to argc_argv_2.c */
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
	
	/* New code to allocate and free to combine concepts for the MIND */
	long unsigned int array_len = 5;
	char* notre = (char *)malloc( array_len * sizeof(char) );
	notre[0] = 'N';
	notre[1] = 'o';
	notre[2] = 't';
	notre[3] = 'r';
	notre[4] = 'e';
	
	fprintf( stdout, "char* notre = %s, &notre = %p, notre = %p\n", 
		notre, &notre, (void *)( notre + 0*sizeof(char) ) );
	
	long unsigned int iter_2;
	for( iter_2 = 0; iter_2 < array_len; ++iter_2 ){
		
		fprintf( stdout, "notre[iter_2] = '%c', &notre[iter_2] = %p, notre[iter_2] = %p\n",
			notre[iter_2], &notre[iter_2], (void *)( notre + iter_2*sizeof(char) ) );
		
	}
	
	free( notre );

	return 0;

}


