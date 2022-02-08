#include <stdio.h>
#include <stdlib.h>

void malloc_arrays( int** matrix, long unsigned int size );

void free_arrays( int** matrix, long unsigned int size );

void read_file( int** matrix, long unsigned int size, FILE* in_file );

int search_maze( int** matrix, long unsigned int size, int iter, int jter );

void print_maze( int** matrix, long unsigned int size );

void solve_maze( int** matrix, long unsigned int size );

int max( int a,  int b );

void malloc_arrays( int** matrix, long unsigned int size ){
	
	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		
		matrix[iter] = (int *)malloc( size * sizeof(int) );
		
	}
	
}

void free_arrays( int** matrix, long unsigned int size ){
	
	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		
		free( matrix[iter] );
		
	}
	
}


void read_file( int** matrix, long unsigned int size, FILE* in_file ){
	
	long unsigned int iter = 0;
	long unsigned int jter = 0;
	
	while( in_file != NULL ){
		
		int curr_val;
		
		fscanf( in_file, "%d", &curr_val );
		
		matrix[iter][jter] = curr_val;
		
		++jter;
		
		if( jter == size ){
			jter = 0;
			++iter;
		}
		
		if( iter == size )
			break;		
		
		if( in_file->_IO_read_ptr == in_file->_IO_read_end  )
			break;		
	}
	
}


int search_maze( int** matrix, long unsigned int size, int iter, int jter ){
	
	int right_val = 0; 
	int down_val = 0;
	
	// Search Down
	if( iter + 1 < (int)size ){
		
		down_val = search_maze( matrix, size, iter + 1, jter );
	}	
	
	// Search Right
	if( jter + 1 < (int)size ){
		
		right_val = search_maze( matrix, size, iter, jter + 1 );
	}
	
	// Compare
	int curr_max = max( down_val, right_val );
	
	// Return curr_max and the current value
	return matrix[iter][jter] + curr_max;
	
}

void print_maze( int** matrix, long unsigned int size ){
	
	
	long unsigned int iter = 0;
	long unsigned int jter = 0;
	
	for( iter = 0; iter < size; ++iter ){
		
		for( jter = 0; jter < size; ++jter ){
			
			fprintf( stdout, "%d ", matrix[iter][jter] );
		}
		fprintf( stdout, "\n" );
	}
	
}


void solve_maze( int** matrix, long unsigned int size ){
	
	int max_squirrels = search_maze( matrix, size, 0, 0 );
	
	fprintf( stdout, "Maximum Squirrels is %d\n", max_squirrels );
	
}

int max( int a,  int b ) {
	
    return (a > b) ? a : b;
	
}



int main( int argc, char* argv[] ){
	
	if( argc != 2 ){
		fprintf( stderr, "Incorrect number of inputs\n" );
		return EXIT_FAILURE;
	}
	
	FILE* in_file = fopen( argv[1], "r" );
	
	long unsigned int size;
	fscanf( in_file, "%lu", &size );
	
	int** matrix = (int **)malloc( size * sizeof(int *) );
	
	malloc_arrays( matrix, size );
	
	read_file(  matrix, size, in_file );
	
	print_maze( matrix, size );
	
	solve_maze( matrix, size );
	
	free_arrays( matrix, size );
	
	free( matrix );
	
	fclose( in_file );
	
	return 0;
}