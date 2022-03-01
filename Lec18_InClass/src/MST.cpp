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
	theGraph.add_edge( 0, 1, 1 );
	theGraph.add_edge( 0, 2, 1 );

	// Nodes from 1	
	theGraph.add_edge( 1, 3, 1 );
	theGraph.add_edge( 1, 4, 1 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 1 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 5, 1 );
	
	// Nodes from 4 
	theGraph.add_edge( 4, 5, 1 );
	
	// Print results:
	std::cout << "Original Graph:" << std::endl;
	theGraph.print_graph();
	std::cout << std::endl;
	
	// Print the Final Minimum Spanning Tree
	std::cout << "\nMST Solution:\n";
	theGraph.MST().print_graph();
	std::cout << std::endl;
	
	return 0;
}