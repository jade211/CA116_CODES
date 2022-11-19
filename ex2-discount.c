/*
 Name: ex2-discount.c
 Author: Jade Hudson
 Date: 3/11/2022

 Description: This program, given command line info on items and their 
 information, calculates the discounts offered on the items and 
 prints the FULL price the person needs to pay for the 
 entire shopping cart.
 Returns: Float of total sum

  Plan:
- I will first create a Struct with all necessary info names added ie: item, price, amount, promotion.
- I will then create an empty instance of the Struct and send this instance to the Struct_Function to get filled with command line values.
- I will then send these completed instance(s) to the Discount function to get calculated (depending on if the items are on sale or not) and print out the total sum of the shopping cart.
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
/* Discount_Function takes in completed cart and calcs the total price the person has to pay for all items in the cart (taking into account sale promotions) */
void Struct_Function(Cart cart[], int *ptr_arg_count, char *argv[]);
void Discount_Function(Cart cart[], int *ptr_arg_count);


/* MAIN FUNCTION */
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
    Discount_Function(cart, &arg_count);  /* Completed struct instances sent to Discount to be calculated. */

    return 0;
}


/* FUNCTIONS */
void Struct_Function(Cart cart[], int *ptr_arg_count, char*argv[])
{
    /* VARIABLES */
    int v = 0; /* Acts as iterator to add each info to correct item information place, ie: All info for item 1 gets added to cart[1], item[2] info gets added to cart[2], etc*/
    
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

void Discount_Function(Cart cart[], int *ptr_arg_count)
{
    /* VARIABLES */
    float sum = 0;  /* Value created to become total price of all items in cart added together*/

    /* MAIN CODE*/
    for (unsigned int i = 0; i < *ptr_arg_count / 4; i++)
    {
        if (strcmp(cart[i].promotion, "On Sale") == 0)  /* If the item is on sale, the price is calculated through this function. */
        {
            /* VARIABLES AND CODE */
            int deal_amount = cart[i].amount / 3;  /* Calcs how many groups of 3 (3 for price of 2 deal) are being bought. */
            int deal_amount_full_used = deal_amount * 3;  /* Multiplies it by 3 to get full number of how many products being bought are part of the deal */
            int mini_sum = deal_amount * (cart[i].price * 2);  /* Calcs the 3 for 2 total of all products in the deal that made it in groups of 3. */
            int unadded = cart[i].amount - deal_amount_full_used;  /* How many of the product being bought did not make it into a 3 for 2 deal (not enough product to make another group of 3 - excess product). */
            mini_sum = mini_sum + (unadded * cart[i].price);  /* Adds 3 for 2 products price to products not included in deals price. */
            sum = mini_sum + sum;  /* Adds full figure to outside sum vairable used to calc entire shopping cart. */
        }
        else
        {
            sum = sum + cart[i].amount * cart[i].price;  /* Products that are not on sale get their prices calculated here and added to sum. */
        }
    }
    printf("%.2f\n", sum);  /* Sum returns total cost of shopping cart as a float (sales and non-sales taken into consideration). */
}
