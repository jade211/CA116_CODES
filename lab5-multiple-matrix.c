/*
 Name: lab5-multiple-matrix.c
 Author: Jade Hudson
 Date: 16/10/2022

 Description: This program accepts two row numbers, two column numbers and integers to go in each matrix's. This program prints the resulting matrix of the product of the two given matrixes
 Returns: Int Matrix
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function creates 2 matrixes and multiplies them to form a new matrix.*/
int Matrix(int *num_list, int *pmatrix_row1, int *pmatrix_column1, int *num_list2, int *pmatrix_row2, int *pmatrix_column2);

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
    int matrix_row1 = atoi(argv[1]);
    int matrix_column1 = atoi(argv[2]);
    int matrix_length1 =  (matrix_row1 * matrix_column1);
    int num_list1[matrix_length1];

    int matrix_row2 = atoi(argv[(3 + matrix_length1)]);
    int matrix_column2 = atoi(argv[(3 + matrix_length1) + 1]);
    int matrix_length2 = (matrix_row2 * matrix_column2);
    int num_list2[matrix_length2];

    /* MAIN CODE */ 
    for(unsigned int i = 0; i < matrix_length1; ++i)
    {
        num_list1[i] = atoi(argv[i + 3]);
        // printf("%d\n", num_list1[i]);
    }

    for(unsigned int j = 0; j < matrix_length2; ++j)
    {
        num_list2[j] = atoi(argv[(3 + matrix_length1) + 2 + j]);
    }
    Matrix(num_list1, &matrix_row1, &matrix_column1, num_list2, &matrix_row2, &matrix_column2);
    return (0);
}

/* FUNCTIONS */
int Matrix(int *num_list, int *pmatrix_row1, int *pmatrix_column1, int *num_list2, int *pmatrix_row2, int *pmatrix_column2)
{
    int matrix_list1[*pmatrix_row1][*pmatrix_column1];
    int matrix_list2[*pmatrix_row2][*pmatrix_column2];
    int v1 = 0;
    int v2 = 0;
    int result[10][10];

    for (unsigned int i = 0; i < *pmatrix_row1; i++)
    {
        for (unsigned int j = 0; j < *pmatrix_column1; j++)
        {
            matrix_list1[i][j] = num_list[v1];
            // printf("Matrix[%d][%d]: %d\n", i, j, num_list[v1]);
            v1++;
        }
    }

    for (unsigned int i = 0; i < *pmatrix_row2; i++)
    {
        for (unsigned int j = 0; j < *pmatrix_column2; j++)
        {
            matrix_list2[i][j] = num_list2[v2];
            // printf("Matrix[%d][%d]: %d\n", i, j, num_list2[v2]);
            v2++;
        }
    }

    for (int i = 0; i < *pmatrix_row1; i++)
    {
        for (int j = 0; j < *pmatrix_column2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < *pmatrix_row2; k++)
            {
                result[i][j] += matrix_list1[i][k] * matrix_list2[k][j];
            }
        }
    }

    for (int i = 0; i < *pmatrix_row1; i++)
    {
        for (int j = 0; j < *pmatrix_column2; j++)
        {
            if ((j == 0))  // OR if (j + 1 < *pmatrix_column2), printf("%d ", result[i][j]), else printf("%d", result[i][j[]])
            {
                printf("%d", result[i][j]);   
            }
            else
            {
                printf(" %d", result[i][j]);
            }
        }
    printf("\n");
    }

    return 0;
}
