#include "../include/Treap4.h"
#include <cstdlib> 
#include <ctime>
#include <vector>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	// Call srand exactly once
	srand( (unsigned)time(0) ); 
	
	/* Dynamic Array with 100 unsigned ints initialized to 0 */
	std::vector< unsigned int > distribution( 100, 0 );
	
	// Run the test 1000000 times 
	for( unsigned int iter = 0; iter < 10000000; iter++ ){
		
		Treap< int > tempTreap;
		
		// Insert 100 random elements
		for( unsigned int jter = 0; jter < 100; jter++ ){
			tempTreap.Insert( rand() % 100 );
		}
		
		// Get the max height of the tree
		unsigned int tempMaxHeight = tempTreap.maxHeight();
		
		// Increment the distribution by 1
		distribution[tempMaxHeight]++;
		
	}
	
	// Print the distribution
	for( unsigned int iter = 0; iter < 100; iter++ ){
		if( distribution.at(iter) != 0 ){
			COUT << iter << " " << distribution.at(iter) << ENDL;
		}			
	}
	
	return 0;
}
