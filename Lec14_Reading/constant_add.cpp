#include <iostream>
#include <cstdlib>

int main( const int argc, const char* argv[] )
{

    if( argc != 2 )
        return EXIT_FAILURE;
        
    std::cout << atoi(argv[1]) + 10 << std::endl;
    
    return EXIT_SUCCESS;
}