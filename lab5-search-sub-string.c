/*
 Name: lab5-search-sub-string.c
 Author: Jade Hudson
 Date: 15/10/2022

 Description: This program takes two strings as input and checks if the first string contains the second string. If yes, it will print the positions of the first and last character of the second string in the first string.
 Returns: Integers
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Function Prototypes */
/* Function takes in 2 strings and returns position of first and last char of where substring is found in first string*/
int Substring(char *normal_string, char *sub_string);


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
    char *normal_string = argv[1];
    char *sub_string = argv[2];

    /* MAIN CODE */ 
    Substring(normal_string, sub_string);
    return (0);
}

/* FUNCTIONS */
int Substring(char *normal_string, char *sub_string)
{

  int start = 0;
  int length = strlen(sub_string);
  int end = 0;

  char *pSub_present = NULL;
  pSub_present = strstr(normal_string, sub_string);
  if (pSub_present)
  {
    start = (pSub_present - normal_string);
    // printf("%d\n", start);
    end = start + (length - 1);
    // printf("%d\n", end);
  }

  printf("%d %d\n", start, end);
  return 0;

}
