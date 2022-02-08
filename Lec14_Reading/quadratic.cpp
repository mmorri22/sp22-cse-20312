#include <iostream>
#include <cstdlib>

int main( const int argc, const char* argv[] )
{

    if( argc != 3 )
        return EXIT_FAILURE

    int iter_max = atoi( argv[1] );
    int jter_max = atoi( argv[2] ); 
    for( int iter = 0; iter < iter_max; ++iter ){
        
        for( int jter = 0; jter < jter_max; ++jter ){
        
            int inside = iter + jter;
            inside *= 2;
        }
    }

    return 0;
}