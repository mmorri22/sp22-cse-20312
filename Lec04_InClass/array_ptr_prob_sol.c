#include <stdio.h>
#include <stdlib.h>

#define NUMSTRS 5
#define NUMCHARS 9

void malloc_arr( char** str_array ){
	
	long unsigned int iter;
	for( iter = 0; iter < NUMSTRS; ++iter ){
		
		str_array[ iter ] = (char *)malloc( NUMCHARS * sizeof( char ) );
		
	}
}

void free_arr( char** str_array ){
	
	long unsigned int iter;
	for( iter = 0; str_array[iter] != NULL; ++iter ){
		
		free( str_array[ iter ] );
		
	}
}

void init_values( char** str_array ){
	str_array[0][0] = 'N';
	str_array[0][1] = 'o';
	str_array[0][2] = 't';
	str_array[0][3] = 'r';
    str_array[0][4] = 'e';
    str_array[0][5] = '\0';
    str_array[1][0] = 'D';
    str_array[1][1] = 'a';
    str_array[1][2] = 'm';
    str_array[1][3] = 'e';
    str_array[1][4] = '\0';
    str_array[2][0] = 'F';
    str_array[2][1] = 'i';
    str_array[2][2] = 'g';
    str_array[2][3] = 'h';
    str_array[2][4] = 't';
    str_array[2][5] = 'i';
    str_array[2][6] = 'n';
    str_array[2][7] = 'g';
    str_array[2][8] = '\0';
    str_array[3][0] = 'I';
    str_array[3][1] = 'r';
    str_array[3][2] = 'i';
    str_array[3][3] = 's';
    str_array[3][4] = 'h';
    str_array[3][5] = '\0';
	
	// Step 9. To make the last string NULL
	// Free str_array[4]
	// Set str_array[4] equal to NULL 
	free( str_array[4] );
	str_array[4] = NULL;
}

// Step 6b. - Print the characters 
// Write the function call
// Remember: When passing by reference
//		Data is passed by reference 
//		Structure is passed by value 
void print_arrays( char** str_array ){

	// Checking if the first pointer is not NULL = Structure
	if( str_array[0] == NULL )
		return;

	// Loop through all the strings
	long unsigned int iter;
	for( iter = 0; iter < NUMSTRS; ++iter ){

		// Checking to see if the second pointer is not NULL = Structure
		if( str_array[ iter ] != NULL ){

			long unsigned jter;
			// Checking if the character is not NULL = Data
			for( jter = 0; str_array[iter][ jter ] != '\0'; ++jter ){
				
				// Print the character
				fprintf( stdout, "%c", str_array[iter][jter] );
			}
			
			// Print a space between the words
			fprintf( stdout, " " );

		}
	} 
	
	// Print a new line after each print out - Outside the loop
	fprintf( stdout, "\n" );


}

// Step 7. Borrow From Next 
// Write the function call
// Remember: When passing by reference
//		Data is passed by reference 
//		Structure is passed by value 
void borrow_from_next( char** str_array ){
	
	// 7-b Checking if the first pointer is not NULL = Structure
	if( str_array == NULL )
		return;
	
	// 7-c Set a temporary pointer to str_array[0] 
	char* temp = str_array[0];

	// 7-d Loop through until the NEXT string is null
	long unsigned int iter;
	for( iter = 0; str_array[iter+1] != NULL; ++iter ){
		
		// Set the current pointer equal to the next pointer 
		str_array[iter] = str_array[iter + 1];
		
	}
	
	// 7-e Set the iter pointer to NULL 
	str_array[iter] = NULL;
	
	// 7-f Free the temporary array 
	free( temp );
	
}


int main( void ){

	// 1. Initially allocate the array 
	char** str_array = (char **)malloc( NUMSTRS * sizeof( char * ) );
	
	// 2. Call the malloc_arr function. Then, go to the end of main for #3
	malloc_arr( str_array );
	
	// 5. Initialize the values
	init_values( str_array );
	
	
	// 6a. We will write a function to print all the array characters.
	//    First, we will write the function 
	//    Then we will come back here and call it.
	print_arrays( str_array );
	
	
	// 8. We will loop through the strings. Follow Dr. Morrison's Golden Rule of Pointers
	// Check if the array is not NULL
	if( str_array != NULL ){

		// Each loop, check if the NULL pointer is not NULL 
		while( str_array[0] != NULL ){
			
			// Call Borrow From Next 
			borrow_from_next( str_array );
			
			// Call Print Arrays 
			print_arrays( str_array );
		}
		
	}

	
	// 3. Call the free function to free all the arrays
	free_arr( str_array );
	
	// 4. Free the char** array. Then go back to where Step 2 was and then do #5
	free( str_array );

	return 0;

}