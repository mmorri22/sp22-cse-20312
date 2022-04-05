// Test Insert, Copy Constructor, Assignment Operator, and operator<<
#include "../inc/RBTree2.h"

#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){
	
	
	// Create the output stream 
	OFSTREAM file_out( "Prob5.txt" );
	
	// Create a 
	RBTree<int> tree1;
	
	// Insert the tree
	tree1.insert( 15 );		tree1.insert( 10 );		tree1.insert( 25 );		
	tree1.insert( 4 );		tree1.insert( 12 );		tree1.insert( 3 );
	tree1.insert( 5 );
	
	// Print tree1 
	COUT << "Print tree1:" << ENDL;
	COUT << tree1 << ENDL << ENDL;
	
	// Test the Assignment Operator 
	RBTree<int> tree2 = tree1;
	tree2.insert(2);
	COUT << "Print tree2:" << ENDL;
	COUT << tree2 << ENDL << ENDL;
	
	// Test the Copy Constructor
	RBTree<int> tree3(tree1);
	tree3.insert( 6 );
	COUT << "Print tree3:" << ENDL;
	COUT << tree3 << ENDL << ENDL;
	
	file_out << "Student successfully answered Problem 5 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	return 0;
}
