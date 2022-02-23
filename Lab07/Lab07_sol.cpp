#include "Lab07.h"


int main( const int argc, const char* argv[] ){
	
	if( argc != 3 ){
		COUT << "Incorrect Number of Inputs" << ENDL;
		
		return EXIT_FAILURE;
	}
	
	STRING string1( argv[1] );
	STRING string2( argv[2] );
	
	COUT << string1 << " " << string2 << ENDL;
	COUT << "The LCS solution is " << LCS( string1, string2 ) << ENDL;
	
	COUT << "-------------------------------------" << ENDL << ENDL;
	COUT << string2 << " " << string1 << ENDL;
	COUT << "The LCS solution is " << LCS( string2, string1 ) << ENDL;
	
	return 0;
	
}