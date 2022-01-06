#include <stdio.h>

int main(){
	
	int i = 0;
	int size = 5;
	int sample[size]; // = {10, 22, -17, 44, 5};
	
	for(i = 0; i < 5; i++){
		
		fprintf( stdout, "element = %d, address = %p, data = %d\n", i, &sample[i], sample[i] );
	}
	
	fprintf( stdout, "\n");
	
	return 0;
}

