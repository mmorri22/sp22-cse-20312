/**********************************************
* File: countSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Counting Sort
* using the C++ STL Libraries
**********************************************/
#include <unordered_map>
#include <forward_list>
#include <string>
#include <iostream>

void printHash(std::unordered_map< int, int >& countSort, int largestNum){

	for(int i = 0; i <= largestNum; i++){
		
		for(int j = 0; j < countSort[i]; ++j){
			
			std::cout << i << " ";
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

	/* The Hash Table for the Counting Sort */
	std::unordered_map<int, int> countSort;
	
	/* A singly-linked list of values to sort */
	std::forward_list<int> theVals{7, 1, 5, 7, 1, 4, 100};
	
	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;
	for(int& curr : theVals){
		
		if(curr > largestNum){
			largestNum = curr;
		}
		
	}
	
	/* Initialize List */
	for(int i = 0; i <= largestNum; i++){
		countSort.insert( {i, 0} );
	}
	
	/* Implement the counting sort */
	/* Increment each bucket when it is hashed */
	for(int& curr : theVals){
		countSort[ curr ]++;
	}

	/* Print the Hash */
	printHash(countSort, largestNum);

	return 0;
}
