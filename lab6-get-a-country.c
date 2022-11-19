/*
 Name: lab6.get-a-country.c
 Author: Jade Hudson
 Date: 21/10/2022

 Description: Program takes in info about a country and returns the info.
 Returns: String
*/

/* Libraries Used */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Country Country; 
struct Country
{
    char name[30];
    char capital[30];
    float population;
    int size;
};

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
    Country country;
    strcpy(country.name, argv[1]);
    strcpy(country.capital, argv[2]);
    country.population = atof(argv[3]);
    country.size = atoi(argv[4]);


    /* MAIN CODE */ 
    printf("%s\n", country.name);
	printf("%s\n", country.capital);
	printf("%.2f million people\n", country.population);
	printf("%d km2\n", country.size);
        
    return (0);
}
