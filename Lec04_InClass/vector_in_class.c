#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	
	// Step 1 - Size
	
	
	// Step 2 - Capacity
	
	
	// Step 3 - Integer Pointer
	
	
} vector;


// Step 6 - Create a function "constructor" which allocates the vector 

	
	// 6-1 Set size and capacity to 0
	
	
	
	// 6-2 Set the integer array pointer to NULL
	
	


// Step 8 - Create a function "destructor" which frees the int pointer 

	
	// 8-1 Dr. Morrison's Golden Rule of Pointers 
	// Avoid excessive frees 
	
		
		// Free the integer array
		
	


// Step 10 - Insertion

	
	// 10-1 Dr. Morrison's Golden Rule of Pointers 
	
		
		// Allocate an array of one integer 
		
		
		// Set the capacity to 1
		
		
	
	
	// Next, check if the size is equal to the capacity 
	
		
		// If so, we need to reallocate 
		// First, multiply the capacity by 2
		
		
		// Then we need to create a pointer to the current array 
		
		
		// Allocate a new vector that is size of the capacity 
		
		
		// Iterate through the array and copy the old values to the new values 
		
		
			
			
			
		
		
		// Finally, free the old array 
		
		
	
	
	// Insert the element at the location of size 
	
	
	// And increment the size 
	
}


// Print the vector 
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