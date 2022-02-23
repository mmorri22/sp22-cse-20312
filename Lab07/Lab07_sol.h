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
	VECTOR< VECTOR<SIZE_T> > matrix( (string1.size() + 1), VECTOR<SIZE_T>(string2.size() + 1, 0)  );
		
	SIZE_T result = 0;
		
	COUT << ENDL << "Initial Matrix" << ENDL;
	
	printMatrix( matrix );
	
	// Perform the algorithm 
	for( SIZE_T iter = 0; iter < string1.size(); iter++ ){
		
		for( SIZE_T jter = 0; jter < string2.size(); jter++ ){
		
			if( string1.at(iter) == string2.at(jter) ){
				
				matrix.at(iter + 1).at( jter + 1 ) = matrix[iter][ jter ] + 1;
				
				if( matrix.at(iter + 1).at( jter + 1 ) > result ){
					
					result = matrix.at(iter + 1).at( jter + 1 );
				}

			}
			else{
				
				if( matrix.at( iter ).at( jter + 1 ) > matrix.at( iter + 1).at( jter ) ){
					
					matrix.at(iter + 1 ).at( jter + 1 ) = matrix.at( iter ).at( jter + 1 );
				}
				else{
					
					matrix.at(iter + 1).at(jter + 1) = matrix.at( iter + 1 ).at( jter );
				}
			}
		}
	}
	
	COUT << ENDL << "Final Matrix" << ENDL;
	
	printMatrix( matrix );
	
	return result;
}


#endif