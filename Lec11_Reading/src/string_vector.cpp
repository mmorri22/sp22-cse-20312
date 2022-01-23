#include <iostream>
#include <vector>
#include <string>

#define COUT std::cout
#define ENDL std::endl 
#define VECTOR std::vector
#define STRING std::string

int main( const int argc, const char* argv[] )
{
    
    VECTOR< STRING > string_vector;
    
    for( int iter = 1; iter < argc; ++iter ){
        
        string_vector.push_back( argv[iter] );
        
        COUT << "Size: " << string_vector.size() 
            << ", Capacity: " << string_vector.capacity() << ENDL;
        
    }
	
	for( long unsigned int jter = 0; jter < string_vector.size(); ++jter ){
		
		COUT << string_vector.at( jter ) << " ";
	}
	COUT << ENDL;

    return 0;
}