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



int main( const int argc, const char* argv[] )
{

    /* Seed the random number generator */
    srand( (unsigned int)time(0) );

    int* array = (int *)malloc( (long unsigned int)(argc - 1) * sizeof(int) );

    int iter;
    for( iter = 1; iter < argc; ++iter){

        /* Convert and store input values */
        array[ iter - 1 ] = atoi( argv[iter] );

    }

    /* Print the initiali arrays */
    fprintf( stdout, "Initial Array  : " );
    printArray(array, argc - 1);

    shuffle( array, array_len );

    fprintf( stdout, "Shuffled Array : " );
    printArray(array, array_len);

    quick_sort(array, argc - 1);
    fprintf( stdout, "Sorted Array   : " );
    printArray(array, argc - 1);

    fprintf( stdout, "\n");
    /* Free the array */
    free( array );

    return 0;
}
