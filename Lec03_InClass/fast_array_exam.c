#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 15

int check_elements( int array[], int check, int length ){

	int iter;
	for( iter = 0; iter < length; ++iter ){

		if( array[iter] == check )
			return 1;
	}

	return 0;
}

void recaman()
{
	/* An array of 20 signed ints stored on the Heap */
	int results_buffer[NMAX];

	/* First array element  */
	results_buffer[0] = 0;

	int iter;
	int previous = 0;
	int current;

	/* for n > 0 */
	for (iter = 1; iter < NMAX; iter++) {

		/* a(n) = a(n-1) - n if nonnegative and not already in the sequence */
		if( previous - iter > 0
			&& check_elements( results_buffer, previous - iter, iter - 1 ) == 0){

				current = previous - iter;
		}

		/* otherwise a(n) = a(n-1) + n. */
			else
				current = previous + iter;

		results_buffer[iter] = current;
		previous = current;

	}

}

int main(void) {

	/* Run 1,000,000 tests */
	long int num_tests = 1000000;

	/* clock_t is a type from #include <time.h> */
	/* clock_t is equivalent to a 64-bit signed integer */
	/* We start the profiling */
	clock_t time_start = clock();

	long int iter;
	for (iter = 0; iter < num_tests; ++iter)
		 recaman();

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
