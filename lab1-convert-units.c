/*
 convert-units.c
 author Jade Hudson
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/


/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes intand converts to inches
 */

int main(int argc, char *argv[])
{
/* variable initialisation */
    int amount_centimetres = 0;
    float result = 0;

/* all command-line arguments come in as character strings, so atoi turns them into ints*/
	amount_centimetres = atoi(argv[1]);

	result = amount_centimetres/2.54; /* centimetres multiplied by 2.54 to get in inches */

	

    /* print to two decimal places*/
    printf ("%.2f\n",result); /* We only want to show only two values to the right of the decimal point*/

    return (0); /* exit correctly*/
} /* end program*/