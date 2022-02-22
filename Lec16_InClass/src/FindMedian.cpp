#include "../include/min_heap.h"
#include "../include/max_heap.h"

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

void addNum( int input, max_heap<int>& left, min_heap<int>& right ){
	



}


void getMedian( max_heap<int>& left, min_heap<int>& right ){
	
	COUT << "Median: ";
	
	if( left.is_empty() && right.is_empty() ){
		COUT << "No values input. No median to calculate" << ENDL;
	}
	
	else if( left.size() > right.size() ){
		COUT << left.top() << ENDL;
	}
	
	else{
		COUT << ( (double)left.top() + (double)right.top() ) / 2 << ENDL;
	}
	
}

int main(){
	
	max_heap< int > left;
	min_heap< int > right;
	
	int input = 0;
	
	while( input >= 0 ){
		
		COUT << "Insert a positive integer (or -1 to quit): ";
		
		CIN >> input;
		
		if( input >= 0 ){
			
			addNum( input, left, right );
			
			COUT << "Left Heap : ";
			left.print_max_heap(); 
			
			COUT << "\tRight Heap: ";
			right.print_min_heap(); 
			
			COUT<< ENDL;
			
			getMedian( left, right );
			COUT << ENDL;
			
		}
	}
	
	return 0;
}
