/*
 Name: ex2-diagonal.c
 Author: Jade Hudson
 Date: 3/11/2022

 Description: This program, given an input of integers, calculates the sum of the anti-diagonal of the matrix made with these integers.
 Returns: Int

Plan:
- I will take in the input and create a usable array called num_list, I will also get the matrix_dim figure.
- I will then send this array and matrix_dim to the Matrix function and create a matrix. 
- After the matrix is made, I will sum the integers found at each of the positions of the anti-diagonal and print out the resulting integer.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function takes in an array of integers and calculates the sum of the matrix anti-diagonal and prints the result.*/
int Matrix(int *pnum_list, int *pmatrix_dim);


/* MAIN FUNCTION */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int matrix_dim = atoi(argv[1]); /* Takes the matrix size */
    int length = argc - 2;  /* Calculates the length of the matrix array minus the matrix_dim command line input and code title command line input. */
    int num_list[length];  /* Creates new array to add matrix numbers into. */


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < length; ++i)
    {
        num_list[i] = atoi(argv[i + 2]);  /* Adds integers from command line into new array*/
    }
    Matrix(num_list, &matrix_dim);  /* Sends new array and pointer to matrix_dim to function Matrix to calc the sum of the anti-diagonal. */
    return (0);
}

/* FUNCTIONS */
int Matrix(int *pnum_list, int *pmatrix_dim)
{
    /* VARIABLES */
    int matrix_list[*pmatrix_dim][*pmatrix_dim];  /* Creates a matrix to the size of (matrix_dim x matrix_dim) */
    int v = 0;  /* Acts as a counter to iterate through the number list. */
    int sum = 0;

    /* MAIN CODE */
    for (unsigned int i = 0; i < *pmatrix_dim; i++)
    {
        for (unsigned int j = 0; j < *pmatrix_dim; j++)
        {
            matrix_list[i][j] = pnum_list[v];  /* Adds number from number list to position in matrix, ie: (First number added to position 0, 0), (Second number added to position 0, 1) etc */
            v++;
        
        }
    }

    for(int i = (*pmatrix_dim - 1); i >= 0; i--)
    {
        sum = sum + matrix_list[i][*pmatrix_dim - i - 1];  /* Adds the numbers together found at the anti-diagonal positions */
    }
    printf("%d\n", sum);
    return 0;
}
