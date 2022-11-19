/*
 Name: lab10-integer-singly-linked-list.c
 Author: Jade Hudson
 Date: 18/11/2022

 Description: Program accepts integers from command line - the first being how many integers to expect, the following being the group of integers.
 The program will then store these integers in a linked list and print them out.
 Returns: ints
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

typedef struct Numbers Numbers;
struct Numbers
{
    int num;
    Numbers *next;
};

/* Function Prototypes */
/* Linked_List creates a linked list of all integers accepted from command line. */
/* Print_Linked_List prints out the integers coming from the linked list function. */
Numbers* Linked_List(char *argv[], int *int_amount);
void Print_Linked_List(Numbers *start);

/* Main function */
int main(int argc, char *argv[])
{
    /* COMMAND LINE CODE */
    if (argc < 2)  /* ensures command line input is given */
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int int_amount = atoi(argv[1]);
    Numbers *start = NULL;
    start = Linked_List(argv, &int_amount);
    Print_Linked_List(start);
    return (0);
}

/* FUNCTIONS */
Numbers* Linked_List(char *argv[], int *int_amount)
{
    Numbers *current;
    Numbers *first;
    first = (Numbers*)calloc(1, sizeof(Numbers));
    current = first;

    for(unsigned int i = 0; i < *int_amount / *int_amount; i+=1)
    {
        current->num = atoi(argv[i + 2]);
        // printf("%d\n", current->num);
    }

    for(unsigned int i = 0; i < *int_amount - 1; i++)
    {
        current->next = (Numbers*)calloc(1, sizeof(Numbers));
        current = current->next;
        current->num = atoi(argv[i + 3]);
    }
    return first;
}

void Print_Linked_List(Numbers *start)
{
    Numbers* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->num);
    }
}
