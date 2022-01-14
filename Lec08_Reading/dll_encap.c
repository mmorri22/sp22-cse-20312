#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node{

	int data;
	struct dll_node* prev_node;
	struct dll_node* next_node;

}dll_node;


typedef struct dllist{

	struct dll_node* head_node;
	struct dll_node* tail_node;

}dllist;

dllist* constructor(){

    dllist* temp_node = (dllist *)malloc( sizeof(dllist) );

    return temp_node;

}

void destructor( dllist* delete_list ){

    free( delete_list );

}

int main()
{

    dllist* list_1 = constructor();
    dllist* list_2 = constructor();

    destructor( list_2 );
    destructor( list_1 );

    return EXIT_SUCCESS;
}
