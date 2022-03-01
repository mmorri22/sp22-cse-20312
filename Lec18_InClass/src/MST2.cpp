#include "../include/Graph.h"
#include <iostream>

int main(){
	
	Graph< char > theGraph;
	
	theGraph.add_vertex( 'A' );		theGraph.add_vertex( 'B' );
	theGraph.add_vertex( 'C' );		theGraph.add_vertex( 'D' );
	theGraph.add_vertex( 'E' );
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 5 );	theGraph.add_edge( 0, 2, 4 );
	theGraph.add_edge( 0, 3, 5 );
	
	// Nodes from 1	
	theGraph.add_edge( 1, 3, 6 );	theGraph.add_edge( 1, 4, 9 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 4 );	theGraph.add_edge( 2, 4, 5 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 4, 2 );
	
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
