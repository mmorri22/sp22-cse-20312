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
	
	/* Sort Sub Array */
	else if( max == min + 1 && array[max] < array[min] ){
		
		int temp = array[max];
		array[max] = array[min];
		array[min] = temp;
	}
	
	/* Subarray longer than two elements */
	else{
		
		int start1 = min;
		int start2 = (min + max) / 2 + 1;
		
		fprintf( stdout, "Min = %d, Mid = %d, Max = %d\n", start1, start2, max );
				
		fprintf( stdout, "Initial Subarray: ");
		for(int iter = min; iter <= max; iter++ ){
			
			fprintf( stdout, "%d ", array[iter] );
		}
		fprintf( stdout, "\n" );
		
		// Create tempArray
		int* arrayTemp = (int *)malloc( sizeof(int) * (long unsigned int)( max - min ) );
		int arrayIter = 0;
		
		while( start1 <= (min + max) / 2 && start2 <= max ){
			
			if( array[start1] >= array[start2] ){		
				
				arrayTemp[arrayIter] = array[start2];	// Put array[start2] in the temp
				start2++;
			}
			else{
				
				arrayTemp[arrayIter] = array[start1];	// Put array[start1] in the temp
				start1++;
			}
			arrayIter++;
		}
		
		/* Add on if start1 didn't reach the midpoint */
		while( start1 <= (min + max) / 2 ){
			
				arrayTemp[arrayIter] = array[start1];
				start1++; arrayIter++;
				
		}

		/* Add on if start2 didn't reach the max */
		while( start2 <= max ){
			
				arrayTemp[arrayIter] = array[start2];
				start2++; arrayIter++;
				
		}
		
		/* Overwrite the subarray with the temp array */
		for(int updateIter = 0; updateIter < arrayIter; updateIter++){
			
			array[min + updateIter] = arrayTemp[updateIter];
			
		}
		
		fprintf( stdout, "Sorted Subarray: ");
		for(int iter = min; iter <= max; iter++ ){
			
			fprintf( stdout, "%d ", array[iter] );
		}
		fprintf( stdout, "\n" );
		
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