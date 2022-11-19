/*
 Name: lab3-is-sorted.c
 Author: Jade Hudson
 Date: 1/10/2022

 Description: The program sorts a command line array in ascending order and prints them out line by line.
 Returns: Integers in ascending order
*/

#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function finds the max number in array.*/
int Selection_Sort(int *num_list, int arg_count);


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

    Selection_Sort(num_list, arg_count);

    return (0);
}


/* FUNCTIONS */
int Selection_Sort(int *num_list, int arg_count)
{
    /* VARIABLES */
    int position;
    int swap;

    /* CODE */
    for (unsigned int i = 0; i < arg_count; i++)
    {
      position = i;
      for (unsigned int j = i + 1; j < arg_count; j++)
      {
         if (num_list[position] > num_list[j])
         {
            position = j;
         }
      }
      if (position != i)
      {
        swap = num_list[i];
        num_list[i] = num_list[position];
        num_list[position] = swap;
      }
    }
    
   for (unsigned int i = 0; i < arg_count; i++)
   {
      printf("%d\n", num_list[i]);
   }
}
