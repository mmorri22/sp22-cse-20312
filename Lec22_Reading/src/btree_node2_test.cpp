#include "../include/btree_node2.h"

#include <string>
#define STRING std::string

int main(){
	
	btree_node<int> node_order_3(3);
	btree_node<STRING> node_order_4(4);
	
	// Test Int Insert 
	node_order_3.insert( 10 );
	node_order_3.print_node();
	COUT << ENDL;
	
	node_order_3.insert( 7 );
	node_order_3.print_node();
	COUT << ENDL;	
	
	// Test String Insert 
	node_order_4.insert( "Zebra" );
	node_order_4.print_node();
	COUT << ENDL;
	
	node_order_4.insert( "Aardvark" );
	node_order_4.print_node();
	COUT << ENDL;	
	
	node_order_4.insert( "Horse" );
	node_order_4.print_node();
	COUT << ENDL;	
	
	return EXIT_SUCCESS;
}