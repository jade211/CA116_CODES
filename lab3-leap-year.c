/*
 Name: lab3-leap-year.c
 Author: Jade Hudson
 Date: 2/10/2022

 Description: Prints out all leap years between the first number and the second number inclusive.
 Returns: Years (Ints)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function finds years that are leap years from year start to year end.*/
int Leap_Year_Calc(int year_start, int year_end);


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
    int year_start = atoi(argv[1]);
    int year_end = atoi(argv[2]);

    /* MAIN CODE */ 
    Leap_Year_Calc(year_start, year_end);
    return (0);
}


/* FUNCTIONS */
int Leap_Year_Calc(int year_start, int year_end)
{
    int gap;
    int year_bw;
    gap = year_end - year_start;

    for (unsigned int i = 0; i <= gap; i++)
    {
        year_bw = year_start + i;
        if (year_bw % 400 == 0)
        {
            printf("%d\n", year_bw);
        }
        else if (year_bw % 4 == 0 && year_bw % 100 != 0)
        {
            printf("%d\n", year_bw);
        }
    }
    return 0;

}