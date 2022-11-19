/*
 name: lab2-find-even-numbers.c
 author: Jade Hudson
*/

#include <stdio.h>
#include <stdlib.h>

/* Function: Main
   Parameters: None
   Description: Finds all even elements in an array of integers.
   Returns: Int
*/

int main(int argc, char *argv[])
{
    /* Variables */
    int length = argc - 1;
    int nums_lst[length];
    int no_evens = 0;
    
    /* Command line codes */
    if (argc == 1)
    {
        printf("No input given!\n");
        return 1;
    }
    for(unsigned int i = 0; i < length; ++i)
        nums_lst[i] = atoi(argv[i + 1]);
    
    /* code */
    for(int j = 0; j < argc - 1; ++j)
        if (nums_lst[j] % 2 == 0)
        {
            no_evens = no_evens + 1;
            printf("%d - %d\n", j, nums_lst[j]);
        }

    if (no_evens == 0)
    {
        printf("Not found!\n");
    }

    return (0);
}
