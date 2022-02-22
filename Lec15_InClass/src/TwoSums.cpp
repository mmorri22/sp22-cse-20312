#include "../include/3Sums.h"

int main(){
	
	COUT << "Test 1:" << ENDL;
	std::vector<int> test1 = { 2, 7, 11, 15 };
	TwoSums( test1, 26 );
	TwoSums( test1, 18 );
	TwoSums( test1, 10 );

	COUT << ENDL << "Test 2:" << ENDL;	
	std::vector<int> test2 = { 44, 18, 99, 102, 55, 1, 7, 88, 206, 77, 67 };
	TwoSums( test2, 143 );
	TwoSums( test2, 144 );
	TwoSums( test2, 8 );
	TwoSums( test2, 56 );
	TwoSums( test2, 308 );
	TwoSums( test2, 100 );
	TwoSums( test2, 101 );
	
	return 0;
}

