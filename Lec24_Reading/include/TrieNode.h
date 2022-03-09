#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector>
#include <iostream>
#include <fstream>

#define VECTOR std::vector
#define LUI long unsigned int

class TrieNode{

private:

	char trie_letter;
	VECTOR< TrieNode* > child_nodes;

public:

	// Default constructor
	// Must set them to NULL, or you will get a stack overflow
	TrieNode() : trie_letter(), child_nodes(128, NULL) {}
	
	// Constructor with char input
	TrieNode(const char& char_in) : trie_letter(char_in), child_nodes(128, NULL) {}
	
	// Add a child character
	void addChild( const char& child_char ){
		
		if( child_nodes.at( (LUI)child_char ) != NULL )
			return;

		TrieNode* temp = new TrieNode(child_char);
		
		child_nodes.at( (LUI)child_char ) = temp;
	}

	
	// Get the Child Pointer
	TrieNode* getChildPtr( const char& child_char ){
		
		return child_nodes.at( (LUI)child_char );
		
	}
	
	
	TrieNode* getChildPtrOrder( unsigned int order ){
		
		return child_nodes.at( order );
		
	}
	
	// Get Letter
	char getLetter() const{
		
		return trie_letter;
		
	}
	
	
	// Operators
	bool operator<( const TrieNode& rhs ) const{
		
		return trie_letter < rhs.trie_letter;
	}
	
	bool operator<=( const TrieNode& rhs ) const{
		
		return trie_letter <= rhs.trie_letter;
	}
	
	bool operator>( const TrieNode& rhs ) const{
		
		return trie_letter > rhs.trie_letter;
	}
	
	bool operator>=( const TrieNode& rhs ) const{
		
		return trie_letter >= rhs.trie_letter;
	}
	
	bool operator==( const TrieNode& rhs ){
		
		return trie_letter == rhs.trie_letter;
	}
	
	friend std::ostream& operator<<( std::ostream& output, const TrieNode& TN){
		
		output << TN.trie_letter << " ";
		
		return output;
	}

};

#endif