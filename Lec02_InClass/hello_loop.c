#include <stdio.h>

int main( void ){

	char* hello = "Hello, World\n";

	long unsigned int iter = 0;
	while( hello[iter] != '\0' ){

		fprintf( stdout, "%c %p\n", hello[iter], &hello[iter] );
		++iter;
	}

	return 0;

}
