/*
 Name: lab3-findMax.c
 Author: Jade Hudson
 Date: 1/10/2022

 Description: Accepts an array of integers via the command line and returns the largest elememt
 Returns: Integer
*/

#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function finds the max number in array.*/
int Max_Num(int *num_list, int arg_count);


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
    Max_Num(num_list, arg_count);

    return (0);
}


/* FUNCTIONS */
int Max_Num(int *num_list, int arg_count)
{
    int biggest;

    biggest = num_list[0];
    for(unsigned int i = 1; i < arg_count; i++)
    {
        if(biggest < num_list[i])
        {
            biggest = num_list[i];
        }
    }

    printf("%d\n", biggest);
}
