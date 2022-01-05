#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ){

	/* Seed the random number generator */
	srand( time(0) );

	int val;
	for ( val = 0; val < 10; ++val ){
		fprintf( stdout, "%d\n", rand() );
	}

	return 0;
}


