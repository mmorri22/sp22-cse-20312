#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

// Step 1 - Write a struct representing the inputs to a function you wish to parallelize
typedef struct thread_func_args{
	
	pthread_t curr_tid;
	int input_1;
	int input_2;
	int sum;
	
}thread_func_args;


// Step 2 - Write the function you wish to implement, except pass a void pointer to the function, and return a void pointer
void* thread_func( void* inputs ){
    
	// Step 3 - Cast the void* back to a struct pointer inside the function
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
    
	// You must return a void pointer in the function, so you will write return NULL; 
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

		// Step 6 - Call pthread_create, calling the thread_ID by reference, NULL (we are not adding attributes in this course) and then pass the struct to the pthread by casting to a void pointer
		pthread_create( &(thread_inputs[ iter ]->curr_tid), NULL, thread_func, (void *)(thread_inputs[ iter ]) );
		
	}	
	
}

void join_threads( thread_func_args** thread_inputs, long unsigned int num_threads ){
	
	long unsigned int iter;
	for ( iter = 0; iter < num_threads; ++iter ) {
		
		// Step 8 - Join the pthreads 
		pthread_join( thread_inputs[ iter ]->curr_tid,  NULL );
	}	
	
}

void free_threads( thread_func_args** thread_inputs, long unsigned int num_threads ){
	
	// Step  8 - Part 2 - Free the dynamically allocated structs for the function inputs
	long unsigned int iter;
	
	for( iter = 0; iter < num_threads; ++iter ){
		
		free( thread_inputs[iter] );
	}
	
}

int main(){
	
	// Number of threads 
	long unsigned int num_threads = 10;

	// Step 5 - Create a dynamically allocated struct object in main, and set the values you'd want to input to the function
    thread_func_args** thread_inputs = (thread_func_args**)malloc( num_threads * sizeof(thread_func_args *) );
	
	// Create the 10 parallel threads
	create_parallel_threads( thread_inputs, num_threads );
	
	// Join all 10 threads
	join_threads( thread_inputs, num_threads );
	
	// Step 8 - Part 1 - Free the dynamically allocated structs for the function inputs
	free_threads( thread_inputs, num_threads );
	
	// Step 8 - Part 3 - Free the ** struct
	free( thread_inputs );
	
	// Step 9 - Call pthread_exit( NULL ); as the last thing you do before return main
	pthread_exit( NULL );
    
    return EXIT_SUCCESS;
}