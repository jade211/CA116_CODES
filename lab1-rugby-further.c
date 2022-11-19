/*
 rugby-further.c
 author Jade Hudson
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/


/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description: Computes total score by adding trys, conversions, penaltys and drop_goals
 */

int main(int argc, char *argv[])
{
/* variable initialisation */
    /* int try;
    int conversion;
    int penalty;
    int drop_goal;
    int total = 0; */
    int try, conversion, penalty, drop_goal;
    int total = 0;

    /*printf("Enter your numbers: Try, Conversion, Penalty, Drop_goal)\n");
    scanf("%i %i %i %i", &try, &conversion, &penalty, &drop_goal); */
    
    printf("Enter your Try number:\n");
    scanf("%i", &try);

    printf("Enter your Conversion number:\n");
    scanf("%i",&conversion);

    printf("Enter your Penalty number:\n");
    scanf("%i", &penalty);

    printf("Enter your Drop_goal number:\n");
    scanf("%i", &drop_goal);

	if (try >= 0 && conversion >= 0 && penalty >= 0 && drop_goal >= 0)
    {
        total = (try*5)+(conversion*2)+(penalty*3)+(drop_goal*3); /* centimetres multiplied by 2.54 to get in inches */
        printf ("%.d\n", total);
    }
    else
    {
        printf("Invalid numbers entered\n");
    }

    return (0); /* exit correctly*/
} /* end program*/