#include "../include/Graph.h"
#include <iostream>

int main(){
	
	Graph< int > theGraph;
	
	theGraph.add_vertex( 4 );
	theGraph.add_vertex( 20 );
	theGraph.add_vertex( 5 );
	theGraph.add_vertex( 10 );
	theGraph.add_vertex( 30 );
	theGraph.add_vertex( 18 );
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 3 );
	theGraph.add_edge( 0, 2, 1 );

	// Nodes from 1	
	theGraph.add_edge( 1, 3, 4 );
	theGraph.add_edge( 1, 4, 2 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 5 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 5, 2 );
	
	// Nodes from 4 
	theGraph.add_edge( 4, 5, 2 );
	
	// Print results:
	theGraph.print_graph();

	std::cout << std::endl;
	
	// Run Dijkstra's Algorithm
	theGraph.Dijkstra( 0, 5 );
	theGraph.Dijkstra( 0, 4 );
	theGraph.Dijkstra( 0, 3 );
	theGraph.Dijkstra( 0, 2 );
	theGraph.Dijkstra( 0, 1 );
	theGraph.Dijkstra( 0, 0 );
	theGraph.Dijkstra( 0, 6 );
	theGraph.Dijkstra( 0, -1 );
	return 0;
}
