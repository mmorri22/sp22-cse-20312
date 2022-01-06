#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int mult(int a, int b) {
	return a * b;
}

typedef int (*MyFunc)(int, int);

int callFunc(MyFunc f,int x,int y) {

	if( f == add )
		fprintf( stdout, "Adding " );

	else if( f == mult )
		fprintf( stdout, "Multiplying ");

	int return_val = f(x,y);

	fprintf( stdout, "%d and %d gives %d\n", x, y, return_val );

	return return_val;

}

int main() {

	fprintf( stdout, "(2+3)*(10*2) = %d\n", callFunc( mult, callFunc( add, 2, 3 ), callFunc( mult, 10, 2) ) );
	
	return 0;
}



