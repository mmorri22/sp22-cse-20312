#include "../include/3Sums.h"

void test1(){
	
	VECTOR<int> test1 = {-1, 0, 1, 2, -1, -4};
	
	COUT << "Original Array: ";
	printVec( test1 );
	COUT << ENDL;
	
	std::random_shuffle ( test1.begin(), test1.end() );	
	std::sort( test1.begin(), test1.end() );

	COUT << "Sorted Array  : ";	
	printVec( test1 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSum( test1 );
	
	printVecVec( results );
	
}


void test2(){
	
	VECTOR<int> test2 = {-1, 0, 1, 2, -1, 4};
	
	COUT << "Original Array: ";
	printVec( test2 );
	COUT << ENDL;
	
	std::random_shuffle ( test2.begin(), test2.end() );	
	std::sort( test2.begin(), test2.end()  );

	COUT << "Sorted Array  : ";	
	printVec( test2 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSum( test2 );
	
	printVecVec( results );
	
}


void test3(){
	
	VECTOR<int> test3 = {-7, 14, 22, 8, -9, 0, -3, -7, -8, -15, 9, 7, 24};
	
	COUT << "Original Array: ";
	printVec( test3 );
	COUT << ENDL;
	
	std::random_shuffle ( test3.begin(), test3.end() );	
	std::sort( test3.begin(), test3.end()  );

	COUT << "Sorted Array  : ";	
	printVec( test3 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSum( test3 );
	
	printVecVec( results );
	
}


int main(){
	
	
	test1();
	
	COUT << ENDL;
	
	test2();
	
	COUT << ENDL;
	
	test3();
	
	return 0;
	
}