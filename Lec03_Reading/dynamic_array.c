#include <stdio.h>
#include <stdlib.h>

int main(){
	
	long unsigned int size = 5;
	double* dbl_array = (double *)malloc( size * sizeof(double) );
	dbl_array[0] = -12.7;
	*(dbl_array + 1) = 25.1;
	dbl_array[2] = -3.3;
	*(dbl_array + 3) = -15.2;
	dbl_array[4] = 1; 
	
	fprintf( stdout, "dbl_array register at %p\n", &dbl_array );
	fprintf( stdout, "Base address of dbl_array in Heap at %p\n", dbl_array );

	long unsigned int i;
	for(i = 0; i < size; ++i){
		
		fprintf( stdout, "element = %lu, address = %p, data = %lf\n", i, dbl_array + i, *(dbl_array + i) );
	}
	
	fprintf( stdout, "\n");

	free( dbl_array );
	
	return 0;
}

