#include <iostream>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <cmath>


#define COUT std::cout 
#define ENDL std::endl
#define MULTISET std::multiset

MULTISET<int> get_numbers( int happy_test ){
	
	MULTISET<int> all_numbers;
	
	while( happy_test != 0 ){
		
		int next_num = happy_test % 10;
		
		all_numbers.insert(all_numbers.begin(), next_num);
		
		happy_test /= 10;
		
	}
	
	return all_numbers;
}


int get_happy( const MULTISET<int>& all_numbers ){
	
	int new_happy = 0;
	
	for( int print_vec : all_numbers ){
		
		int square = print_vec * print_vec;
		
		new_happy += square;
	}
	
	return new_happy;
}


void print_vec( const MULTISET<int>& all_numbers ){
	
	for( int print_vec : all_numbers ){
		
		COUT << print_vec << " ";
		
	}
	
	COUT << ENDL;
}


int main( const int argc, const char* argv[] ){
	
	if( argc != 2 ){
		
		COUT << "Incorrect number of command line arguments" << ENDL;
		return EXIT_FAILURE;
	}
	
	int happy_test = atoi( argv[1] );
	
	int iter = 0;
	
	while( happy_test != 1 && iter < 20 ){
	
		COUT << "Checking Happy: " << happy_test << ENDL;
		
		MULTISET<int> all_numbers = get_numbers( happy_test );
		
		print_vec( all_numbers );
		
		happy_test = get_happy( all_numbers );
		
		++iter;
			
	}
	
	COUT << "Solution: " << happy_test << ENDL;

	return EXIT_SUCCESS;
}