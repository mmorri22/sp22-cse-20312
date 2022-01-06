#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int (*ptrAdd)(int, int);

int main() {

	ptrAdd = add;

	fprintf( stdout, "a + b = %d\n", ptrAdd(1,2) );
	return 0;
}
