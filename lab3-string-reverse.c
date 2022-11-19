/*
 Name: lab3-string-reverse.c
 Author: Jade Hudson
 Date: 1/10/2022

 Description: Reverses the given string.
 Returns: String
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* Function Prototypes */
/* To reverse the given string from command line.*/
char Reverse_String(char *sentence);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }

    /* MAIN CODE */ 
	// strcpy(sentence, argv[1]);

    Reverse_String(argv[1]);

    return (0);
}


/* FUNCTIONS */
char Reverse_String(char *sentence)  /* star needed when passing array.str to function */
{
    int i;
    int j;
    int position = 0;
    char reverse[100];

    while (sentence[position] != '\0')  /* iterates over every char in string */
    {
        position++;
    }
    j = position - 1;  /* exits while loop once '\0' is found, j is position of last char */

    for (i = 0; i < position; i++)
    {
        reverse[i] = sentence[j];
        --j; /* decrements */
    }
    printf("%s\n", reverse);

    // strrev(sentence);

}
