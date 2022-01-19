#include <stdio.h>
#include <stdlib.h>
// #include <string>


/**
 * Type representing a cell in the maze.
 */
typedef struct maze_cell {
    item whatsHere; // Which item, if any, is present.

    struct maze_cell* north;
    struct maze_cell* south;
    struct maze_cell* east;
    struct maze_cell* west;
	
}maze_cell;

/**
 * Type representing an item in the maze.
 */
enum item { NOTHING, SPELLBOOK, POTION, WAND };

/********************
 * Function: is_path_to_freedom
 * Preconditions: An initial maze_cell, a character array moves
 *                and a long unsigned integer representing the string length
 *
 * Post Conditions: int. 0 if false, 1 if true.
 *********************/
int is_path_to_freedom(maze_cell* start, const char* moves, long unsigned int str_length);
