#include <stdio.h>

int foo( int x );
int bar( int y );

int main(){
    fprintf( stdout, "%d\n", foo(10) );
    return 0;
}

int foo( int x ){
    
    fprintf( stdout, "In foo: x = %d\n", x);
    
    if( x <= 0 ){
        fprintf( stdout, "Foo base case!\n");
        return 1;
    }
    
    if( x % 2 == 0 ){
        fprintf( stdout, "Foo Case 2!\n");
        return x + bar( x - 1 );
    }
        
    else{
        fprintf( stdout, "Foo Case 3!\n");
        return x + foo( x - 4 );
    }
    
}

int bar( int y ){
    
    fprintf( stdout, "In bar: y = %d\n", y);
    
    if( y <= 0 ){
        fprintf( stdout, "Bar base case!\n");
        return 2;
    }
    
    if( y % 2 == 0 ){
        fprintf( stdout, "Bar Case 2!\n");
        return y + foo( y - 2 );
    }
        
    else{
        fprintf( stdout, "Bar Case 3!\n");
        return y + bar( y - 3 );
    }
    
}