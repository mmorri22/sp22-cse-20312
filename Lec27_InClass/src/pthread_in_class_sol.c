#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

pthread_mutex_t Lock = PTHREAD_MUTEX_INITIALIZER;

// Step 1 - Create the input thread struct 
typedef struct thread_func_args{
	
	pthread_t curr_tid;
	int input_1;
	int* int_ptr;
	
}thread_func_args;


// Step 2 - pass a void pointer to the function, and return a void pointer
void* thread_func( void* inputs ){
	
	// Step 3 - Cast the void* back to a struct pointer inside the function
	thread_func_args* func_inputs = (thread_func_args *)inputs;
	
	// Step 3-b Brief Intro to Mutual Exclusion
	
	pthread_mutex_lock(&Lock);
	
	fprintf( stdout, "%p %p ", &func_inputs, func_inputs );
	fprintf( stdout, "%p %ld ", &(func_inputs->curr_tid), func_inputs->curr_tid );
	fprintf( stdout, "%p %d ", &(func_inputs->input_1), func_inputs->input_1 );
	
	// Add the value to the pointer 
	*(func_inputs->int_ptr) += func_inputs->input_1;
	fprintf( stdout, "%p %p %d\n", &(func_inputs->int_ptr), func_inputs->int_ptr, *(func_inputs->int_ptr) );
	
	pthread_mutex_unlock(&Lock);
	
	// Step 4 - Return NULL
	return NULL;
}


void create_parallel_threads( thread_func_args** thread_inputs, long unsigned int num_threads, int* global_int_ptr ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_threads; ++iter ){
		
		// Note: malloc only allocates the memory, but does not initialize it 
		// Use calloc to initialize the memory to pass valgrind 
		thread_inputs[ iter ] = (thread_func_args*)calloc( 1, sizeof(thread_func_args) );
		
		thread_inputs[ iter ]->input_1 = (int)iter;
		
		thread_inputs[ iter ]->int_ptr = global_int_ptr;

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
	
	// Number of threads 
	long unsigned int num_threads = 5;
	
	// Integer to update 
	int solution = 0;
	
	// Print the address and the initial value of solution
	fprintf( stdout, "%p %d\n", &solution, solution );
	
	// 1 - Create a struct with the inputs for the function
    thread_func_args** thread_inputs = (thread_func_args**)malloc( num_threads * sizeof(thread_func_args *) );
	
	// Print the address and the initial value of solution
	fprintf( stdout, "%p %p\n", &thread_inputs, thread_inputs );
	
	// 2 - Create the 5 parallel threads
	create_parallel_threads( thread_inputs, num_threads, &solution );
	
	// 3 - Join all 5 threads
	join_threads( thread_inputs, num_threads );
	
	// 4 - Free the memory allocated to the structs
	free_threads( thread_inputs, num_threads );
	
	// 5 - Free the ** struct
	free( thread_inputs );
	
	// 6 - Should be the last thing in main before return 0 if using this
	// Ensure main does not end before everything else
	pthread_exit( NULL );
	
	
	return EXIT_SUCCESS;
}