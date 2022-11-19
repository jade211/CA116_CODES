/*
 Name: lab3-calculator.c
 Author: Jade Hudson
 Date: 30/09/2022

 Description: Calculates product or division of two floating numbers.
 Returns: Float
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* Function Prototypes */
/* To calculate whether to divide or multiply, 2 functions are needed.*/
float Calc_Divide(float number1, float number2);
float Calc_Multiply(float number1, float number2);

/* Main function */
int main(int argc, char *argv[])
{
    /* Variables */
    float number1;
    float number2;
    float result;
    
    /* Command line codes */
    if (argc == 1)
    {
        printf("invalid\n");
        return 1;
    }

    number1 = atof(argv[2]);
    number2 = atof(argv[3]);

    // if (number2 == 0)
    // {
    //     printf("invalid\n");
    //     return 1;
    // }

    /* Main Code */ 
    if (number2 != 0)
    {
        if ((strcmp(argv[1], "multiply")) == 0)
        {
            result = Calc_Multiply(number1, number2);
            printf("%f\n", result);
        }
        else if (strcmp(argv[1], "divide") == 0)
        {
            printf("%f\n", Calc_Divide(number1, number2));
        }
        else
        {
            printf("invalid\n");
        }
    }
    else
    {
        printf("invalid\n");
    }
    return (0);
}

/* functions */
float Calc_Multiply(float number1, float number2)
{
    return number1 * number2;
}

float Calc_Divide(float number1, float number2)
{
    return number1 / number2;
}
