#include "../include/Graph4.h"
#include <iostream>
#include <vector>

int main(){
	
	Graph< int > theGraph;
	
	theGraph.add_vertex( 4 );
	theGraph.add_vertex( 20 );
	theGraph.add_vertex( 5 );
	theGraph.add_vertex( 10 );
	theGraph.add_vertex( 30 );
	theGraph.add_vertex( 18 );
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 1 );
	theGraph.add_edge( 0, 2, 1 );

	// Nodes from 1	
	theGraph.add_edge( 1, 3, 1 );
	theGraph.add_edge( 1, 4, 1 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 1 );
	theGraph.add_edge( 2, 5, 1 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 5, 1 );
	
	// Nodes from 4 
	theGraph.add_edge( 4, 5, 1 );
	
	// Print results:
	std::cout << theGraph << std::endl;
	
	// Run Breadth-First Search
	theGraph.DFS( 0, 5 );
	theGraph.DFS( 1, 5 );
	theGraph.DFS( 0, 4 );
	theGraph.DFS( 2, 4 );
	theGraph.DFS( 3, 5 );
	theGraph.DFS( 1, 4 );
	theGraph.DFS( 4, 1 );
	theGraph.DFS( 6, 5 );
	theGraph.DFS( 1, 1 );
	theGraph.DFS( 0, -1 );	
	return 0;
}
