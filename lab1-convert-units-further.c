/*
 convert-units-further.c
 author Jade Hudson
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/


/* Function: Main
 parameters: 30-50
description:  Takes within 30-50 and computes into inches of all inbetween
 */

int main(int argc, char *argv[])
{
/* variable initialisation */

    int amount_centimetres_lower = 30;
    int amount_centimetres_higher = 50;


    while(amount_centimetres_lower <= amount_centimetres_higher)
    {
        printf ("%.2f\n", amount_centimetres_lower/2.54); /* centimetres multiplied by 2.54 to get in inches */
        amount_centimetres_lower++;
    }

	
    return (0); /* exit correctly*/
} /* end program*/