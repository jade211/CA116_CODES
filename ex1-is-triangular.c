/*
 Name: ex1-is-triangular.c
 Author: Jade Hudson
 Date: 6/10/2022

Description: Takes one integer from command line and determines whether it is a triangular number
Returns: String

Plan:
- Will take in integer and compare 2 * integer to triangle formula
  Formula: (i * (i + 1)
- If it is equal to any of the iterations, it will confirm that it is a triangle number
- If it does not, it will confirm that it is not a triangle number.
*/


/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function takes number and runs it through (n * n+1) formula to see if it is in the triangle sequence */
char Triangle_Verifier(int num);


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
    
    /* MAIN CODE */ 
    Triangle_Verifier(number);
    return (0);
}


/* FUNCTIONS */
char Triangle_Verifier(int number)
{
    /* VARIABLES */
    int i = 1;

    /* Main Code */
    for (i; i <= number; i++)
    {
      if (i * (i + 1) == 2 * number)  /* formula simulates how sequence is calculated eg; 1 * 1+1 = 3 (first triangle), 2 * 2+1 = 6 second triangle number, etc */
      {
        return printf("%d is a triangular number\n", number);
      }
    }
    return printf("%d is not a triangular number\n", number);
}
