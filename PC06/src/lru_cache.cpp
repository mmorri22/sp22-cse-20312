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
		

}


void put_value( dllist& cache_list, UNOR_MAP< int, dllist_node* >& cache_map, 
    int insert_data, int num_accesses ){


}
