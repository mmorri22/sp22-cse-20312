#include <stdio.h>

int main( void ){

	double the_double = 0.3;
	double comp_double = 0.1;

	the_double -= 0.2;

	fprintf( stdout, "%lf %lf\n", the_double, comp_double);

	if( the_double == comp_double ){
		fprintf( stdout, "They match!\n" );
		fprintf( stdout, "%la %la\n", the_double, comp_double );
		fprintf( stdout, "%.23lf %.23lf\n", the_double, comp_double );
	}

	else{

		fprintf( stdout, "They do not match!\n" );
		fprintf( stdout, "%la %la\n", the_double, comp_double );
		fprintf( stdout, "%.23lf %.23lf\n", the_double, comp_double );
	}

	return 0;

}
