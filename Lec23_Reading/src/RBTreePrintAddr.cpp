#include "../inc/RBTree.h"
#include <string>

/********************************************
* Function Name  : insertAndPrint
* Pre-conditions : RBTree<T>* tree, T value
* Post-conditions: none
*  
*  Inserts into the Red-Black Tree and prints the
*  in-order and level order traversal to the user
********************************************/
template<class T>
void insertAndPrint(RBTree<T>* tree, T value){

	std::cout << "Inserting: " << value << std::endl;
	std::cout << "rb_tree*: " << &tree << std::endl;
	tree->insert(value);
	tree->print_addresses( std::cout );
	
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* Main driver file for the program  
********************************************/
int main( const int argc, const char* argv[] ) { 

	RBTree<int>* tree = new RBTree<int>(); 
  
	// Showing the results of insertion and deletion
	// Insert: 20, 10, 30, 15, 17, 12, 35, 25, 13, and 9. 
	std::cout << "Red-Black Tree: Integer Template Insertion and Deletion" << std::endl;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		insertAndPrint( tree, temp );
		
	}
	
	delete tree;

	return 0; 
} 
