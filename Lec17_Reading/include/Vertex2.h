#ifndef VERTEX2_H
#define VERTEX2_H

#include "Edge.h"

#include <iostream>
#include <vector>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector


template<typename T>
struct Vertex{

	private:
	
		VECTOR< Edge > edges;	// Contains all outgoing edges
		T data;					// The data stored in the Vertex
		bool valid;				// Mark as valid - False for Lazy Deletion
		
	public:
	
		// Default Constructor
		Vertex( ) : edges(), data( ), valid( true ) {}
	
		// Overloaded Constructor
		Vertex( const T& dataIn ) : edges(), data( dataIn ), valid( true ) {}
		
		// Get the Vertex data
		T get_vertex_value() const{
			
			return data;
		}
		
		// Set the Vertex Value
		void set_vertex_value(const T& dataIn){
			
			data = dataIn;
		}
		
		// Adding an Edge to a Vertex
		void add_edge( unsigned int destin, int weight ){
			
			// If not, put the edge on the back of the array
			edges.push_back( Edge(destin, weight) );
			
		}
		
		// Remove the edge to an input destination
		bool remove_edge( unsigned int edgeLoc ){
			
			bool deleted = false;
			
			for(unsigned int i = 0; i < edges.size(); i++){
				
				if( edges[i].destin == edgeLoc ){
					edges.erase( edges.begin() + i);
					deleted = true;
					break;
				}
			}
			
			return deleted;
		}
		
		// Function to Print the Vertex
		void print_vertex(){
			
			// If the vertex is valid
			if( this->valid ){
			
				// Print the data element first
				COUT << "[" << this->data << ": ";
				
				// 
				for( long unsigned int iter = 0; iter < this->edges.size(); iter++ ){
					
					// Print the destination
					COUT << "{" << this->edges.at(iter).destin << ", ";
					
					// Print the weight
					COUT << this->edges.at(iter).weight << "} ";
					
				}
				COUT << "]";
			
			}
			// If the vertex is not valid, indicate Lazy Deletion
			else{
				COUT << "[DELETED]";
			}
			
		}
		

};

#endif