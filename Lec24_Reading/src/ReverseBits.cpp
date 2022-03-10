#include <bitset>
#include <iostream>
#include <cmath>


// Must do maxSum instead of writing a function since it must be 
// a known value at compile time - Length of unsigned int is 32
const int unsignedIntLen = 32;

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


template <size_t bitsetsize>
unsigned int reverseBits(unsigned int num, std::bitset<bitsetsize>& unsignedBits){

	unsigned int reverseResult = 0;
	unsigned int mask = 1;
	for (unsigned int i = 0; i < bitsetsize; i++) {
		
		// Check if num bits and mask are the same
		if ((num & mask) != 0) {
			
			unsignedBits[ i ] = 1;
			
			reverseResult += (unsigned int)pow(2, 31-i);
		}
		
		// Bitshift mask by 1
		mask <<= 1;
	}
	
	return reverseResult;
}

void test( unsigned int numTest ){
	
	// a vector of maxSum number of bits	
	std::bitset< unsignedIntLen > unsignedBits;
	
	unsigned int reverseResult = reverseBits( numTest, unsignedBits );
	
	std::cout << "The reverse Bits of " << numTest << " is " << reverseResult;
	
	std::cout << " and the reversed bits are: ";
	
	printBitset( unsignedBits );
	
}

int main(){

	test( 4 );
	test( 7 ); 
	test( 31 ); 
	test( 32 ); 
	test( 42 ); 
	test( 187 );	
	test( 2278135 );
	test( 348594621 );	
	test( 4294967295 );
	return 0;
}