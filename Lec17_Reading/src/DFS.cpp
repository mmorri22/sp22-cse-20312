#include "../include/Graph3.h"
#include <iostream>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob4.txt" );
	
	Graph< int > theGraph;
	
	theGraph.add_vertex( 4 );	theGraph.add_vertex( 20 );	theGraph.add_vertex( 5 );
	theGraph.add_vertex( 10 );	theGraph.add_vertex( 30 );	theGraph.add_vertex( 18 );
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 1 );	theGraph.add_edge( 0, 2, 1 );

	// Nodes from 1	
	theGraph.add_edge( 1, 3, 1 );	theGraph.add_edge( 1, 4, 1 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 1 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 5, 1 );
	
	// Nodes from 4 
	theGraph.add_edge( 4, 5, 1 );
	
	// Run Depth-First Search
	theGraph.DFS( 5 );		theGraph.DFS( 4 );		theGraph.DFS( 3 );
	theGraph.DFS( 2 );		theGraph.DFS( 1 );		theGraph.DFS( 0 );
	theGraph.DFS( 6 );		theGraph.DFS( -1 );	
	
	// Print results:
	file_out << "Completed Problem 4" << std::endl;
	
	file_out.close();
	
	return 0;
}
