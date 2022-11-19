/*
 Name: lab6.cal-enerything.c
 Author: Jade Hudson
 Date: 21/10/2022

 Description: Program accepts 2 integers and returns the product, difference, sum, division, power and natural log of them to 2 decimal places.
 Returns: Floats
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Function Prototypes */
/* Function return the sum, product, differece, division, power and log of two numbers through a pointer to each function*/
float Sum(int a, int b);
float Product(int a, int b);
float Difference(int a, int b);
float Division(int a, int b);
float Power(int a, int b);
float Natural_Log(int a, int b);
float pointer_funct(float(*pfunction)(int, int), int a, int b);


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
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float result = 0.0;
    float (*pfunction)(int a, int b) = NULL;

    /* MAIN CODE */ 
    pfunction = Sum;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);

    pfunction = Difference;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);
    
    pfunction = Product;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);

    pfunction = Division;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);

    pfunction = Power;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);

    pfunction = Natural_Log;
    result = pointer_funct(pfunction, a, b);
    printf("%.2f\n", result);
    
    return (0);
}

/* FUNCTIONS */
float pointer_funct(float(*pfunction)(int, int), int a, int b)
{
    return pfunction(a, b);
}

float Sum(int a, int b)
{
    return a + b;
}

float Difference(int a, int b)
{
    return a - b;
}

float Product(int a, int b)
{
    return a * b;
}

float Division(int a, int b)
{
    return a / b;
}

float Power(int a, int b)
{
    return pow(a, b);
}

float Natural_Log(int a, int b)
{
    return log(a) + log(b);
}
