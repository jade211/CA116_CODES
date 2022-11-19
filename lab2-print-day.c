/*
 name: lab2-print-day.c
 author: Jade Hudson
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: Main
   Parameters: None
   Description: Takes a single Command-line Argument (an integer) and prints the name of the day of the week to which it corresponds.
   Returns: Int
*/

int main(int argc, char *argv[])
{
    /* Variables */
    int day;
    
    /* Command line codes */
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Too many integers given!\n");
        return 1;
    }

    day = atoi(argv[1]);

    /* Code */
    if (day == 1)
    {
        printf("Sunday\n");
    }
    else if (day == 2)
    {
        printf("Monday\n");
    }
    else if (day == 3)
    {
        printf("Tuesday\n");
    }
    else if (day == 4)
    {
        printf("Wednesday\n");
    }
    else if (day == 5)
    {
        printf("Thursday\n");
    }
    else if (day == 6)
    {
        printf("Friday\n");
    }
    else if (day == 7)
    {
        printf("Saturday\n");
    }
    else
    {
        printf("Integer does not correspond to any day of the week.\n");
    }

    return (0);
}
