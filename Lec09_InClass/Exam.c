#include <stdio.h>
#include <stdlib.h>

int main(const int argc, const char* argv[] )
{
    
    long unsigned int array_len = 5;
    int* array_1 = (int *)malloc( array_len * sizeof(int) );
    *(array_1 + 0) = 7;
    *(array_1 + 1) = 2;
    *(array_1 + 2) = 1;
    *(array_1 + 3) = -44;
    *(array_1 + 4) = 16;
    
    fprintf( stdout, "%p %d\n", &argc, argc );
    fprintf( stdout, "%p %p\n", &argv, argv );

    
    int iter;
    for( iter = 0; iter < argc; ++iter ){
        fprintf( stdout, "%p %p %s\n", &argv[iter], argv[iter], argv[iter] );
    }
    
    fprintf( stdout, "%p %p\n", &array_1, array_1 );

    long unsigned int jter;
    for( jter = 0; jter < array_len; ++jter ){
        
        fprintf( stdout, "%d %p\n", array_1[jter], &array_1[jter] );
    }

    
    free( array_1 );

    return 0;
}
