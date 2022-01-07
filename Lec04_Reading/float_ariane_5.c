#include <stdio.h>

int main( void ){

	// Largest number that can be save in a float
	double the_double = 0x1.fffffep+127;

	float the_float = the_double;

	fprintf( stdout, "The double and the float = %lf %f\n", the_double, the_float );

	fprintf( stdout, "Now we add 1 to the_double and try to save to the float!\n" );

	// One bit greater than can be held in a float
	the_double = 0x1.ffffffp+127;
	the_float = the_double;	// Ariane 5 Error!

	fprintf( stdout, "The double and the float = %lf %f\n", the_double, the_float );

	return 0;

}
