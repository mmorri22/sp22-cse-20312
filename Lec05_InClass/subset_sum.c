#include <stdio.h>
#include <stdlib.h>
 
// Returns true if there exists a subsequence of `A[0…n]` with the given sum
int subset_sum(int* array, int array_len, int sum){
    // return true if the sum becomes 0 (subset found)
    if (sum == 0) {
        return 1;
    }
 
    // base case: no items left, or sum becomes negative
    if (array_len < 0 || sum < 0) {
        return 0;
    }
 
    // Case 1. Include the current item `A[n]` in the subset and recur
    // for the remaining items `n-1` with the remaining total `k-array[n]`
    int include = subset_sum(array, array_len - 1, sum - array[ array_len ]);
	
	// No need to take the right case if we have already found the solution
	if( include ==  1 )
		return include;
 
    // Case 2. Exclude the current item `A[n]` from the subset and recur for
    // the remaining items `n-1`
    int exclude = subset_sum(array, array_len - 1, sum);
 
    // return true if we can get subset by including or excluding the
    // current item. Can do exclude because, if we got here, include must be 0
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