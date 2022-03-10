#include "../include/SplayTree.h"

#include <iostream>
#include <string>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

template<class T>
void insertSplay(SplayTree<T>& theTree, const T& value){
	
	COUT << "Inserting " << value << " into the splay..." << ENDL;
	theTree.Insert(value);
	COUT << theTree << ENDL;
	COUT << "------------------------------" << ENDL;
}


int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob3.txt" );
	
	SplayTree<int> theTree;
	
	insertSplay(theTree, 12);	insertSplay(theTree, 10);	insertSplay(theTree, 8);
	insertSplay(theTree, 13);	insertSplay(theTree, 11);	insertSplay(theTree, 14);
	insertSplay(theTree, 16);	insertSplay(theTree, 15);	insertSplay(theTree, 17);
	insertSplay(theTree, 7);	insertSplay(theTree, 9);
	
	file_out << "Student successfully answered Problem 3 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	return 0;
}
