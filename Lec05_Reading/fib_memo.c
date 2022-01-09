#include <stdio.h>
#include <stdlib.h>

double Fibonacci( int fib_num, double* fib_nums ){
	
	if( fib_nums[fib_num] != 0 )
		return fib_nums[fib_num];
	
	if( fib_num == 0 ){
		fib_nums[0] = 1;
	}
	
	else if( fib_num == 1 ){
		fib_nums[1] = 1;
	}
	
	else{
		fib_nums[fib_num] = Fibonacci( fib_num - 1, fib_nums ) + Fibonacci( fib_num - 2, fib_nums );
	}
	
	return fib_nums[fib_num];
	
}

int main( const int argc, const char* argv[] ){
	
	if( argc != 2 ){
	
		fprintf( stderr, "Incorrect Number of inputs\n" );
		
		return EXIT_FAILURE;
		
	}
	
	int fib_num = atoi( argv[1] );
	
	double* fib_nums = (double *)malloc( (long unsigned int)fib_num * sizeof( double ) );
	
	int iter;
	for( iter = 0; iter < fib_num; ++iter ){
		
		fib_nums[iter] = 0;
	}
	
	fprintf( stdout, "The %d Fib Number is = %lf\n", fib_num, Fibonacci( fib_num - 1, fib_nums ) );
	
	free( fib_nums );
	
	return EXIT_SUCCESS;
	
}