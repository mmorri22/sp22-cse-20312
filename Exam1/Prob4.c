#include <stdio.h>
#include <stdlib.h>

int main()
{

    int array_len = 13 * sizeof(float);

    void* void_array = malloc( array_len );
    void* reference = void_array;

    *( (float *)( void_array + 2*sizeof(float) ) ) = -22.7;

    fprintf( stdout, "%lf\n",  *( (float *)( void_array + 2*sizeof(float *) ) ) );

    free( void_array );
    free( reference );

    return 0;
}
