#include <bitset>
#include <iostream>

/********************************************
* Function Name  : printBitset
* Pre-conditions : std::bitset<bitsetsize>& bitSums
* Post-conditions: none
* 
* Prints the bitset to the user 
********************************************/
template <size_t bitsetsize>
void printBitset(std::bitset<bitsetsize>& bitSums){
	
	for(int iter = 0; iter < bitsetsize; ++iter){
		std::cout << bitSums[iter] << "|";
	}
	std::cout << std::endl;
	
}
 
/********************************************
* Function Name  : subsetSum
* Pre-conditions : std::bitset<bitsetsize>& bitSums, const int arrNums[], int n
* Post-conditions: none
*
* Creates a bitset with all possible sums  
********************************************/
template <size_t bitsetsize>
void subsetSum(std::bitset<bitsetsize>& bitSums, const int arrNums[], int n)
{
	// set all the bits to 0
	bitSums.reset();
	// set the 0th bit because subset sum of 0 exists
	bitSums[0] = 1;
	
	std::cout << "Bitset after inserting 0 sum:" << std::endl;
	printBitset(bitSums);
	 
	// apply the same technique as explained above
	for (int iter = 0; iter < n; ++iter){
		
		bitSums |= (bitSums << arrNums[iter]);
		
		std::cout << "Bitset after iteration " << iter + 1;
		std::cout << " for value " << arrNums[iter]	<< ":" << std::endl;
		printBitset(bitSums);
	}
	std::cout << std::endl;
}

/********************************************
* Function Name  : printBitCheck
* Pre-conditions : std::bitset<bitsetsize>& bitSums, size_t n
* Post-conditions: none
* 
* Prints the Bitset with the element we are searching for 
* highlighted with a *1* ot *0* 
********************************************/
template <size_t bitsetsize>
void printBitCheck(std::bitset<bitsetsize>& bitSums, size_t n){
	
	for(int iter = 0; iter < bitsetsize; ++iter){
		
		if(iter == n)
			std::cout << "*";
		
		std::cout << bitSums[iter];
		
		if(iter == n)
			std::cout << "*";
		
		std::cout << "|";
	}
	std::cout << std::endl;
	
}

/********************************************
* Function Name  : checkValue
* Pre-conditions : int n, std::bitset<bitsetsize> bitSums
* Post-conditions: none
* 
* Checks the bitset to determine whether a subset sum equal 
* to n exists in the array or not 
********************************************/
template <size_t bitsetsize>
void checkValue(int n, std::bitset<bitsetsize> bitSums)
{ 
	
	if(n < 0){
		std::cout << n << " is less than 0, which is not a valid sum" << std::endl;
		return;
	}

	if(n >= bitsetsize){
		std::cout << n << " is bigger than the largest possible sum" << std::endl;
		return;
	}
	
	if (bitSums[n])
		std::cout << "subset sum of " << n << " exists\n";
	else
		std::cout << "subset sum of " << n << " does not exist\n";
	
	printBitCheck(bitSums, n);

}

/********************************************
* Function Name  : printArray
* Pre-conditions : int arrNums[], int& numElements
* Post-conditions: none
* 
* Print the initial Array Header to the user 
********************************************/
void printArray(int arrNums[], int& numElements){
	
	std::cout << "Initial array of size " << numElements << ": ";
	for(int iter = 0; iter < numElements; iter++){
		
		std::cout << arrNums[iter] << " ";
	}
	std::cout << std::endl << std::endl;
}
 
/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* Main Driver function 
********************************************/
int main()
{
	std::cout << "Determine if the sum of any subset of elements in an array is equal to a value" << std::endl;
	int arrNums[] = {4, 1, 10, 8, 5};
	
	// Must do maxSum instead of writing a function since it must be 
	// a known value at compile time (28 + 1)
	const int maxSum = 29;
 
	// a vector of maxSum number of bits	
	std::bitset< maxSum > bitSums;
	
	std::cout << std::endl;
	std::cout << "sizeof(arr) = Bytes used in Array = " << sizeof(arrNums) << std::endl;
	std::cout << "sizeof(arr[0]) = Bytes used to store an integer = " << sizeof(arrNums[0]) << std::endl;
	int numElements = (int)sizeof(arrNums) / (int)sizeof(arrNums[0]);
	std::cout << "numElements = sizeof(arr) / sizeof(arr[0]) = " << numElements << std::endl;
	
	// Print the array to the user
	printArray(arrNums, numElements);
	
	// Create a bitset with the sum of all elements 
	subsetSum(bitSums, arrNums, numElements);

	// Test Cases
	std::cout << "Test cases for the function." << std::endl;
	checkValue(-1, bitSums);
	checkValue(2, bitSums);
	checkValue(5, bitSums);	 	
	checkValue(6, bitSums);	 	
	checkValue(7, bitSums);	 	
	checkValue(16, bitSums);	 
	checkValue(24, bitSums);
	checkValue(28, bitSums);
	checkValue(43, bitSums);
	 
	return 0;
}