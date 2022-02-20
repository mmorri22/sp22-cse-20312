#include <iostream>
#include <vector>
#include <unordered_map>

#define COUT std::cout 
#define CIN std::cin
#define ENDL std::endl
#define SIZE_T long unsigned int
#define VECTOR std::vector 


struct memory_element{
	
	int data;
	int time_val;
};

VECTOR< memory_element > initialize_cache( ){
	
	COUT << "State the size of the cache: ";
	
	int capacity;
	
	CIN >> capacity;
	
	VECTOR< memory_element > cache( capacity );
	
	return cache;
}

void print_cache( const VECTOR< memory_element >& the_cache ){
    
    for( SIZE_T iter = 0; iter < the_cache.size(); ++iter ){
        
        COUT << iter << ": " << the_cache.at( iter ).time_val; 
		
		COUT << ", " << the_cache.at( iter ).data << ENDL;
        
    }
}

int main( const int argc, const char* argv[] ){
	
	VECTOR< memory_element > the_cache = initialize_cache();
	
	char continue_read = 'y';
	
	while( continue_read == 'y' ){
	    
	    // Print the current status of the cache 
	    print_cache( the_cache );
	    
	    COUT << "Do you wish to continue? (y/n): ";
	    CIN >> continue_read;
	}
	
	return EXIT_SUCCESS;
}