#include <iostream>
#include <cstdlib>

template <class T>
T max ( const T& a, const T& b ){

    if ( a < b )
        return b;

    else
        return a;
        
}

int main(){
    
    int int_1 = 1, int_2 = 2;
    double double_1 = 1.1, double_2 = -2.2;
    float float_1 = (float)3.3, float_2 = (float)4.4;
    
    std::cout << max( int_1, int_2 ) << std::endl;
    std::cout << max( double_1, double_2 ) << std::endl;
    std::cout << max( float_1, float_2) << std::endl;

    return EXIT_SUCCESS;
}