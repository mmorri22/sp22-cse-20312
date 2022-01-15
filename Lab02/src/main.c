#include "../include/sllist.h"

int main(){
	
	// Leave the head_node initially NULL for empty
	struct sllist the_list = { NULL };
	
	// Push elements into the list
	push_front( &the_list, 10 );
	push_front( &the_list, -20 );
	push_front( &the_list, 15 );
	push_front( &the_list, -4 );
		
	// Iterator pointer 
	print_list( &the_list );
	
	// Pop and Print 
	while( pop_front( &the_list ) ){
	
		print_list( &the_list );
		
		fprintf( stdout, "-----------\n" );
	
	}
	
	// Delete the list 
	delete_node( &(the_list.head_node) );
	
	return EXIT_SUCCESS;	
	
}
