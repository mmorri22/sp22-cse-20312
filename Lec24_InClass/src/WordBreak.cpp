#include "../include/Trie.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl


void getFileStream(const int argc, const char* argv[], std::ifstream& ifs){
	
	// Must be exactly two characters
	if(argc != 2){
		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);
	}
	
	// Attempt to open the file
	ifs.open (argv[1], std::ifstream::in);
	
	if(!ifs.is_open()){
		COUT << "Input File Name " << argv[1] << " does not exist" << ENDL;
		exit(-1);
	}
	
}


void wordBreak( Trie& dictTrie, const std::string& str, 
	long unsigned int size, std::string result ){
	
	// Iterate through each element in the size
	for( long unsigned int iter = 1; iter <= size; iter++ ){
		
		// Get the substring from the origin to iter
		std::string prefix = str.substr(0, iter);
		
		// If the word is in the Trie
		if( dictTrie.contains( prefix ) ){
			
			// If we reached the end of the Word
			// Print the entire array
			if(iter == size){
				
				// Add the word to the substring
				result += str.substr(0, iter);
				
				// Print out all the words
				std::cout << result << std::endl;
				return;
			}
			
			// Recursively Call 
			// Go from iter to 
			wordBreak(dictTrie, str.substr(iter, size-iter), size-iter, 
				std::string(result + prefix + " ") );
		}
	}
}


void wordBreak( Trie& dictTrie, const std::string& str ){
	
	COUT << "Testing " << str << "..." << ENDL;
	
	wordBreak(dictTrie, str, str.size(), std::string(""));
	
}


int main( const int argc, const char* argv[] ){
	
	// Check the input 
	std::ifstream dictionaryIn;
	getFileStream(argc, argv, dictionaryIn);
	
	// Initialize the Trie
	Trie dictTrie;
	
	// Read in the dictionary information 
	while( !dictionaryIn.eof() ){
		
		// Get the unsigned int from the file 
		std::string word;
		
		dictionaryIn >> word;
		
		// COUT << word << ENDL;
		
		dictTrie.addString( word );
		
	}
	
	// Tests 
	wordBreak( dictTrie, std::string("") );
	wordBreak( dictTrie, std::string("ILIKEPIZZA") );
	wordBreak( dictTrie, std::string("GKLHSKHKLHWSJGRJGJLHGKD") );
	wordBreak( dictTrie, std::string("WAKEUPTHEECHOES") );
	wordBreak( dictTrie, std::string("CANTELOPE") );
	wordBreak( dictTrie, std::string("APPLEPENAPPLE") );
	wordBreak( dictTrie, std::string("ITWASTHEBESTOFTIMESITWASTHEWORSTOFTIMES") );
	
	return 0;
}





