#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

int main(){
    
	// Created, but not initialized - Will not pass PQC yet
    pthread_t tid_0;
    
    fprintf( stdout, "%p %ld\n", &tid_0, tid_0 );
    
    return EXIT_SUCCESS;
}