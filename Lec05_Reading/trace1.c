#include <stdio.h>

int func_1( int val );
int func_2( int val );

int main(){
    
    fprintf(stdout, "\n Answer is %d\n", func_1( 5 ) );
    
    return 0;
}

int func_1( int val ){
    
    val *= 2;
    
    if( val == 0 ){
        fprintf( stdout, "1 " );
        return 1;
    }
    
    int return_val = val * func_2( val - 2 );
    
    fprintf( stdout, "%d ", return_val );
    
    return return_val;
    
}

int func_2( int val ){
    
    if( val <= 2 ){
        fprintf( stdout, "2 " );
        return 2;
    }
    
    val /= 2;
    
    int return_val = val * func_1( val - 1 );  
    
    fprintf( stdout, "%d ", return_val );
    
    return return_val;

}
