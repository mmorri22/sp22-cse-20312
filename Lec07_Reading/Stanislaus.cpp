#include <iostream>
#include <vector>
#include "../classes/stack.h"
#include "../classes/Stanislaus.h"

void solveEqn(int testNum, unsigned int len, char* test, int* arity, Stanislaus& stanis){

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Test " << testNum << "..." << std::endl;
		
	for(unsigned iter = 0; iter < len; iter++){
		
		std::cout << "Pushing " << test[iter] << " at " << arity[iter] << std::endl;
		
		stanis.push( test[iter], arity[iter] - 1 );
	}
	
	std::cout << std::endl << "Running ALGOL... " << std::endl;
	
	std::cout << "The final solution is " << stanis.runALGOL() << std::endl;	
	
}


int main(){
	
	// Initialize the Simulator
	Stanislaus stanis;
	
	// Test 1
	char test1[9]  = { 'C','I','1','N','0','I','N','1','0' };
	int arity1[9]  = { 1,2,3,3,4,2,3,4,3 };
	
	solveEqn(1, 9, test1, arity1, stanis);
	
	
	// Test 2
	char test2[42]  = { 'N', 'D','I','C','D','I','N','1', '1',
		'I', 'C', '1', 'N', '1', 'C', '1', 'D', '1', '1', '1', '1',
		'C', 'D', 'I', 'N', '1', 'N', '1', '1',
		'D', 'I', '1', '1',
		'C', 'D', '1', 'N', '1',
		'D', 'N', '1', '1'
	};
		
	int arity2[42]  = { 1, 2, 3, 4, 5, 6, 7, 8, 7, 	
		6, 7, 8, 8, 9, 7, 8, 8, 9, 9, 5, 6,			
		3, 4, 5, 6, 7, 6, 7, 4,
		4, 5, 6, 6,	
		5, 6, 7, 7, 8,	
		6, 7, 8, 7
		
	};
	
	solveEqn(2, 42, test2, arity2, stanis);
	
	return 0;
	
}