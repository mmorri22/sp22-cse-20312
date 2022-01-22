/****************************
 * File Name: fenwick.h 
 * Author: Matthew Morrison 
 * Email: matt.morrison@nd.edu
 * Date Created: 1-05-2022
 *
 * This file contains the function declarations 
 * required for completion of the Programminc Challenge 3
 * Fenwick Tree Assignment 
 ******************************/

#ifndef FENWICK_H
#define FENWICK_H

#include <stdio.h>
#include <stdlib.h>

int* create_array( const char* argv[], long unsigned int num_inputs );

void print_menu();

void print_array( int* array, long unsigned int array_len );

int get_choice();

int* make_fenwick( int* array, long unsigned int length );

void update_fenwick( int* array, int* fenwick, long unsigned int array_len );

void sum_vals( int* fenwick, long unsigned int array_len );

#endif