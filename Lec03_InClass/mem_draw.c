#include <stdio.h>
#include <stdlib.h>

int main(){

	int int_static[] = {1, 3, 5, 7};

	long unsigned int length = 5;
	int* int_dynamic = (int *)malloc( length * sizeof(int) );

	int_dynamic[0] = 2;
	*(int_dynamic + 1) = 4;
	int_dynamic[2] = 6;
	*(int_dynamic + 3) = 8;
	int_dynamic[3] = 10;

	fprintf( stdout, "Static Memory addresses: %p %p\n", &int_static, int_static );
	fprintf( stdout, "Dynamic Memory addresses: %p %p\n", &int_dynamic, int_dynamic );

	long unsigned int iter;
	for( iter = 0; iter < 4; ++iter ){

		fprintf( stdout, "int_static[%lu] = %d at %p\n", iter, int_static[iter], &int_static[iter] );
	}

	for( iter = 0; iter < length; ++iter ){

		fprintf( stdout, "int_dynamic[%lu] = %d at %p\n", iter, int_dynamic[iter], &int_dynamic[iter] );
	}

	// Free dynamically allocated memory
	free( int_dynamic );

	return 0;

}
