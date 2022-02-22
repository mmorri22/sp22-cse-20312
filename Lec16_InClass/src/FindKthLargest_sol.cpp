#include "../include/min_heap.h" 

#include <iostream>
#include <cstdlib>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void findKthLargest( void* unsorted, min_heap< T >& heap, int kTh, int length ){
	
	if( kTh > length ){
		
		COUT << kTh << " exceeds the array length of " << length << ENDL;
	}
	
	for( int iter = 0; iter < kTh; iter++ ){
	
		// In C++, you can call the std::vector by reference
		// I am only doing void * and de-referencing to review
		// for students that, ultimately, it's all cast void pointers	
		heap.push( *((int *)unsorted + iter ) );
	}
	
	for( int iter = kTh; iter < length; iter++ ){
		
		if( *((int *)unsorted + iter ) > heap.top() ){
			
			heap.pop();
			heap.push( *((int *)unsorted + iter ) );
		}
	}
	
	COUT << "The " << kTh << "-th largest element is " << heap.top() << ENDL;
}

int main() {
	
	
	// Create an array of 12 unsorted elements 
	// Using void* to review procedural programming
	void* unsorted = malloc( 12 * sizeof( int ) );
	
	// Insert 12 values 
	*((int *)unsorted) = 22;
	*((int *)unsorted + 1) = 44;
	*((int *)unsorted + 2) = 1;
	*((int *)unsorted + 3) = -33;
	*((int *)unsorted + 4) = 405;
	*((int *)unsorted + 5) = 9;
	*((int *)unsorted + 6) = 1842;
	*((int *)unsorted + 7) = 16;
	*((int *)unsorted + 8) = 99;
	*((int *)unsorted + 9) = -16;
	*((int *)unsorted + 10) = 207;
	*((int *)unsorted + 11) = 14;
	
	COUT << "Pre-Sorted: ";
	for( long unsigned int iter = 0; iter < 12; iter++ ){
		
		COUT << *((int *)unsorted + iter) << " ";
	}
	COUT << ENDL;
	
	// Create a MinHeap with a Default Constructor
	min_heap< int > heap1;

	findKthLargest( unsorted, heap1, 1, 12 );
	findKthLargest( unsorted, heap1, 2, 12 );	
	findKthLargest( unsorted, heap1, 3, 12 );
	findKthLargest( unsorted, heap1, 4, 12 );
	findKthLargest( unsorted, heap1, 5, 12 );
	findKthLargest( unsorted, heap1, 6, 12 );
	findKthLargest( unsorted, heap1, 7, 12 );
	findKthLargest( unsorted, heap1, 8, 12 );
	findKthLargest( unsorted, heap1, 9, 12 );
	findKthLargest( unsorted, heap1, 10, 12 );
	findKthLargest( unsorted, heap1, 11, 12 );
	findKthLargest( unsorted, heap1, 12, 12 );
	
	return 0;
	
}
