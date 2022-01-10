#include "SortSearch.h"

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
		
		// Create tempArray
		int* arrayTemp = (int *)malloc( sizeof(int) * (long unsigned int)( max - min ) );
		int arrayIter = 0;
		
		while( start1 <= (min + max) / 2 && start2 <= max ){
			
			if( array[start1] >= array[start2] ){
				
				arrayTemp[arrayIter] = array[start2];
				start2++;
				
			}
			else{
				
				arrayTemp[arrayIter] = array[start1];
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
		
	}

}

int ReadArray(int array[], int maxSize) 
{
  int iter = 0, value ;

  /* The priming read */
  fscanf (stdin, "%d", &value);

  while (value != SENTINEL)
  {
     if (iter == maxSize) 
     {
        return(-1) ;
     }
     array[iter] = value ;
     iter++ ;

     fscanf (stdin, "%d", &value);
  }
  return iter ;
}


int GetValidInt(){
	
	int value;
		
	fscanf( stdin, "%d", &value );
	
	return value;
}


int FindElement( int array[], unsigned int arrayLen, int searchVal  ){
	
	int low = 0;
	int high = (int)arrayLen - 1;
	int middle = ( high + low ) / 2;
	
	bool found = false;
	
	while( !found && high > low ){
		
		middle = ( high + low ) / 2;
		
		fprintf( stdout, "Low = %d, Middle = %d, High = %d\n", low, middle, high );
		
		if( array[middle] == searchVal ){
			
			found = true;
			
			fprintf( stdout, "Found at %d\n", middle );
			
			continue;
		}
		else if( array[middle] > searchVal ){
			
			high = middle - 1;
		}
		else if( array[middle] < searchVal ) {
			
			low = middle + 1;
		}
		
	}
	
	// Check the new high and low
	if( array[high] == searchVal )
		return high;
		
	if( array[low] == searchVal )
		return low;
	
	// Otherwise, it was a found middle element
	if( found ){
		return middle;
	}
	
	// Was not found
	else{
		
		return SENTINEL;
	}
}
