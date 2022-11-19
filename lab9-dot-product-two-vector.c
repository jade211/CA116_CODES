/*
 Name: lab9-dot-product-two-vector.c
 Author: Jade Hudson
 Date: 12/11/2022

 Description: Program takes in two vectors and calculates the dot product of them.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function Dot_Product_Calc returns the Dot Product of the two given vectors. */
void Dot_Product_Calc(int *vec1, int *vec2, int *pvector_count);

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
    int vector_size = atoi(argv[1]);

    int *pVector1 = (int*)malloc(vector_size*sizeof(int));
    if(!pVector1)
    {
        printf("Failed to allocate memory!");
        free(pVector1);
        pVector1 = NULL;
    }

    int *pVector2 = (int*)malloc(vector_size*sizeof(int));
    if(!pVector2)
    {
        printf("Failed to allocate memory!");
        free(pVector2);
        pVector2 = NULL;
    }
    

    /*CODE*/
    for(unsigned int i = 0; i < vector_size; ++i)
    {
        pVector1[i] = atoi(argv[i + 2]);
        // printf("VECTOR 1: %d\n", pVector1[i]);
    }

    for(unsigned int i = 0; i < vector_size; ++i)
    {
        pVector2[i] = atoi(argv[vector_size + 2 + i]);
        // printf("VECTOR 2 : %d\n", pVector2[i]);
    }

    Dot_Product_Calc(pVector1, pVector2, &vector_size);

    free(pVector1);
    pVector1 = NULL;
    free(pVector2);
    pVector2 = NULL;
    return (0);
}

/* FUNCTIONS*/
void Dot_Product_Calc(int *vec1, int *vec2, int *pvector_count)
{
    /* VARIABLES */
    int result = 0;
    int mini_multiplier = 0;


    /* CODE */
    for (unsigned int i = 0; i < *pvector_count; i++)
    {
        mini_multiplier = vec1[i] * vec2[i];
        result = result + mini_multiplier;
    }
    printf("%d\n", result);
}
