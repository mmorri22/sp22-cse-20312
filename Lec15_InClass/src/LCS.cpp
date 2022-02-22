#include "../include/LCS.h"


int main(){
	
	STRING string1 = "LACBF";
	STRING string2 = "BADCBQ";
	
	COUT << string1 << " " << string2 << ENDL;
	COUT << "The LCS solution is " << LCS( string1, string2 ) << ENDL;
	
	COUT << "-------------------------------------" << ENDL << ENDL;
	COUT << string2 << " " << string1 << ENDL;
	COUT << "The LCS solution is " << LCS( string2, string1 ) << ENDL;
	

	STRING string3 = "ABEDAF";
	STRING string4 = "ACBEF";
	
	COUT << "-------------------------------------" << ENDL << ENDL;
	COUT << string3 << " " << string4 << ENDL;
	COUT << "The LCS solution is " << LCS( string3, string4 ) << ENDL;

	COUT << "-------------------------------------" << ENDL << ENDL;
	COUT << string4 << " " << string3 << ENDL;
	COUT << "The LCS solution is " << LCS( string4, string3 ) << ENDL;
	
	return 0;
	
}