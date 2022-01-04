#include <stdio.h>

int main(void){

	int print_int = 5;

	fprintf( stdout, "%d %p\n", print_int, &print_int );

	return 0;
}
