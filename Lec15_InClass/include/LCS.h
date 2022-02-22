#ifndef LCS_H
#define LCS_H

#include <string>
#include <iostream>
#include <vector>

#define STRING std::string
#define VECTOR std::vector
#define COUT std::cout
#define ENDL std::endl
#define SIZE_T long unsigned int

void printMatrix( const VECTOR< VECTOR<SIZE_T> >& matrix, SIZE_T rows, SIZE_T cols ){
	
	for( long unsigned int iter = 0; iter < rows; iter++ ){
		
		for( long unsigned int jter = 0; jter < cols; jter++ ){
			
			COUT << matrix.at(iter).at(jter) << " ";
			
		}
		COUT << ENDL;
	}
	
	
}

SIZE_T LCS( STRING& string1, STRING& string2 ){
	
	
	VECTOR< VECTOR<SIZE_T> > matrix( (string1.size() + 1), VECTOR<SIZE_T>(string2.size() + 1, 0)  );
		
	SIZE_T result = 0;
		
	COUT << "Initial Matrix" << ENDL;
	
	printMatrix( matrix, string1.size() + 1, string2.size() + 1 );
	
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
	
	COUT << "Final Matrix" << ENDL;
	
	printMatrix( matrix, string1.size() + 1, string2.size() + 1 );
	
	return result;
}


#endif