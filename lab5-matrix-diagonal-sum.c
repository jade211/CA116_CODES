/*
 Name: lab5-matrix-diagonal-sum.c
 Author: Jade Hudson
 Date: 15/10/2022

 Description: This program, given an array of integers, calculates the sum of the matrix main diagonal and prints the result.
 Returns: Int
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function takes an array of integers and calculates the sum of the matrix main diagonal and prints the result.*/
int Matrix(int *pnum_list, int *pmatrix_dim);

/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int matrix_dim = atoi(argv[1]);
    int length = argc - 2;
    int num_list[length];


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < length; ++i)
    {
        num_list[i] = atoi(argv[i + 2]);
    }
    Matrix(num_list, &matrix_dim);
    return (0);
}

/* FUNCTIONS */
int Matrix(int *pnum_list, int *pmatrix_dim)
{
    int matrix_list[*pmatrix_dim][*pmatrix_dim];
    int v = 0;
    int sum = 0;

    for (unsigned int i = 0; i < *pmatrix_dim; i++)
    {
        for (unsigned int j = 0; j < *pmatrix_dim; j++)
        {
            matrix_list[i][j] = pnum_list[v];
            // printf("Matrix[%d][%d]: %d\n", i, j, pnum_list[v]);
            v++;
        
        }
    }

    for(int i = 0; i < *pmatrix_dim; i++)
    {
        sum = sum + matrix_list[i][i];
    }

    printf("%d\n", sum);
    return 0;
}
