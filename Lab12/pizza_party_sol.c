#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library


// Step 3 - Part 1 - Define the mutex Lock 
pthread_mutex_t Lock = PTHREAD_MUTEX_INITIALIZER;

// Step 3 - Part 2 - Define the Thread Function Input Arguments 
typedef struct thread_func_args{
	
	pthread_t curr_tid;
	int kid_id;
	int curr_slices;
	int* pizza_ptr;
	
}thread_func_args;


// Thread Function 
void* thread_func( void* inputs ){
	
	// Step 3 - Part 3 - Cast the void* back to a struct pointer inside the function
	thread_func_args* func_inputs = (thread_func_args *)inputs;	
	
	// Step 3 - Part 4 - Loop while the pizza_ptr input is greater than 0
	while( *(func_inputs->pizza_ptr) > 0  ){
		
		// Step 3 - Part 5 - If the number of pizza slices is zero, break the while loop
		if( *(func_inputs->pizza_ptr) == 0 )
			break;
		
		// Step 3 - Part 6 - Lock the pthread_mutex_lock 
		pthread_mutex_lock(&Lock);
		
		// Step 3 - Part 7 - If the total pizzas is greater than 18, and the user's curr_slices is less than 2
		if( *(func_inputs->pizza_ptr) > 18 && func_inputs->curr_slices < 2 ){
			
			// Create an integer for number of slices that is 2 minus the kid's curr_slices 
			int num_slices = 2 - func_inputs->curr_slices;
			
			// Subtract the number of slices from the total slices of pizza
			*(func_inputs->pizza_ptr) -= num_slices;
			
			// Add the number of slices to the output 
			func_inputs->curr_slices += num_slices;
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate %d slices and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, num_slices, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );
			
		}
		
		/* Step 3 - Part 8 - If the pizza_ptr is less than or equal to 18 AND the pizza_ptr is greater than 3
		 * AND the user's curr_slices is less than 3
		 */
		else if( *(func_inputs->pizza_ptr) <= 18 && *(func_inputs->pizza_ptr) > 3 && func_inputs->curr_slices < 3 ){
			
			// Subtract one from the pizza_ptr
			*(func_inputs->pizza_ptr) -= 1;
			
			// Add one to the curr_slices 
			func_inputs->curr_slices += 1;
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate 1 slice and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );	
			
		}
		
		/* Step 3 - Part 9 - If the pizza_ptr is less than or equal to 3 and the pizza_ptr is greater than 1 */
		else if( *(func_inputs->pizza_ptr) <= 3 && *(func_inputs->pizza_ptr) >= 1 ) {
			
			// Subtract one from the pizza_ptr
			*(func_inputs->pizza_ptr) -= 1;
			
			// Add one to the curr_slices
			func_inputs->curr_slices += 1;
			
			// Print the information to the user 
			fprintf( stdout, "Kid %d ate 1 slice and has eaten %d slices. There are %d total slices remaining.\n",
				func_inputs->kid_id, func_inputs->curr_slices, *(func_inputs->pizza_ptr) );			
			
		}
		
		// Step 3 - Part 10 - Unlock the pthread_mutex_lock 
		pthread_mutex_unlock(&Lock);
		
	}
	
	// Step 3 - Part 11 - return NULL
	return NULL;
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
    thread_func_args** thread_inputs = (thread_func_args**)malloc( num_kids * sizeof(thread_func_args *) );
	
	// Step 4 - Part 2 - Create the parallel threads  
	create_parallel_threads( thread_inputs, num_kids, &pizza_slices );
	
	// Step 4 - Part 3 - Join the parallel threads  
	join_threads( thread_inputs, num_kids );
	
	// Free the thread inputs pointers
	free_threads( thread_inputs, num_kids );
	
	// Free the thread inputs 
	free( thread_inputs );
	
	// Should be the last thing in main before return 0 if using this
	// Ensure main does not end before everything else
	pthread_exit( NULL );
		
	return EXIT_SUCCESS;
}