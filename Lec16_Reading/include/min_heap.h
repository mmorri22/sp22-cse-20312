#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>

#define VECTOR std::vector

template< typename T >
struct min_heap{
	
	private:
	
		// Use a private vector on the Heap! Encapsulation
		VECTOR<T>* heap_vec;
		
	public:
		
		// Constructor with new on the Heap 
		min_heap() : heap_vec( new VECTOR<int> ) {}
		
		// Destructor
		~min_heap(){
			
			// Using the C++ vector's destructor - Aggregation!
			delete heap_vec;
			
		}
		
		// Push an element onto the min heap 
		void push( const T& push_elem ){
			
			// Push onto the back of the vector 
			heap_vec->push_back( push_elem );
			
			// Get the location
			long unsigned int loc = heap_vec->size() - 1;
			
			// Establish a bool to stop_swaps
			bool stop_swaps = false;
			
			// Create a long unsigned int for the parent
			long unsigned parent;
			
			// While location is not 0 and stop_swaps is false
			while( loc != 0 && !stop_swaps ){
				
				// Get the initial parent
				parent = (loc / 2);
				
				// If loc %2 is 0, subtract 1 from the parent 
				if( loc % 2 == 0 )
					parent -= 1;
			
				// If the value at the parent is greater than the location
				if( heap_vec->at(parent) > heap_vec->at(loc) ){
					
					// Swap using a temp variable
					T temp = heap_vec->at(parent);
					heap_vec->at(parent) = heap_vec->at(loc);
					heap_vec->at(loc) = temp;
					
					// Update the loc to the parent 
					loc = parent;
				}
				
				// Else, set stop_swaps to true
				else{
					stop_swaps = true;
				}
			}
			
		}
		
		bool is_empty(){
			
			return heap_vec->size() == 0;
			
		}
		
		T top(){
			
			return heap_vec->at( 0 );
			
		}
		
		long unsigned int size(){
			
			return heap_vec->size();
			
		}
		
		// For pop 
		bool pop(){
			
			// If the heap is empty, return false
			if( is_empty() )
				return false;
			
			// If the heap size is 1
			if( heap_vec->size() == 1 ){
				
				// Erase the beginning element
				heap_vec->erase( heap_vec->begin() );
				
				// Return true
				return true;
			}
			
			// Otherwise, we need to compare the elements 
			// Get the index of the last element 
			long unsigned int last = heap_vec->size() - 1;
			
			// Copy the last element to 0
			heap_vec->at( 0 ) = heap_vec->at( last );
			
			// Erase the last element
			heap_vec->erase( heap_vec->begin() + last );
			
			// Now we need to move the new top element down
			long unsigned int loc = 0;
			
			// Create a bool for left_valid, and right_valid
			bool left_valid = true;
			bool right_valid = true;
			
			while( true ){
				
				// Develop cases for stopping the swaps
				// First, derive the locations for the children 
				long unsigned int right_child = 2*( loc + 1 );
				long unsigned int left_child = right_child - 1;
				
				if( right_child >= heap_vec->size() )
					right_valid = false;
				
				if( left_child >= heap_vec->size() )
					left_valid = false;
				
				// If both are invalid, loc is a leaf node 
				if( !left_valid && !right_valid )
					return true;
				
				// If the right is invalid, just compare the left node
				// Note: Using > instead of >= will result in a core dump is heap contains duplicates
				if( !right_valid && heap_vec->at(loc) >= heap_vec->at(left_child) ){
					
					// Swap the elements 
					T temp = heap_vec->at(loc);
					heap_vec->at(loc) = heap_vec->at(left_child);
					heap_vec->at(left_child) = temp;
					
					// loc is now guaranteed to be a leaf, so we can return true 
					return true;
				}
				
				// There will not be a situation where the left is invalid and right is valid
				
				// Final case: Both are valid 
				// First, we check if the elements are both larger, then we stop 
				if( heap_vec->at(loc) < heap_vec->at(left_child) &&
					heap_vec->at(loc) < heap_vec->at(left_child)  ){
				
					return true;
				
				}
				
				// Now, we are in a situation where one is guaranteed to be less than or equal 
				long unsigned int swap_loc;
				if( heap_vec->at(left_child) < heap_vec->at(right_child) ){
					
					swap_loc = left_child;
				}
				else{
					
					swap_loc = right_child;
				}
				
				// Swap the locations 
				T temp = heap_vec->at(loc);
				heap_vec->at(loc) = heap_vec->at(swap_loc);
				heap_vec->at(swap_loc) = temp;
				
				// Finally, update the loc to swap_loc 
				loc = swap_loc;
			}
			
			
			return true;
		}
		
		void print_min_heap(){
			
			for( long unsigned int iter = 0; iter < this->heap_vec->size(); ++iter ){
				
				std::cout << this->heap_vec->at( iter ) << " ";
				
			}		
			
		}
	
};
	
	
#endif