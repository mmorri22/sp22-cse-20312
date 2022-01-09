/******************************************************************************/

int get_random_int (int min, int max){
  int random_int = rand();
  random_int = random_int % (max - min + 1) + min;
  return random_int;
}

/******************************************************************************/

void fill_array(int int_array[], long unsigned int length, int min, int max){
  srand( (unsigned int)time(NULL) );
  long unsigned int iter;
  for (iter = 0; iter < length; ++iter) {
    int_array[iter] = get_random_int(min, max);
  }
  fprintf(stdout, "Unsorted array\n");
  fprintf(stdout, "Printing array...\n");
  for (iter = 0; iter < length; ++iter) {
    fprintf(stdout, "%d ", int_array[iter]);
  }
  fprintf(stdout, "\n");
}

/******************************************************************************/

void insertion_sort(int int_array[], long unsigned int length){
  long unsigned int last_sorted;
  long unsigned int first_unsorted;
  int test_index;
  for (first_unsorted = 1; first_unsorted < length; first_unsorted++){
    //iterating through unsorted elemenets
    last_sorted = first_unsorted - 1;
    //getting index of the last element that is sorted -- right before the first unsorted
    test_index = int_array[first_unsorted];
    //extracting first unsorted value to check during this loop
    while(test_index < int_array[last_sorted]){
      //checking if test_index is less than greatest element in sorted portion
      int_array[last_sorted + 1] = int_array[last_sorted];
      //if yes -- moving the last sorted element to the right (which prev contained first unsorted element)
      last_sorted = last_sorted - 1;
      //now we will check the element that was to the left (second greatest of sorted elements)
    }
    //test_index > or = the 'last_sorted' element so it will go last
  int_array[last_sorted + 1] = test_index;
  //putting the test_index at the end of the sorted elements
  //adding 1 to last_sorted because there's now one more sorted element (test_index)
  }
  //iterating through to next unsorted element until we get to the last element in the array
  //ie first unsorted will be last element
  //after that all elements will have been sorted
}

/******************************************************************************/

void print_array(int int_array[], long unsigned int length){
  long unsigned int iter;
  fprintf(stdout, "Sorted array\n");
  fprintf(stdout, "Printing array...\n");
  for (iter = 0; iter < length; ++iter) {
    fprintf(stdout, "%d ", int_array[iter]);
  }
  fprintf(stdout, "\n");
}
