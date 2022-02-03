/**********************************************
* File: namespace.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of when using namespace can be bad 
*
* Lecture 02 - Part 2 - Slide 10
**********************************************/
#include <iostream>

namespace foo{
	
	int cout(){
		return 10;
	}
}

using namespace std;
using namespace foo;

int main(){
	
	cout << cout() << endl;
	
	return 0;
}
