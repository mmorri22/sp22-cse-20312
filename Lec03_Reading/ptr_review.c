#include <stdio.h>

int main()
{
    int x = 5;
    int* int_ptr = &x;
    
    fprintf( stdout, "The address of x = %p\n", &x );
    fprintf( stdout, "The data contained in x = %d\n", x );
    fprintf( stdout, "The address of int_ptr = %p\n", &int_ptr );
    fprintf( stdout, "The data contained in int_ptr = %p\n", int_ptr);
    fprintf( stdout, "The data at the address pointed to by int_pointer = %d\n", *int_ptr );

    return 0;
}
