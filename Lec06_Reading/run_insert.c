#include "insert_sort.h"

int main(){

  int max = 100;
  int min = 1;

  long unsigned int length = 10;
  int int_array[length];

  fill_array(int_array, length, min, max);

  insertion_sort(int_array, length);

  print_array(int_array, length);

  return 0;
}
