#include "../include/Treap3.h"
#include <cstdlib> 
#include <ctime> 

#define COUT std::cout
#define ENDL std::endl

template< class T >
void insertAndPrint( Treap<T>& theTreap, T value ){
	
	COUT << "Inserting value " << value << "...\n";
	theTreap.Insert( value );
	COUT << theTreap << ENDL;
	COUT << "-----------------------------------------" << ENDL;
}

int main(){
	
	// Call srand exactly once
	srand( (unsigned)time(0) ); 
	
	Treap< char > treap1;
	
	insertAndPrint( treap1, 'D' );	insertAndPrint( treap1, 'F' );
	insertAndPrint( treap1, 'H' );	insertAndPrint( treap1, 'C' );
	insertAndPrint( treap1, 'A' );	insertAndPrint( treap1, 'I' );
	insertAndPrint( treap1, 'G' );
	
	return 0;
}
