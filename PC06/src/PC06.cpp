#include "../include/lru_cache.h"

int main( ){
	
	// Create the new dllist
	dllist cache_list( initialize_cache() );
	
	// Hash Map with the dllist node and the time stamp
	UNOR_MAP< int, dllist_node* > cache_map;
	
	char continue_read = 'y';
	
	int num_accesses = 0;
	
	while( continue_read == 'y' ){
	    
	    // Increment the number of accesses
	    ++num_accesses;
	    
	    char user_choice = get_user_choice( );
	   
		switch( user_choice ) {
				
			case 'p':
				int next_data;
				COUT << "You selected put. Insert a data value to place at the next address: ";
				CIN >> next_data;
				
				// Put the value 
				put_value( cache_list, cache_map, next_data, num_accesses );

				break;
				
			case 'g':
				int get_location;
				COUT << "You selected get. Select a data to get from the cache: ";
				
				CIN >> get_location;
				
				// Get and promote the value
				get_value( cache_list, cache_map, get_location, num_accesses );	
				
				break;
				
			default:
				COUT << "Value must be between 1 and 3" << ENDL;
			
		}
		
		// Print the update list to the user
		cache_list.print_list();
	    
	    COUT << "Do you wish to continue? (y/n): ";
	    CIN >> continue_read;
	    
	}
	
	return EXIT_SUCCESS;
}