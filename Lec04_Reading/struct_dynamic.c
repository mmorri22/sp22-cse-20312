#include <stdio.h>
#include <stdlib.h>

// struct definition
typedef struct simple{
	int the_int;
  float the_float;
	double the_double;
} simple;

int main(){
      //create a struct on the heap
      simple* dynamic_struct = (simple *)malloc( sizeof(simple) );

			dynamic_struct->the_int = 45;
			dynamic_struct->the_float = (float)-1.1;
			dynamic_struct->the_double = 45.1;

			fprintf( stdout, "%p %p\n", &dynamic_struct, dynamic_struct);
			fprintf( stdout, "%d %p\n", dynamic_struct->the_int, &(dynamic_struct->the_int));
      fprintf( stdout, "%f %p\n", dynamic_struct->the_float, &(dynamic_struct->the_float));
      fprintf( stdout, "%lf %p\n", dynamic_struct->the_double, &(dynamic_struct->the_double));

			free( dynamic_struct );

      return 0;
}
