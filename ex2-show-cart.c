/*
 Name: ex2-show-cart.c
 Author: Jade Hudson
 Date: 3/11/2022

 Description: This program, given command line input of an item, amount, price and promotion will return all entered item info and whether the item is on sale or not.
 Returns: String of items and given info

 Plan:
- I will first create a Struct with all necessary info names added ie: item, price, amount, promotion.
- I will then create an empty instance of the Struct and send this instance to the Struct_Function to get filled with command line values.
- After the values have been added and the instance is made, I will send it to the Print_Function and return the item and all given info.
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cart Cart; 
struct Cart
{
    char item[20];
    unsigned int amount;
    float price;
    char promotion[20];
};

/* Function Prototypes */
/* Struct_Function takes in empty instance of Cart struct and fills with command line values. */
/* Print_Function takes in filled Cart instance and prints out item and info. */
void Struct_Function(Cart cart[], int *ptr_arg_count, char *argv[]);
void Print_Function(Cart cart[], int *ptr_arg_count);


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
    Cart cart[100];  /* Empty instance of Cart initialised to be sent to Struct_Function. */
    int arg_count = argc - 1;

    /* MAIN CODE*/
    Struct_Function(cart, &arg_count, argv);  /* Empty instance of cart, pointer to length of usable arguements and command line arguements sent to Struct_Function. */
    Print_Function(cart, &arg_count);  /* Resulting, filled up instance of Cart sent to Print_Function to return info on items. */

    return 0;
}


/* FUNCTIONS */
void Struct_Function(Cart cart[], int *ptr_arg_count, char*argv[])
{
    /* VARIABLES */
    int v = 0;  /* Acts as iterator to add each info to correct item information place, ie: All info for item 1 gets added to cart[1], item[2] info gets added to cart[2], etc*/
    
    /* MAIN CODE */
    for(unsigned int i = 1; i < *ptr_arg_count; i+=4)  /* Iterates through info given on items (goes by i+=4 each time as every 4 arguements are members of the same instance). */
    {
        strcpy(cart[v].item, argv[i]);  /* Using strcpy because it is a string command line input*/
        cart[v].amount = atoi(argv[i + 1]);
        cart[v].price = atof(argv[i + 2]);
        if (atoi(argv[i + 3]) == 1)  /* If the number given is 1, the item is on sale, else (if it is 0), it is not on sale. */
        {
            strcpy(cart[v].promotion, "On Sale");
        }
        else
        {
            strcpy(cart[v].promotion, "No Sale");
        }
        v++;
    }
}


void Print_Function(Cart cart[], int *ptr_arg_count)
{
    /* MAIN CODE */
    for (unsigned int i = 0; i < *ptr_arg_count / 4; i++)
    {
        printf("%s,%d,%.2f,%s\n", cart[i].item, cart[i].amount, cart[i].price, cart[i].promotion);  /* Prints info out on each item line by line. */
    }
}
