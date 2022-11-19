/*
 Name: lab3-find-longest-word.c
 Author: Jade Hudson
 Date: 2/10/2022

 Description: The program finds the longest word in the sentence and print them out
 Returns: String
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function finds the max number in array.*/
char Longest_Word(char *sentence, int length);


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
    int length = strlen(argv[1]);

    /* MAIN CODE */ 
    Longest_Word(argv[1], length);

    return (0);
}


/* FUNCTIONS */
char Longest_Word(char *sentence, int length)
{
    /* Variables */
    int i = 0, j;
    int iterator = 0;
    int position;
    int longest = 0;
    char largest_word[50];

    /* Gets position and length of word */
    for (i; i < length; i++)
    {
        if (sentence[i] != ' ')
        {
            iterator++;
        }
        else
        {
            if (iterator > longest)
            {
                longest = iterator;
                position = i - longest;
            }
        iterator = 0;
       }
    // printf("len %d word %d\n", longest, position);
    }
    
    
    /* Prints word out */
    if (iterator > longest)
    {
        longest = iterator;
        position = length - longest;
    }

    j = 0;
    for (i = position; i < position + longest; i++)
    {
        largest_word[j] = sentence[i];
        j++;
    }
    largest_word[j] = '\0';

    printf("%s\n", largest_word);
    return 0;
}
