/*
 Name: lab9-second-largest.c
 Author: Jade Hudson
 Date: 12/11/2022

 Description: Program takes in a list of floating numbers and finds the second largest value and prints to 1 decimal place.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function Second_Largest accepts a float array and organises them from smallest to largest, printing out the second largest number. */
void Second_Largest(float *num_list, int *arg_count);

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
    float *pNumlist = calloc(arg_count, sizeof(float));
    if(!pNumlist)
    {
        printf("Not enough memory!");
        exit(0);
    }

    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)
    {
        pNumlist[i] = atof(argv[i + 1]);
    }

    Second_Largest(pNumlist, &arg_count);
    free(pNumlist);
    pNumlist = NULL;

    return (0);
}


/* FUNCTIONS */
void Second_Largest(float *num_list, int *arg_count)
{
    /* VARIABLES */
    int position;
    int swap;
    int count = 1;

    /* CODE */
    for (unsigned int i = 0; i < *arg_count; i++)
    {
      position = i;
      for (unsigned int j = i + 1; j < *arg_count; j++)
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
   while (num_list[*arg_count - 1] == num_list[*arg_count - count])
   {
    count = count + 1;
   }
   printf("%.1f\n", num_list[*arg_count - count]);
}
