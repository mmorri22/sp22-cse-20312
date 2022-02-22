#include "../include/lru_cache.h"

int main( ){
	
	/*************************************
	 * Here, you will call the constructor for the Doubly Linked List 
	 * and create the unordered_map with the int, dll_node* key value pair
	 ************************************/
	
	char continue_read = 'y';
	
	int num_accesses = 0;
	
	while( continue_read == 'y' ){
	    
	    // Increment the number of accesses
	    ++num_accesses;
	    
	    char user_choice = get_user_choice( );
	   
		switch( user_choice ) {
				
			case 'p':
				
				/*************************************
				 * Here, you will get the input data value from the user 
				 * and then call the put function
				 ************************************/				

				break;
				
			case 'g':
			
				/*************************************
				 * Here, you will get the input data value from the user 
				 * and then call the get function
				 ************************************/	
				
				break;
				
			default:
				COUT << "Value must be between 1 and 3" << ENDL;
			
		}
		
		/*************************************
		 * Here, you will call print_list on your doubly linked list 
		 ************************************/			
	    
	    COUT << "Do you wish to continue? (y/n): ";
	    CIN >> continue_read;
	    
	}
	
	/*************************************
	 * Note: Since you will be calling the constructor for dllist 
	 * without making it a pointer, the destructor will 
	 * automatically be called, so you do not need to call it!
	 ************************************/
	
	return EXIT_SUCCESS;
}