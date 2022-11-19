/*
 Name: lab10-push-pop.c
 Author: Jade Hudson
 Date: 18/11/2022

 Description: Program accepts integers from command line - the first being how many integers to expect, the following being the group of integers.
 The program will then store these integers in a linked list and pop out the last two elements and add (push) two new elements.
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
    Numbers *prev;
};

/* Function Prototypes */
/* Linked_List creates a linked list of all integers accepted from command line. */
/* Pop() pops out the last element added to the linked list (using next == NULL) */
/* Add() adds the two variables from command line to the end of the linked list. */
/* Print_Linked_List prints out the integers coming from the linked list function. */
Numbers* Linked_List(char *argv[], int *int_amount);
void Pop(Numbers *first);
Numbers* Add(Numbers *start, int add1, int add2);
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
    Pop(start);
    Pop(start);
    Add(start, atoi(argv[argc - 2]), atoi(argv[argc - 1]));
    Print_Linked_List(start);
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
        current->num = atoi(argv[i + 2]);
        current->prev = NULL;
        // printf("%d\n", current->num);
    }

    for(unsigned int i = 0; i < *int_amount - 1; i++)
    {
        current->next = (Numbers*)calloc(1, sizeof(Numbers));
        prev = current;
        current = current->next;
        current->num = atoi(argv[i + 3]);
        current->prev = prev;
    }
    current->next = NULL;
    // Pop(current);
    return first;
}





void Pop(Numbers *first)
{
	Numbers* p = first;
    Numbers *temp = NULL;

	for(p = first; p != NULL; p = p->next)
	{
        if(p->next->next == NULL)
        {
            p->next = NULL;
        }

	}

}

Numbers* Add(Numbers *start, int add1, int add2)
{
    Numbers *current;
    Numbers *first;
    // Numbers *prev;
    first = start;
    current = first;

	for(current = first; current != NULL; current = current->next)
	{
        if(current->next == NULL)
        {
            current->next = (Numbers*)calloc(1, sizeof(Numbers));
            // prev = current;
            current = current->next;
            current->num = add1;
            // current->prev = prev;
            
            current->next = (Numbers*)calloc(1, sizeof(Numbers));
            // prev = current;
            current = current->next;
            current->num = add2;
            // current->prev = prev;
            break;
        }

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
