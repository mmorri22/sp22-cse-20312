#include <stdio.h>
#include <stdlib.h>

int main(void){

	int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "hello address = %p\n", hello );
	fprintf( stdout, "size address  = %p\n", &size );

	return 0;
}
