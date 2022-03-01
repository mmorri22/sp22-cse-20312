#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <stack>
#include <iostream>
#include <vector>
#include <queue>

#define VECTOR std::vector
#define STACK std::stack
#define QUEUE std::queue

template< typename T >
struct Graph{
	
	private:
	
		VECTOR< Vertex< T > > vertices;	// Adjacency List
		
		// Private DFS method
		bool DFS( unsigned int destin, unsigned int vertVal, VECTOR<unsigned int>& parents, VECTOR<bool>& visited ){
				
			if( !visited[ vertVal ] ){
				
				// Set the visited edges to true
				visited[ vertVal ] = true;
				
				// Check each outgoing edge 
				for( unsigned int iter = 0; iter < vertices[ vertVal ].num_edges(); iter++ ){
					
					// Obtain a temporary copy of the Edge
					Edge tempEdge = vertices[ vertVal ].get_edge( iter );
					
					// If the destination has not been visited, make recursive call
					if( !visited[ tempEdge.destin ] ){
						
						// Set the destination's parent to vertVal
						parents[ tempEdge.destin ] = vertVal;
						
						// If we found the vertex, return true
						if( tempEdge.destin == destin ){
							
							return true;
						}
						
						// Otherwise, recursively call the destination vertex
						bool check = DFS( destin, tempEdge.destin, parents, visited );
						
						// Recursively return true if check is true
						if( check ){
							
							return true;
						}
					}
					
				}
			}
			
			// Otherwise, return false
			return false;
				
		}
		
	public:
		// Constructor
		Graph( ) : vertices() {}
		
		// Destructor
		~Graph( ) { }
		
		// Add a vertex prior to any edges
		void add_vertex( const T& vertexData ){
			
			Vertex<T> theVertex( vertexData );
			vertices.push_back( theVertex );
		}
		
		// Add Edge from Origin to Destination, with weight
		void add_edge(unsigned int origin, unsigned int destin, int weight ){
			if( origin < vertices.size() && destin < vertices.size() ){
			
				vertices[origin].add_edge( destin, weight );
		
			}
		}
		
		// Return the value with a Call by Reference
		// bool for if the vertex requested was valid
		bool get_vertex_value( const unsigned int vertex, T& value ){
			
			if( vertex < vertices.size() ){
				
				value = vertices.at(vertex).get_vertex_value();
				return true;
			}
			
			return false;
			
		}
		
		// Set the value at a given vertex 
		// bool for if the vertex requested was valid
		bool set_vertex_value( const unsigned int vertex, T& value ){
						
			if( vertex < vertices.size() ){
				
				value = vertices[vertex].set_vertex_value( value );
				return true;
			}			
			return false;
		}
		
		// Return the value with a Call by Reference
		// bool for if the origin and destination requested were valid
		bool get_edge_value( const unsigned int origin, const unsigned int destin, int& weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				return vertices[origin].get_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Set the value at a given origin and destination 
		// bool for if the origin and destination requested were valid
		bool set_edge_value( const unsigned int origin, const unsigned int destin, int weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				return vertices[origin].set_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Remove an edge
		bool remove_edge( unsigned int origin, unsigned int destin){
				
			// If the origin and destination are valid
			if( origin < vertices.size() && destin < vertices.size() ){
				
				// From the Origin vertex, remove the destination vertex
				return vertices[origin].remove_edge( destin );
			}
			
			return false;
		}
		
		
		void remove_vertex( unsigned int vertVal ){
			
			// First, perform Lazy Deletion on the vertex 
			vertices[ vertVal ].lazy_delete();
			
			// Next, go through each vertex and remove all edges with the destination to the vertex 
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				
				int jter = 0;
				
				// While the increment is less than the number of edges
				while( jter < vertices[iter].num_edges() ){
					
					// If the destination of the edge is the vertex we are removing
					if( vertices[iter].get_edge( jter ).destin == vertVal ){
						
						// Remove that edge
						vertices[iter].remove_edge( vertVal );
					}
					else{
						// Only increment jter is there is not any deletion
						jter++;
					}
				}
			}
		}
		
		
		// Public DFS Method
		void DFS( unsigned int destin ){
			
			// If the input is invalid or the Graph is empty
			if( destin >= vertices.size() || vertices.size() == 0){
				
				std::cout << "Invalid inputs to DFS" << std::endl;
				
				return;
			}
			
			/* Initialize the Values for the DFS */
			
			// Track the parents for printing the results
			VECTOR<unsigned int> parents(vertices.size());
			
			// Keep track of the visited vertices
			VECTOR<bool> visited(vertices.size());
			
			// Create a stack to store the final path
			STACK< unsigned int > finalPath;
			bool found = false;

			// Initialize the search	
			parents[0] = -1;
			
			// Set all the visited elements to false
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				visited[iter] = false;
			}
			
			// If the destination is the origin, mark found as true
			if( destin == 0 ){
				
				found = true;
				
			}
			
			// Otherwise, run the recursive DFS 
			else{

				found = DFS( destin, 0, parents, visited );
			
			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from 0 to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid DFS path from 0 to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			
			std::cout << std::endl;
				
			
		}
		
		
		// Public DFS Method
		void DFS( unsigned int origin, unsigned int destin ){
			
			// If the input is invalid or the Graph is empty
			if( origin >= vertices.size() || destin >= vertices.size() || vertices.size() == 0){
				
				std::cout << "Invalid inputs to DFS" << std::endl;
				
				return;
			}
			
			/* Initialize the Values for the DFS */
			
			// Track the parents for printing the results
			VECTOR<unsigned int> parents(vertices.size());
			
			// Keep track of the visited vertices
			VECTOR<bool> visited(vertices.size());
			
			// Create a stack to store the final path
			STACK< unsigned int > finalPath;
			bool found = false;

			// Initialize the search	
			parents[ origin ] = -1;
			
			// Set all the visited elements to false
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				visited[iter] = false;
			}
			
			// If the destination is the origin, mark found as true
			if( destin == origin ){
				
				found = true;
				
			}
			
			// Otherwise, run the recursive DFS 
			else{

				found = DFS( destin, origin, parents, visited );
			
			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from " << origin << " to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid DFS path from " << origin << " to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
				
			
		}
		
		void BFS( unsigned int destin ){
			
			// If Graph can't be search, inform user and return 
			// destin cannot be greater than the number of vertices
			// The number of vertices must not be 0
			if( destin >= vertices.size() || vertices.size() == 0){
				
				std::cout << destin << " is not a valid vertex location" << std::endl;
				
				return;
			}
			
			/* Create elements for the search */
			
			// queue to store the next vertex to evaluate
			QUEUE< unsigned int > theQueue;
			
			// Keeping track if the vertex has been visited. Set all initially to false
			bool* visited = new bool[vertices.size()];
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				
				visited[iter] = false;
			}
			
			// Keeping track of the parents 
			unsigned int* parents = new unsigned int[vertices.size()];
			
			// Use this stack for the final path
			STACK< unsigned int > finalPath;
			
			/* Initialize the search */
			bool found = false; 
			
			// Push the origin onto the Queue
			theQueue.push(0);
			
			// The origin has no parent, and the origin has been visited
			parents[0] = -1;
			
			// Set found to true if the origin is the destination
			if( destin == 0 ){
				found = true;
			}
			
			// While the element is not found and the queue is not empty
			while( !found && !theQueue.empty() ){
				
				// First step in BFS is to obtain and remove the front element from the queue 
				unsigned int vertex = theQueue.front();
				theQueue.pop();
				
				// Mark the vertex as visited
				visited[ vertex ] = true;
				
				// Iterate through each edge 
				for( unsigned int iter = 0; iter < vertices[ vertex ].num_edges(); iter++){
					
					// Get the destination from the edge
					unsigned int edgeDestin = vertices[ vertex ].get_edge( iter ).destin;
					
					// If the edge's destination matches our destination, we found the node
					if( edgeDestin == destin ){
						
						found = true;
						
						// Mark the destination's parent as vertex 
						parents[ edgeDestin ] = vertex;
						
						break;
					}
					
					// If the destination has not been visited
					else if( visited[ edgeDestin ] == false ) {
						
						// Push the destination onto the queue
						theQueue.push( edgeDestin );
						
						// Mark edgeDestin's parent as vertex
						parents[ edgeDestin ] = vertex;
						
						// Mark visited as true
						visited[ edgeDestin ] = true;

					}
				}

			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from origin to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid BFS path from the 0 to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
		}

		// BFS with an origin and destination node
		void BFS( unsigned int origin, unsigned int destin ){
			

			/****************************************************
			 * Part 3 - Checking Inputs
			 *
			 * Print an error message to the user if the origin or destination
			 * is greater than or equal to the size of the Adjacency List (name vertices)
			 * or if the vertices size is equal to 0.
			 * Then, return so the rest of the code is not run.
			 *****************************************************/
			 
			 
			 /*****************************************************
			  * Part 4 - Setting up the Breadth-First Search
			  *
			  * Create a queue templated to unsigned int called "theQueue"
			  * - Note, #include <queue> is provided, and #define QUEUE std::queue is already in Graph.h
			  * Push the origin index onto the queue.
			  *
			  * Next, create a bool array or bool vector called visited initialized to the size of the this->vertices and
			  * set all  the values of the bool equal to false.
			  *
			  * Next, create an unsigned array or vector called parents and initialize the size of parents to the size
			  * of this->vertices. Set the index at origin equal to -1 (indicating it has no parent, and is an origin
			  *
			  * **************************************/
			bool found = false;

			// Set found to true if the origin is the destination
			if( destin == origin ){
				found = true;
			}


			/********************************************************************
			 * Step 5 - Implementing the BFS Algorithm
			 *
			 * Loop while we have not found the element (found is false) and the queue is not empty
			 *
			 * - First, create an unsigned int vertex equal to the front of the queue
			 * - Then pop the element off the front of the queue 
			 * - Mark the index indicated vy vertex in visited equal to true.
			 *
			 * - Now you will put all the unvisited outgoing edges onto the queue 
			 *   - From lecture: the number of edges in the vertex is found with vertices[ vertex ].num_edges()
			 *   - To simplify the code, create a variable edgeDestin equal to the destination
		     *      - The line of code is: unsigned int edgeDestin = this->vertices[ vertex ].get_edge( iter ).destin;
			 *   - If the edgeDestin is equal to the destin we are seeking,
			 *      - Set found to true 
			 *      - Set the index in parents at destin to vertex 
			 *      - break the while loop 
			 *   - If the edgeDestin has not been visited
			 *      - Push edgeDestin onto the queue 
			 *      - Mark edgeDestin's parent as vertex 
			 *      - Mark edgeDestin as visited 
			 *
			 **************************************************************************/
			 
			 
			 
			 
			 
			 /******************************************************************************
			  * The code below will print the full BFS path and is provided for you
			  *****************************************************************************/

			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from " << origin << " to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			// Use this stack for the final path
			STACK< unsigned int > finalPath;
			
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the stack
				
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid BFS path from " << origin << " to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
		}


		
		// Overloaded Operator
		void print_graph(){
			
			for( unsigned int iter = 0; iter < this->vertices.size(); iter++ ){
				
				COUT << iter << ": "; 
				this->vertices[ iter ].print_vertex();
				COUT << ENDL;
				
			}
			
		}
};

#endif
