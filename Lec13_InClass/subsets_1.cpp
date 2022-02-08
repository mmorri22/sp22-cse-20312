#include <iostream>
#include <vector>

void initial_iteration( const std::vector<int>& numbers ){
    
	// size_t is a C++ version of long unsigned int
    for( size_t iter = 0; iter < numbers.size(); ++iter ){
    
        for( size_t jter = iter + 1; jter < numbers.size(); ++jter ){
        
            for( size_t kter = jter + 1; kter < numbers.size(); ++kter ){
            
                std::cout << numbers.at(iter) << " " << numbers.at(jter) << " " << numbers.at(kter) << std::endl;
            }
        }
    }
}   
    
int main( ) {
    
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

    initial_iteration( numbers );

	return 0;
}