/*
 name: lab2-cylinder-area.c
 author: Jade Hudson
 */


#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

/* Function: Main
   Parameters: none
   Description: Gets radius and height from the command line and computes the area of a cylinder
   Returns: int
*/

int main(int argc, char *argv[])
{
    /* Variables */
    int radius;
    int height;
    float area = 0.0f;
    
    /* Command line error fix*/
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }
    else if (argc == 2)
    {
        printf("Two arguments needed!\n");
        return 1;
    }

    /* Normal command line reading */
    radius = atoi(argv[1]);
    height = atoi(argv[2]);

    /* Area */
    if ((radius < 0 && height < 0) || (radius < 0 && height > 0) || (radius > 0 && height < 0))
    {
        printf("The radius or height cannot be negative!\n");
    }
    else
    {
        area = (height * (2 * PI * radius)) + (2 * PI * (radius * radius));
        printf ("%.2f\n", area);
    }

    return (0);
}
