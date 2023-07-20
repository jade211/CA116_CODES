/*
 Name: lab11-bin-2-dec.c
 Author: Jade Hudson
 Date: 26/10/2022

 Description: Takes binary input from command line and outputs decimal equivalent (or error message).
 Returns: Integer
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


/* Function Prototypes */
/* Function Binary_To_Decimal converts binary number to decimal.*/
void Binary_To_Decimal(int num, int *binary_count, int *total, int i);


/* Main function */
int main(int argc, char *argv[])
{

    /* COMMAND LINE CODE */
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }

    /* VARIABLES */
    int binary_count = argc - 1;
    char num_list[100];
    int total = 0;

    /* MAIN CODE */ 
    if((binary_count <= 8))
    {
        for(unsigned int i = 0; i < argc - 1; ++i)
        {
            num_list[i] = atoi(argv[i + 1]);
            if(strcmp(argv[1 + i], "1") == 0 || strcmp(argv[i + 1], "0") == 0)
            {
                // printf("%d\n", num_list[i]);
                Binary_To_Decimal(num_list[i], &binary_count, &total, i);
                binary_count = binary_count - 1;
            }
            else
            {
                printf("Only digits 1 and 0 are permitted.\n");
                return 0;
            }
        }
    }
    else
    {
        printf("Too many binary digits entered.\n");
        return 0;
    }
    printf("%d\n", total);
    return (0);

}

/* FUNCTIONS */
void Binary_To_Decimal(int num, int *binary_count, int *total, int i)
{
    int calc_num = *binary_count - 1;
    if(num != 0)
    {
        num = pow((num + 1), calc_num);
        *total = *total + num;
    }

}
