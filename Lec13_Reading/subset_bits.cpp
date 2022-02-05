#include <iostream>
#include <vector>


int main(){
   
	int size = 3;
    
	std::cout << (1 << size) << std::endl;
	
	for (int bit = 0; bit < ( 1 << size ); ++bit) {
		
		// Create an empty vector
		std::vector<int> subset;
		
		// Iterate through the size
		for (int iter = 0; iter < size; ++iter) {
			
			// If the integer value of the bit and 
			if (bit & ( 1 << iter ) ) 
				subset.push_back(iter);
		}
		
        std::cout << "{ ";
		
		if( subset.size() == 0 ){
			std::cout << "Empty Set ";
		}
		
		// Use the C++ Smart Iterator
		for( int values : subset ){
			std::cout << values << " ";
		}
		std::cout << "}, ";
	}
	
	std::cout << std::endl;
    
    return EXIT_SUCCESS;
}