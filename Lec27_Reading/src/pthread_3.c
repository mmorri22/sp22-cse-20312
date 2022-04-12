#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

typedef struct thread_func_args{
	
	pthread_t curr_tid;
	int input_1;
	int input_2;
	int sum;
	
}thread_func_args;


void* thread_func( void* inputs ){
    
	// Cast the void* back to a struct pointer
    thread_func_args* func_inputs = (thread_func_args *)inputs;
	
	int temp_1 = func_inputs->input_1;
	int temp_2 = func_inputs->input_2;
	int temp_sum = 0;
		
	int iter;
	for( iter = 0; iter < 1000000; ++iter ){
		
		temp_sum = temp_1 + temp_2;
		temp_1 = temp_2;
		temp_2 = temp_1 + 5;
		
	}
	
	fprintf( stdout, "%ld , Initial: %d %d %d, Final: %d %d %d\n",
		func_inputs->curr_tid, func_inputs->input_1, func_inputs->input_2, func_inputs->sum,
		temp_1, temp_2, temp_sum );
	
	func_inputs->sum = temp_sum;
	func_inputs->input_1 = temp_1; 
	func_inputs->input_2 = temp_2;
    
	// Return NULL 
	return NULL;
}

void create_parallel_threads( thread_func_args** thread_inputs, long unsigned int num_threads ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_threads; ++iter ){
		
		// Note: malloc only allocates the memory, but does not initialize it 
		// Use calloc to initialize the memory to pass valgrind 
		thread_inputs[ iter ] = (thread_func_args*)calloc( 1, sizeof(thread_func_args) );
		
		thread_inputs[ iter ]->input_1 = (int)iter;
		
		thread_inputs[ iter ]->input_2 = (int)( iter * 2 );

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

int main(){
	
	// Number of threads 
	long unsigned int num_threads = 10;

	// 1 - Create a struct with the inputs for the function
    thread_func_args** thread_inputs = (thread_func_args**)malloc( num_threads * sizeof(thread_func_args *) );
	
	// 2 - Create the 10 parallel threads
	create_parallel_threads( thread_inputs, num_threads );
	
	// 3 - Join all 10 threads
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