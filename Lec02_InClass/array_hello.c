#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	long unsigned int size = 13 * sizeof(char);

	char* hello = (char *)malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello ); 
	
	hello[0] = 'H';
	fprintf( stdout, "%c %p\n", hello[0], &hello[0] );

	hello[1] = 'e';
	fprintf( stdout, "%c %p\n", hello[1], &hello[1] );

	hello[2] = 'l';
	fprintf( stdout, "%c %p\n", hello[2], &hello[2] );

	hello[3] = 'l';
	fprintf( stdout, "%c %p\n", hello[3], &hello[3] );

	hello[4] = 'o';
	fprintf( stdout, "%c %p\n", hello[4], &hello[4] );
	
	hello[5] = ',';
	fprintf( stdout, "%c %p\n", hello[5], &hello[5] );
	
	hello[6] = ' ';
	fprintf( stdout, "%c %p\n", hello[6], &hello[6] );
	
	hello[7] = 'W';
	fprintf( stdout, "%c %p\n", hello[7], &hello[7] );
	
	hello[8] = 'o';
	fprintf( stdout, "%c %p\n", hello[8], &hello[8] );
	
	hello[9] = 'r';
	fprintf( stdout, "%c %p\n", hello[9], &hello[9] );
	
	hello[10] = 'l';
	fprintf( stdout, "%c %p\n", hello[10], &hello[10] );
	
	hello[11] = 'd';
	fprintf( stdout, "%c %p\n", hello[11], &hello[11] );
	
	hello[12] = '\n';
	fprintf( stdout, "%c %p\n", hello[12], &hello[12] );

	free( hello );
	
	return 0;
}
