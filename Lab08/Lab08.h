#ifndef LAB09_H
#define LAB09_H

#include <iostream>
#include <vector>
#include <algorithm>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

template< class T >
void printVector( const VECTOR<T>& printVec ){
	
   COUT << "{ ";
   
	for(long unsigned int iter = 0; iter < printVec.size(); iter++){
		COUT << printVec.at(iter) << " ";
	}
   
   COUT << "}" << ENDL ;
	
}


template< class T >
void printVecVec( const VECTOR< VECTOR<T> >& printVec ){
	
   COUT << "{";
   
	for(long unsigned int iter = 0; iter < printVec.size(); iter++){
		
		COUT << " { ";
		
		for(long unsigned int jter = 0; jter < printVec.at(iter).size(); jter++){
		
			COUT << printVec.at(iter).at(jter) << " ";
		
		}
		
		COUT << "} ";
	}
   
   COUT << "}" << ENDL ;
	
}

bool cmp(VECTOR<int> a, VECTOR<int> b){
	
	return a[0]<b[0];
	
}


int max( int& value1, int& value2 ){
	
	return (value1 > value2) ? value1 : value2;
	
}


int min( int& value1, int& value2 ){
	
	return (value1 < value2) ? value1 : value2;
	
}



VECTOR< VECTOR<int> > insert( VECTOR< VECTOR<int> >& intervals, VECTOR <int>& newInterval) {
	
	// Your lab work will go here 
	
}

#endif