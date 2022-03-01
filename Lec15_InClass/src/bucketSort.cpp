/**********************************************
* File: bucketSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Bucket Sort 
* using the C++ STL Libraries
**********************************************/
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <iostream>

int HashFunc(int value, int numBuckets){
	return value / numBuckets;
}


void insertVal(std::unordered_map<int, std::set<int> >& bucketSort, int value, int numBuckets){
	
	bucketSort[ HashFunc(value, numBuckets) ].insert(value);
	
}


void printHash(std::unordered_map< int, std::set<int> >& bucketSort, int numBuckets){

	for(int i = 0; i < numBuckets; i++){
		
		/* bucketSort[i] gives the bucket's Red-Black Tree */
		/* std::set returns curr as const, therefore const int required */
		for(const int& curr : bucketSort[i]){
			
			std::cout << curr << " ";
		}

	}
	
	std::cout << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){

	/* Hash Table for Bucket Sort */
	std::unordered_map<int, std::set<int> > bucketSort;
	
	/* Vector with Values to Sort */
	std::vector<int> theVals{78, 17, 39, 26, 72, 94, 21, 12, 23, 68};

	/* Initialize List */
	for(int i = 0; i < (int)theVals.size(); ++i){
		
		std::set<int> temp;
		bucketSort.insert( {i, temp} );
		
	}
	
	/* Insert the elements */
	for(int& curr : theVals){
		
		insertVal(bucketSort, curr, (int)theVals.size());
		
	}

	/* Print the Hash */
	printHash(bucketSort, (int)theVals.size());

	return 0;
}
