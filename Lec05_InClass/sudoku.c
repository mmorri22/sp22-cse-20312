/* Author: Matthew Morrison
 * Email: matt.morrison@nd.edu 
 * File Name: sudoku.c
 * Date Created: 9/18/2021
 * Data Modified: 10/15/2021
 *
 * This file contains the main driver function for
 * the Sudoku Combined Concepts lecture(s)
 *
 * Also contains FILE* and Recursive Concepts for 
 * the Sudoku Solver
 **********************************************/

#include "sudoku_func.h"

int main( const int argc, const char* argv [] ){
	
	if( argc != 2 ){
		
		fprintf( stderr, "Incorrect Number of inputs\n" );
		
		return EXIT_FAILURE;
	}
	
	/* Print Greeting to User */
	print_greeting();
	
	FILE* sudoku_file = fopen( argv[1], "r" );
	
	int** sudoku = (int**)malloc( ROWS * sizeof(int *) );
	
	alloc_sudoku( sudoku );
	
	populate_puzzle( sudoku_file, sudoku );
	
	fclose( sudoku_file );
	
	/* Get choice */
	int player_input = 1;
	
	/* User input choice declarations */
	int value;
	long unsigned int row;
	long unsigned int col;
	unsigned int solved = 0;
	
	while( player_input != 4 ){
		
		player_input = player_choice();
		
		switch( player_input ){
			
			case 1:
				print_puzzle( sudoku );
				break;
				
			case 2:
				get_user_choice( &value, &row, &col );
				
				fprintf( stdout, "User input: %d %ld %ld\n", value, row, col );
				
				if( check_user_input( sudoku, value, row, col ) == 1 )
					update_puzzle( sudoku, value, row, col );
				
				break;	
				
			case 3:
				fprintf( stdout, "Attempting to solve the Puzzle...\n" );
				solved = recursive_solver( sudoku, 0, 0 );
				break;
			case 4:
				fprintf( stdout, "Ending the game...\n" );
				break;				
			
		}
		
		if( check_puzzle( sudoku ) || solved == 1 ){
			
			fprintf( stdout, "You solved the puzzle!\n" );
			print_puzzle( sudoku );
			break;
		}
		
	}
	
	// Free the array of arrays
	free_sudoku( sudoku );
	
	// Free the initial array pointer
	free( sudoku );
	
	return 0;
}
