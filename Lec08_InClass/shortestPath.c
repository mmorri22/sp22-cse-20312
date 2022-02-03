#include <stdio.h>
#include <stdlib.h>

// Added queue class 
#include "sn_queue.h"


/********************************************
* Function Name  : isValid
* Pre-conditions : int matrix[][N], bool visited[][N], int rowVal, int colVal
* Post-conditions: bool
*  
* Determines if the matrix move is valid.
* Checks if (rowVal,colVal) is a valid position 
********************************************/
int isValid(int matrix[][N], int visited[][N], int rowVal, int colVal)
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
	
	fprintf( stdout, "Searching from (%d, %d) to (%d, %d)...\n", orig_x, orig_y, dest_x, dest_y );
	
	
	// Brace Initializer Lists for Visited
	int visited[M][N] =
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
	
	// Create the Queue for the Breadth-First Search
	sn_queue* theQueue = (sn_queue*)malloc( sizeof(sn_queue) );
	theQueue->head_node = NULL;
	theQueue->tail_node = NULL;
	
	// Mark the origin as visited
	visited[orig_x][orig_y] = 1;
	
	// Push the origin onto the queue
	search_node* origin = (search_node*)malloc( sizeof(search_node) );
	origin->x = orig_x;
	origin->y = orig_y;
	origin->dist = 0;

	push_back( theQueue, origin );
	
	// stores length of longest path from source to destination
	int total_dist = 0;	
	
	// Case 3 - The queue is empty, we run out of cases 
	while ( theQueue->head_node != NULL )
	{
		// Get the front SearchNode and evaluate the BFS
		search_node* frontSearchNode = front( theQueue );
		
		// Set iterarors to the x and y coordinate, and get the current distance
		int iter = frontSearchNode->x, jter = frontSearchNode->y, dist = frontSearchNode->dist;
				
		// Remove the front element 
		pop_front( theQueue );
		
		// Case 1 - If we found the values, we found the destination
		if (iter == dest_x && jter == dest_y)
		{
			fprintf( stdout, "Destination Found!!!\n" );
			total_dist = dist;
			break;
		}
		
		// Next, we check for all elements 
		// First, check down
		if( isValid( matrix, visited, iter + 1, jter ) ){
			
			visited[ iter + 1 ][ jter ] = 1;
			
			search_node* temp_node = (search_node*)malloc( sizeof(search_node) );
			temp_node->x = iter + 1;
			temp_node->y = jter;
			temp_node->dist = dist + 1;
			
			push_back( theQueue, temp_node );
			
		}
		
		// Next, check right
		if( isValid( matrix, visited, iter, jter + 1 ) ){
			
			visited[ iter ][ jter + 1 ] = 1;
			
			search_node* temp_node = (search_node*)malloc( sizeof(search_node) );
			temp_node->x = iter;
			temp_node->y = jter + 1;
			temp_node->dist = dist + 1;		
			
			push_back( theQueue, temp_node );

		}
		
		// Next, check up
		if( isValid( matrix, visited, iter - 1, jter ) ){
			
			visited[ iter - 1 ][ jter ] = 1;
			
			search_node* temp_node = (search_node*)malloc( sizeof(search_node) );
			temp_node->x = iter - 1;
			temp_node->y = jter;
			temp_node->dist = dist + 1;		
			
			push_back( theQueue, temp_node );
			
		}
		
		// Finally, check left
		if( isValid( matrix, visited, iter, jter - 1 ) ){
			
			visited[ iter ][ jter - 1 ] = 1;
			
			search_node* temp_node = (search_node*)malloc( sizeof(search_node) );
			temp_node->x = iter;
			temp_node->y = jter-1;
			temp_node->dist = dist + 1;		
			
			push_back( theQueue, temp_node );
		}
	}
	
	// If total_dist is less than N*M + 1, then the length has been found
	if (total_dist != 0)
		fprintf( stdout, "The shortest path from source to destination has length %d\n",  total_dist );
	else
		fprintf( stdout, "Destination can't be reached from given source\n" );
	
	// Free the queue 
	destructor( theQueue->head_node );
	free( theQueue );
	
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
	
	int row, col;
	for( row = 0; row < M; ++row ){
		
		for( col = 0; col < N; ++col ){
			
			fprintf( stdout, "%d ", matrix[row][col] );
		}
		
		fprintf( stdout, "\n" );
	}
	
	fprintf( stdout, "Enter the origin and destination as o_x o_y d_x d_y: ");
	
	int origin_x, origin_y, destin_x, destin_y;
	fscanf( stdin, "%d %d %d %d", &origin_x, &origin_y, &destin_x, &destin_y );
	
	BFS(matrix, origin_x, origin_y, destin_x, destin_y);

	
	return 0;
	
}