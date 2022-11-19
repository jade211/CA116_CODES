/*
 Name: ex1-odd-even-array.c
 Author: Jade Hudson
 Date: 6/10/2022

 Description: The program calculates the summary of the odd elements and subtract the 2nd, 3rd etc. even elements from the first even element. Print the sum and the difference line by line. You can assume the maximum number of elements is 50. If there is no odd or even elements in the array, the corresponding result is zero.
 Returns: Integer

 Plan:
- Take in array and put into both ODD and EVEN function
- Odd function: Will modulo(%) by 2 to get all numbers that do not give 0 (odds) and add them together
- Even Function: To get first number, will grab first number that gives 0 after being moduloed(%) by 2.
-  Will then take all evens after first and minus them.
- Print out both answers.
*/


/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function Odds finds odds in array and adds them*/
/* Function Evens finds evens in array and minuses them beginning at first even*/
int Odds(int *num_list, int arg_count);
int Evens(int *num_list, int arg_count);


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
    int arg_count = argc - 1;  /* minus 1 to disinclude question name */
    int num_list[arg_count];


    /* MAIN CODE */ 
    for(unsigned int i = 0; i < arg_count; ++i)  /* for loop creates a usable array of the integers for the funcion*/
    {
        num_list[i] = atoi(argv[i + 1]);
    }

    Odds(num_list, arg_count);
    Evens(num_list, arg_count);

    return (0);
}


/* FUNCTIONS */
int Odds(int *num_list, int arg_count)  /* finds odds by finding numbers that when moduloed do not give 0 */
{
    int total = 0;
    for (unsigned int i = 0; i < arg_count; i++)
    {
        if (num_list[i] % 2 != 0)
        {
            total = total + num_list[i]; /* adds them together */
        }
    }
printf("%d\n", total);
return 0;
}


int Evens(int *num_list, int arg_count)
{
    int i = 0;
    int first_even = 0;
    int result;
    while((num_list[i] % 2) != 0)  /* finds first even number in array to be used as number to be minused from */
    {
        i++;
    }
    first_even = num_list[i];


    int beginning_num = first_even;
    for (unsigned int i = 0; i < arg_count; i++)
    {
        if (num_list[i] % 2 == 0)  /* iterates through the rest of the evens and minuses them from first even */
        {
            beginning_num = beginning_num - num_list[i];
        }
    result = first_even + beginning_num;  /* adds first even back in as it was also included in the minusing */
    }
printf("%d\n", result);
return 0;
}
