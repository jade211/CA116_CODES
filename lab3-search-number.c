/*
 Name: lab3-search-number.c
 Author: Jade Hudson
 Date: 1/10/2022

 Description: Finds a specific number in an array of numbers.
 Returns: Integer and index of integer.
*/

#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function finds the max number in array.*/
int Find_Num(int *num_list, int target, int arg_count);


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
    int target;
    int arg_count = argc - 1;
    int num_list[arg_count];


    /* MAIN CODE */ 
    target = atoi(argv[1]);

    for(unsigned int i = 1; i < arg_count; ++i)
    {
        num_list[i] = atoi(argv[i + 1]);
    }

    Find_Num(num_list, target, arg_count);

    return (0);
}


/* FUNCTIONS */
int Find_Num(int *num_list, int target, int arg_count)
{
    for(unsigned int i = 1; i < arg_count; i++)
    {
        if(target == num_list[i])
        {
            printf("Found %d at %d\n", target, i - 1);
        }
    }
}
