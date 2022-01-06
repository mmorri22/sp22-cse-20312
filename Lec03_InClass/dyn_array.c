#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25


void fibonacci()
{
	/* An array of 25 unsigned ints stored on the Heap */
	unsigned int* results_buffer = (unsigned int *)malloc( NMAX * sizeof(int) );
	
	/* First array element  */
	results_buffer[0] = 1; 
	
	/* Second array element */
	results_buffer[1] = 1;
	
	long unsigned int iter;
	for (iter = 2; iter < NMAX; iter++) {
		
		results_buffer[ iter ] = results_buffer[ iter-2 ] + results_buffer[ iter - 1 ];

	}
	
	free( results_buffer );
}

int main(void) {
	
	/* Run 10,000,000 tests */
	long int num_tests = 10000000;

	/* clock_t is a type from #include <time.h> */
	/* clock_t is equivalent to a 64-bit signed integer */
	/* We start the profiling */
	clock_t time_start = clock();
	
	long int iter;
	for (iter = 0; iter < num_tests; ++iter)
		fibonacci();

	/* Obtain the end time and complete the time profile */
	clock_t time_end = clock();

	/* compute average execution time */
	clock_t time_run = time_end - time_start;
	long int num_clk_pulses = CLOCKS_PER_SEC*num_tests;
	
	/* To obtain the average in an efficient manner */
	/* Type cast BOTH long ints to a double and then store */
	double final_avg = (double)(time_end) / (double)(num_clk_pulses) ;

	/* print avg execution time in milliseconds */
	fprintf( stdout, "Start time : %ld\n", time_start );
	fprintf( stdout, "Finish time: %ld\n", time_end );
	fprintf( stdout, "Total time: %ld\n", time_run );
	fprintf( stdout, "Number of Clock Pulses: %ld\n", num_clk_pulses );
	fprintf( stdout, "Avg. execution time: %lf msec\n", final_avg*1000);
	
	return 0;
}
