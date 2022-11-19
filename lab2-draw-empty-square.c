/*
 name: lab2-draw-empty-squares.c
 author: Jade Hudson
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: Main
   Parameters: None
   Description: Takes an argument as width and draws a square of "*"
   Returns: Square of "*"s
*/

int main(int argc, char *argv[])
{
    /* Variables */
    int width;
    
    /* Command line codes */
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }
    width = atoi(argv[1]);

    /* Shape code */
    for(int num = 0; num < width; ++num)
        printf("*");
	printf("\n");

	for(int i = 1; i < width - 1; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if((j == 0) || (j == width - 1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for(int num = 0; num < width; ++num)
		printf("*");
	printf("\n");

    return (0);
}
