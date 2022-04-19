#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

pthread_mutex_t Lock = PTHREAD_MUTEX_INITIALIZER;

// Step 1 - Create the input thread struct 

	
	
	
	
	



// Step 2 - pass a void pointer to the function, and return a void pointer

	
	// Step 3 - Cast the void* back to a struct pointer inside the function
	
	
	// Step 3-b Brief Intro to Mutual Exclusion
	
	
	
	
	
	
	
	// Add the value to the pointer 
	
	
	
	
	
	// Step 4 - Return NULL
	
}




int main( void ){
	
	// Number of threads 
	long unsigned int num_threads = 5;
	
	// Integer to update 
	int solution = 0;
	
	// Print the address and the initial value of solution
	fprintf( stdout, "%p %d\n", &solution, solution );
	
	// Step 5 - Create a struct with the inputs for the function
    
	
	// Step 6 - Create the 5 parallel threads
	
	
	// Step 7 - Join all 5 threads
	
	
	// Step 8 - Free the memory allocated to the structs
	
	
	// Step 8b - Free the ** struct
	
	
	// Step 9 - Should be the last thing in main before return 0 if using this
	// Ensure main does not end before everything else
	
	
	
	return EXIT_SUCCESS;
}