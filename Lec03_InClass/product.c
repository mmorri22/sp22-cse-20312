#include <stdio.h>
#include <stdlib.h>


void printArray( int* print_array, long unsigned int length ){

	fprintf( stdout, "[");

	long unsigned int iter;
	for(iter = 0; iter < length; ++iter){

		fprintf( stdout, " %d", *(print_array + iter) );

		if( iter < length - 1 ){
			fprintf( stdout, ",");
		}
	}

	fprintf( stdout, " ]");

}


int* solveArray( int* int_array, long unsigned int length ){

	int* solution_array = (int *)malloc( length * sizeof(int) );

	// Set solution's initial value equal to 1
	solution_array[0] = 1;

	// Forward Iteration starting at 1 and go through all the elements
	long unsigned int iter;
	for(iter = 1; iter < length; ++iter){

		// The solution at the iter value is the solution at iter - 1 times
		// the_array at iter - 1
		solution_array[iter] = solution_array[iter - 1] * int_array[iter - 1];
	}

	// Create a temp variable to go backward equal to 1
	int tempBackward = 1;

	// Reverse Iteration starting at the_array.size() -1 and go through all the elements
	// Note: Be sure to do iter > 0, or else you will get an infinite loop!
	for(iter = length - 1; iter > 0; --iter){

		// Multiple the temp variable *= int_array at iter's value
		tempBackward *= int_array[ iter ];

		// Multiple the solution_array at iter - 1 by the temp variable
		solution_array[iter - 1] *= tempBackward;
	}

	// Return the solution array pointer
	return solution_array;

}

void runSolution( int* int_array, long unsigned int length ) {

	// Print the Initial Input
	fprintf( stdout, "Input : " );
	printArray( int_array, length );
	fprintf( stdout, "\n" );

	int* solution_array = solveArray( int_array, length );

	// Run the Solution and Print the Output
	fprintf( stdout, "Output : " );
	printArray( solution_array, length );
	fprintf( stdout, "\n" );

	free( solution_array );

}



int main( const int argc, const char* argv[] ){

	if( argc < 2 ){
		fprintf( stdout, "Cannot process 0 length vector\n" );
		exit( EXIT_FAILURE );
	}

	int* input_array = (int *)malloc( (long unsigned int)(argc - 1) * sizeof(int) );

	int iter;
	for( iter = 1; iter < argc; ++iter ){

		int temp = atoi( argv[iter] );

		input_array[ iter - 1] = temp;
	}

	runSolution( input_array, (long unsigned int)(argc - 1) );

	free( input_array );

	return EXIT_SUCCESS;
}
