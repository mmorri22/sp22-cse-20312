#ifndef SORTSEARCH_H
#define SORTSEARCH_H

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>	// boolean

#define SENTINEL -1
#define MAX      100  

void printArray(int* array, int length);

void merge( int* array, int min, int max );

int ReadArray( int array[], int maxSize) ;

int GetValidInt();

int FindElement( int array[], unsigned int arrayLen, int searchVal  );

#endif
