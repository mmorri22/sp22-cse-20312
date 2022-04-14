#include "../include/Treap.h"

#define COUT std::cout
#define ENDL std::endl

template< class T >
void insertAndPrint( Treap<T>& theTreap, T value, double priority ){
	
	COUT << "Inserting value " << value << " with priority " << priority << "...\n";
	
	theTreap.Insert( value, priority );
	
	COUT << theTreap << ENDL;
	
	COUT << "-----------------------------------------" << ENDL;
	
}

int main(){
	
	Treap< char > treap1;
	
	insertAndPrint( treap1, 'D', 60 );
	insertAndPrint( treap1, 'F', 75 );
	insertAndPrint( treap1, 'H', 14 );
	insertAndPrint( treap1, 'C', 70 );
	insertAndPrint( treap1, 'A', 55 );
	insertAndPrint( treap1, 'I', 55 );
	insertAndPrint( treap1, 'G', 80 );
	
	return 0;
}
