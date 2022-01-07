#include <stdio.h>

// struct definition
typedef struct simple{
	int the_int;
  float the_float;
	double the_double;
} simple;

int main(){
      //create a struct on the stack
      simple simple_str = {-14, (float)22.7, 9.2 };

      fprintf( stdout, "%p\n", &simple_str);
      fprintf( stdout, "%d %p\n", simple_str.the_int, &(simple_str.the_int));
      fprintf( stdout, "%f %p\n", simple_str.the_float, &(simple_str.the_float));
      fprintf( stdout, "%lf %p\n", simple_str.the_double, &(simple_str.the_double));

      return 0;
}
