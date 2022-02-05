/*******************************************
 * File name: n_queens.cpp 
 * Author: Matthew Morrison
 * E-mail: matt.morrison@nd.edu
 *
 * This file contains the detailed solution to the 
 * N-Queens problem as presented in CSE 20312 Data Structures
 *******************************************/

#include <iostream>
#include <vector>
#include <string>


bool check_diagonal( int row, int col, std::vector< std::pair<int, int> >& all_queens ){
	
	// row and col is a potential queen place 
	// all_queens contains the previous queens was have placed 
	// Iterate through all the queens 
	for( long unsigned int iter = 0; iter < all_queens.size(); ++iter ){
		
		// Get the delta row coordinate
		int delta_row = std::abs(row - all_queens.at( iter ).first);
		int delta_col = std::abs(col - all_queens.at( iter ).second);
		
		// If they are equal, return false 
		if( delta_row == delta_col )
			return false;
	}
	
	// Checked all the queens no. So this is a potentially valid location 
	return true;
}

void search( std::vector<std::vector<std::string>>& n_queens_sols,	// All the solutions
		     std::vector<std::string>& current_board, 				// Current board we are evaluating
			 std::vector<bool>& valid_cols, 						// valid columns
			 std::vector< std::pair<int, int> >& all_queens,		// Locations of current queens
			 int curr_row, int board_size ){						// Current row and board size
	
	// If curr_row is equal to the board size, we made it!
	if (curr_row == board_size) {
		
		// Put the current board on the solutions:
		n_queens_sols.push_back( current_board );
		return;
	}
	
	// Each time we call this function, we are incrementing a row
	// So start at curr_col = 0 and go until we reach the end 
	for( int curr_col = 0; curr_col < board_size; ++curr_col ) {
		
		// Only perform recursion if we can *potentially* place a value there 
		if( valid_cols.at( curr_col ) && check_diagonal( curr_row, curr_col, all_queens ) ){
			
			// Set the current board to Q
			current_board.at( curr_row ).at( curr_col ) = 'Q';
			
			// Set the current colum to valid 
			valid_cols.at(curr_col) = false;
			
			// Push the current queen back onto the board 
			all_queens.push_back( {curr_row, curr_col} );

			// Go to the next row 
			search(n_queens_sols, current_board, valid_cols, all_queens, curr_row+1, board_size);

			// Set the location column and row back to true to allow for further backtracking 
			current_board.at( curr_row ).at( curr_col ) = '.';
			
			// Allow for this column to be valid
			valid_cols.at(curr_col) = true;	
			
			// Remove the previous queen
			all_queens.pop_back( );			
		}
	}
	
}

std::vector< std::vector< std::string > > solve_n_queens( int num_queens ){
	
	std::cout << "Solving for " << num_queens << " Queens on an ";
	std::cout << num_queens << " x " << num_queens << " chessboard." << std::endl;
	
	// Will contain all the valid boards
	std::vector< std::vector< std::string > > n_queens_sols;
	
	// We will play this num_queens times 
	// We are playing at each row 
	for( int curr_col = 0; curr_col < num_queens; ++curr_col ){
	
		// Create a num_queens x num_queens board with strings where all values are initially 0
		std::vector<std::string> curr_board( num_queens, std::string(num_queens, '.'));
		
		// Create a vector for valid rows and valid columns 
		std::vector<bool> valid_cols( num_queens, true );
		
		// Create a vector of std::pair of ints to keep track of each queen 
		std::vector< std::pair<int, int> > all_queens;
		
		// Set the top element at the current column equal to 'Q'
		curr_board.at(0).at(curr_col) = 'Q';
		valid_cols.at( curr_col ) = false;
		
		// Add the first queen 
		all_queens.push_back( {0, curr_col} );
	
		// Run the Backtracking Algorithm for the current board and total solutions 
		// Pass row = 1 to start, since the current board has a Queen in row 0
		search( n_queens_sols, curr_board, valid_cols, all_queens, 1, num_queens );
	}
	
	// Return the final vector of vectors
	return n_queens_sols;
}

void print_board( const std::vector<std::string>& the_board ){
	
	for( long unsigned int iter = 0; iter < the_board.size(); ++iter ){
		
		// Print spaces between characters to make the board look clean
		for( long unsigned int jter = 0; jter < the_board.at(iter).size(); ++jter )
			std::cout << the_board.at(iter).at(jter) << " ";
		
		std::cout << std::endl;
	}
	
}


void print_all_solutions( const std::vector<std::vector<std::string>>& n_queens_sols ){
	
	std::cout << "Total Solutions found = " << n_queens_sols.size() << std::endl;
	
	for( long unsigned int iter = 0; iter < n_queens_sols.size(); ++iter ){
		
		std::cout << "Solution " << (iter + 1 ) << std::endl;
		
		print_board( n_queens_sols.at( iter ) );
	}
}

int main( const int argc, const char* argv[] ){
	
	if( argc != 2 ){
		
		std::cerr << "Must input two values" << std::endl;
		return EXIT_FAILURE;
	}
	
	// Convert user input to the number of queens 
	int num_queens = atoi( argv[1] );

	// Obtain all the solutions!
	std::vector<std::vector<std::string>> n_queens_sols = solve_n_queens( num_queens );
	
	// Print all the solutions
	print_all_solutions( n_queens_sols );
	
	return EXIT_SUCCESS;
}