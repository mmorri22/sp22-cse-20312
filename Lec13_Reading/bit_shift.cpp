#include <iostream>

int main(){
    
    int size = 3;
    
    std::cout << "size = " << size << ", ( 1 << size ) = " << ( 1 << size ) << std::endl;
    
    for( int iter = 0; iter < (1 << size); ++iter){
    
        std::cout << iter << ", " << (1 << iter) << std::endl;
    
    }
    
    return EXIT_SUCCESS;
}