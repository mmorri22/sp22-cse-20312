#include "../include/DynArr.h"

#include <string>

#include <iostream>

int main(){

	DynArr<int> testArr;
	
	DynArr< std::string > theArray;

	testArr.push_back( 5);
	testArr.push_back( 6);
	
	std::cout << testArr[0] << std::endl;
	std::cout << testArr[1] << std::endl;

	testArr.erase( 0 );

	std::cout << testArr[0] << std::endl;
	
	testArr.erase( 0 );
	
	testArr.erase( 0 );	
	
	theArray.push_back( "test1" );
	theArray.push_back( "test2" );
	
		std::cout << theArray[0] << std::endl;
		std::cout << theArray[1] << std::endl;
		
	theArray.erase( 0 );

	std::cout << theArray[0] << std::endl;
	
	theArray.erase( 0 );
	
	theArray.erase( 0 );	


	return 0;

}
