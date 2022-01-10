#include <stdio.h>
#include <stdlib.h>

#define length1 8
#define length2 9

void printArray(int* array, int length){
	
	for(int iter = 0; iter < length; iter++){
		
		fprintf( stdout, "%d ", *(array + iter) );
		
	}
	
	fprintf( stdout, "\n" );
}



void merge( int* array, int min, int max ){
	
	if( max > min + 1 ){
		
		merge( array, min, (min + max)/2 );
		
		merge( array, (min + max)/2 + 1, max );
	}
	
	/* If min == max, no need to sort. Same element */
	if( min == max )
		return;
	
	/* sort Sub Array */
	else if( max == min + 1 && array[max] < array[min] ){
		
		fprintf( stdout, "Swapping array positions %d and %d\n", min, max );
		
		int temp = array[max];
		array[max] = array[min];
		array[min] = temp;
	}
}


int main(){
	
	/* Array of even length */
	int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};
	
	/* Array of odd length */
	int array2[length2] = {14, 99, 42, 77, 2, 66, 1, 8, 44};
	
	/* Print the initiali arrays */
	fprintf( stdout, "Initial Array 1: " );
	printArray(array1, length1);
	
	merge( array1, 0, length1 - 1 );
	
	fprintf( stdout, "Final Array 1: " );
	printArray(array1, length1);
	
	fprintf( stdout, "\n---------------------\n");
	
	fprintf( stdout, "Initial Array 2: " );
	printArray(array2, length2);
	
	merge( array2, 0, length2 - 1 );
	
	fprintf( stdout, "Final Array 2  : " );
	printArray(array2, length2);
	
	return 0;
	
}