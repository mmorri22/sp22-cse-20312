#include <stdio.h>
#include <stdlib.h>

int main( const int argc, const char** argv ){
	
	if( argc != 2 )
		return EXIT_FAILURE;

	FILE* the_input = fopen( argv[1], "r" );

	// Remember Dr. Morrison's Golden Rule of Pointers
	while( the_input != NULL ){
		
		char word[20];
		char space_or_new_line;

		// Read in the two strings and a new line char
		fscanf( the_input, "%s", word );
		fscanf( the_input, "%c ", &space_or_new_line );		
		
		// Print the contents to the user
		fprintf( stdout, "File Contents: %s\n", word );
		
		// Print the location of the two pointers
		fprintf( stdout, "FILE pointers: %p %p\n", the_input->_IO_read_ptr, the_input->_IO_read_end );
		
		// If the FILE read pointer reaches the end of the FILE, break the while 
		// Citation: https://code.woboq.org/userspace/glibc/libio/bits/types/struct_FILE.h.html#_IO_FILE
		if( the_input->_IO_read_ptr == the_input->_IO_read_end  )
			break;
		
	}


	fclose( the_input );

	return EXIT_SUCCESS;

}
