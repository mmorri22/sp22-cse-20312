#include <stdio.h>
#include <stdlib.h>

int main(void){

	int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "&hello = %p, hello = %p\n", &hello, hello );
	fprintf( stdout, "size address  = %p\n", &size );

	return 0;
}
