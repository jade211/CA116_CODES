/*
Program: lab1-hello-again-further.c
Author: Jade Hudson
Input: A full name
Output: Print out the given name from keyboard
*/

/* includes */
#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main(int argc, char * argv[])
{
   char name[100];

   printf("Enter your name:\n");
   scanf("%s", name);
   printf("Hello %s\n", name);
   return(0);
}