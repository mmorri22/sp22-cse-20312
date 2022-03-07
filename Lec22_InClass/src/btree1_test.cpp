#include "../include/btree1.h"

#include <string>
#define STRING std::string

int main(){
	
	btree< int > tree_order_3(3);
	
	btree< STRING > tree_order_4(4);
	
	return EXIT_SUCCESS;
};