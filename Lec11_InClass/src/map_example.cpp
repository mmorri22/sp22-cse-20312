#include <iostream>
#include <vector>
#include <map>

#define COUT std::cout
#define ENDL std::endl

int main()
{
    // Initialize the Map
    std::map< int, std::string > map_pair;
    
    // Create the Vectors for the ordering 
    std::vector< int > ordering = { 4, 1, 7, 3, 2, 5, 6 };
    std::vector< std::string > names = {"Josh", "Greg", "Savannah", "Mike", "McKenna", "Eirinn", "Patrick"};
    
    // Insert the values into the std::map 
    // the size() method for std::vector returns a long unsigned int!
    for( long unsigned int iter = 0; iter < ordering.size() ; ++iter ){
        
		COUT << "Inserting: " << ordering.at(iter) << ", " << names.at(iter) << ENDL;
		
		// Use the { first, second } to create a static std::pair
        map_pair.insert( { ordering.at(iter), names.at(iter) } );
    }
    
	// Use const std::pair< int, std::string > to use the smart iterator
    for( const std::pair< int, std::string >& curr_val : map_pair ){
		
        COUT << curr_val.first << " " << curr_val.second << ENDL;
		
    }   

    return 0;
}