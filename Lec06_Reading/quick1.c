#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length1 8
#define length2 9

void printArray(int* array, long unsigned int length){

    long unsigned int iter;
    for(iter = 0; iter < length; ++iter){

        fprintf( stdout, "%d ", *(array + iter) );
    }

    fprintf( stdout, "\n" );
}


void shuffle(int *array, long unsigned int array_len)
{
    if (array_len > 1)
    {
        long unsigned int iter;
        for (iter = 0; iter < array_len - 1; ++iter)
        {
          long unsigned int denominator = RAND_MAX / (array_len - iter) + 1;
          long unsigned int jter = iter + (long unsigned int)rand() / denominator;

            // Swap the values at iter and jter
            int temp = array[jter];
            array[jter] = array[iter];
            array[iter] = temp;
        }
    }
}

int main()
{

    /* Seed the random number generator */
    srand( (unsigned int)time(0) );

    /* Array of even length */
    int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};

    /* Array of odd length */
    int array2[length2] = {14, 99, 42, 77, 2, 66, 1, 8, 44};

    /* Print the initiali arrays */
    fprintf( stdout, "Initial Array 1: " );
    printArray(array1, length1);

    shuffle(array1, length1);
    fprintf( stdout, "Shuffled Array 1: " );
    printArray(array1, length1);

    fprintf( stdout, "Initial Array 2: " );
    printArray(array2, length2);

    shuffle(array2, length2);
    fprintf( stdout, "Shuffled Array 2: " );
    printArray(array2, length2);


    return 0;
}
