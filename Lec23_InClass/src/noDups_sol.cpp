#include <iostream>
#include <set>

#define COUT std::cout
#define ENDL std::endl
#define SET std::set

void print_set( const SET<int>& print_set ){
	
	for( const int& curr_int : print_set )
		COUT << curr_int << " ";
	
	COUT << ENDL;
	
}

void emplace( SET<int>& print_set, const int insert_int ){
	
	if( print_set.count( insert_int ) != 0 )
		print_set.erase( insert_int );
	
	else
		print_set.insert( insert_int );
	
}

int main( const int argc, const char* argv[] ){
	
	SET<int> solution_set;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int insert_int = atoi( argv[iter] );
		
		emplace( solution_set, insert_int );
	}
	
	print_set( solution_set );
	
	return 0;
	
}