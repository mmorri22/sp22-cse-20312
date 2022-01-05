#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );
	void* reference = hello;

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello ); 

	*(char *)( reference ) = 72;
	
	reference += sizeof(char);
	*(char *)( reference ) = 0x65;
	
	reference += sizeof(char);
	*(char *)( reference ) = 108;
	
	reference += sizeof(char);
	*(char *)( reference ) = 0x6c;

	reference += sizeof(char);
	*(char *)( reference ) = 111;
	
	reference += sizeof(char);
	*(char *)( reference ) = 44;
	
	reference += sizeof(char);
	*(char *)( reference ) = 0x20;
	
	reference += sizeof(char);
	*(char *)( reference ) = 87;
	
	reference += sizeof(char);
	*(char *)( reference ) = 0x6f;
	
	reference += sizeof(char);
	*(char *)( reference ) = 114;
	
	reference += sizeof(char);
	*(char *)( reference ) = 0x6c;
	
	reference += sizeof(char);
	*(char *)( reference ) = 100;
	
	reference += sizeof(char);
	*(char *)( reference ) = 10;
	
	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		
		fprintf( stdout, "%c %p\n", *( (char *)( hello + iter*sizeof(char) ) ), hello + iter*sizeof(char) );
	}

	free( hello );
	
	return 0;
}
