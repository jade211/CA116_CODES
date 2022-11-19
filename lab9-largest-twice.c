/*
 Name: lab9-largest-twice.c
 Author: Jade Hudson
 Date: 12/11/2022

 Description: Program takes in a list of numbers prints the first largest element that is at least twice as large as at least one number in the array
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>


/* Function Prototypes */
/* Function Largest_Twice iterates through the array passes to Max_Num a new array of all numbers at least twice as large as at least one other array number (or prints 0 if none) */
/* Function Max_Num prints out largest number in twice_array. */
void Largest_Twice(int *num_list, int *arg_count);
void Max_Num(int *twice_array, int *count);

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
    int *pNumlist = calloc(arg_count, sizeof(int));
    if(!pNumlist)
    {
        printf("Not enough memory!");
        exit(0);
    }

    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)
    {
        pNumlist[i] = atoi(argv[i + 1]);
    }

    Largest_Twice(pNumlist, &arg_count);
    free(pNumlist);
    pNumlist = NULL;

    return (0);
}


/* FUNCTIONS */
void Largest_Twice(int *num_list, int *arg_count)
{
    /* VARIABLES */
    int *pDoubles_array = calloc(*arg_count, sizeof(int));
    if(!pDoubles_array)
    {
        printf("Not enough memory!");
        exit(0);
    }
    int twice_array[*arg_count];
    int count = 0;


    /* CODE */
    for (unsigned int i = 0; i < *arg_count; i++)
    {
        pDoubles_array[i] = num_list[i] * 2;
    }

    for (unsigned int i = 0; i < *arg_count; ++i)
    {
        for (unsigned int j = 0; j < *arg_count; ++j)
        {
            if (num_list[i] >= pDoubles_array[j])
            {
                twice_array[count] = num_list[i];
                count = count + 1;
            }
        }
    }

    if (count > 0)
    {
        Max_Num(twice_array, &count);
    }
    else
    {
        printf("%d\n", 0);
    }
    free(pDoubles_array);
    pDoubles_array = NULL;
}

void Max_Num(int *twice_array, int *count)
{
    /* VARIABLES */
    int biggest;
    
    /* CODE*/
    biggest = twice_array[0];
    for(unsigned int i = 0; i < *count; i++)
    {
        if(biggest < twice_array[i])
        {
            biggest = twice_array[i];
        }
    }
    printf("%d\n", biggest);

}
