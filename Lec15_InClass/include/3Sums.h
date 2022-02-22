#ifndef SUMS_H
#define SUMS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector
#define SIZE_T long unsigned int


void TwoSums( std::vector<int>& theValue, int target ){
	
	COUT << "Target is " << target << ", Array = ";
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		COUT << theValue.at(iter) << " ";
	}
	
	COUT << ENDL;
	
	std::unordered_map<int, long unsigned int> theHash;
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		theHash.insert( { theValue.at(iter), iter } );
		
	}
	
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		if( theHash.count( target - theValue.at(iter) ) != 0 ){
			
			COUT << "Sum found at elements [" << iter << ", " << theHash[ target - theValue.at(iter) ] << "]" << ENDL;
			
			// May assume exactly one solution, so return
			return;
		}
		
	}
	
	// If we get here, there is no solution
	COUT << "No pair adds to " << target << ENDL;
	
}


// Takes in sorted vectors and finds the 3Sum solution
VECTOR< VECTOR<int> > ThreeSum( VECTOR<int>& theValues ){
	
	VECTOR< VECTOR<int> > results;

	for (int iter = 0; iter < (int)theValues.size(); ++iter) {
		
		// Never let iter refer to the same value twice to avoid duplicates.
		if (iter != 0 && theValues[iter] == theValues[iter - 1]) 
			continue;
		
		int jter = iter + 1;
		int kter = (int)theValues.size() - 1;
		
		while (jter < kter) {
			if (theValues[iter] + theValues[jter] + theValues[kter] == 0) {
				results.push_back({theValues[iter], theValues[jter], theValues[kter]});
				++jter;
				
				// Never let jter refer to the same value twice (in results) to avoid duplicates
				while (jter < kter && theValues[jter] == theValues[jter-1]) 
					++jter;
			} 
			else if (theValues[iter] + theValues[jter] + theValues[kter] < 0) {
				++jter;
			} 
			else {
				--kter;
			}
		}
	}
	
	return results;
}


void printVec( const VECTOR<int>& the_Vec ){
	

	for( SIZE_T iter = 0; iter < the_Vec.size(); iter++ ){
			
		COUT << the_Vec.at(iter) << " ";
	}
	
	COUT << ENDL;
}


void printVecVec( const VECTOR< VECTOR<int> >& results ){
	

	for( long unsigned int iter = 0; iter < results.size(); iter++ ){
		
		for( long unsigned int jter = 0; jter < results.at(iter).size(); jter++ ){
			
			COUT << results.at(iter).at(jter) << " ";
		}
		COUT << ENDL;
	}
}


#endif