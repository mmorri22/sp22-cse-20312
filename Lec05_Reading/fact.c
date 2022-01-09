#include <stdio.h>
#include <stdlib.h>

double factorial( int fact_num ){
	
	if( fact_num == 1 )
		return 1;
	
	return (double)fact_num * factorial( fact_num - 1 );
	
}

int main( const int argc, const char* argv[] ){
	
	if( argc != 2 ){
	
		fprintf( stderr, "Incorrect Number of inputs\n" );
		
		return EXIT_FAILURE;
		
	}
	
	int fact_num = atoi( argv[1] );
	
	fprintf( stdout, "%d! = %lf\n", fact_num, factorial( fact_num ) );
	
	return EXIT_SUCCESS;
	
}