/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;

}sll_node;


typedef struct sllist{

	struct sll_node* head_node;

}sllist;

sllist* constructor(){

    sllist* temp_node = (sllist *)malloc( sizeof(sllist) );

    return temp_node;

}

void destructor( sllist* delete_list ){

    free( delete_list );

}

int main()
{

    sllist* list_1 = constructor();

    sllist* list_2 = constructor();

    destructor( list_2 );

    destructor( list_1 );

    return EXIT_SUCCESS;
}
