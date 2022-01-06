#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int main() {
	fprintf( stdout, "a + b = %d\n", add(1,2) );
	return 0;
}
