/*
 Name: ex1-hailstones.c
 Author: Jade Hudson
 Date: 6/10/2022

 Description: Accepts a single command line arguement and prints the 
              numbers in the hailstones sequence starting at that point
              and continues until the sequence reaches 1.
Returns: Array of Integers
Plan:
- Will take in number and pass through Hailstone function
- Hailstone function will then start from number
- if number is even, number will be divided by 2
- if odd, number will be multiplied by 3 (then +1)
- this will continue until 1 is reached at which time it will exit the while loop
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

/* Function Prototypes */
/* Function takes number and prints out numbers from there till 1 of the hailstone sequence */
int Hailstone(int number);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int number;
    number = atoi(argv[1]);  /* converts command line ints into actual ints */


    /* MAIN CODE */ 
    Hailstone(number);
    return (0);
}



/* FUNCTIONS */
int Hailstone(int number)
{
    while (number != 1)
    {
        printf("%d ", number);  /* Prints out original number for beginning of sequence */
        if (number % 2 == 0)
        {
            number = number / 2;
        }
        else if (number % 2 != 0)
        {
            number = (number * 3) + 1;
        }
    }
    printf("%d\n", number);  /* prints out 1 as ending number */
    return 0;
}
