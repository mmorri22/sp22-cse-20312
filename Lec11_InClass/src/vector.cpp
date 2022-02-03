#include <iostream>
#include <vector>

#define COUT std::cout
#define ENDL std::endl

int main()
{
    
    std::vector< int > int_vector;
    
    for( int iter = 0; iter < 10; ++iter ){
        int_vector.push_back( iter );
		COUT << "Vector size = " << int_vector.size() << ", ";
		COUT << "Vector capacity = " << int_vector.capacity() << ENDL;
    }
    
    COUT << &int_vector << ENDL;
    
    for( int iter = 0; iter < 10; ++iter ){
        COUT << int_vector.at( iter ) << " " << &int_vector.at( iter ) << ENDL;
    }   
	

    return 0;
}