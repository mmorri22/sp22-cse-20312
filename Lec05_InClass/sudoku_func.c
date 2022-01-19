/* Author: Matthew Morrison
 * Email: matt.morrison@nd.edu 
 * File Name: sudoku_08.c
 * Date Created: 9/18/2021
 * Date Modified: 10/15/2021
 *
 * This file contains the function definitions for
 * the Sudoku Combined Concepts lecture(s)
 *
 * Also contains the recursive solution to the Sudoku 
 * Solver presented in Lecture 24
 **********************************************/

#include "sudoku_func.h"

void print_greeting( void ){
	
	fprintf( stdout, "Welcome to our Sudoku Game!\n" );
	
}

void alloc_sudoku( int** sudoku ){
	
	long unsigned int iter;
	for( iter = 0; iter < COLS; ++iter ){
		
		sudoku[iter] = (int *)malloc( COLS*sizeof(int) );
		
	}
	
}

void free_sudoku( int** sudoku ){
	
	long unsigned int iter;
	for( iter = 0; iter < COLS; ++iter ){
		
		free( sudoku[iter] );
		
	}	
	
}

void populate_puzzle( FILE* sudoku_file, int** sudoku ){
	
	long unsigned int curr_row = 0;
	while( sudoku_file != NULL && curr_row < 9 ){
		
		int val0, val1, val2, val3, val4, val5, val6, val7, val8;
		
		fscanf( sudoku_file, "%d %d %d %d %d %d %d %d %d",
			&val0, &val1, &val2, &val3, &val4, &val5, &val6, &val7, &val8 );
		
		sudoku[curr_row][0] = val0;
		sudoku[curr_row][1] = val1;
		sudoku[curr_row][2] = val2;
		sudoku[curr_row][3] = val3;
		sudoku[curr_row][4] = val4;
		sudoku[curr_row][5] = val5;
		sudoku[curr_row][6] = val6;
		sudoku[curr_row][7] = val7;
		sudoku[curr_row][8] = val8;
		
		++curr_row;
		
		if( sudoku_file->_IO_read_ptr == sudoku_file->_IO_read_end  )
			break;
	}
}

int player_choice ( void ){
	
	int player_choice;
	
	fprintf( stdout, "Enter your choice:\n" );
	fprintf( stdout, "1: Print the puzzle\n" );
	fprintf( stdout, "2: Make a change\n" );
	fprintf( stdout, "3: Run Auto-Solver to see if puzzle is solveable\n" );
	fprintf( stdout, "4: Quit the game\n" );
	
	fscanf( stdin, "%d", &player_choice );
	
	return player_choice;
	
}


void print_puzzle( int** sudoku ){

	long unsigned int row_iter;
	for( row_iter = 0; row_iter < ROWS; ++row_iter ){

		long unsigned int col_iter;
		for( col_iter = 0; col_iter < COLS; ++col_iter ){
			
			fprintf( stdout, "%d ", sudoku[row_iter][col_iter] );
			
		}
		fprintf( stdout, "\n" );
	}
}

void get_user_choice( int* value, long unsigned int* row,
						long unsigned int* col )
{
	
	fprintf( stdout, "Enter your choice: value row col:\n" );
	
	fscanf( stdin, "%d %ld %ld", value, row, col );
	
}

void update_puzzle( int** sudoku, int value, long unsigned int row, 
					long unsigned int col )
{
	sudoku[row][col] = value;
}

unsigned int check_user_input( int** sudoku, int value, 
					long unsigned int row, long unsigned int col )
{
	
	/* Check if there is a valid value at the location already */
	if( sudoku[row][col] != 0 ){
		
		fprintf( stdout, "Valid value %d at %ld, %ld\n", sudoku[row][col], row, col );
		
		return 0;
	}

	/* Check to make sure the input scanned value is between 1 and 9 */
	if ( value < 1 || value > 9 ){
		fprintf( stdout, "The value must be between 1 and 9. You entered %d\n", value );
		
		/* Return int of 0 for false */
		return 0;
	}
  
	/* Next, check to make sure the row is less than 9 */
	if( row >= 9 ){
		fprintf( stdout, "The row value must be between 0 and 8. You entered %lu\n", row );
		
		/* Return int of 0 for false */
		return 0;  
	}

	/* Next, check to make sure the column is less than 9 */
	if( col >= 9 ){
		fprintf( stdout, "The col value must be between 0 and 8. You entered %lu\n", col );
		
		/* Return int of 0 for false */
		return 0;  
	}

	/* Before inserting, first check if there if that value is already in a row */
	long unsigned int row_iter;
	for( row_iter = 0; row_iter < ROWS; ++row_iter ){

		if( sudoku[ row_iter ][ col ] == value ){

			fprintf( stdout, "There is already a %d at (%lu, %lu)\n", 
			value, row_iter, col );

			/* Return int of 0 for false */
			return 0;
		}
	}
  
  /* Next, if there if that value is already in a column */ 
	long unsigned int col_iter;
	for( col_iter = 0; col_iter < COLS; ++col_iter ){

		if( sudoku[ row ][ col_iter ] == value ){

			fprintf( stdout, "There is already a %d at (%lu, %lu)\n", 
			value, row, col_iter );

			/* Return int of 0 for false */
			return 0;
		}
	}
  

	/* Using mod to get the 3x3 box */

	long unsigned int row_begin =  row - (row % 3);
	long unsigned int row_end = row_begin + 2;
	  
	long unsigned int col_begin =  col - (col % 3);
	long unsigned int col_end = col_begin + 2;
  
	// Finally, iterate through row_min to row_main
	// And inside, iterate through col_min to col_max 
	for( row_iter = row_begin; row_iter <= row_end; ++row_iter ){

		for( col_iter = col_begin; col_iter <= col_end; ++col_iter ){	

			if( sudoku[ row_iter ][ col_iter ] == value ){

				fprintf( stdout, "There is already a %d at (%lu, %lu)\n", 
					value, row_iter, col_iter );

				return 0;
			}
		}	
	}
	
	/* Return int of 1 for true */
	return 1;
}


unsigned int check_user_input_no_print( int** sudoku, int value, 
					long unsigned int row, long unsigned int col )
{
	
	/* Check if there is a valid value at the location already */
	if( sudoku[row][col] != 0 ){
				
		return 0;
	}

	/* Check to make sure the input scanned value is between 1 and 9 */
	if ( value < 1 || value > 9 ){
		
		/* Return int of 0 for false */
		return 0;
	}
  
	/* Next, check to make sure the row is less than 9 */
	if( row >= 9 ){
		
		/* Return int of 0 for false */
		return 0;  
	}

	/* Next, check to make sure the column is less than 9 */
	if( col >= 9 ){
		
		/* Return int of 0 for false */
		return 0;  
	}

	/* Before inserting, first check if there if that value is already in a row */
	long unsigned int row_iter;
	for( row_iter = 0; row_iter < ROWS; ++row_iter ){

		if( sudoku[ row_iter ][ col ] == value ){

			/* Return int of 0 for false */
			return 0;
		}
	}
  
  /* Next, if there if that value is already in a column */ 
	long unsigned int col_iter;
	for( col_iter = 0; col_iter < COLS; ++col_iter ){

		if( sudoku[ row ][ col_iter ] == value ){

			/* Return int of 0 for false */
			return 0;
		}
	}
  

	/* Using mod to get the 3x3 box */

	long unsigned int row_begin =  row - (row % 3);
	long unsigned int row_end = row_begin + 2;
	  
	long unsigned int col_begin =  col - (col % 3);
	long unsigned int col_end = col_begin + 2;
  
	// Finally, iterate through row_min to row_main
	// And inside, iterate through col_min to col_max 
	for( row_iter = row_begin; row_iter <= row_end; ++row_iter ){

		for( col_iter = col_begin; col_iter <= col_end; ++col_iter ){	

			if( sudoku[ row_iter ][ col_iter ] == value ){

				return 0;
			}
		}	
	}
	
	/* Return int of 1 for true */
	return 1;
}



unsigned int recursive_solver( int** sudoku, long unsigned int row, long unsigned int col ){

	/* Skip all non-zero characters in the current row */
	while (row < 9 && sudoku[row][col] != 0) {
		
		// Increment the current column 
		++col;
		
		// If we reach the end of the row
		if (col == 9) {
			
			// Go to the next row
			++row;
			
			// Reser the column 
			col = 0;
		}
	}

	/* Base case -- we're done */
	if (row == 9) 
		return 1;

	// Create a sentinel value 
	int sentinel;
	for ( sentinel = 1; sentinel <= 9; ++sentinel ) {
		
		// Check if the input is possibly valid
		unsigned int check_input = check_user_input_no_print( sudoku, sentinel, row, col );
		
		// Temporarily set the puzzle to the sentinel value
		sudoku[row][col] = sentinel;
		
		// If we can
		if( check_input && recursive_solver( sudoku, row, col ) ){ 
			
			return 1;
		}

		// If we got to this point, we need to set to 0 and backtrack
		else{
			sudoku[row][col] = 0;
		}
	}
	
	return 0;
}


unsigned int check_puzzle( int** sudoku ){

  long unsigned int row_iter;
  long unsigned int col_iter;
  
  for( row_iter = 0; row_iter < ROWS; ++row_iter ){
  
    for( col_iter = 0; col_iter < COLS; ++col_iter ){
    
      if( sudoku[ row_iter ][ col_iter ] == 0 )
        return 0;
    }
  }
  
  return 1;

}


