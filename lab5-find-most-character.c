/*
 Name: lab5-find-most-character.c
 Author: Jade Hudson
 Date: 14/10/2022

 Description: The program find the character which has the most number of appearances in the string and prints the character out.
 Returns: char
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function takes word and length of word and returns the most occuring character in the word. */
char most_char(char *word, int *plength);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    char *word = argv[1];
    int length = strlen(argv[1]);

    /* MAIN CODE */ 
    most_char(word, &length);
    return (0);
}



/* FUNCTIONS */
char most_char(char *word, int *plength)
{
    int freq[*plength];
    char max = 0;
    char most_occuring;

    /* CODE */
    for (unsigned int i = 0; i < *plength; i++)
    {
        freq[i] = 1;
        for (unsigned int j = i + 1; j < *plength; j++)
        {
            if (word[i] == word[j] && word[i] != '0' && word[i] != ' ')
            {
                freq[i]++;
                word[j] = '0';  /* set back to 0 so it can iterate along with i */
            }
        }
    }

    for (int i = 0; i < *plength; i++)
    {
        if(max < freq[i]) 
        {  
            max = freq[i]; 
            most_occuring = word[i]; 
        }
    }
    
    // printf("%c: %d\n", most_occuring, max);
    printf("%c\n", most_occuring);
    return 0;
}
