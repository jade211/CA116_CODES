/*
 Name: ex1-happy-number.c
 Author: Jade Hudson
 Date: 6/10/2022

Description: Takes command line number and sums the squares of its digits to decide if it is happy or not.
Returns: String (happy, not happy)

Plan:
- Will take in integer and grab each digit in integer (by modulo(%) by 10)
- will take the square of each digit and add together.
- will then repeat on resulting sum until 1 (or not 1) is reacheed using recursion
- if 1 is reached = happy, if another number is last reached = not happy
*/


/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function takes number and runs it through digit segmentation, squaring and summing */
int Happy_Num(int num);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE - Makes sure an input is always given, returns invalid if no input is given*/
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int number = atoi(argv[1]); /* number to be analysed */
    int recursive_result = number;
    
    /* MAIN CODE */ 
    while (recursive_result != 1 && recursive_result != 4)  /* will leave loop if equal to 1 (happy) or 4 (not happy) */
    {
        recursive_result = Happy_Num(recursive_result);  /* will continue running resulting sums of the squared digits until 1 (or timeout) */
    }


    if (recursive_result == 1)
    {
        printf("is happy\n");
    }
    else
    {
        printf("not happy\n");
    }
    return (0);
}


/* FUNCTIONS */
int Happy_Num(int number)
{
    /* VARIABLES */
    int total_sum = 0;
    int num_mod = 0;


    /* Main Code */
    while(number > 0)  /* will continue to iterate through number until all digits are segmented */
    {
        total_sum = total_sum  + ((number % 10) * (number % 10));  /* adds squared digit to total */
        number = number / 10; /* gets next digit in number */
    }
    return total_sum;
}
