#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length1 8
#define length2 9

void printArray(int* array, int length){

    int iter;
    for(iter = 0; iter < length; ++iter){

        fprintf( stdout, "%d ", *(array + iter) );
    }

    fprintf( stdout, "\n" );
}


void shuffle(int *array, int array_len)
{
    if (array_len > 1)
    {
        int iter;
        for (iter = 0; iter < array_len - 1; ++iter)
        {
            int denominator = RAND_MAX / (array_len - iter) + 1;
            int jter = iter + (int)rand() / denominator;

            // Swap the values at iter and jter
            int temp = array[jter];
            array[jter] = array[iter];
            array[iter] = temp;
        }
    }
}

void exchange( int* array, int a, int b){

    fprintf( stdout, "Exchanging %d and %d\n", *(array + a), *(array + b) );

    int temp = *(array + a);
    *(array + a) = *(array + b);
    *(array + b) = temp;

}

int partition(int* array, int lo, int hi ) {
    int pivot = lo;
    int i = pivot + 1;
    int j = hi;

    // Get low value to improve run time
    int pivot_value = *(array + pivot);

    fprintf( stdout, "pivot = %d, left = %d, right = %d\n", pivot_value, array[i], array[j] );

    // Go until we break
    while ( 1 ) {

        // find item on lo to swap
        while ( array[i] < pivot_value ) {
            if (i == hi)
				        break;

            ++i;
			      fprintf( stdout, "left is moved to array[%d] with value %d\n", i, array[i] );
        }

        // find item on hi to swap
        while ( pivot_value < array[j] ) {
            if (j == lo)
				        break;      // redundant since a[lo] acts as sentinel

			     --j;
           fprintf( stdout, "right is moved to array[%d] with value %d\n", j, array[j] );

        }

        // check if pointers cross
        if (i >= j)
			     break;

        // Otherwise, exchange he values
        exchange(array, i, j);
    }

    // put partitioning item v at a[j]
    if( lo != j)
      exchange(array, lo, j);

    // now, a[lo .. j-1] <= a[j] <= a[j+1 .. hi]
    return j;
}

// quicksort the subarray from a[lo] to a[hi]
void quick_sort_recursive(int* array, int lo, int hi, int array_len ) {

    fprintf( stdout, "low = %d, high = %d\n", lo, hi );

    /* Base Case */
    if (hi <= lo)
        return;

    if( hi == lo + 1 ){

      if( array[hi] < array[lo] )
        exchange(array, lo, hi);
    }


    /* Recursive Case */
    int j = partition(array, lo, hi);
    fprintf( stdout, "partition = %d, lo = %d, hi = %d\n", j, lo, hi);

    fprintf( stdout, "Array After Partition : " );
    printArray(array, array_len);

    quick_sort_recursive(array, lo, j-1, array_len);
    quick_sort_recursive(array, j+1, hi, array_len);
}

void quick_sort(int* array, int array_len) {

    fprintf( stdout, "Initialize the Quick Sort...\n");
    quick_sort_recursive(array, 0, array_len - 1, array_len);
}

int main( const int argc, const char* argv[] )
{

    /* Seed the random number generator */
    srand( (unsigned int)time(0) );

    long unsigned int array_len = (long unsigned int)(argc - 1);

    int* array = (int *)malloc( array_len * sizeof(int) );

    int iter;
    for( iter = 1; iter < argc; ++iter){

        /* Convert and store input values */
        array[ iter - 1 ] = atoi( argv[iter] );

    }

    /* Print the initiali arrays */
    fprintf( stdout, "Initial Array  : " );
    printArray(array, argc - 1);

    shuffle( array, argc - 1 );

    fprintf( stdout, "Shuffled Array : " );
    printArray(array, argc - 1);

    quick_sort(array, argc - 1);
    fprintf( stdout, "Sorted Array   : " );
    printArray(array, argc - 1);

    fprintf( stdout, "\n");
    /* Free the array */
    free( array );

    return 0;
}
