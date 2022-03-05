#include "../include/btree2.h"

#include <string>
#define STRING std::string

int main(){
	
	btree< int > tree_order_3(3);
	
	btree< STRING > tree_order_4(4);
	
	// Test Int Insert 
	tree_order_3.insert( 10 );
	tree_order_3.print_tree();
	
	tree_order_3.insert( 7 );
	tree_order_3.print_tree();
	
	// Test String Insert 
	tree_order_4.insert( "Zebra" );
	tree_order_4.print_tree();
	
	tree_order_4.insert( "Aardvark" );
	tree_order_4.print_tree();
	
	tree_order_4.insert( "Horse" );
	tree_order_4.print_tree();
	
	return EXIT_SUCCESS;
};