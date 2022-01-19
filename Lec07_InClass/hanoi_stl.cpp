#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>

#define VECTOR std::vector
#define STACK std::stack
#define COUT std::cout
#define ENDL std::endl


void move( STACK<int>& source, STACK<int>& destination, int& numMoves){
	
	// De-reference and Increment the number of moves
	++numMoves;
	
	// Get the data from the head node, and push on the top
	destination.push( source.top() );
	
	// Remove the element from the source
	source.pop();
	
}


void hanoi( int n, STACK<int>& source, STACK<int>& destination, STACK<int>& auxillary, int& numMoves){
		
	if( n > 0 ){
		
		hanoi( n-1, source, auxillary, destination, numMoves );
		
		move( source, destination, numMoves );
		
		hanoi( n-1, auxillary, destination, source, numMoves );
	}
}


int main( const int argc, const char* argv[] ){


	if( argc != 2 ){
		
		COUT << "Incorrect number of inputs" << ENDL;
		return EXIT_FAILURE;
		
	}
	
	// Get the Stack Size 
	int stack_size = atoi( argv[1] );
	
	// Track the number of moves 
	int num_moves = 0;
	
	// Dynamically allocate three stacks  
	STACK<int> tower_1;
	STACK<int> tower_2;
	STACK<int> tower_3;
	
	
	// Insert elements in reverse
	int iter;
	for( iter = stack_size; iter > 0; --iter ){
		
		tower_1.push( iter );
		
	}
	
	// Run the algorithm
	hanoi( stack_size, tower_1, tower_2, tower_3, num_moves );
	
	COUT << stack_size << " plates moved in " << num_moves << " moves" << ENDL;
	
	return EXIT_SUCCESS;
}