#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	
	// Step 1 - Size
	long unsigned int size;
	
	// Step 2 - Capacity
	long unsigned int capacity;
	
	// Step 3 - Integer Pointer
	int* the_vec;
	
} vector;


// Step 6 - Create a function "constructor" which allocates the vector 
void constructor( vector* int_vector ){
	
	// 6-1 Set size and capacity to 0
	int_vector->size = 0;
	int_vector->capacity = 0;
	
	// 6-2 Set the integer array pointer to NULL
	int_vector->the_vec = NULL;
	
}

// Step 8 - Create a function "destructor" which frees the int pointer 
void destructor( vector* int_vector ){
	
	// 8-1 Dr. Morrison's Golden Rule of Pointers 
	if( int_vector->the_vec != NULL )
		
		// Free the integer array
		free( int_vector->the_vec );
	
}

// Step 10 - Insertion
void insert( vector* int_vector, int value ){
	
	// 10-1 Dr. Morrison's Golden Rule of Pointers 
	if( int_vector->the_vec == NULL ){
		
		// Allocate an array of one integer 
		int_vector->the_vec = (int *)malloc( sizeof(int) );
		
		// Set the capacity to 1
		int_vector->capacity = 1;
		
	}
	
	// Next, check if the size is equal to the capacity 
	if( int_vector->size == int_vector->capacity ){
		
		// If so, we need to reallocate 
		// First, multiply the capacity by 2
		int_vector->capacity *= 2;
		
		// Then we need to create a pointer to the current array 
		int* temp = int_vector->the_vec;
		
		// Allocate a new vector that is size of the capacity 
		int_vector->the_vec = (int *)malloc( int_vector->capacity * sizeof(int) );
		
		// Iterate through the array and copy the old values to the new values 
		long unsigned int iter;
		for( iter = 0; iter < int_vector->size; ++iter ){
			
			int_vector->the_vec[iter] = temp[iter];
			
		}
		
		// Finally, free the old array 
		free( temp );
		
	}
	
	// Insert the element at the location of size 
	int_vector->the_vec[ int_vector->size ] = value;
	
	// And increment the size 
	++(int_vector->size);
}


// Step 12 - Print the vector 
void print( vector* int_vector ){
	
	fprintf( stdout, "--------------------------\n" );
	fprintf( stdout, "Vector Size = %lu, Capacity = %lu\n", 
			int_vector->size, int_vector->capacity);
	
	long unsigned int iter;
	for( iter = 0; iter < int_vector->size; ++iter ){
		
		fprintf( stdout, "%d %p\n", 
			int_vector->the_vec[iter], &(int_vector->the_vec[iter]) );
		
	}
	
}

int main(){
	
	
	// Step 4 - Dynamically Allocate the Struct 
	vector* int_vector = (vector *)malloc( sizeof( vector ) );
	
	// Step 7 - Call the Constructor
	constructor( int_vector );
	
	// Loop and increment the vector size
	char char_continue = 'y';
	while( char_continue == 'y' ){
		
		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		// Pass By Reference Function 
		insert( int_vector, read_int );
		
		// Print function 
		print( int_vector );

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &char_continue );		
		
	}
	
	// Step 9 - Call the Destructor
	destructor( int_vector );
	
	// Step 5 - Call free on the vector 
	free( int_vector );
	
	return 0;
}