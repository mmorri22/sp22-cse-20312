#include <iostream>
#include <deque>

void search( std::deque<int>& subset, int start, int end ) {
    
    if ( start == end ) {
        std::cout << "{ ";
		
		if( subset.size() == 0 ){
			std::cout << "Empty Set ";
		}
		
		// Smart Iterator
        for( int value : subset ){
            std::cout << value << " ";
        }
        std::cout << "}, ";
    } 

    else {
        search(subset, start+1, end);
        subset.push_back(start);
        search(subset, start+1, end);
        subset.pop_back();
    }
}


int main(){
    
    std::deque<int> subset;
    
    search( subset, 0, 3 );
	
	std::cout << std::endl;
    
    return EXIT_SUCCESS;
}