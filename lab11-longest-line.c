/*
 Name: lab11.longest-line.c
 Author: Jade Hudson
 Date: 26/11/2022

 Description: Program reads input from a text file and prints out the length of the longest line and the contents of the line.
 Returns: int and string
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function Longest_Line reads paragraph.txt file and returns the longest lines size and the contents of the longest line. */
void Longest_Line(FILE *pfile);


/* Main function */
int main(int argc, char *argv[])
{

    /* VARIABLES */
    FILE *pfile = NULL;
    char *filename = "paragraph.txt";

    /* CODE */
    pfile = fopen(filename, "r");
    if(!pfile)
    {
        printf("Failed to open %s.\n,", filename);
    }
    Longest_Line(pfile);
    fclose(pfile);
    return 0;
}

/* FUNCTIONS */
void Longest_Line(FILE *pfile)
{
    /* VARIABLES */
    int largest_sentence_length = 0;
    char largest_sentence[200];
    char line[200];

    /* CODE */
    while(fgets(line, sizeof(line), pfile) != NULL)
    {
        for(int i = 0; i < strlen(line); i++)
        {
            if(strlen(line) > largest_sentence_length)
            {
                largest_sentence_length = strlen(line);
                strcpy(largest_sentence, line);
            }
        }
    }
    printf("%d\n", largest_sentence_length);
    printf("%s\n", largest_sentence);
}
