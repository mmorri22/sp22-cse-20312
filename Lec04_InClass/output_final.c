#include <stdio.h>
#include <stdlib.h>

#define _IO_TERMINATE 0xfbad2498

int main( const int argc, const char** argv ){

	FILE* the_input = fopen( "test.txt", "r" );

	// Remember Dr. Morrison's Golden Rule of Pointers
	while( the_input != NULL ){
		
		char address[20];
		char word[20];
		char new_line_char;

		// Read in the two strings and a new line char
		fscanf( the_input, "%s %s", address, word );
		fscanf( the_input, "%c", &new_line_char );
		
		// Print the contents to the user
		fprintf( stdout, "File Contents: %s %s\n", address, word );
		
		// Print the location of the two pointers
		fprintf( stdout, "FILE pointers: %p %p\n", the_input->_IO_read_ptr, the_input->_IO_read_end );
		
		// If the FILE read pointer reaches the end of the FILE, break the while 
		// Citation: https://code.woboq.org/userspace/glibc/libio/bits/types/struct_FILE.h.html#_IO_FILE
		if( the_input->_IO_read_ptr == the_input->_IO_read_end  )
			break;
		
	}
	
	// Code to input if the FILE* is NULL - Build from output_2.c
	if( the_input == NULL ){
		fprintf( stderr, "When NULL, the_input = %p\n", the_input );
		fprintf( stderr, "stderr is at %p\n", stderr );
		fprintf( stdout, "stdout is at %p\n", stdout );

		FILE* the_output = fopen( "test.txt", "w");

		fprintf( stdout, "After w, the_output is now at %p\n", the_output );

		int iter;
		for( iter = 0; iter < argc; ++iter ){

			fprintf( the_output, "%p, %s\n", &argv[iter], argv[iter] );

		}

		fclose( the_output );

		exit( EXIT_FAILURE );
	}


	fclose( the_input );

	return EXIT_SUCCESS;

}
