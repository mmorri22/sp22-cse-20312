#include <stdio.h>
#include <stdlib.h>

void printArray( const int* the_array, long unsigned int array_len );

int* solveArray( const int* the_array, long unsigned int array_len );

void runSolution( int* the_array, long unsigned int array_len );


void printArray( const int* the_array, long unsigned int array_len ){
	
	fprintf( stdout, "[" );
	
	long unsigned int iter;
	for(iter = 0; iter < array_len; ++iter){
		
		fprintf( stdout, "%d ", the_array[iter] );
		
		if( iter < array_len - 1 ){
			
			fprintf( stdout, ",");
		}
	}
	
	fprintf( stdout, "]" );
	
}



void runSolution( int* the_array, long unsigned int array_len ) {
	
	// Print the Initial Input
	fprintf( stdout, "Input : " );
	printArray( the_array, array_len );
	fprintf( stdout, "\n" );

	// Run the Solution and Print the Output
	fprintf( stdout, "Output: " );
	printArray( solveArray( the_array, array_len ), array_len );
	fprintf( stdout, "\n\n" );	
	
}


int* solveArray( const int* the_array, long unsigned int array_len ){
	

	// Create an array to store the solution that is the same size as the_array
	int* solution = (int *)malloc( array_len * sizeof( int ) );
	
	// Set solution's initial value equal to 1
	solution[0] = 1;
	
	// Forward Iteration starting at 1 and go through all the elements
	long unsigned int iter;
	for(iter = 1; iter < array_len; ++iter){
		
		// The solution at the iter value is the solution at iter - 1 times 
		// the_array at iter - 1 
		solution[iter] = solution[iter - 1] * the_array[iter - 1];
	
	}
	
	// Create a temp variable to go backward equal to 1
	int tempBackward = 1;
	
	// Reverse Iteration starting at the_array.size() -1 and go through all the elements
	// Note: Be sure to do iter > 0, or else you will get an infinite loop!
	for(iter = array_len - 1; iter > 0; --iter){
		
		// Multiple the temp variable *= the_array at iter's value
		tempBackward *= the_array[iter];
		
		// Multiple the solution at iter - 1 by the temp variable
		solution[iter - 1] *= tempBackward;
		
	}
	
	// Return the solution vector
	return solution;
	
}


int main( const int argc, const char* argv[] ){
	
	if( argc < 2 ){
		
		fprintf( stdout, "Incorrect number of inputs\n" );
		
		return EXIT_FAILURE;
	}
	
	long unsigned int array_len = (long unsigned int)( argc - 1 );
	
	int* the_array = (int *)malloc( array_len * sizeof(int) );
	
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array[ iter - 1] = temp;
	}
	
	runSolution(the_array, array_len);
	
	free( the_array );
	
	return EXIT_SUCCESS;
}
