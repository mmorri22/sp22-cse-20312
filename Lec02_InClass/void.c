#include <stdio.h>
#include <stdlib.h>

int main()
{
    void* hello = malloc( 6 * sizeof(char) );
    
	*(char *)(hello + 0*sizeof(char)) = 72;
	*(char *)(hello + 1*sizeof(char)) = 0x65;
	*(char *)(hello + 2*sizeof(char)) = 108;
	*(char *)(hello + 3*sizeof(char)) = 0x6c;
	*(char *)(hello + 4*sizeof(char)) = 111;
	*(char *)(hello + 5*sizeof(char)) = 10;
	
	void* reference = hello;
	
	fprintf( stdout, "hello register = %p\n", &hello );
	fprintf( stdout, "reference register = %p\n", &reference );
	fprintf( stdout, "hello points to = %p\n", hello );
	fprintf( stdout, "reference points to = %p\n", reference );
	
	long unsigned int iter;
	for( iter = 0; iter < 6; ++iter ){
		
		fprintf( stdout, "%p %c\n", 
			reference, *(char *)(reference) );
			
		reference = reference + sizeof(char) ;
	}
 
 	fprintf( stdout, "hello points to = %p\n", hello );
	fprintf( stdout, "reference points to = %p\n", reference );
	
 
    // free( hello );
	free( hello );
	// free( hello );
    return 0;
}

