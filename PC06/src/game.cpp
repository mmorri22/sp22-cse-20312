/*****************************
 * File Name: game.cpp
 * Author: Matthew Morrison
 * E-Mail: matt.morrison@nd.edu
 *
 * This file contains the solution to the C++
 * version of the 2048 game function definitions
 ********************************/

#include "../include/game.h"

void initialize_board( VECTOR< VECTOR<int> >& game_board ){
	
	// Get the random number between 0 and 15
	int initial_block = rand()%16;
	
	int height_location = initial_block / 4;
	int width_location = initial_block % 4;
	
	// Print the initial location
	COUT << "Initial Location: (" << height_location << ", " << width_location << ")" << ENDL;
	
	// Set that location equal to 2
	game_board.at( height_location ).at( width_location ) = 2;
	
}


void print_board( const VECTOR< VECTOR<int> >& game_board, const int score ){
	
	COUT << "Score = " << score << ENDL;
	
	COUT << "---------" << ENDL;
	
	for( SIZE_T iter = 0; iter < HEIGHT; ++iter ){
		
		COUT << "|";
		
		for( SIZE_T jter = 0; jter < WIDTH; ++jter ){
			
			if( game_board.at( iter ).at( jter ) == 0 )
				COUT << " |";
			else
				COUT << game_board.at( iter ).at( jter ) << "|";
		}
		COUT << ENDL << "---------" << ENDL;
	}
	
}

bool check_board( const VECTOR< VECTOR<int> >& game_board ){
	
	for( SIZE_T iter = 0; iter < HEIGHT; ++iter ){
		
		for( SIZE_T jter = 0; jter < WIDTH; ++jter ){
			
			if( game_board.at(iter).at(jter) == 0 )
				return true;
		}
	}	
	
	return false;
}


void generate_new_initial( VECTOR< VECTOR<int> >& game_board ){
	
	bool found_spot = false;
	
	int initial_block, height_location, width_location;
	
	while( !found_spot ){
	
		initial_block = rand()%16;
		
		height_location = initial_block / 4;
		width_location = initial_block % 4;
		
		if( game_board.at( height_location ).at( width_location ) == 0 )
			found_spot = true;
	}
	
	COUT << "New 2 placed at: (" << height_location << ", " << width_location << ")" << ENDL;
	
	game_board.at( height_location ).at( width_location ) = 2;
	
}

char get_move_choice(){
	
	COUT << "Make a choice to move:" << ENDL;
	COUT << "l for left, r for right, u for up, d for down: ";
	
	char choice;
	
	CIN >> choice;
	
	return choice;
}

void move_left( VECTOR< VECTOR<int> >& game_board, int& score ){
	
	// Iterate through all the rows
	for( SIZE_T iter = 0; iter < HEIGHT; ++iter ){
		
		// Iterate from WIDTH - 1 to 1 (not to the rightmost element)
		for( SIZE_T jter = WIDTH - 1; jter > 0; --jter ){		
		
			// If the value to the left is 0
			if( game_board.at( iter ).at( jter - 1 ) == 0 ){
				
				// Set the value to the left equal to the current value
				game_board.at( iter ).at( jter - 1 ) = game_board.at( iter ).at( jter );
				// Set the current value equal to 0
				game_board.at( iter ).at( jter ) = 0;
				
				// Now we loop back to the right going from the current value to WIDTH - 2
				for( SIZE_T kter = jter; kter < WIDTH - 1; ++kter ){
					
					// Set the current value equal to the value to the right 
					game_board.at( iter ).at( kter ) = game_board.at( iter ).at( kter + 1 );
				}
				
				// Set the WIDTH-1 value equal to 0
				game_board.at( iter ).at( WIDTH - 1 ) = 0;
			}
		}
		
		// Now we will iterate in the opposite direction, from 0 to WIDTH-2 (not the rightmost element)
		for( SIZE_T jter = 0; jter < WIDTH - 1; ++jter ){	

			// If the value to the right is equal to the current value
			if( game_board.at( iter ).at( jter + 1 ) == game_board.at( iter ).at( jter ) ){
				
				// Multiply the current value by 2
				game_board.at( iter ).at( jter ) *= 2;
				// Increment score by the current value
				score += game_board.at( iter ).at( jter );
				
				// Again, we loop back to the right going from the current value to WIDTH - 2
				for( SIZE_T kter = jter + 1; kter < WIDTH - 1; ++kter ){
					
					// Set the current value equal to the value to the right 
					game_board.at( iter ).at( kter ) = game_board.at( iter ).at( kter + 1 );
				}
				
				// Set the WIDTH-1 value equal to 0
				game_board.at( iter ).at( WIDTH - 1 ) = 0;
			}
		}
	}		
}


void move_right( VECTOR< VECTOR<int> >& game_board, int& score ){
	
	// Iterate through all the rows
	for( SIZE_T iter = 0; iter < HEIGHT; ++iter ){
		
		// Iterate from 0 to WIDTH-2 (not to the rightmost element)
		for( SIZE_T jter = 0; jter < WIDTH-1; ++jter ){		
		
			// If the value to the right is 0
			if( game_board.at( iter ).at( jter + 1 ) == 0 ){
				
				// Set the value to the right equal to the current value
				game_board.at( iter ).at( jter + 1 ) = game_board.at( iter ).at( jter );
				// Set the current value equal to 0
				game_board.at( iter ).at( jter ) = 0;
				
				// Now we loop back to the left going from the current value to 1 (not the leftmost element)
				for( SIZE_T kter = jter; kter > 0; --kter ){
					
					// Set the current value equal to the value to the left 
					game_board.at( iter ).at( kter ) = game_board.at( iter ).at( kter - 1 );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( iter ).at( 0) = 0;
			}
		}
		
		// Now we will iterate in the opposite direction, from WIDTH-1 to 1 (not the lefttmost element)
		for( SIZE_T jter = WIDTH-1; jter > 0; --jter ){	

			// If the value to the left is equal to the current value
			if( game_board.at( iter ).at( jter - 1 ) == game_board.at( iter ).at( jter ) ){
				
				// Multiply the current value by 2
				game_board.at( iter ).at( jter ) *= 2;
				// Increment score by the current value
				score += game_board.at( iter ).at( jter );
				
				// Again, we loop back to the left going from the current value to 1 (not the leftmost element)
				for( SIZE_T kter = jter - 1; kter > 0; --kter ){
					
					// Set the current value equal to the value to the left 
					game_board.at( iter ).at( kter ) = game_board.at( iter ).at( kter - 1 );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( iter ).at( 0 ) = 0;
			}
		}
	}		
}

void move_up( VECTOR< VECTOR<int> >& game_board, int& score ){
	
	// Iterate through all the columns
	for( SIZE_T col = 0; col < WIDTH; ++col ){
		
		// Iterate from HEIGHT-1 to 1 (not to the topmost element)
		for( SIZE_T row = HEIGHT-1; row > 0; --row ){		
		
			// If the value above is 0
			if( game_board.at( row - 1 ).at( col ) == 0 ){
				
				// Set the value above equal to the current value
				game_board.at( row - 1 ).at( col ) = game_board.at( row ).at( col );
				// Set the current value equal to 0
				game_board.at( row ).at( col ) = 0;
				
				// Now we loop back to the left going from the current value to HEIGHT - 1 (not the bottom element)
				for( SIZE_T kter = row; kter < HEIGHT-1; ++kter ){
					
					// Set the current value equal to the value above 
					game_board.at( kter ).at( col ) = game_board.at( kter+1 ).at( col );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( HEIGHT-1 ).at( col ) = 0;
			}
		}
		
		// Now we will iterate in the opposite direction, from 0 to HEIGHT-1 (not the lefttmost element)
		for( SIZE_T row = 0; row < HEIGHT-1; ++row ){	

			// If the value below is equal to the current value
			if( game_board.at( row + 1 ).at( col ) == game_board.at( row ).at( col ) ){
				
				// Multiply the current value by 2
				game_board.at( row ).at( col ) *= 2;
				// Increment score by the current value
				score += game_board.at( row ).at( col );
				
				// Now we loop back to the left going from the current value to HEIGHT - 1 (not the bottom element)
				for( SIZE_T kter = row + 1; kter < HEIGHT-1; ++kter ){
					
					// Set the current value equal to the value above 
					game_board.at( kter ).at( col ) = game_board.at( kter+1 ).at( col );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( HEIGHT-1 ).at( col ) = 0;
			}
		}
	}	
}


void move_down( VECTOR< VECTOR<int> >& game_board, int& score ){
	
	// Iterate through all the columns
	for( SIZE_T col = 0; col < WIDTH; ++col ){
		
		// Iterate from 0 to WIDTH-2 (not to the rightmost element)
		for( SIZE_T row = 0; row < HEIGHT-1; ++row ){		
		
			// If the value to the right is 0
			if( game_board.at( row + 1 ).at( col ) == 0 ){
				
				// Set the value to the right equal to the current value
				game_board.at( row + 1 ).at( col ) = game_board.at( row ).at( col );
				// Set the current value equal to 0
				game_board.at( row ).at( col ) = 0;
				
				// Now we loop back to the left going from the current value to 1 (not the leftmost element)
				for( SIZE_T kter = row; kter > 0; --kter ){
					
					// Set the current value equal to the value to the left 
					game_board.at( kter ).at( col ) = game_board.at( kter-1 ).at( col );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( 0 ).at( col ) = 0;
			}
		}
		
		// Now we will iterate in the opposite direction, from WIDTH-1 to 1 (not the lefttmost element)
		for( SIZE_T row = WIDTH-1; row > 0; --row ){	

			// If the value to the left is equal to the current value
			if( game_board.at( row - 1 ).at( col ) == game_board.at( row ).at( col ) ){
				
				// Multiply the current value by 2
				game_board.at( row ).at( col ) *= 2;
				// Increment score by the current value
				score += game_board.at( row ).at( col );
				
				// Again, we loop back to the left going from the current value - 1 to 1 (not the leftmost element)
				for( SIZE_T kter = row - 1; kter > 0; --kter ){
					
					// Set the current value equal to the value to the left 
					game_board.at( kter ).at( col ) = game_board.at( kter - 1 ).at( col );
				}
				
				// Set the leftmost value in the row equal to 0
				game_board.at( 0 ).at( col ) = 0;
			}
		}
	}	
}