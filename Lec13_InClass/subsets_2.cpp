#include <iostream>
#include <vector>

size_t initial_iteration( const std::vector<int>& numbers ){
	
	// size_t is a C++ version of long unsigned int
	size_t count = 0;
	
    for( size_t iter = 0; iter < numbers.size(); ++iter ){
    
        for( size_t jter = iter + 1; jter < numbers.size(); ++jter ){
        
            for( size_t kter = jter + 1; kter < numbers.size(); ++kter ){
            
				int value_1 = numbers.at(iter);
				int value_2 = numbers.at(jter);
				int value_3 = numbers.at(kter);
				int sum = value_1 + value_2 + value_3;
			
                if( sum % 3 == 0 ){
					
					std::cout << value_1 << " + ";
					std::cout << value_2 << " + ";
					std::cout << value_3 << " = ";
					std::cout << sum << std::endl;
					
					++count;
				}
            }
        }
    }
	
	return count;
}   
    
int main( ) {
    
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 

    std::cout << "Total combinations = " << initial_iteration( numbers ) << std::endl;

	return 0;
}