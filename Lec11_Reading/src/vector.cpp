#include <iostream>
#include <vector>

int main()
{

    std::vector<int> int_vector;
    
    for( int iter = 0; iter < 17; ++iter ){
        
        int_vector.push_back( iter );
        
    }
    
    for( int iter = 0; iter < 17; ++iter ){
        
        std::cout << int_vector.at(iter) << " ";
    }
    std::cout << std::endl;

    return 0;
}