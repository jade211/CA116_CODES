/*
 rugby.c
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
    int try = 0;
    int conversion = 0;
    int penalty = 0;
    int drop_goal = 0;
    int total = 0;

/* all command-line arguments come in as character strings, so atoi turns them into ints*/
	try = (atoi(argv[1]))*5;
    conversion = (atoi(argv[2]))*2;
    penalty = (atoi(argv[3]))*3;
    drop_goal = (atoi(argv[4]))*3;

	total = try+conversion+penalty+drop_goal; /* centimetres multiplied by 2.54 to get in inches */

	

    printf ("%.d\n",total);

    return (0); /* exit correctly*/
} /* end program*/