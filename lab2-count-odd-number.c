/*
 name: lab2-count-odd-numbers.c
 author: Jade Hudson
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: Main
   Parameters: None
   Description: Counts the number of odd numbers in an array of integers
   Returns: Int
*/

int main(int argc, char *argv[])
{
    /* Variables */
    int length = argc - 1;
    int nums_lst[length];
    int num_odds = 0;
    
    /* Command line codes */
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }
    for(unsigned int i = 0; i < length; ++i)
        nums_lst[i] = atoi(argv[i + 1]);
    
    /* code */
    for(int j = 0; j < argc; ++j)
        if (nums_lst[j] % 2 == 1)
        {
            num_odds = num_odds + 1;
        }
    printf ("%d\n", num_odds);

    return (0);
}
