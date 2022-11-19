/*
 Name: ex1-is-symmetric.c
 Author: Jade Hudson
 Date: 6/10/2022

Description: This program checks if the input string is symmetric and 
             prints yes if they are, or otherwise will print no.
Returns: String (yes or no)

Plan:
- Will read in input and compare characters from front 
  of string to characters from back of string 
- example: See if char[first] == char[last], 
  char[second] == char[second_last] etc.
- I will then comfirm if they are symmetrical by 
  comparing the amount of characters that are symmetrical 
  with the total len of the string.
- If they are equal, string is symmetrical
*/


/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function operates by reading input from front and back at the same time and compares each char from front to back */
char Symmetric_String(char *word, int arg_count);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE - Makes sure an input is always given, returns invalid if no input is given*/
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }


    /* VARIABLES */
    int arg_count = strlen(argv[1]); /* length of word to be analysed*/
    

    /* MAIN CODE */ 
    Symmetric_String(argv[1], arg_count);
    return (0);
}



/* FUNCTIONS */
char Symmetric_String(char *word, int arg_count)
{
    /* VARIABLES */
    int count = 0;  /* Used to count how many of the letters ended up being matching. If it is equal to the entire len, it is symmetric.*/
    int i = 1;  /* starting from 1 to avoid the /0 */

    /* Main Code */
    while (word[i] == word[arg_count - (i + 1)])  /* iterates through word comparing front elements to back elements */
    {
        count = count + 1;
        ++i;
    }

    if (count == arg_count)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
