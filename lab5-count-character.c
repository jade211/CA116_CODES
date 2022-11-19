/*
 Name: lab5-count-character.c
 Author: Jade Hudson
 Date: 14/10/2022

 Description: This program counts the number of occurences of the character in the string and prints the result. If the character does not exist in the string, prints 0.
 Returns: Int
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function takes word, char and length of word and returns the number of times char has occured. */
int count_char(char *charac, char *word);


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
    char *charac = argv[1];
    char *word = argv[2];

    /* MAIN CODE */ 
    count_char(charac, word);
    return (0);
}



/* FUNCTIONS */
int count_char(char *charac, char *word)
{
    char *pword = word;  /* initialises pointer to word*/
    int counter = 0;

    while(pword = strchr(pword, *charac))  /* strchr() checks if char in word*/
    {
        counter = counter + 1;
        pword = pword + 1;
    }
    
    printf("%d\n", counter);
    return 0;

}
