/**********************************************
* File: nameGood2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of fixing namespace conflict
* and simplifying using compiler directives
*
* Lecture 02 - Part 2 - Slide 13
**********************************************/
#include <iostream>

// Compiler Directives 
#define COUT std::cout
#define ENDL std::endl
#define FOO_COUT foo::cout

namespace foo{
	
	int cout(){
		return 10;
	}
	
}


int main(){
	
	COUT << FOO_COUT() << ENDL;
	
}
