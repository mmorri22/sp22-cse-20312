#include <bitset>
#include <string>
#include <iostream>
#include <fstream>

// Put the number of primeURLs here 
#define primeURLs 110378

/********************************************
* Function Name  : getAndCheckFile
* Pre-conditions : std::ifstream& fileStream, std::string fileName
* Post-conditions: none
* 
* Verifies a valid file and returns an input stream
********************************************/
void getAndCheckFile(std::ifstream& fileStream, std::string fileName){
	
	fileStream.open(fileName);
	
	if(!fileStream.is_open()){
		
		std::cout << "The file " << fileName << " does not exist. Exiting Program..." << std::endl;
		exit(-1);
		
	}	
}

/********************************************
* Function Name  : getURLHash
* Pre-conditions : std::string& urlHash
* Post-conditions: unsigned long
*  
* Converts a string to a Hashable unsigned long 
* Modified from source code at http://www.cse.yorku.ca/~oz/hash.html 
* Uses updated XOR presented by Dan Bernstein suggested 
* but not utilized in the web code 
********************************************/
unsigned long hashFunc1(std::string& urlHash){

	// In-Class Code goes here 
	unsigned long hashVal = primeURLs;
	
	int c; int i = 0;
	
	while( (c = (int)urlHash[i++]) ){
		
		hashVal = ((hashVal << 5) + hashVal) ^ c;
		
	}

	return hashVal % primeURLs;
	
}

/********************************************
* Function Name  : hashFunc2
* Pre-conditions : std::string& urlHash
* Post-conditions: unsigned long
*  
********************************************/
unsigned long hashFunc2(std::string& urlHash)
{
	unsigned long hashVal = 0, g;
	int c;	int i = 0;

	while ( (c = (int)urlHash[i++]) ) {
		hashVal = ( hashVal << 4 ) + c;
		if ( ( g = hashVal & 0xF0000000 ) )
			hashVal ^= g >> 24;
		hashVal &= ~g;
	}

	return hashVal % primeURLs;
}

// Hash Functions 3 and 4 will go here 
unsigned long hashFunc3( std::string& urlHash ){
	
	unsigned long hash = 0;
	int c; int i = 0;
	
	while ( (c = (int)urlHash[i++]) ) {
		
		hash = c + (hash << 6) + (hash << 16) - hash;
		
	}
	
	return hash % primeURLs;
	
}


unsigned long hashFunc4( std::string& urlHash ){
	
	unsigned long hash = 0;
	int c; int i = 0;
	
	while ( (c = (int)urlHash[i++]) ) {
		
		hash += c;
		
	}
	
	return hash % primeURLs;
	
}

// getBloomVals will go here 
template< size_t bitsetsize >
void getBloomVals( std::string& urlIn, std::bitset< bitsetsize >& bitHash ){
	
	bitHash[ hashFunc1( urlIn ) ] = true;
	bitHash[ hashFunc2( urlIn ) ] = true;
	bitHash[ hashFunc3( urlIn ) ] = true;
	bitHash[ hashFunc4( urlIn ) ] = true;
	
}

/********************************************
* Function Name  : getURLs
* Pre-conditions : std::ifstream& urlFile, std::bitset< bitsetsize >& bitHash
* Post-conditions: none
*  
* This function reads all the URLs, and then Hashes them into a Bloom Filer 
* represented as a std::bitset 
********************************************/
template < size_t bitsetsize >
void getURLs(std::ifstream& urlFile, std::bitset< bitsetsize >& bitHash){
	
	std::string urlIn;
	int totalDBURLs = 0;
	while (urlFile >> urlIn)
	{
		// Hash the URL to an unsigned long value 
		totalDBURLs++;
		// Hash the URL
		getBloomVals(urlIn, bitHash);
	}
	
	std::cout << "The database has " << totalDBURLs << " URLs." << std::endl;
	
}

// checkBloomVals will go here 
template< size_t bitsetsize >
bool checkBloomVals( std::string& urlIn, std::bitset< bitsetsize >& bitHash ){
	
	return bitHash[ hashFunc1( urlIn ) ] && bitHash[ hashFunc2( urlIn ) ] 
		&& bitHash[ hashFunc3( urlIn ) ] && bitHash[ hashFunc4( urlIn ) ];
	
}



template <size_t bitsetsize>
void checkURLAccesses(std::ifstream& urlFile, std::bitset< bitsetsize >& bitHash){
	
	// In class code goes here 
	std::string urlIn;
	int countURL = 0, totalAccesses = 0;
	
	while(urlFile >> urlIn){
		
		totalAccesses++;
		
		if( checkBloomVals( urlIn, bitHash ) )
			countURL++;
		
	}
	
	std::cout << "There were " << totalAccesses << " checked pages of which " 
				<< countURL << " were in the database." << std::endl;

} 

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*  
********************************************/
int main(int argc, char** argv){
	
	if( argc != 3 ){
		
		std::cout << "Incorrect Inputs\n";
		exit(-1);
	}

	// Get the inputstream with the URL Files
	std::ifstream urlFile;

	// Initialize the bitset 
	// a vector of maxSum number of bits	
	std::bitset< primeURLs > bitHash;

	// Verify the file for URLs Database	
	getAndCheckFile(urlFile, argv[1]);
	
	// Get the URLs from the Database and put into the Bloom Filter 
	getURLs(urlFile, bitHash);
	
	// Close the Database File 
	urlFile.close();
	
	// Get the inputstream with the URL Access Files
	std::ifstream urlAccessFile;

	// Verify the file for Access URLs 	
	getAndCheckFile(urlAccessFile, argv[2]);

	// Get the URLs from the Access Files and check the Bloom Filter 
	checkURLAccesses(urlAccessFile , bitHash);

	// Close the Access File 	
	urlAccessFile.close();
	
	return 0;
	
}
