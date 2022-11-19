/*
 Name: lab3-duplicated-number.c
 Author: Jade Hudson
 Date: 1/10/2022

 Description: The program goes through a command line array looking for duplicated numbers and prints out the duplicated number if any.
 Returns: Integer or "no duplicated number"
*/

#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function finds the max number in array.*/
int Find_Duplicates(int *num_list, int arg_count);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int arg_count = argc - 1;
    int num_list[arg_count];


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)
    {
        num_list[i] = atoi(argv[i + 1]);
    }

    Find_Duplicates(num_list, arg_count);

    return (0);
}


/* FUNCTIONS */
int Find_Duplicates(int *num_list, int arg_count)
{
    /* VARIABLES */
    int duplicate= -1;

    /* CODE */
    for (unsigned int i = 0; i < arg_count; ++i)
    {
        for (unsigned int j = i + 1; j < arg_count; ++j)
        {
            if (num_list[i] == num_list[j])
            {
                duplicate = num_list[j];
                printf("%d\n", duplicate);
                return 0;
            }
        }
    }

    if (duplicate == -1)
    {
        printf("no duplicated number\n");
    }
}