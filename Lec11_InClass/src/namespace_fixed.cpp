/**********************************************
* File: namespace_fixed.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of fixing the namespace conflict
* in namespace.cpp
**********************************************/
#include <iostream>

namespace foo{
	
	int cout(){
		return 10;
	}
}

int main(){
	
	std::cout << foo::cout() << std::endl;
	
	return 0;
	
}
