#include <iostream>
#include "../include/Vertex1.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	Vertex< std::string > theVertex( "Hello, Vertex!" );
	
	COUT << theVertex.get_vertex_value() << ENDL;
	
	theVertex.set_vertex_value( "Updated Vertex!" );
	
	COUT << theVertex.get_vertex_value() << ENDL;
	
	return 0;
	
}

