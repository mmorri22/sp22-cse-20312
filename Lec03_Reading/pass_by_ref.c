#include <stdio.h>

void foo( int* x ){

	fprintf( stdout, "Working memory (register) address of x in foo            : %p\n", &x);
	fprintf( stdout, "Value of the information inside the register x in foo    : %p\n", x );	
	fprintf( stdout, "Working memory (register) address of de-ferenced x in foo: %p\n", &*x );	
	fprintf( stdout, "De-referenced value of x in foo prior to addition        : %d\n", *x );

	*x += 2;

	fprintf( stdout, "De-referenced value of x in foo after the addition       : %d\n", *x );
}

int main( void ){

	int x = 4;

	fprintf( stdout, "Old x data value in the working memory (register) in main: %d\n", x);
	fprintf( stdout, "Working memory (register) address of x in main           : %p\n", &x);

	foo( &x );

	fprintf( stdout, "New x data value in the working memory (register) in main: %d\n", x);	

	return 0;

}
