#include "../include/SplayTree.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


void printSplayRoot(SplayTree< void * >& cacheSplay){
	
	std::cout << "Location " << cacheSplay.returnRootVal() << " contains the value ";
	
	std::cout << *( (int *)(cacheSplay.returnRootVal()) );
	
}

int main(){
	
	// Seed the Random Number Generator
	srand ( (unsigned int)time(NULL) );	
	
	// Create an integer array of 100 elements
	int* intCache = new int[100];
	
	SplayTree< void * > cacheSplay;
	
	for(unsigned int i = 0; i < 100; i++){
		
		intCache[i] = i*2;
		cacheSplay.Insert( (intCache + i) );
		
	}
	
	printSplayRoot( cacheSplay );
	
	std::cout << "-------------" << std::endl;
	std::cout << cacheSplay << std::endl;
	
	return 0;
	
}
