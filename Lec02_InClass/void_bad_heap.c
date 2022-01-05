#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main( void ){
	
	struct rusage r_usage;	// To be used to store memory information
	long unsigned int mem_size = 10000 * sizeof(char);
	long int curr_mem = 0;	
	int increment = 0;
	
	while( 1 ){
		void* hello = malloc( mem_size );

		/* Get the memory */
		getrusage(RUSAGE_SELF,&r_usage);
		
		/* If the number of sets is the same */
		if( curr_mem == r_usage.ru_maxrss ){
			++increment;
		}
		/* Otherwise, re-start the count */
		else{
			curr_mem = r_usage.ru_maxrss;
			increment = 1;
		}

		/* r_usage.ru_maxrss: long unsigned int containing total memory usage */
		fprintf( stdout, "Local Register, Long-Term Mem, Mem Usage: %p %p %ld %d\n", 
			&hello, hello, r_usage.ru_maxrss, increment);

		free( hello );

	}
	return 0;
}
