#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

#include <iostream>
#include <vector>

#define VECTOR std::vector

template<class T>
class Vertex{

	private:
	
		VECTOR< Edge > edges;
		T data;
		bool valid;			// Valid Vertex
		
	public:
	
		Vertex( ) : edges(), data( ), valid( true ) {}
	
		Vertex( const T& dataIn ) : edges(), data( dataIn ), valid( true ) {}
		
		~Vertex(){ }
		
		Vertex( const Vertex<T>& rhs ) : edges(), data( ), valid( true ) {
			
			if( this != &rhs ){
				
				for( unsigned int iter = 0; iter < rhs.num_edges(); iter++ ){
				
					edges.push_back( rhs.edges[iter] );
					
				}
				
				data = rhs.data;
				
			}			
			
		}
		
		Vertex<T>& operator=( const Vertex<T>& rhs ){
			
			if( this != &rhs ){
				
				for( unsigned int iter = 0; iter < rhs.num_edges(); iter++ ){
					edges.push_back( rhs.edges[iter] );
				}
		
				data = rhs.data;
			}
			
			return *this;
		}
		
		T get_vertex_value() const{
			
			return data;
		}

		void set_vertex_value(const T& dataIn){
			
			data = dataIn;
		}
		
		// Adding an Edge to a Vertex
		void add_edge( unsigned int destin, int weight ){
			
			// If not, put the edge on the back of the array
			edges.push_back( Edge(destin, weight) );
			
		}
		
		// Pass the destination, return weight with call be reference, bool if found
		bool get_edge_value( unsigned int destin, int& weight ) const{
			
			bool edgeFound = false;
			
			for( unsigned int i = 0; i < edges.size(); i++){
				if( edges[i].destin == destin ){

					edgeFound = true;
					weight = edges[i].weight;
				}					
			}
			
			return edgeFound;
		}

		// Pass the destination and weight, bool if found		
		bool set_edge_value( unsigned int destin, int weight) {
			
			bool edgeFound = false;
			
			for( unsigned int i = 0; i < edges.size(); i++){
				if( edges[i].destin == destin ){

					edgeFound = true;
					edges[i].weight = weight;
				}
			}
			
			return edgeFound;
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
		
		// Return an edge
		Edge get_edge( unsigned int edgeOrder ) {
			
			return edges[ edgeOrder ];
		}
		
		// Return the number of edges
		unsigned int num_edges() const{
			
			return (unsigned int)edges.size();
		}
		
		// Clear the vertex 
		void lazy_delete(){
			
			valid = false;
			
			while( edges.size() > 0 ){
				
				// Remove the front edge
				edges.erase( edges.begin() );
			}
			
		}
		
		// Overloaded Friend Output Operator
		friend std::ostream& operator<<( std::ostream& output, const Vertex<T>& theVert ){
			
			// If the vertex is valid
			if( theVert.valid ){
			
				// Print the data element first
				output << "[" << theVert.data << ": ";
				
				// 
				for( long unsigned int iter = 0; iter < theVert.edges.size(); iter++ ){
					
					// Print the destination
					output << "{" << theVert.edges[iter].destin << ", ";
					
					// Print the weight
					output << theVert.edges[iter].weight << "} ";
					
				}
				output << "]";
			
			}
			// If the vertex is not valid, indicate Lazy Deletion
			else{
				output << "[DELETED]";
			}
			
			return output;
		}
		
};

#endif