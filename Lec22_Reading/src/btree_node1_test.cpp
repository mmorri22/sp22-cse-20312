#include "../include/btree_node1.h"

#include <string>
#define STRING std::string

int main(){
	
	btree_node<int> node_order_3(3);
	btree_node<STRING> node_order_4(4);
	
	return EXIT_SUCCESS;
}