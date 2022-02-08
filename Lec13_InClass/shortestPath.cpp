#include <iostream>
#include <cstdlib>

// Added queue class 
#include <queue>

// M x N matrix
#define M 10
#define N 10

#define COUT std::cout
#define ENDL std::endl

// queue SearchNode used in BFS
struct SearchNode
{
	
	int x;	// x value of the coordinate 
	int y;	// y value of the coordinate
	int dist;	// Distance traveled from source
	
	SearchNode(  ) : x(), y(), dist() {}
	
	SearchNode( int xIn, int yIn, int distIn ) : x(xIn), y(yIn), dist(distIn) {}

};

/********************************************
* Function Name  : isValid
* Pre-conditions : int matrix[][N], bool visited[][N], int rowVal, int colVal
* Post-conditions: bool
*  
* Determines if the matrix move is valid.
* Checks if (rowVal,colVal) is a valid position 
********************************************/
bool isValid(int matrix[][N], bool visited[][N], int rowVal, int colVal)
{
	return (rowVal >= 0) 		// rowVal greater than or equal to 0, so inside the maze
			&& (rowVal < M) 	// rowVal is less than M, so inside the maze 
			&& (colVal >= 0) 	// colVal greater than or equal to 0, so inside the maze
			&& (colVal < N)		// colVal is less than M, so inside the maze 
			&& matrix[rowVal][colVal] 		// if matrix[rowVal][colVal] is true, then valid move
			&& !visited[rowVal][colVal];	// if visited[rowVal][colVal] is false, then not yet visited
}

void BFS(int matrix[][N], int orig_x, int orig_y, int dest_x, int dest_y)
{
	
	COUT << "Searching from (" << orig_x << ", " << orig_y << ")";
	COUT << " to (" << dest_x << ", " << dest_y << ")..." << ENDL;
	
	// If the origin is false, then the matrix cannot be solved
	if( !matrix[orig_x][orig_y] ){
		
		COUT << "The origin at [" << orig_x << "][" << orig_y << "] is inaccessible" << ENDL;
		
		return;
		
	}
	
	// Brace Initializer Lists for Visited
	bool visited[M][N] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	}; 	
	
	std::queue< SearchNode > theQueue;
	
	// Mark the origin as visited
	visited[orig_x][orig_y] = true;
	
	// Push the origin onto the queue
	theQueue.push( {orig_x, orig_y, 0} );
	
	// stores length of longest path from source to destination
	int min_dist = M*N + 1;	// Every single possible SearchNode in the array visited once
	
	// Case 3 - The queue is empty, we run out of cases 
	while (!theQueue.empty())
	{
		// Get the front SearchNode and evaluate the BFS
		SearchNode frontSearchNode = theQueue.front();
		theQueue.pop();
		
		// Set iterarors to the x and y coordinate, and get the current distance
		int iter = frontSearchNode.x, jter = frontSearchNode.y, dist = frontSearchNode.dist;
		
		// Case 1 - If we found the values, we found the destination
		if (iter == dest_x && jter == dest_y)
		{
			min_dist = dist;
			break;
		}
		
		// Next, we check for all elements 
		// First, check down
		if( isValid( matrix, visited, iter + 1, jter ) ){
			
			visited[ iter + 1 ][ jter ] = true;
			
			theQueue.push( SearchNode( iter + 1, jter, frontSearchNode.dist + 1 ) );
		}
		
		// Next, check right
		if( isValid( matrix, visited, iter, jter + 1 ) ){
			
			visited[ iter ][ jter + 1 ] = true;
			
			theQueue.push( SearchNode( iter, jter + 1, frontSearchNode.dist + 1 ) );
		}
		
		// Next, check up
		if( isValid( matrix, visited, iter - 1, jter ) ){
			
			visited[ iter - 1 ][ jter ] = true;
			
			theQueue.push( SearchNode( iter - 1, jter, frontSearchNode.dist + 1 ) );
		}
		
		// Finally, check left
		if( isValid( matrix, visited, iter, jter - 1 ) ){
			
			visited[ iter ][ jter + 1 ] = true;
			
			theQueue.push( SearchNode( iter, jter - 1, frontSearchNode.dist + 1 ) );
		}
		
	}
	
	// If min_dist is less than N*M, then the length has been found
	if (min_dist != N*M + 1)
		COUT << "The shortest path from source to destination "
				"has length " << min_dist << ENDL;
	else
		COUT << "Destination can't be reached from given source" << ENDL;
	
}

int main(){
	
	// Brace Initializer Lists
	int matrix[M][N] =
	{
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
	}; 
	
	BFS(matrix, 0, 0, 7, 5);

	
	return 0;
	
}