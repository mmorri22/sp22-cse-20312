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


int main(){
	
	/* Array of even length */
	int array1[length1] = {22, 13, 33, 44, -10, 55, 88, 27};
	
	/* Array of odd length */
	int array2[length2] = {14, 99, 42, 77, 2, 66, 1, 8, 44};
	
	/* Print the initiali arrays */
	fprintf( stdout, "Initial Array 1: " );
	printArray(array1, length1);
	
	fprintf( stdout, "Initial Array 2: " );
	printArray(array2, length2);
	
	return 0;
	
}