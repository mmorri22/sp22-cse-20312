#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 30       /* Maximum number of rows in picture      */
#define MAX_COLS 50       /* Maximum number of culumns in picture   */


/* Prototype for the flood fill function */
void Flood (char box[MAX_ROWS][MAX_COLS], int row, int col, char fill);


/* Prototype for the show picture function */
void Show (char box[MAX_ROWS][MAX_COLS], int rows, int cols);


/* Prototype for the read picture function */
void Read (FILE *inputFile, char box[MAX_ROWS][MAX_COLS], int rows, int cols);


int main(const int argc, const char* argv[])
{
   FILE *inputFile ;

   /* The character array  */
   char box [MAX_ROWS][MAX_COLS];

   /* The character that will flood fill */
   char fillChar;

   /* The actual size of the picture   */
   int rows, cols;

   /* The starting position for flood fill */
   int row, col;


   /************************************************************
    * STEP 1                                                   *
    * Complete the check for correct number of arguments at    *
    * start of program below                                   *
    ************************************************************/

   /* if ( checking number of arguments goes here ) */
   {
      /*  print message to standard error goes here */
      exit (-1);
   }


   /* Open the input file and check if OK  */
   inputFile = fopen (argv[4], "r");

   if (inputFile == NULL)
   {
      fprintf (stderr, "\n Could not open the input file %s. ", argv[4]);
      fprintf (stderr, "Check its name and try again.\n");
      exit (-2);
   }


   /*************************************************************
    * STEP 2                                                    *
    * Uncomment the code section below                          *
    *************************************************************/

   /*
     fscanf (inputFile, "%d,%d\n", &rows, &cols);
     printf ("The size of the picture will be %d by %d characters\n",
             rows, cols);
     Read (inputFile, box, rows, cols);
   */

   fclose (inputFile);

   /* Parse the flood fill parameters from the command line */
   sscanf (argv[1], "%d", &row);
   sscanf (argv[2], "%d", &col);
   sscanf (argv[3], "%c", &fillChar);


   /*************************************************************
    * STEP 3                                                    *
    * Complete the definition of Show() at end of this file and *
    * uncomment the call to Show() below;                       *
    *************************************************************/
   /* Show (box, rows, cols); */
   printf ("\n");


   /*************************************************************
    * STEP 4                                                    *
    * Complete the definition of Flood() at end of this file and*
    * uncomment the calls to Flood() and Show() below;          *
    *************************************************************/

   /* Flood (box, row, col, fillChar); */
   /* Show (box, rows, cols); */

   printf ("\n\nGood Bye\n\n");
   return 0;
}



/*************************************************************
Read()
 Inputs:    pointer to input file
            integer number of rows to read
            integer number of columns to read
 Outputs    character array that must be modified by reading
            one character into each array position
*************************************************************/
void Read (FILE *inputFile, char box[MAX_ROWS][MAX_COLS], int rows, int cols)
{
   int i, j;
   char k;

   for (i = 0; i < rows; i++)
   {
      for (j = 0; j < cols; j++)
      {
	 fscanf (inputFile, "%c", &box [i][j]);
      }

      /* read the endline character */
      fscanf (inputFile, "%c", &k);
   }
}



/*************************************************************
 STEP 3
 Complete the definition of Show()
 Inputs:    character array that must be displayed
            integer number of rows to display
            integer number of columns to display
 Outputs    none
*************************************************************/
void Show (char box[MAX_ROWS][MAX_COLS], int rows, int cols)
{
   int i, j;

   /*  complete here. don't forget to output a newline
   **  at the end of each output line
   */

}



/*************************************************************
 STEP 4
 Complete the recursive definition of Flood()
 Inputs:    integer row of the picture
            integer column of the picture
            character that must fill the spaces
 Outputs    character array that must be modified by writing
            the flood character into each reachable blank position
*************************************************************/
void Flood (char box[MAX_ROWS][MAX_COLS], int row, int col, char fill)
{
   /* Base case - return if this spot is not a space */
   if ( box [row][col] != ' ')
   {
      return;
   }

   box[row][col] = fill;

   /*  Complete here. Use four recursive calls to Flood() to fill the adjacent
   **  blank positions. Pay attention to array boundaries.
   */
}
