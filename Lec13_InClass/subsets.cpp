#include <iostream>
#include <vector>

std::vector<int> return_subsets( const std::vector<int>& numbers ){
	
	// size_t is a C++ version of long unsigned int
	std::vector<int> solutions;

	// size_t is a C++ version of long unsigned int	
    for( size_t iter = 0; iter < numbers.size(); ++iter ){
    
        for( size_t jter = iter + 1; jter < numbers.size(); ++jter ){
        
            for( size_t kter = jter + 1; kter < numbers.size(); ++kter ){
            
				int value_1 = numbers.at(iter);
				int value_2 = numbers.at(jter);
				int value_3 = numbers.at(kter);
				int sum = value_1 + value_2 + value_3;
			
				// Push all the integers onto the vector
                if( sum % 3 == 0 ){
					solutions.push_back(value_1);
					solutions.push_back(value_2);
					solutions.push_back(value_3);
				}
            }
        }
    }
	
	return solutions;
}   

void print_subsets( const std::vector<int>& solutions ){
	
	std::cout << "Number of solutions = " << solutions.size() / 3 << std::endl;
	
	// Iterate through the entire vector
	for( size_t iter = 0; iter < solutions.size(); ++iter ){
		
		// When iter = 2, iter + 1 = 3, therefore we have reached the correct mod
		if( (iter + 1) % 3 == 0 ){
			
			std::cout << "{" << solutions.at( iter - 2 ) << ", ";
			std::cout << solutions.at( iter - 1 ) << ", ";
			std::cout << solutions.at( iter ) << "} = ";
			std::cout << solutions.at( iter - 2 ) + solutions.at( iter - 1 ) + solutions.at( iter ) << std::endl;
		}
	}
}
    
int main( const int argc, const char* argv[] ) {
	
	if( argc < 4 )
		return EXIT_FAILURE;
    
    std::vector<int> numbers;
	
	for(int iter = 1; iter < argc; ++iter ){
		
		numbers.push_back( atoi( argv[iter] ) );
	}
	
	std::vector<int> solutions = return_subsets( numbers );

    print_subsets( solutions );

	return 0;
}