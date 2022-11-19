/*
 Name: lab10-float-doubly-linked-list.c
 Author: Jade Hudson
 Date: 18/11/2022

 Description: Program accepts floats from command line - the first being how many floats to expect, the following being the group of floats.
 The program will then store these floats in a double linked list and print them out in reverse order.
 Returns: floats
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>

typedef struct Numbers Numbers;
struct Numbers
{
    float num;
    Numbers *next;
    Numbers *prev;
};

/* Function Prototypes */
/* Linked_List creates a linked list of all floats accepted from command line (and returns the last node). */
/* Print_Rev_Linked_List prints out the floats coming from the linked list function in reverse (starting with last node). */
Numbers* Linked_List(char *argv[], int *int_amount);
void Print_Rev_Linked_List(Numbers *start);

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
    Print_Rev_Linked_List(start);
    return (0);
}

/* FUNCTIONS */
Numbers* Linked_List(char *argv[], int *int_amount)
{
    Numbers *current;
    Numbers *first;
    Numbers *prev;
    first = (Numbers*)calloc(1, sizeof(Numbers));
    current = first;

    for(unsigned int i = 0; i < *int_amount / *int_amount; i+=1)
    {
        current->num = atof(argv[i + 2]);
        current->prev = NULL;
        // printf("%d\n", current->num);
    }

    for(unsigned int i = 0; i < *int_amount - 1; i++)
    {
        current->next = (Numbers*)calloc(1, sizeof(Numbers));
        prev = current;
        current = current->next;
        current->num = atof(argv[i + 3]);
        current->prev = prev;
    }
    current->next = NULL;
    return current; // returns last node (instead of first)
}

void Print_Rev_Linked_List(Numbers *start)
{
    Numbers* p = NULL;
    for(p = start; p != NULL; p = p->prev)  // using p->prev to get previous nodes to give reverse order (instead of the normal p->next)
    {
        printf("%.2f\n", p->num);
    }
}
