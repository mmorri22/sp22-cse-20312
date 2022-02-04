/* Author: Matthew Morrison
 * Email: matt.morrison@nd.edu 
 * File Name: sudoku_08.h
 * Date Created: 9/18/2021
 *
 *
 * This file contains the function declarations for
 * the Sudoku Combined Concepts lecture(s)
 **********************************************/
 
#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

void print_greeting( void );

void alloc_sudoku( int** sudoku );

void populate_puzzle( FILE* sudoku_file, int** sudoku );

void free_sudoku( int** sudoku );

int player_choice ( void );

void print_puzzle( int** sudoku );

void get_user_choice( int* value, long unsigned int* row,
						long unsigned int* col );

void update_puzzle( int** sudoku, int value, long unsigned int row, 
					long unsigned int col );
					
unsigned int check_user_input( int** sudoku, int value, 
					long unsigned int row, long unsigned int col );
					
unsigned int check_user_input_no_print( int** sudoku, int value, 
					long unsigned int row, long unsigned int col );

unsigned int recursive_solver( int** sudoku, long unsigned int row, long unsigned int col );
				
unsigned int check_puzzle( int** sudoku );

#endif