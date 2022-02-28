#ifndef VERTEX1_H
#define VERTEX1_H

#include "Edge.h"
#include <vector>

#define VECTOR std::vector

template< typename T>
struct Vertex{

	/* Lecture 15 - Problem 1 Continues Here */
	private:
	
		VECTOR< Edge > edges;
		T data;
		
	public:
	
		Vertex( ) : edges(), data( ) {}
	
		Vertex( const T& dataIn ) : edges(), data( dataIn ) {}
		
		/* Provided to students since get/set methods already covered */
		T get_vertex_value() const{
			
			return data;
		}
		
		void set_vertex_value(const T& dataIn){
			
			data = dataIn;
		}
	
};

#endif
