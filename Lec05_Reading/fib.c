#include <stdio.h>
#include <stdlib.h>

double Fibonacci( int fib_num ){
	
	if( fib_num == 0 )
		return 1;
	
	if( fib_num == 1 )
		return 1;
	
	return Fibonacci( fib_num - 1 ) + Fibonacci( fib_num - 2 );
	
}

int main( const int argc, const char* argv[] ){
	
	if( argc != 2 ){
	
		fprintf( stderr, "Incorrect Number of inputs\n" );
		
		return EXIT_FAILURE;
		
	}
	
	int fib_num = atoi( argv[1] );
	
	fprintf( stdout, "The %d Fib Number is = %lf\n", fib_num, Fibonacci( fib_num - 1 ) );
	
	return EXIT_SUCCESS;
	
}