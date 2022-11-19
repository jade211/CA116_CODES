/*
 Name: lab10-inside-the-queue.c
 Author: Jade Hudson
 Date: 19/11/2022

 Description: Program accepts 2 integers from command line - the first being a number in the given array, the following being the number we want 
 to add into the linked list at the position after that number. The program will then add this number in at said position and print out the resulting array.
 Returns: Integer array.
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
/* Linked_List creates a linked list of all floats accepted from command line. */
/* Add_At_Position finds the position of the first argv number in the array and inserts the second argv in after it. */
/* Print_Linked_List prints out the floats coming from the linked list function. */
Numbers* Linked_List(int linked_list_nums[], int *int_amount);
Numbers* Add_At_Position(Numbers *start, int num_before, int added_num);
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
    int int_amount = 10;
    int linked_list_nums[11] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    Numbers *start = NULL;
    start = Linked_List(linked_list_nums, &int_amount);
    Add_At_Position(start, atoi(argv[1]), atoi(argv[2]));
    Print_Linked_List(start);
    return (0);
}

/* FUNCTIONS */
Numbers* Linked_List(int linked_list_nums[], int *int_amount)
{
    Numbers *current;
    Numbers *first;
    Numbers *prev;
    first = (Numbers*)calloc(1, sizeof(Numbers));
    current = first;

    for(unsigned int i = 0; i < *int_amount / *int_amount; i+=1)
    {
        current->num = linked_list_nums[i];
        current->prev = NULL;
        // printf("%d\n", current->num);
    }

    for(unsigned int i = 0; i < *int_amount - 1; i++)
    {
        current->next = (Numbers*)calloc(1, sizeof(Numbers));
        prev = current;
        current = current->next;
        current->num = linked_list_nums[i + 1];
        current->prev = prev;
    }
    current->next = NULL;
    return first;
}

Numbers* Add_At_Position(Numbers *start, int num_before, int added_num)
{
    Numbers *current;
    Numbers *first;
    first = start;
    current = first;

	for(current = first; current != NULL; current = current->next)
	{
        if(current->num == num_before)
        {
            Numbers *temp = current->next;
            Numbers *new = (Numbers*)calloc(1, sizeof(Numbers));
            new->num = added_num;
            new->next = temp;
            current->next = new;
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
