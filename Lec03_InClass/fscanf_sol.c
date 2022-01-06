#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int int_input;
    char* char_input = (char*)malloc( 25 * sizeof(char) );
    float float_input;
    double double_input;
    
    // fscanf anf fprintf will go here
    fscanf( stdin, "%d %s %f %lf", &int_input, char_input, &float_input, &double_input);
	fprintf( stdin, "%d %s %f %lf\n", int_input, char_input, float_input, double_input);
	
    free( char_input );
    
    return 0;
}






