#include "../include/Trie.h"
#include <queue>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <list>

// M x N matrix
#define M 5
#define N 5

#define COUT std::cout
#define ENDL std::endl

// queue SearchNode used in BFS
struct SearchNode
{
	
	int x;	// x value of the coordinate 
	int y;	// y value of the coordinate
	
	std::string currString;
	
	SearchNode(  ) : x(), y(), currString() {}
	
	SearchNode( int xIn, int yIn, std::string currIn ) : x(xIn), y(yIn), currString( currIn ) {}

};


void getFileStream(int argc, char** argv, std::ifstream& ifs){

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

/********************************************
* Function Name  : isValid
* Pre-conditions : int matrix[][N], bool visited[][N], int rowVal, int colVal
* Post-conditions: bool
*  
* Determines if the matrix move is valid.
* Checks if (rowVal,colVal) is a valid position 
********************************************/
bool isValid(char matrix[][N], bool visited[][N], int rowVal, int colVal)
{
	return (rowVal >= 0) 		// rowVal greater than or equal to 0, so inside the maze
			&& (rowVal < M) 	// rowVal is less than M, so inside the maze 
			&& (colVal >= 0) 	// colVal greater than or equal to 0, so inside the maze
			&& (colVal < N)		// colVal is less than M, so inside the maze 
			&& matrix[rowVal][colVal] 		// if matrix[rowVal][colVal] is true, then valid move
			&& !visited[rowVal][colVal];	// if visited[rowVal][colVal] is false, then not yet visited
}

void printMatrix(char matrix[5][5], int row, int col){
    COUT << "Input Matrix: " << ENDL;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            COUT << matrix[i][j] << "\t";
        }
        COUT << ENDL;
    }
}

void findWordsDFS(const Trie& theTrie, char matrix[5][5], std::string& currentStr, int orig_x, int orig_y, 
	bool visited[5][5], std::unordered_map< std::string, bool >& wordMap, 
	std::priority_queue< std::string >& wordsInOrder ){
	
	// Create the string to keep track of the current string
	currentStr.push_back( matrix[orig_x][orig_y] );
	
	// Mark the origin as visited
	visited[orig_x][orig_y] = true;
	
	// If the string is in the Trie and not in the Hash, print and Hash
	if( theTrie.contains( currentStr ) && wordMap.count( currentStr ) == 0 ){
		
		// Put the words in the Priority Queue
		wordsInOrder.push( currentStr );
		
		// Put it in the Hash so we don't print a duplicate
		wordMap.insert( { currentStr, true } );
		
	}
	
	// Next, we check for all elements 
	// Check Down 
	if( isValid( matrix, visited, orig_x + 1, orig_y ) ){
		
		visited[ orig_x + 1 ][ orig_y ] = true;
		
		findWordsDFS( theTrie, matrix, currentStr, orig_x + 1, orig_y, visited, wordMap, wordsInOrder);
					
	}
	
	// Next, check right
	if( isValid( matrix, visited, orig_x, orig_y + 1 ) ){
		
		visited[ orig_x ][ orig_y + 1 ] = true;
		
		findWordsDFS( theTrie, matrix, currentStr, orig_x, orig_y + 1, visited, wordMap, wordsInOrder);
		
	}
	
	// Next, check up
	if( isValid( matrix, visited, orig_x - 1, orig_y ) ){
		
		visited[ orig_x - 1 ][ orig_y ] = true;
		
		findWordsDFS( theTrie, matrix, currentStr, orig_x - 1, orig_y, visited, wordMap, wordsInOrder);
		
	}
	
	// Finally, check left
	if( isValid( matrix, visited, orig_x, orig_y - 1 ) ){
		
		visited[ orig_x ][ orig_y - 1 ] = true;
		
		findWordsDFS( theTrie, matrix, currentStr, orig_x, orig_y - 1, visited, wordMap, wordsInOrder);
		
	}

	// Remove the last element from the string
	currentStr.pop_back();
	
	// Mark the origin as visited
	visited[orig_x][orig_y] = false;

}

void findWords(const Trie& theTrie, char matrix[5][5] ){
	
	// Keep track of all unique words 
	std::unordered_map< std::string, bool > wordMap;
	
	// Priority Queue
	std::priority_queue< std::string > wordsInOrder;

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; ++j){
			
			// Brace Initializer Lists for Visited
			bool visited[5][5] = {
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			}; 	
			
			std::string currentStr;
            findWordsDFS( theTrie, matrix, currentStr, i, j, visited, wordMap, wordsInOrder );
        }
    }
	
	// Print the top of the Binomial Heap Priority Queue until it is empty 
	COUT << "\nWords found (in alphabetical order):" << ENDL;
	while( !wordsInOrder.empty() ){
		COUT << wordsInOrder.top() << ENDL;
		wordsInOrder.pop();
	}
}



int main(int argc, char** argv){
    // Check the input
	std::ifstream dictionaryIn;
	getFileStream(argc, argv, dictionaryIn);

	Trie dictTrie;

    // read in dictioanry information
    while( !dictionaryIn.eof() ){

		// Get the unsigned int from the file
		std::string word;

		dictionaryIn >> word;

		dictTrie.addString( word );
	}

    char matrix[5][5] = {
        {'T','S','A','N','E'},
        {'A','Q','N','O','D'},
        {'R','T','T','T','R'},
        {'Y','V','L','S','E'},
        {'Z','I','O','U','V'}
    };

    printMatrix(matrix, 5, 5);

    findWords(dictTrie, matrix);
	
	// IMMUNOELECTROPHORETICALLY
    char matrix2[5][5] = {
        {'I','E','R','P','O'},
        {'M','T','O','H','R'},
        {'M','I','L','L','T'},
        {'U','C','A','Y','C'},
        {'N','O','E','L','E'}
    };
	
	COUT << "\n\n-----------------------------\n\n";
	
    printMatrix(matrix2, 5, 5);

    findWords(dictTrie, matrix2);

    return 0;
}
