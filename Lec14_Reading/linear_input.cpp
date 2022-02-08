#include <iostream>
#include <cstdlib>

int main( const int argc, const char* argv[] )
{

    if( argc != 2 )
        return EXIT_FAILURE

    int iter_max = atoi( argv[1] );
    for( int iter = 0; iter < iter_max; ++iter ){
        
        iter += 2;
    }

    return 0;
}