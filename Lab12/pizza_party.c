#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library


// Step 3 - Part 1 - Define the mutex Lock 


// Step 3 - Part 2 - Define the Thread Function Input Arguments 

	
	
	
	
	
	



// Thread Function 
void* thread_func( void* inputs ){
	
// Thread Function 
void* thread_func( void* inputs ){
	
	// Step 3 - Part 3 - Cast the void* back to a struct pointer inside the function
	
	
	// Step 3 - Part 4 - Loop while the pizza_ptr input is greater than 0
	while(   ){
		
		// Step 3 - Part 5 - If the number of pizza slices is zero, break the while loop
		
			
		
		// Step 3 - Part 6 - Lock the pthread_mutex_lock 
		
		
		// Step 3 - Part 7 - If the total pizzas is greater than 18, and the user's curr_slices is less than 2
		if(  ){
			
			// Create an integer for number of slices that is 2 minus the kid's curr_slices 
			
			
			// Subtract the number of slices from the total slices of pizza
			
			
			// Add the number of slices to the output 
			
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate %d slices and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, num_slices, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );
			
		}
		
		/* Step 3 - Part 8 - If the pizza_ptr is less than or equal to 18 AND the pizza_ptr is greater than 3
		 * AND the user's curr_slices is less than 3
		 */
		else if(  ){
			
			// Subtract one from the pizza_ptr
			
			
			// Add one to the curr_slices 
			
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate 1 slice and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );	
			
		}
		
		/* Step 3 - Part 9 - If the pizza_ptr is less than or equal to 3 and the pizza_ptr is greater than 1 */
		else if(  ) {
			
			// Subtract one from the pizza_ptr
			
			
			// Add one to the curr_slices
			
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate 1 slice and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );			
			
		}
		
		// Step 3 - Part 10 - Unlock the pthread_mutex_lock 
		
		
	}
	
	// Step 3 - Part 11 - return NULL
	

}


void create_parallel_threads( thread_func_args** thread_inputs, long unsigned int num_threads, int* main_pizza_ptr ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_threads; ++iter ){
		
		// Note: malloc only allocates the memory, but does not initialize it 
		// Use calloc to initialize the memory to pass valgrind 
		thread_inputs[ iter ] = (thread_func_args*)calloc( 1, sizeof(thread_func_args) );
		
		thread_inputs[ iter ]->curr_slices = 0;
		
		thread_inputs[ iter ]->kid_id = (int)iter;
		
		thread_inputs[ iter ]->pizza_ptr = main_pizza_ptr;

		pthread_create( &(thread_inputs[ iter ]->curr_tid), NULL, thread_func, (void *)(thread_inputs[ iter ]) );
		
	}	
}

void join_threads( thread_func_args** thread_inputs, long unsigned int num_threads ){
	
	long unsigned int iter;
	for ( iter = 0; iter < num_threads; ++iter ) {
		
		pthread_join( thread_inputs[ iter ]->curr_tid,  NULL );
	}	
	
}

void free_threads( thread_func_args** thread_inputs, long unsigned int num_threads ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_threads; ++iter ){
		
		free( thread_inputs[iter] );
	}
	
}

int main( void ){
	
	int pizza_slices = 48;
	
	long unsigned int num_kids = 15;
	
	fprintf( stdout, "Initial Pizza Slices = %d for %ld kids\n", pizza_slices, num_kids );
	
	// Step 4 - Part 1 - Create the thread_inputs 
    
	
	// Step 4 - Part 2 - Create the parallel threads  
	
	
	// Step 4 - Part 3 - Join the parallel threads  
	
	
	// Free the thread inputs pointers
	free_threads( thread_inputs, num_kids );
	
	// Free the thread inputs 
	free( thread_inputs );
	
	// Step 4 - Part 4 - Should be the last thing in main before return 0 if using this
	// Ensure main does not end before everything else
	
		
	return EXIT_SUCCESS;
}