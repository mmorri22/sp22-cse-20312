#include <iostream>
#include <set>
#include <ctime>

#define COUT std::cout
#define ENDL std::endl

int main()
{
    // Set the random number generator
    srand( (unsigned int)time(0) );
    
	// Create the set
    std::set< int > int_set;
    
	// Insert random values into the Tree
    COUT << "Inserting: ";
    for( int iter = 0; iter < 7; ++iter ){
        
        int rand_val = rand() % 25;
        COUT << rand_val << " ";
        int_set.insert( rand_val );
        
    }
    COUT << ENDL;
    
	// Using the C++ Smart Iterator, Print the addresses and values 
    COUT << "Set's base address: " << &int_set << ENDL;
    for( const int& curr_val : int_set ){
		
        COUT << curr_val << " " << &curr_val << ENDL;
		
    }   

    return 0;
}