#include "../include/TrieNode.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string
#define NUM_ASCII 128

void addString( TrieNode* theNode, const std::string& word, unsigned int value ){
	
	// We haven't reach the end of the word
	if( value < word.size() ){
		
		// Add each character to the word
		// addChild will not permit duplicates
		theNode->addChild( word[value] );
		
		// Get the TrieNode correlating to the char
		TrieNode* nextLevel = theNode->getChildPtr( word[value] );
		
		if( nextLevel == NULL ){
			std::cout << "Got here" << std::endl;
		}
		
		// Recursively call the next level
		addString( nextLevel, word, value + 1);
	}
	
	// If we have reached the end of the word
	else if( value == word.size() ){
		
		// Add a star indicating this is a valid word
		theNode->addChild( '*' );
		return;
	}
	
}


void printTriePreOrder( TrieNode* theNode, unsigned int level ){
	
	// If we've reached the end, return 
	if( theNode == NULL ){
		return;
	}
	
	// If we are at the root, just print the level
	if( theNode->getLetter() == 0 ){
		COUT << "root: " << level << ENDL;
	}
	
	else{
		// Print the letter and the level
		COUT << theNode->getLetter() << " " << level << ENDL;
	}
	
	// If we are at a star, we can return
	if( theNode->getLetter() == '*' ){
		return;
	}
	
	// Otherwise, recursively call
	for(unsigned int iter = 0; iter < NUM_ASCII; iter++){
		
		printTriePreOrder(theNode->getChildPtrOrder(iter), level + 1);
		
	}
	
}

int main(){
	
	STRING CAN("CAN");
	STRING CANDY("CANDY");
	STRING COUNT("COUNT");
	STRING COULD("COULD");
	STRING FIT("FIT");
	STRING FAST("FAST");
	STRING FASTER("FASTER");
	STRING FAT("FAT");
	STRING FOX("FOX");
	STRING FOUND("FOUND");
	
	// Create a root TrieNode
	TrieNode* root = new TrieNode();

	// Add the strings 
	addString(root, FOUND, 0);
	addString(root, COUNT, 0);
	addString(root, FIT, 0);	
	addString(root, CAN, 0);
	addString(root, FASTER, 0);
	addString(root, CANDY, 0);
	addString(root, FAST, 0);
	addString(root, COULD, 0);
	addString(root, FOX, 0);
	addString(root, FAT, 0);
		
	printTriePreOrder(root, 1);
	
	COUT << ENDL; 
	
	return 0;
}