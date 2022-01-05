#include <stdio.h>
#include <stdlib.h>

int main(void){

	int size = -1* 13 * sizeof(char);
	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello );
	fprintf( stdout, "address of hello[2] = %p\n", hello + 2*sizeof(char) );
	fprintf( stdout, "cast char* hello[2] = %p\n", (char *)( hello + 2*sizeof(char) ) );

	*(char *)( hello + 2*sizeof(char) ) = 'l';

	fprintf( stdout, "hello[2] data value = %c\n", *(char *)( hello + 2*sizeof(char) ) );

	free( hello );

	return 0;
}
