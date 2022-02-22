#include "../include/max_heap.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, char * argv[] ){
	
	
	// Instantiate a min heap on the heap using new
	max_heap<int>* the_heap = new max_heap<int>();
	
	COUT << "Push and Show:" << ENDL;
	
	for( int iter = 1; iter < argc; ++iter ){
	
		the_heap->push( atoi( argv[iter] ) );
		
		COUT << "Updated heap: "; 
		
		the_heap->print_max_heap();
		
		COUT << ENDL;
	
	}
	
	COUT << "Pop and Show:" << ENDL;
	
	while( !the_heap->is_empty() ){
		
		COUT << "Top element : " << the_heap->top() << ENDL;
		
		COUT << "Updated heap: "; 
		
		the_heap->print_max_heap();
		
		COUT << ENDL;
		
		the_heap->pop();
	}
	
	// Delete the Heap using delete
	delete the_heap;
	
	return 0;
}

