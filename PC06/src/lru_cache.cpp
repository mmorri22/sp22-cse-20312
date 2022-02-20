#include "../include/lru_cache.h"

char get_user_choice( ){
	
	COUT << "Enter your choice: " << ENDL;
	COUT << "p: Put value onto cache" << ENDL;
	COUT << "g: Get value from cache" << ENDL;
	COUT << "Enter your choice: ";
	
	char user_choice;
	
	CIN >> user_choice;
	
	return user_choice;
	
}


SIZE_T initialize_cache( ){
	
	COUT << "State the size of the cache: ";
	
	int capacity;
	
	CIN >> capacity;
	
	return capacity;
}


void get_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    const int insert_data, int num_accesses ){
		
	if( cache_map.count( insert_data ) != 0 ){
		
		COUT << insert_data << " is in the cache. Cache hit!" << ENDL;
    
		dllist_node* index_to_promote = cache_map[insert_data];
		
		// Goes directly to the *index* and removes the element in O(1) time
		cache_list.promote_node_to_front( index_to_promote, num_accesses );
	
	}
	else{
		
		COUT << insert_data << " is not in the cache. Cache miss!" << ENDL;
	}    
}


void put_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    int insert_data, int num_accesses ){
    
	if( cache_map.count( insert_data ) == 0 ){
		
		COUT << insert_data << " is not in the cache." << ENDL;
	
		if( cache_list.at_capacity() ){
			
			cache_list.pop_back();
			
			cache_map.erase( insert_data );
			
		}
		
		// Create a memory element 
		dllist_node* inserted_node = cache_list.push_front( insert_data, num_accesses );
		
		// Push the element on the front of the linked list 
		cache_map.insert( { insert_data, inserted_node } );	
	}
	else{
		
		COUT << insert_data << " is already in the cache." << ENDL;
		
		get_value( cache_list, cache_map, insert_data, num_accesses );
		
	}
}
