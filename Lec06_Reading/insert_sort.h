#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_int (int min, int max);
/* returns a random number within certain bounds */

void fill_array(int int_array[], long unsigned int length, int min, int max);
/* fills an array with random integers using the get_random_int function */

void insertion_sort(int int_array[], long unsigned int length);
/* sorts the array of random numbers using insertion sort */

void print_array(int int_array[], long unsigned int length);
/* prints the values of the array */

#endif
