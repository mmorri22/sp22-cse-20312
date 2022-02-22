#include "../include/BinomialHeap.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main( )
{
    BinomialHeap<int> heapOdd;
    BinomialHeap<int> heapEven;
    BinomialHeap<int> heapMerge;

    COUT << "Begin test.\nInserting: ";
    for( int i = 37; i != 0; i = ( i + 37 ) % 500 ){
		
		COUT << i << " ";
		
        if( i % 2 == 0 )
            heapEven.insert( i );
        else
            heapOdd.insert( i );
	}
	
	COUT << ENDL << ENDL;

	// Test merge and copy constructor methods
    heapOdd.merge( heapEven );
    heapMerge = heapOdd;

	COUT << "Removing : ";
    while( !heapMerge.isEmpty( ) )
    {
		COUT << heapMerge.findMin( ) << " ";
		
		heapMerge.deleteMin( );
    }
	
	COUT << ENDL;

    COUT << "Successfully completed test!" << ENDL;

    return 0;
}
