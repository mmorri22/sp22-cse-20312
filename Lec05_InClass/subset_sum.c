#include <stdio.h>
#include <stdlib.h>
 
int subset_sum(int* array, int array_len, int sum){
    
	// return true if the sum becomes 0 (subset found)
    if (sum == 0) {
        return 1;
    }
 
    if (array_len < 0 || sum < 0) {
        return 0;
    }
 
    int include = subset_sum(array, array_len - 1, sum - array[ array_len ]);
	
	if( include ==  1 )
		return include;
 
    int exclude = subset_sum(array, array_len - 1, sum);
 
    return exclude;
}
 
 
void run_solution( int array[], int array_len, int sum ){
	
	fprintf( stdout, "\nChecking for subset sum for %d...\n", sum );
 
    if ( subset_sum(array, array_len - 1, sum) ) {
        fprintf( stdout, "Subsequence with the given sum %d exists\n", sum );
    }
    else {
        fprintf( stdout, "Subsequence with the given sum %d does not exist\n", sum );
    }
	
}
 
// Subset Sum Problem
int main( )
{
    // Input: a set of items and a sum
    int array[] = { 7, 3, 2, 5, 8 };
    int array_len = 5;
 
	fprintf( stdout, "Array = {" );
	int iter;
	for( iter = 0; iter < array_len; ++iter ){
		
		fprintf( stdout, "%d ", array[iter] );
	}
	fprintf( stdout, "}\n" );
	
	run_solution( array, array_len, 14 );
	run_solution( array, array_len, 6 );
	run_solution( array, array_len, 4 );
	run_solution( array, array_len, 20 );
	run_solution( array, array_len, 19 );
	run_solution( array, array_len, 25 );
	run_solution( array, array_len, 26 );
 
    return EXIT_SUCCESS;
}