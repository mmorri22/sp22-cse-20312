#include <iostream>
#include <cstdlib>

int main(){
    
    // C++ equivalent of malloc
    // C synonym: int* int_array = (int *)malloc( 10 * sizeof(int) );
    int* int_array = new int[10];
    
	std::cout << &int_array << " " << &int_array[0] << std::endl;
	
    for( int iter = 0; iter < 10; ++iter ){
        
        int_array[iter] = iter * 2;
        
        std::cout << int_array[iter] << " ";
    }
    std::cout << std::endl;
    
    // C++ equivalent of free 
    // C synonym: free( int_array );
    delete [] int_array;
    
    return EXIT_SUCCESS;
}