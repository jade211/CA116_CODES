/*
 Name: ex1-largest-smallest.c
 Author: Jade Hudson
 Date: 6/10/2022

 Description: Accepts an array of floats and prints out the largest or smallest float based on the first arguement.
 Returns: Float

 Plan:
 - Will take in input and decide whether to send it to Largest function (if argv[1] is "largest")
   or to send to Smallest function (if argv[1] is "smallest") by using strcmp()
 - Will then use a base number as started biggest (or smallest) and compare each
   number to it to find the biggest (or smallest) number in the array
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function Largest finds largest Float in Array, Dunction Smallesr finds smallest Float in Array */
float Largest_Float(float *num_list, int arg_count);
float Smallest_Float(float *num_list, int arg_count);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* makes sure to have an input in command line, if none will print invalid */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int arg_count = argc - 1;
    float num_list[arg_count];  /* num_list is as big as number of command line arguements */


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)  /* adds all numbers to a usable array for functions */
    {
        num_list[i] = atof(argv[i + 1]);
    }
    
    if ((strcmp(argv[1], "largest")) == 0)
    {
        Largest_Float(num_list, arg_count);
    }
    else if (strcmp(argv[1], "smallest") == 0)
    {
        Smallest_Float(num_list, arg_count);
    }

    return (0);
}


/* FUNCTIONS */
float Largest_Float(float *num_list, int arg_count)
{
    /* Variables */
    float biggest;

    /* CODE */
    biggest = 0;  /* starts at 0 for base comparison to numbers in array */
    for(unsigned int i = 1; i < arg_count; i++)
    {
        if(biggest < num_list[i])  /* if number is larger than previous biggest, will replace */
        {
            biggest = num_list[i];
        }
    }
    printf("%.2f\n", biggest);
    return 0;
}


float Smallest_Float(float *num_list, int arg_count)
{
    /* VARIABLES */
    float smallest;

    /* CODE */
    smallest = num_list[1];  /* starts at first number in array */
    for(unsigned int i = 2; i < arg_count; i++)
    {
        if(num_list[i] < smallest)  /* if number is smaller than previous smallest, will replace */
        {
            smallest = num_list[i];
        }
    }
    printf("%.2f\n", smallest);
    return 0;
}
