/*
 Name: lab9-longest-sentence.c
 Author: Jade Hudson
 Date: 13/11/2022

 Description: Program takes in a list of numbers prints the first largest element that is at least twice as large as at least one number in the array
 Returns: string(s)

*/


/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* Function Prototypes */
/* Function Longest prints out the longest words/ sentences found. */
void Longest(char **pWordlist, int *arg_count);

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
    int arg_count = argc - 1;
    char *word_array[arg_count];
    char **pWordlist = calloc(arg_count, sizeof(char*));
    if(!pWordlist)
    {
        printf("Not enough memory!");
        exit(0);
    }

    /* MAIN CODE */
    for(int i = 0; i< arg_count ;i++){
        word_array[i] = argv[i+1];
    }

    for(int i = 0 ; i < arg_count; i++)
    {
        int length = strlen(word_array[i]);
        pWordlist[i] = calloc(1, sizeof(char)*length);
        pWordlist[i] = word_array[i];
        // printf("%s\n", pWordlist[i]);
    }
    Longest(pWordlist, &arg_count);
    free(pWordlist);
    pWordlist = NULL;
 
    return (0);
}


/* FUNCTIONS*/
void Longest(char **pWordlist, int *arg_count)
{
    /* VARIABLES */
    int largest = strlen(pWordlist[0]);

    /* CODE */
    for (int i = 1; i < *arg_count; i++)
    {
        if (strlen(pWordlist[i]) >= largest)
        {
            largest = strlen(pWordlist[i]);
            // printf("%s\n", pWordlist[i]);
        }
    }

    for (int i = 0; i < *arg_count; i++)
    {
        if (strlen(pWordlist[i]) == largest)
        {
            printf("%s\n", pWordlist[i]);
        }
    }

}
