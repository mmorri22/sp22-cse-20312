#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

typedef struct thread_func_args{
	
	pthread_t curr_tid;
	int input_1;
	int input_2;
	
}thread_func_args;


void* thread_func( void* inputs ){
    
	// Cast the void* back to a struct pointer
    thread_func_args* func_inputs = (thread_func_args *)inputs;
    
	// Print the data from the struct pointer
    fprintf( stdout, "%d %d\n", func_inputs->input_1, func_inputs->input_2 );
    
	// You must return a void pointer  
	return NULL;
}

int main(){
    

	// Create a struct with the inputs for the function
    thread_func_args* tid_0_inputs = (thread_func_args*)malloc( sizeof(thread_func_args) );
	tid_0_inputs->input_1 = 10;
	tid_0_inputs->input_2 = 20;
	
	// Join the ID, the function call itself, and the struct of inputs cast to void 
	pthread_create( &(tid_0_inputs->curr_tid), NULL, thread_func, (void *)tid_0_inputs );
	
	// Print the ID's register and value
    fprintf( stdout, "%p %ld\n", &(tid_0_inputs->curr_tid), tid_0_inputs->curr_tid );
	
	// Join the pthread, which will also free the thread after being used
	pthread_join( tid_0_inputs->curr_tid,  NULL );
	
	// Free the structs
	free( tid_0_inputs );
	
	// Should be the last thing in main before return 0 if using this
	// Ensure main does not end before everything else
	pthread_exit( NULL );
    
    return EXIT_SUCCESS;
}