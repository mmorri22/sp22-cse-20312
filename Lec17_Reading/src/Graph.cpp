#include "../include/Graph.h"
#include <iostream>
#include <vector>

int main(){
	
	Graph< int > theGraph;
	
	for(int iter = 1; iter <= 8; iter++){
		theGraph.add_vertex( iter * 2 );
	}
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 7 );	theGraph.add_edge( 0, 2, 1 );
	theGraph.add_edge( 0, 3, 1 );

	// Nodes from 1	
	theGraph.add_edge( 1, 2, 1 );	theGraph.add_edge( 1, 4, 2 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 3 );	theGraph.add_edge( 2, 4, 1 );	
	theGraph.add_edge( 2, 5, 1 );	theGraph.add_edge( 2, 6, 5 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 6, 4 );
	
	// Nodes from 4 
	theGraph.add_edge( 4, 5, 3 );	theGraph.add_edge( 4, 7, 1 );
	
	// Nodes from 5
	theGraph.add_edge( 5, 6, 1 );	theGraph.add_edge( 5, 7, 1 );
	
	// Node 6
	theGraph.add_edge( 6, 7, 8 );
	
	// Print the Graph to the User 
	theGraph.print_graph();
	
	return 0;
}