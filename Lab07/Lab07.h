#ifndef LAB_07_H
#define LAB_07_H

#include <string>
#include <iostream>
#include <vector>

#define STRING std::string
#define VECTOR std::vector
#define COUT std::cout
#define ENDL std::endl
#define SIZE_T long unsigned int

void printMatrix( const VECTOR< VECTOR<SIZE_T> >& matrix ){
	
	
	/**********************************
	 * STEP 3: Practice with Smart Iterators for C++ STL 
	 *
	 * In this step, you will write a smart iterator similar
	 * to what we have learned in class as well as the readings
	 **********************************/
	
	for( VECTOR<SIZE_T> curr_vec : matrix ){
		
		for( SIZE_T curr_val : curr_vec ){
			
			COUT << curr_val << " ";
			
		}
		COUT << ENDL;
	}
	
	
}

SIZE_T LCS( STRING& string1, STRING& string2 ){
	
	
	/***************************************************
	 * STEP 4: Creating a Vector of Vector of long unsigned ints 
	 * The number of rows (aka the number of Vectors of SIZE_T) should 
	 * be the size of string1 + 1.
	 * For the columns, it should be the size of string2 + 1, with
	 * each integer set to 0
	 *****************************************************/
		
	SIZE_T result = 0;
		
	COUT << ENDL << "Initial Matrix" << ENDL;
	
	printMatrix( matrix );
	
	/***************************************************
	 * STEP 5: Iterating and Checking through the
	 * Vector of Vector of Strings to solve the Longest 
	 * Common Subsequence Problem
	 *****************************************************/
	 
	
	COUT << ENDL << "Final Matrix" << ENDL;
	
	printMatrix( matrix );
	
	return result;
}


#endif