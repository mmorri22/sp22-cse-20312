#include <stdio.h>
#include <stdlib.h>

#define NUMSTRS 9
#define NUMCHARS

void malloc_arr( char** str_array ){
	long unsigned int iter;
	for( iter = 0; iter < NUMSTRS; ++iter ){
		str_array[ iter ] = (char *)malloc( NUMCHARS * sizeof( char ) );
	}
}

void free_arr( char** str_array ){
	long unsigned int iter;
	for( iter = 0; iter < NUMSTRS; ++iter ){
		
		/* Step X: Since we free'd the arrays earlier, we need to
		   follow Dr. Morrison's Golden Rule of Pointers and 
		   check if the pointer is not NULL before freeing */
		free( str_array[ iter ] );
	}
}

// 5b - We need to change it to char*** to CHANGE THE ADDRESSES in order for the pointers 
//      to be passed by reference and preserved 
//		We will also see how de-referencing works by changing
//		all the str_array to *sta_array
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
	// Free str_array[4] then set str_array[4] equal to NULL 
	
}

// Step 6b. - Print the characters 
// Write the function call
// Remember: When passing by reference
//		Data is passed by reference 
//		Structure is passed by value 


	// Checking if the first pointer is not NULL = Structure


	// Loop through all the strings


		// Checking to see if the second pointer is not NULL = Structure

			// Loop and check if the character is not NULL = Data

				
				// Print the character


			// Print a space between the words


	
	// Print a new line after each print out - Outside the loop
	
}



int main( void ){

	// 1. Initially allocate the array for char** of size NUMSTRS  
	
	// 2. Call the malloc function. Then, go to the end of main for #3
	
	// 5. Initialize the values
	
	// 6. We will write a function to print all the array characters.
	//    First, we will write the function 
	//    Then we will come back here and call it.
	
	// 8. We will loop through the strings. Follow Dr. Morrison's Golden Rule of Pointers
	// Check if the array is not NULL

		// Each loop, check if the NULL pointer is not NULL 
			
			// Call Borrow From Next 
			
			// Call Print Arrays 
	
	// 3. Call the free function to free all the arrays
	
	// 4. Free the char** array 

	return 0;

}
