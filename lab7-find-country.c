/*
 Name: lab7.find-country.c
 Author: Jade Hudson
 Date: 28/10/2022

 Description: Program takes in info about multiple countries and returns all of the countries whose size is lower than 100000km^2 in tabular form.
 Returns: tabular strings.
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



/* Function Prototypes */
/* Function Size_Countries returns countries that are below 100000km^2 */
void Size_Countries(struct Country *country);

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
    int arg_count = argc - 1;
    char arg_list[arg_count];
    struct Country country;

    /*CODE*/
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for(unsigned int i = 1; i < arg_count; i+=4)
    {
        strcpy(country.name, argv[i]);
        strcpy(country.capital, argv[i + 1]);
        country.population = atof(argv[i + 2]);
        country.size = atoi(argv[i + 3]);
        Size_Countries(&country);
        // printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country->name, country->capital, country->size, country->population);
    }
    return (0);
}

/* FUNCTIONS*/
void Size_Countries(struct Country *country)
{
    if (country->size < 100000)
    {
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country->name, country->capital, country->size, country->population);
    }
}
