#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int mult(int a, int b) {
	return a * b;
}

typedef int (*MyFunc)(int, int);

void callFunc(MyFunc f,int x,int y) {

	fprintf( stdout, "Calling f = %d\n", f(x,y) );

}

int main() {
	callFunc(add, 2, 3);
	callFunc(mult, 10, 2);
	return 0;
}



