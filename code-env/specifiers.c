/**********************************************
* File: intPrint.c
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This files shows examples of int being added and subtracted and printed
* to the standard output 
**********************************************/

#include <stdio.h>

/********************************************
* Function Name  : main
* Pre-conditions : void
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(void){

	/* Variables */
	int i = 17, j = 16, k = 13, sum, diff;
	
	fprintf(stdout, "Calculating integer sum...\n");
	
	sum = i + j + k;
	
	fprintf(stdout, "Decimal value of sum is: %d\n", sum);
	fprintf(stdout, "Hex value of sum is    : %x\n", sum);
	
	/* Performing subtraction */
	
	fprintf(stdout, "\nCalculating Integer Difference\n");
	
	diff = i - j - k;
	
	fprintf(stdout, "Decimal value of diff is: %d\n", diff);
	fprintf(stdout, "Hex value of diff is    : %x\n", diff);

	return 0;
}
