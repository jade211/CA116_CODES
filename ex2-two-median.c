/*
 Name: ex2-two-median.c
 Author: Jade Hudson
 Date: 3/11/2022

 Description: Accepts an even numbered array of integers as input and calulates the median.
 Returns: Two Ints

 Plan:
 - I will take in the input and create a usable array called num_list.
 - I will then send this array to the Numeric_Sort function to sort the numbers in order.
 - I will then send the sorted array to the Median_Calc function where it will divide the array length by 2 and print the 2 values in the middle of the array.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function Numeric_Sort will sort the array in numerical order (smallest to biggest). Median_Calc will return the two values found in the middle of the array */
void Numeric_Sort(int *num_list, int *ptr_arg_count);
int Median_Calc(int *num_list, int *ptr_arg_count);


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
    int arg_count = argc - 1;  /* Gives amount of numbers in array (minus code title) */
    int *ptr_arg_count = NULL;
    ptr_arg_count = &arg_count;  /* Initialises pointer towards arg_count address. */
    int num_list[arg_count];  /* num_list is as big as number of command line arguements */


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)  /* adds all numbers to a usable array for functions */
    {
        num_list[i] = atoi(argv[i + 1]);
    }
    Numeric_Sort(num_list, ptr_arg_count);  /* Sending new num_list array and pointer to arg_count to Numeric_Sort function to get sorted */
    return 0;
}


/* FUNCTIONS */
void Numeric_Sort(int *num_list, int *ptr_arg_count)
{
    /* VARIABLES */
    int position;
    int swap;

    /* MAIN CODE */
    for (unsigned int i = 0; i < *ptr_arg_count; i++)
    {
      position = i;
      for (unsigned int j = i + 1; j < *ptr_arg_count; j++)
      {
         if (num_list[position] > num_list[j])  /* Takes number at position [i] and compares it to number at position [j] (which is the number next to it).*/
         {
            position = j;  /* If the number at position [i] is bigger, position increases to [j] and number is left in place*/
         }
      }
      if (position != i)
      {
        swap = num_list[i];  /* If the number is less than one at position [j], the two numbers swap positions. */
        num_list[i] = num_list[position];
        num_list[position] = swap;
      }
    }
    Median_Calc(num_list, ptr_arg_count);  /* New sorted array is then sent to Median_Calc to get the middle values. */
}


int Median_Calc(int *num_list, int *ptr_arg_count)
{
    /* VARIABLES */
    int median = *ptr_arg_count / 2;  /* Halves the array size to find the middle values and prints. */

    /* MAIN CODE */
    printf("%d\n", num_list[median - 1]);
    printf("%d\n", num_list[median]);
    return 0;
}