#include <iostream>
#include <vector>


int main(){
    
    std::vector<int> subset;
	int size = 3;
    
	for (int bit = 0; bit < ( 1 << size); ++bit) {
		
		std::vector<int> subset;
		
		for (int i = 0; i < size; ++i) {
			
			if (bit & ( 1 << i ) ) 
				subset.push_back(i);
		}
		
        std::cout << "{ ";
		
		if( subset.size() == 0 ){
			std::cout << "Empty Set ";
		}
		
		for( int values : subset ){
			std::cout << values << " ";
		}
		std::cout << "}, ";
	}
	
	std::cout << std::endl;
    
    return EXIT_SUCCESS;
}