#include <iostream>
#include <vector>

int main()
{

    std::vector<int> int_vector;
    
    for( int iter = 0; iter < 17; ++iter ){
        
        int_vector.push_back( iter );
		
        std::cout << "Vector size: " << int_vector.size();
		std::cout << ", Vector capacity: " << int_vector.capacity();
		std::cout << ", Element address: " << &int_vector.at(iter);
		std::cout << ", Element value " << int_vector.at(iter) << std::endl;
    }

    std::cout << std::endl;

    return 0;
}